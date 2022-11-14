using System;

namespace OkvirnaMetoda
{
    class Program
    {
        static void Main()
        {
            Beverage beverage = new Coffee();
            beverage.Prepare();

            Console.WriteLine();

            beverage = new Tea();
            beverage.Prepare();

            Console.WriteLine();

            beverage = new CoffeeWithSugar(new Coffee(), 100);
            beverage.Prepare();
        }
    }
}
