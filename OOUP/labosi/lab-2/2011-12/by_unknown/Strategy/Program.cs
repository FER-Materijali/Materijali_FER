using System;
using System.Collections.Generic;
using System.Text;
using System.Text.RegularExpressions;

namespace Strategy
{
    class Program
    {
        static void Main(string[] args)
        {
            Paragraf p =
                new Paragraf("Ovo je paragraf duzi od 40 znakova i treba ga razlomiti u vise redaka, ali samo ako je odabrana strategija BreakIntoLines!")
                //new Paragraf("Neki   kratki...")
                {
                    Align = new CenterAlign(40),
                    LineBreaker = new BreakLinesNotWords(20)
                };
            Console.WriteLine(p);
        }
    }

    class Paragraf
    {
        private StringBuilder _text;
        public IList<string> Text { get; protected set; }

        private Align _align;
        public Align Align 
        {
            get
            {
                return _align;
            }
            set
            {
                _align = value;
                format();
            }
        }

        private LineBreaker _lineBreaker;
        public LineBreaker LineBreaker
        {
            get
            {
                return _lineBreaker;
            }
            set
            {
                _lineBreaker = value;
                format();
            }
        }

        public Paragraf(string text = "")
        {
            _text = new StringBuilder();
            _text.Append(normalize(text));

            Text = new List<string>();
            Text.Add(_text.ToString());

            _align = new MockAlign();
            _lineBreaker = new MockLineBreak();

            format();
        }

        public void AddText(string text)
        {
            _text.Append(normalize(text));
            format();
        }

        private void format()
        {
            Text = LineBreaker.Format(_text.ToString());
            for (int i = 0; i < Text.Count; i++)
            {
                Text[i] = Align.Format(Text[i]);
            }
        }

        private string normalize(string text)
        {
            return Regex.Replace(text, @"\s+", " ", RegexOptions.None);
        }

        public override string ToString()
        {
            return string.Join(Environment.NewLine, Text);
        }
    }

    abstract class Align
    {
        protected int lineLength;

        public abstract string Format(string text);

        public Align(int lineLength = 80)
        {
            this.lineLength = lineLength;
        }
    }

    abstract class LineBreaker
    {
        protected int lineLength;

        public abstract IList<string> Format(string text);

        public LineBreaker(int lineLength = 80)
        {
            this.lineLength = lineLength;
        }
    }

    class MockAlign : Align
    {
        public MockAlign(int lineLength = 80)
            : base(lineLength)
        { }

        public override string Format(string text)
        {
            return text;
        }
    }

    class LeftAlign : Align
    {
        public LeftAlign(int lineLength = 80)
            : base(lineLength)
        { }

        public override string Format(string text)
        {
            return text;
        }
    }

    class RightAlign : Align
    {
        public RightAlign(int lineLength = 80)
            : base(lineLength)
        { }

        public override string Format(string text)
        {
            if (text.Length >= lineLength)
            {
                return text;
            }

            return new string(' ', lineLength - text.Length) + text;
        }
    }

    class CenterAlign : Align
    {
        public CenterAlign(int lineLength = 80)
            : base(lineLength)
        { }

        public override string Format(string text)
        {
            if (text.Length >= lineLength)
            {
                return text;
            }

            return new string(' ', (lineLength - text.Length) / 2) + text;
        }
    }

    class MockLineBreak : LineBreaker
    {
        public MockLineBreak(int lineLength = 80)
            : base(lineLength)
        { }

        public override IList<string> Format(string text)
        {
            IList<string> lines = new List<string>();
            lines.Add(text);
            return lines;
        }
    }

    class BreakIntoLines : LineBreaker
    {
        public BreakIntoLines(int lineLength = 80)
            : base(lineLength)
        { }

        public override IList<string> Format(string text)
        {
            IList<string> lines = new List<string>();

            while (lines.Count * lineLength < text.Length)
            {
                if (text.Length < lines.Count * lineLength + lineLength)
                {
                    lines.Add(text.Substring(lines.Count * lineLength));
                }
                else
                {
                    lines.Add(text.Substring(lines.Count * lineLength, lineLength));
                }
            }

            return lines;
        }
    }

    class BreakLinesNotWords : LineBreaker
    {
        public BreakLinesNotWords(int lineLength = 80)
            : base(lineLength)
        { }

        public override IList<string> Format(string text)
        {
            IList<string> lines = new List<string>();
            int startPosition = 0;

            while (startPosition + lineLength < text.Length)
            {
                int pos = text.LastIndexOf(" ", startPosition + lineLength, lineLength);
                if (pos < 0)
                {
                    pos = text.IndexOf(" ", startPosition);
                    if (pos < 0)
                    {
                        break;
                    }
                }

                lines.Add(text.Substring(startPosition, pos - startPosition + 1));
                startPosition = pos + 1;
            }

            lines.Add(text.Substring(startPosition));

            return lines;
        }
    }

    class DontBreakLines : LineBreaker
    {
        public DontBreakLines(int lineLength = 80)
            : base(lineLength)
        { }

        public override IList<string> Format(string text)
        {
            IList<string> lines = new List<string>();
            lines.Add(text);
            return lines;
        }
    }
}
