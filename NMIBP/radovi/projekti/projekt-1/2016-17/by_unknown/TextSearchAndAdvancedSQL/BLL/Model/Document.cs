using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace TextSearchAndAdvancedSQL.BLL.Model
{
    public class Document
    {
        public const int MAX_TITLE_LENGTH = 200;
        public const int MAX_KEYWORDS_LENGTH = 200;
        public const int MAX_SUMMARY_LENGTH = 1000;
        public const int MAX_BODY_LENGTH = 10000;

        private string title;
        private string keywords;
        private string summary;
        private string body;

        public Document()
        {
            title = string.Empty;
            keywords = string.Empty;
            summary = string.Empty;
            body = string.Empty;
        }

        public Document(string title, string keywords, string summary, string body)
        {
            Title = title;
            Keywords = keywords;
            Summary = summary;
            Body = body;
        }

        public string Title
        {
            get { return title; }
            set
            {
                if(string.IsNullOrEmpty(value) || value.Length > MAX_TITLE_LENGTH) 
                {
                    throw new ArgumentException($"Invalid keywords {value}");
                }
                title = value;
            }
        }

        public string Keywords
        {
            get { return keywords; }
            set
            {
                if (string.IsNullOrEmpty(value) || value.Length > MAX_KEYWORDS_LENGTH)
                {
                    throw new ArgumentException($"Invalid title {value}");
                }
                keywords = value;
            }
        }

        public string Summary
        {
            get { return summary; }
            set
            {
                if (string.IsNullOrEmpty(value) || value.Length > MAX_SUMMARY_LENGTH)
                {
                    throw new ArgumentException($"Invalid summary {value}");
                }
                summary = value;
            }
        }

        public string Body
        {
            get { return body; }
            set
            {
                if (string.IsNullOrEmpty(value) || value.Length > MAX_BODY_LENGTH)
                {
                    throw new ArgumentException($"Invalid body {value}");
                }
                body = value;
            }
        }
    }
}