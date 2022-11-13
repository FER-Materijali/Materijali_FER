using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TextSearch
{
    public class KnuthMorrisPrattSearcher : Searcher
    {
        public List<int> Search(string text, string pattern)
        {
            List<int> rv = new List<int>();
            int patternLength = pattern.Length;
            int textLength = text.Length;
            int i = 0;
            int j = 0;
            int[] lps = ComputeLPSArray(pattern);

            while (i < textLength)
            {
                if (pattern[j] == text[i])
                {
                    j++;
                    i++;
                }

                if (j == patternLength)
                {
                    rv.Add(i - j);
                    j = lps[j - 1];
                }

                else if (i < textLength && pattern[j] != text[i])
                {
                    if (j != 0)
                        j = lps[j - 1];
                    else
                        i = i + 1;
                }
            }

            return rv;
        }

        private static int[] ComputeLPSArray(string pattern)
        {
            int length = 0;
            int i = 1;
            var lps = new int[pattern.Length];

            lps[0] = 0;

            while (i < pattern.Length)
            {
                if (pattern[i] == pattern[length])
                {
                    length++;
                    lps[i] = length;
                    i++;
                }
                else
                {
                    if (length != 0) { length = lps[length - 1]; }
                    else { lps[i++] = 0; }
                }
            }

            return lps;
        }
    }
}
