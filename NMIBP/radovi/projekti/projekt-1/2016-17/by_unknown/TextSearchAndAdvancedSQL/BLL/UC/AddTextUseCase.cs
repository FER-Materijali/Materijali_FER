using Npgsql;
using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using TextSearchAndAdvancedSQL.BLL.Model;

namespace TextSearchAndAdvancedSQL.BLL.UC
{
    public class AddTextUseCase : UseCase
    {
        public bool Execute(Document doc)
        {
            using (var conn = new NpgsqlConnection(connectionString))
            {
                conn.Open();
                var cmd = new NpgsqlCommand(
                    "insert into document (title, summary, body, keywords, vector, title_vector)" +
                    "values(@title, @summary, @body, @keywords, " +
                    "setweight(to_tsvector(coalesce(@title, '')), 'A') || setweight(to_tsvector(coalesce(@keywords, '')), 'B') " +
                    "|| setweight(to_tsvector(coalesce(@summary,'')), 'C') || setweight(to_tsvector(coalesce(@body,'')), 'D'), " +
                    "to_tsvector('english', coalesce(@title)))", conn);
                cmd.Parameters.AddWithValue("@title", doc.Title);
                cmd.Parameters.AddWithValue("@summary", doc.Summary);
                cmd.Parameters.AddWithValue("@body", doc.Body);
                cmd.Parameters.AddWithValue("@keywords", doc.Keywords);
                return cmd.ExecuteNonQuery() != 0;
            }
        }
    }
}