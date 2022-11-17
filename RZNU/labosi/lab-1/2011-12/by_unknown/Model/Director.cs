using System;
using System.ComponentModel;
using System.ComponentModel.DataAnnotations;

namespace FilmInfoService.Model
{
    public class Director
    {
        [Key]
        public int ID { get; set; }

        [RegularExpression("[MF]"),StringLength(1)]
        public string Gender { get; set; }

        [StringLength(32)]
        public string Name { get; set; }

        [StringLength(32)]
        public string Surname { get; set; }

        public override bool Equals(object obj)
        {
            if (obj is Director)
            {
                Director other = (Director)obj;
                if (this.ID == other.ID && this.Name.Equals(other.Name) && this.Surname.Equals(other.Surname))
                    return true;
            }
            return false;
        }
    }
}