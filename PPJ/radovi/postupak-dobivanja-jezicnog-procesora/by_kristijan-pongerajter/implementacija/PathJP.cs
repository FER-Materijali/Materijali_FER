using System;

namespace JP
{
    public class PathJP
    {
        public JP JP;
        public JP Source;
        public JP Program;
        public bool IsChaining;

        public PathJP(JP jp, JP source, JP program)
        {
            this.JP = jp;
            this.Source = source;
            this.Program = program;
            this.IsChaining = false;
        }

        public PathJP(JP jp, JP source, JP program, bool chaining)
        {
            this.JP = jp;
            this.Source = source;
            this.Program = program;
            this.IsChaining = chaining;
        }

        public override string ToString()
        {
            if (JP == null)
                return "";
            if (Source == null || Program == null)
                return JP.ToString();
            return JP + "(" + Source + "->[" + Program + "])";
        }

        //smatramo da su objekti isti ako je jezični procesor isti,
        //zanemarujemo alternativne puteve do istog procesora
        public override bool Equals(object obj)
        {
            if (obj.GetType() != typeof(PathJP))
                return false;
            PathJP other = (PathJP)obj;
            return this.JP.Equals(other.JP);
        }

        public override int GetHashCode()
        {
            return this.JP.GetHashCode();
        }
    }
}
