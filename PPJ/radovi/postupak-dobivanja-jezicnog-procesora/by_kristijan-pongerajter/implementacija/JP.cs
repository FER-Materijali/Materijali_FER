using System;

namespace JP
{
    public class JP
    {
        public string FromLang;
        public string ToLang;
        public string Lang;

        public bool IsMachineLang { get { return Lang == Lang.ToLowerInvariant(); } }

        public JP(string line)
        {
            string[] split = line.Split(new char[] { ',' });
            if (split.Length != 3)
                throw new Exception("Invalid JP input: " + line);
            this.ToLang = split[1].Trim();
            this.FromLang = split[0].Trim();
            this.Lang = split[2].Trim();
        }

        public JP(string from, string to, string lang)
        {
            this.ToLang = to;
            this.FromLang = from;
            this.Lang = lang;
        }

        public static bool operator ==(JP a, JP b)
        {
            if (System.Object.ReferenceEquals(a, b))
                return true;
            if (((object)a == null) || ((object)b == null))
                return false;
            return a.Equals(b);
        }

        public static bool operator !=(JP a, JP b)
        {
            return !(a == b);
        }

        public override string ToString()
        {
            return FromLang + " -> " + ToLang + " in " + Lang;
        }

        public string ToString(bool chaining)
        {
            if (chaining)
                return FromLang + " -> " + ToLang + " in " + Lang;
            else
                return FromLang + " -> " + ToLang + " in " + Lang + " [exec]";
            //return "[" + FromLang + " -> " + ToLang + " in " + Lang + "]";
        }

        public override bool Equals(object obj)
        {
            if (obj.GetType() != typeof(JP))
                return false;
            JP other = (JP)obj;
            return this.ToLang == other.ToLang && this.FromLang == other.FromLang && this.Lang == other.Lang;
        }

        public override int GetHashCode()
        {
            return ToLang.GetHashCode() ^ FromLang.GetHashCode() ^ Lang.GetHashCode();
        }
    }
}
