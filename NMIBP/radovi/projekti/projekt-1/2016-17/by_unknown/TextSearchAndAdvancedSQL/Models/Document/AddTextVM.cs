using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace TextSearchAndAdvancedSQL.Models.Document
{
    public class AddTextVM
    {
        [Required(ErrorMessage = "Document title is required")]
        [MaxLength(200, ErrorMessage = "Title must be 200 characters or less")]
        public string Title { get; set; }

        [Required(ErrorMessage = "Document keywords are required")]
        [MaxLength(200, ErrorMessage = "Keywords must have 200 characters or less")]
        public string Keywords { get; set; }

        [Required(ErrorMessage = "Summary is required")]
        [MaxLength(1000, ErrorMessage = "Summary must have 1000 characters or less")]
        public string Summary { get; set; }

        [Required(ErrorMessage = "Body is required")]
        [MaxLength(10000, ErrorMessage = "Body must have 10000 characters or less")]
        public string Body { get; set; }
    }
}