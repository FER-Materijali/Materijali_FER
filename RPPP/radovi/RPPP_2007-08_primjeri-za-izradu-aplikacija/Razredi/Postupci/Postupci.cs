using System;

class Postupak
{
  // uèahurivanje (encapsulation) - skrivanje èlana
  private int localVar = -1;

  // pristup skrivenom èlanu obavlja se javnim postupcima
  public void SetVar(int var) { localVar = var; }
  public int GetVar() { return localVar; }
}

class Postupci
{
  public static void SwapByVal(int a, int b)
  {
    int temp = a;
    a = b;
    b = temp;
  }
  public static void SwapByRef(ref int a, ref int b)
  {
    int temp = a;
    a = b;
    b = temp;
  }

  public static void TestVal(Postupak post, int defval)
  {
    post = new Postupak();
    post.SetVar(defval);
  }

  public static void TestRef(ref Postupak post, int defval)
  {
    post = new Postupak();
    post.SetVar(defval);
  }

  public static void TestOut(out int val, int defval)
  {
    val = defval; // mora biti postavljen
  }

  public static void Main()
  {
    Postupak p = new Postupak();
    Console.WriteLine("Var prije " + p.GetVar());
    p.SetVar(3);
    Console.WriteLine("Var poslije " + p.GetVar());

    int a, b;

    a = 1; b = 2; // argumenti moraju biti inicijalizirani
    Console.WriteLine("Postavljeno a={0}  b={1}", a, b);
    SwapByVal(a, b);
    Console.WriteLine("SwapByVal a={0}  b={1}", a, b);
    SwapByRef(ref a, ref b);
    Console.WriteLine("SwapByRef a={0}  b={1}", a, b);

    TestVal(p, 21);
    Console.WriteLine("TestVal p=" + p.GetVar());
    TestRef(ref p, 22);
    Console.WriteLine("TestRef p=" + p.GetVar());

    int i = 33;   // varijabla ne mora biti inicijalizirana
    TestOut(out i, 13);
    Console.WriteLine("TestOut out i={0}", i);
  }
}
