using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DatabaseLayer
{
    public class Result
    {
        public int id { get; set; }
        public string headline { get; set; }
        public string text { get; set; }
        public string author { get; set; }
        public  List<CommentResult> comments { get; set; }
        public byte[] picture { get; set; }
    }
    public class CommentResult{
        public DateTime timestamp { get; set; }
        public string text { get; set; }
    }

}
