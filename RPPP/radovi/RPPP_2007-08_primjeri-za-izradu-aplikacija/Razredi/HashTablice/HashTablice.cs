#define HASH
using System;
using System.Collections; // zbog Hashtable
using System.Collections.Generic; // Dictionary
using System.Text;

namespace HashTablice
{
  class HashTablice
  {
    static void Main(string[] args)
    {

      //hash tablice (Hashtable i Dictionary)
#if HASH
      Hashtable a = new Hashtable(10); //10 je predviðeni maksimalan broj elemenata 
#else
      Dictionary<int, string> a = new Dictionary<int, string>(10); //Dictionary
#endif

      a.Add(100, "Jedan");  // kljuè (na prvom mjestu) mora biti jedinstven
      a.Add(200, "Dva");

#if HASH
     foreach (DictionaryEntry d in a)
#else
     foreach (KeyValuePair<int,string> d in a) 
#endif
      {
        Console.WriteLine(d.Value);
      }

      a.Remove(100);
      a.Remove(200);
      a.Clear();

    }
  }
}
