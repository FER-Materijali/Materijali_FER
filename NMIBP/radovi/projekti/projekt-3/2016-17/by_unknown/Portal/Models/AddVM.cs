using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace Portal.Models
{
    public class AddVM
    {
        public string Headline { get; set; }

        public string Text { get; set; }

        public string Author { get; set; }

        [Required]
        [Display(Name = "Picture")]
        public string File { get; set; }
    }
}