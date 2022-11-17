using System;
using System.Text;

class StringTest
{
  public static void Main(string[] args)
  {

    //System.String

    Console.WriteLine("********** Primjeri sa String-om **********");
    string a = "abcd";
    Console.WriteLine("Duljina stringa {0} je {1}.", a, a.Length);

    string b = a.Replace('b', 'o');
    Console.WriteLine("Nakon zamjene b sa o:\n{0}", b);

    string c = b.Insert(3, "xy");
    string d = c.ToUpper();
    Console.WriteLine("Nakon umetanja xy na 3.mjesto i prebacivanja na velika slova:\n{0}", d);

    string e = d.Remove(0, 3);
    Console.WriteLine("Nakon brisanja prva 3 znaka:\n{0}", e);

    Console.WriteLine("\nFormatiranje stringa: ");
    Console.WriteLine("Desno poravnati, zauzimaju 5 znakova:\n{0,5} {1,5}", 123, 456);
    Console.WriteLine("Lijevo poravnati, zauzimaju 5 znakova:\n{0,-5} {1,-5}", 123, 456);

    //System.Text.StringBuilder

    Console.WriteLine("\n********** Primjeri sa StringBuilder-om **********");
    string text = "Pero Periæ 23\nMarija Mariæ 20\nIvo Iviæ 21";
    string[] niz = text.Split('\n');

    StringBuilder sb = new StringBuilder();

    foreach (string str in niz)
    {
      string[] s = str.Split(' ');

      sb.Append(s[0]);
      sb.Append(" ");
      sb.Append(s[1].ToUpper());
      sb.Append(" ");
      sb.Append(s[2]);
      sb.Append("\n");
    }

    //ToString()

    Console.WriteLine(sb.ToString());

    int x = 2;
    Console.WriteLine("a" + x); //automatski poziv metode ToString() na broju x
  }
}
