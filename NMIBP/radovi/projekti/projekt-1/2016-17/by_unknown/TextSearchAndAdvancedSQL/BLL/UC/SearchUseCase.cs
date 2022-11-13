using Npgsql;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Web;
using TextSearchAndAdvancedSQL.BLL.Model;

namespace TextSearchAndAdvancedSQL.BLL.UC
{
    public abstract class SearchUseCase : UseCase
    {
        public enum Operator
        {
            And, Or
        }

        public class Response
        {
            
            public string SQLQuery { get; set; }

            public IEnumerable<Tuple<int, string, double>> Results { get; set; }
        }

        public abstract Response Execute(ICollection<string> patterns, Operator op);

        protected bool logQuery(ICollection<string> patterns, Operator op)
        {
            using (var conn = new NpgsqlConnection(connectionString))
            {
                conn.Open();
                var cmd = new NpgsqlCommand($"INSERT INTO search_log(query) VALUES ('{convertToQueryString(patterns, op)}')", conn);
                return cmd.ExecuteNonQuery() != 0;
            }
        }

        private string convertToQueryString(ICollection<string> patterns, Operator op)
        {
            var sb = new StringBuilder();
            var separator = op == Operator.And ? " & " : " | ";
            foreach (var pattern in patterns.AsEnumerable())
            {
                sb.Append(pattern + separator);
            }
            sb.Remove(sb.Length - separator.Length, separator.Length);
            return sb.ToString();
        }
    }
}