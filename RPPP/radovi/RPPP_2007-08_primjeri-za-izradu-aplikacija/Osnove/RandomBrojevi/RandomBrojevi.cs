using System;

class RandomNumbers
{
  static void Main(string[] args)
  {
    // inicijalizacija generatora
    //Random generator = new Random(); 
    Random generator = new Random(13);
    //Random generator = new Random(DateTime.Now.Millisecond); 

    int intNum;
    double doubleNum;

    intNum = generator.Next();
    Console.WriteLine("Rand [0, Int32.MaxValue]: " + intNum);

    intNum = generator.Next(10);
    Console.WriteLine("Rand [0, 9]: " + intNum);

    intNum = generator.Next(10) + 1;
    Console.WriteLine("Rand [1, 10]: " + intNum);

    intNum = generator.Next(15) + 20;
    Console.WriteLine("Rand [20, 34]: " + intNum);

    intNum = generator.Next(20) - 10;
    Console.WriteLine("Rand [-10, 9]: " + intNum);

    doubleNum = generator.NextDouble();
    Console.WriteLine("Rand double [0, 1]: " + doubleNum);

  }
}
