using System;

namespace OkvirnaMetoda
{
    class Coffee : Beverage
    {
        public override void Brew()
        {
            Console.WriteLine("Adding coffee");
        }

        public override void AddCondiment()
        {
            Console.WriteLine("Adding sugar and milk");
        }
    }
}
