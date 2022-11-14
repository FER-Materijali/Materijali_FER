using System;

namespace OkvirnaMetoda
{
    abstract class Beverage
    {
        public void Prepare()
        {
            BoilWater();
            Brew();
            PourOutWater();
            AddCondiment();
        }

        public void BoilWater()
        {
            Console.WriteLine("Boiling water");
        }

        public void PourOutWater()
        {
            Console.WriteLine("Pouring water");
        }

        public abstract void Brew();
        public abstract void AddCondiment();
    }
}
