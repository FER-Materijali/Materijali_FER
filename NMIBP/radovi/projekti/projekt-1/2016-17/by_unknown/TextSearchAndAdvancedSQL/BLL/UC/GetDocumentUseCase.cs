using Npgsql;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using TextSearchAndAdvancedSQL.BLL.Model;

namespace TextSearchAndAdvancedSQL.BLL.UC
{
    public class GetDocumentUseCase : UseCase
    {
        public Document Execute(int id)
        {
            using (var conn = new NpgsqlConnection(connectionString))
            {
                conn.Open();
                var cmd = new NpgsqlCommand($"select title, keywords, summary, body from document where id = {id}", conn);

                var reader = cmd.ExecuteReader();
                var doc = new Document();
                while (reader.Read())
                {
                    doc.Title = reader[0].ToString();
                    doc.Keywords = reader[1].ToString();
                    doc.Summary = reader[2].ToString();
                    doc.Body = reader[3].ToString();
                }

                return doc;
            }
        }
    }
}