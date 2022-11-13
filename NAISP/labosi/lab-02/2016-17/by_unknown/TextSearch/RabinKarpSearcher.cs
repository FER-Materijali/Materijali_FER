using System.Collections.Generic;

namespace TextSearch
{
    public class RabinKarpSearcher : Searcher
    {
        public List<int> Search(string text, string pattern)
        {
            List<int> rv = new List<int>();
            ulong textSignature = 0;
            ulong patternSignature = 0;
            ulong q = 100007;
            ulong d = 256;

            for (int i = 0; i < pattern.Length; ++i)
            {
                textSignature = (textSignature * d + text[i]) % q;
                patternSignature = (patternSignature * d + pattern[i]) % q;
            }

            if (textSignature == patternSignature) { rv.Add(0); }

            ulong pow = 1;

            for (int k = 1; k < pattern.Length; ++k) { pow = (pow * d) % q; }

            for (int j = 1; j <= text.Length - pattern.Length; ++j)
            {
                textSignature = (textSignature + q - pow * text[j - 1] % q) % q;
                textSignature = (textSignature * d + text[j + pattern.Length - 1]) % q;

                if (textSignature == patternSignature && text.Substring(j, pattern.Length) == pattern) { rv.Add(j); }
            }

            return rv;
        }
    }
}
