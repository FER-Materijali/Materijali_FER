using System;

namespace OkvirnaMetoda
{
    abstract class CondimentBeverage : Beverage
    {
        protected Beverage _beverage;

        public CondimentBeverage(Beverage beverage)
        {
            _beverage = beverage;
        }

        public override void Brew()
        {
            _beverage.Brew();
        }
    }

    class CoffeeWithSugar : CondimentBeverage
    {
        private int sugarQuantity;

        public CoffeeWithSugar(Coffee coffee, int sugarQuantity)
            : base(coffee)
        {
            this.sugarQuantity = sugarQuantity;
        }

        public override void AddCondiment()
        {
            //_beverage.AddCondiment();
            Console.WriteLine("Adding {0} grams of sugar", sugarQuantity);
        }
    }
}
