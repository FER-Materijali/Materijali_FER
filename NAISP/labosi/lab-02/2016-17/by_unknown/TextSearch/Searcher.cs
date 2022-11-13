using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TextSearch
{
    public interface Searcher
    {
        List<int> Search(string text, string pattern);
    }
}
