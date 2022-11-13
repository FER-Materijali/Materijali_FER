using Npgsql;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Web;

namespace TextSearchAndAdvancedSQL.BLL.UC
{
    public class FuzzySearchUseCase : SearchUseCase
    {
        public override Response Execute(ICollection<string> patterns, Operator op)
        {
            logQuery(patterns, op);
            using (var conn = new NpgsqlConnection(connectionString))
            {
                conn.Open();
                var simPattern = (op == Operator.And) ? createSQLSimilarityFunctions(new List<string> { concat(patterns) }) : createSQLSimilarityFunctions(patterns);
                var wherePattern = (op == Operator.And) ? createSQLWhereCompare(new List<string> { concat(patterns) }) : createSQLWhereCompare(patterns);
                var cmd = new NpgsqlCommand($"select \n\tid,\n" +
                    $"\ttitle headline,\n" +
                    $"\t{simPattern} sim\n" +
                    $"from document\n" +
                    $"where {wherePattern}\n" +
                    $"order by sim desc", conn);

                var reader = cmd.ExecuteReader();
                var docs = new List<Tuple<int, string, double>>();
                while (reader.Read())
                {
                    docs.Add(new Tuple<int, string, double>(int.Parse(reader[0].ToString()), reader[1].ToString(), double.Parse(reader[2].ToString())));
                }

                return new Response { SQLQuery = cmd.CommandText, Results = docs };
            }
        }

        private string concat(ICollection<string> patterns)
        {
            var sb = new StringBuilder();
            foreach(var p in patterns.AsEnumerable())
            {
                sb.AppendFormat("{0} ", p);
            }
            var temp = sb.ToString();
            return temp.Substring(0, temp.Length - 1);
        }

        private string createSQLSimilarityFunctions(ICollection<string> patterns)
        {
            var sb = new StringBuilder();
            var sqlPattern = "similarity(title, '{0}') + ";
            foreach(var p in patterns.AsEnumerable())
            {
                sb.AppendFormat(sqlPattern, p);
            }
            sb.Remove(sb.Length - 2, 2);
            return sb.ToString();
        }

        private string createSQLWhereCompare(ICollection<string> patterns)
        {
            var sb = new StringBuilder();
            var sqlPattern = "title % '{0}' OR ";
            foreach(var p in patterns.AsEnumerable())
            {
                sb.AppendFormat(sqlPattern, p);
            }
            sb.Remove(sb.Length - 3, 3);
            return sb.ToString();
        }
    }
}