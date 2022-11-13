using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;
using TextSearchAndAdvancedSQL.BLL.UC;

namespace TextSearchAndAdvancedSQL.Models.Document
{
    public class AnalyzeVM
    {
        [Display(Name = "Start date")]
        [Required(ErrorMessage = "Start date is required")]
        [DataType(DataType.Date)]
        public DateTime Start { get; set; } = DateTime.Now;

        [Display(Name = "End date")]
        [Required(ErrorMessage = "End date is required")]
        [DataType(DataType.Date)]
        public DateTime End { get; set; } = DateTime.Now;

        [Required(ErrorMessage = "Granulation is required")]
        public string Granulation { get; set; } = "Day";

        public Tuple<List<string>, List<AnalyzeUseCase.Result>> Response { get; set; } 
            = new Tuple<List<string>, List<AnalyzeUseCase.Result>>(new List<string>(), new List<AnalyzeUseCase.Result>());
    }
}