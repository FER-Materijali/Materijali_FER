using System;
using System.Collections.Generic;
using System.Text;

namespace JP
{
    public class Generator
    {
        public List<JP> Input;
        public JP Requested;

        List<PathJP> AllPossible;
        List<PathJP> novi;

        public Generator(List<JP> input, JP Requested)
        {
            this.Input = input;
            this.Requested = Requested;
        }

        public string Resolve()
        {
            string res = "";
            ////provjerimo da rješenje nije u ulazu
            //if (Input.Contains(Requested))
            //    return "Traženi JP je već u ulaznom skupu: " + Requested;
            //Lista koja sadrži sve trenutno dostupne procesore koji kreću iz zadanog jezika
            AllPossible = new List<PathJP>();
            //korak 1 dodajemo sve koji idu iz inputa
            novi = new List<PathJP>();
            foreach (JP x in Input)
                novi.Add(new PathJP(x, null, null));

            while (novi.Count > 0)
            {
                AllPossible.AddRange(novi);
                novi = new List<PathJP>();

                res = CheckForSolution();
                if (res != "")
                    return res;

                for (int i = 0; i < AllPossible.Count - 1; ++i)
                    for (int j = i + 1; j < AllPossible.Count; ++j)
                    {
                        PathJP a = AllPossible[i];
                        PathJP b = AllPossible[j];
                        if (b.JP.IsMachineLang && a.JP.Lang == b.JP.FromLang)
                            DodajUNoveAkoNePostoji(new PathJP(new JP(a.JP.FromLang, a.JP.ToLang, b.JP.ToLang), a.JP, b.JP));
                        if (a.JP.IsMachineLang && b.JP.Lang == a.JP.FromLang)
                            DodajUNoveAkoNePostoji(new PathJP(new JP(b.JP.FromLang, b.JP.ToLang, a.JP.ToLang), b.JP, a.JP));
                        if (a.JP.IsMachineLang && a.JP.Lang == b.JP.Lang)
                        {
                            if (a.JP.FromLang == b.JP.ToLang)
                                DodajUNoveAkoNePostoji(new PathJP(new JP(b.JP.FromLang, a.JP.ToLang, a.JP.Lang), b.JP, a.JP, true));
                            if (b.JP.FromLang == a.JP.ToLang)
                                DodajUNoveAkoNePostoji(new PathJP(new JP(a.JP.FromLang, b.JP.ToLang, a.JP.Lang), a.JP, b.JP, true)); 
                        }
                    }
            }

            //nismo ništa novo dodali, nema rješenja
            return null;
        }

        public int DodajUNoveAkoNePostoji(PathJP el)
        {
            if (!AllPossible.Contains(el))
                if (!novi.Contains(el))
                {
                    novi.Add(el);
                    return 1;
                }
            return 0;
        }

        private string CheckForSolution()
        {
            for (int i = 0; i < AllPossible.Count; ++i)
            {
                if (AllPossible[i].JP == Requested)
                {
                    StringBuilder sb = new StringBuilder();
                    GetSolution(i, 0, sb, true);
                    return sb.ToString();
                }
            }
            return "";
        }

        private void GetSolution(int i, int depth, StringBuilder sb, bool isChain)
        {
            PathJP x = AllPossible[i];
            Indent(depth, sb);
            sb.AppendLine(x.JP.ToString(isChain));
            if (x.Source != null && x.Program != null)
            {
                if (Input.IndexOf(x.Source) < 0)
                    GetSolution(GetIndex(x.Source), depth + 1, sb, true);
                else
                {
                    Indent(depth + 1, sb);
                    sb.AppendLine(x.Source.ToString());
                }
                if (Input.IndexOf(x.Program) < 0)
                    GetSolution(GetIndex(x.Program), depth + 1, sb, x.IsChaining);
                else
                {
                    Indent(depth + 1, sb);
                    sb.AppendLine(x.Program.ToString(x.IsChaining));
                }
            }
        }

        private void Indent(int n, StringBuilder sb)
        {
            for (int i = 0; i < n; ++i)
                sb.Append("  ");
        }

        private int GetIndex(JP jp)
        {
            for (int i = 0; i < AllPossible.Count; ++i)
                if (AllPossible[i].JP == jp)
                    return i;
            return -1;
        }
    }
}
