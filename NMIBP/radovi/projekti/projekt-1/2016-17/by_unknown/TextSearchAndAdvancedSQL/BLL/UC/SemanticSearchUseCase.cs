using Npgsql;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace TextSearchAndAdvancedSQL.BLL.UC
{
    public class SemanticSearchUseCase : SearchUseCase
    {
        public override Response Execute(ICollection<string> patterns, Operator op)
        {
            logQuery(patterns, op);
            using (var conn = new NpgsqlConnection(connectionString))
            {
                conn.Open();
                var ts_pattern = convertToSQLPatterns(patterns, op);

                var cmd = new NpgsqlCommand($"select \n\tid,\n" +
                    $"\tts_headline(title, to_tsquery('english', '{ts_pattern}')) headline,\n" +
                    $"\tts_rank(array[0.2,0.2,0.3,0.3], vector, to_tsquery('english', '{ts_pattern}')) rank\n" +
                    $"from document\n" +
                    $"where vector @@ to_tsquery('english', '{ts_pattern}')\n" +
                    $"order by rank desc", conn);

                var reader = cmd.ExecuteReader();
                var docs = new List<Tuple<int, string, double>>();
                while (reader.Read())
                {
                    docs.Add(new Tuple<int, string, double>(int.Parse(reader[0].ToString()), reader[1].ToString(), double.Parse(reader[2].ToString())));
                }

                return new Response { SQLQuery = cmd.CommandText, Results = docs };
            }
        }

        private string convertToSQLPatterns(ICollection<string> patterns, Operator op)
        {
            var sql_patterns = new List<string>();
            foreach (var pattern in patterns.AsEnumerable())
            {
                sql_patterns.Add($"({pattern.Replace(" ", " & ")})");
            }
            var separator = op == Operator.And ? " & " : " | ";
            return string.Join(separator, sql_patterns);
        }
    }
}