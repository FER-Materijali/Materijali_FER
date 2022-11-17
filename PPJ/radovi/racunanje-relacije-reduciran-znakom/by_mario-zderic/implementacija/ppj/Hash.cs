using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace WindowsFormsApplication1
{
    class Hash
    {
        char[] c;

        public Hash( char[] m) 
        {
            
            c = m;
    
        }

        public int GetInt(char n)
        {
            for (int j = 0; j < c.Length; j++)
                if (c[j] == n) return j;
            return 0;
        
        }

        
    }
}
