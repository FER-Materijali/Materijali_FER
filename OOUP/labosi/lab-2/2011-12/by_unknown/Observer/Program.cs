using System;
using System.Collections.Generic;

namespace Observer
{
    class Program
    {
        static void Main()
        {
            Subject subject = new Subject();

            Observer hexObserver = new HexObserver(subject);
            Observer octObserver = new OctObserver(subject);
            Observer romanObserver = new RomanObserver(subject);

            while (true)
            {
                Console.Write("Input integer: ");
                string input = Console.ReadLine();

                int state;
                if (int.TryParse(input, out state))
                {
                    subject.State = state;
                }
                else
                {
                    Console.WriteLine("Invalid integer.");
                }

                Console.WriteLine();
            }
        }
    }

    class Subject
    {
        private int _state;
        public int State
        {
            get
            {
                return _state;
            }
            set
            {
                _state = value;
                Notify();
            }
        }

        private ICollection<Observer> Observers;

        public Subject()
        {
            Observers = new List<Observer>();
        }

        public void Attach(Observer observer)
        {
            Observers.Add(observer);
        }

        public void Notify()
        {
            foreach (var observer in Observers)
            {
                observer.Update();
            }
        }
    }

    abstract class Observer
    {
        protected Subject _subject;

        public Observer(Subject subject)
        {
            _subject = subject;
            _subject.Attach(this);
        }

        public abstract void Update();
    }

    class HexObserver : Observer
    {
        public HexObserver(Subject subject)
            : base(subject)
        { }

        public override void Update()
        {
            Console.WriteLine("Hexadecimal: {0}",
                Convert.ToString(_subject.State, 16));
        }
    }

    class OctObserver : Observer
    {
        public OctObserver(Subject subject)
            : base(subject)
        { }

        public override void Update()
        {
            Console.WriteLine("Octal: {0}",
                Convert.ToString(_subject.State, 8));
        }
    }

    class RomanObserver : Observer
    {
        static readonly string[,] table = null;

        public RomanObserver(Subject subject)
            : base(subject)
        { }

        static RomanObserver()
        {
            table = new string[,] 
            { 
                { "CM", "D", "CD", "C" }, 
                { "XC", "L", "XL", "X" }, 
                { "IX", "V", "IV", "I" } 
            };
        }

        public override void Update()
        {
            int value = _subject.State;

            Console.Write("Roman: ");

            if (value > 3999)
            {
                Console.WriteLine("****");
                return;
            }

            while (value >= 1000)
            {
                Console.Write("M");
                value -= 1000;
            }

            for (int multiplier = 100, index = 0; multiplier >= 1;
                                                  multiplier /= 10, index++)
            {
                if (value >= 9 * multiplier)
                {
                    Console.Write(table[index, 0]);
                    value -= 9 * multiplier;
                }
                else if (value >= 5 * multiplier)
                {
                    Console.Write(table[index, 1]);
                    value -= 5 * multiplier;
                }
                else if (value >= 4 * multiplier)
                {
                    Console.Write(table[index, 2]);
                    value -= 4 * multiplier;
                }

                while (value >= 1 * multiplier)
                {
                    Console.Write(table[index, 3]);
                    value -= 1 * multiplier;
                }
            }

            Console.WriteLine();
        }
    }
}
