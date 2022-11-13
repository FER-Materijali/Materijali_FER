using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace TextSearchAndAdvancedSQL.Models.Document
{
    public class SearchVM
    {
        public class Document
        {
            public int Id { get; set; }

            public string Title { get; set; }

            public double Rank { get; set; }
        }

        [Display(Name = "Search patterns")]
        [Required(ErrorMessage = "Search pattern is required")]
        [MaxLength(200, ErrorMessage = "Search pattern must be 200 characters or less")]
        public string Patterns { get; set; }

        [Display(Name = "Logical operator")]
        [Required(ErrorMessage = "Logical operator is required")]
        public string Operator { get; set; } = "And";

        [Display(Name = "Search type")]
        [Required(ErrorMessage = "Search type is required")]
        public string SearchType { get; set; } = "Semantic";

        public string SQLQuery { get; set; } = string.Empty;

        public IEnumerable<Document> Documents { get; set; } = new List<Document>();
    }
}