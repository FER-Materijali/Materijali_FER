using Npgsql;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace TextSearchAndAdvancedSQL.BLL.UC
{
    public class AnalyzeUseCase : UseCase
    {
        public class Result
        {
            public string SearchPattern { get; set; } = string.Empty;

            public List<string> Times { get; set; } = new List<string>();
        }

        public enum Granulation
        {
            Days, Hours
        }

        public Tuple<List<string>, List<Result>> Execute(DateTime startDate, DateTime endDate, Granulation gran)
        {
            using (var conn = new NpgsqlConnection(connectionString))
            {
                conn.Open();

                var gen = gran == Granulation.Days ? generateDaysQuery(startDate, endDate) : generateHoursQuery(startDate, endDate);
                using (var insert = new NpgsqlCommand(gen.Item2, conn))
                {
                    insert.ExecuteNonQuery();
                }

                var resp = new List<Result>();
                var select = new NpgsqlCommand(gen.Item3, conn);
                using (var reader = select.ExecuteReader())
                {
                    while (reader.Read())
                    {
                        var res = new Result() { SearchPattern = reader[0].ToString() };
                        for (int i = 1; i <= gen.Item1.Count; i++)
                        {
                            res.Times.Add(reader[i].ToString());
                        }
                        resp.Add(res);
                    }
                }
                select.Dispose();

                using (var del = new NpgsqlCommand(gen.Item4, conn))
                {
                    del.ExecuteNonQuery();
                }

                return new Tuple<List<string>, List<Result>>(gen.Item1, resp);
            }
        }

        private Tuple<List<string>, string, string, string> generateDaysQuery(DateTime startDate, DateTime endDate)
        {
            var headers = new List<string>();
            var insert = "create table v (i text); insert into v values ";
            var select = "SELECT * " +
                "FROM crosstab(  $$SELECT query::text q, date(stamp)::text s, count(date(stamp))::text c" +
                $"                 from search_log where date(stamp) >= '{startDate.ToString("yyyy-MM-dd")}' and date(stamp) <= '{endDate.ToString("yyyy-MM-dd")}'" +
                "group by q, s order by q, s$$, $$SELECT i from v order by i$$) as piv (q text, ";
            var c = 0;
            for (var i = startDate; i <= endDate; i = i.AddDays(1))
            {
                var dateStr = i.ToString("yyyy-MM-dd");
                insert += $"('{dateStr}'), ";
                headers.Add(dateStr);
                select += $"c{c++} text, ";
            }
            insert = insert.TrimEnd(new char[] { ' ', ',' });
            select = select.TrimEnd(new char[] { ' ', ',' }) + ")";
            return new Tuple<List<string>, string, string, string>(headers, insert, select, "drop table v");
        }

        private Tuple<List<string>, string, string, string> generateHoursQuery(DateTime startDate, DateTime endDate)
        {
            var headers = new List<string>();
            var insert = "create table v (i text); insert into v values ";
            var select = "SELECT * " +
                "FROM crosstab(  $$SELECT query::text q, to_char(stamp, 'HH24') s, count(to_char(stamp, 'HH24'))::text c" +
                $"                 from search_log where date(stamp) >= '{startDate.ToString("yyyy-MM-dd")}' and date(stamp) <= '{endDate.ToString("yyyy-MM-dd")}'" +
                "group by q, s order by q, s$$, $$SELECT i from v order by i$$) as piv (q text, ";
            var c = 0;
            for (var h = 0; h < 24; h++)
            {
                var header = h.ToString("D2");
                headers.Add(header);
                insert += $"('{header}'), ";
                select += $"c{c++} text, ";
            }
            insert = insert.Substring(0, insert.Length - 2);
            select = select.Substring(0, select.Length - 2) + ")";
            return new Tuple<List<string>, string, string, string>(headers, insert, select, "drop table v");
        }
    }
}