using System;
using System.ComponentModel;
using System.ComponentModel.DataAnnotations;

namespace FilmInfoService.Model
{
    public class Film
    {
        [Key]
        public int ID { get; set; }

        public string Title { get; set; }

      //  [ForeignKey("ID")]
        public int Director { get; set; }

        public int Year { get; set; }

        //[RegularExpression("tt[0-9]{
        public string IMDBID { get; set; }
    }
}