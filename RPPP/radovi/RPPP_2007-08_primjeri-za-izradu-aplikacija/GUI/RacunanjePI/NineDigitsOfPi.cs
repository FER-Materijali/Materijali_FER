// NineDigitsOfPiAt.cs

/*
 * Computation of the n'th decimal digit of pi with very little memory.
 * Written by Fabrice Bellard on January 8, 1997.
 * Ported to C# by Chris Sells on May 5, 2002.
 * 
 * We use a slightly modified version of the method described by Simon
 * Plouffe in "On the Computation of the n'th decimal digit of various
 * transcendental numbers" (November 1996). We have modified the algorithm
 * to get a running time of O(n^2) instead of O(n^3log(n)^3).
 * 
 * This program uses mostly integer arithmetic. It may be slow on some
 * hardwares where integer multiplications and divisons must be done
 * by software.
 */

using System;

public class NineDigitsOfPi
{
  public static int NextPrime(long a, long b, int m)
  {
    return (int)((a * b) % m);
  }

  // return the inverse of x mod y
  public static int InvMod(int x, int y)
  {
    int q = 0;
    int u = x;
    int v = y;
    int a = 0;
    int c = 1;
    int t = 0;

    do
    {
      q = v / u;

      t = c;
      c = a - q * c;
      a = t;

      t = u;
      u = v - q * u;
      v = t;
    }
    while (u != 0);

    a = a % y;
    if (a < 0) a = y + a;

    return a;
  }

  // return (a^b) mod m
  public static int PowMod(int a, int b, int m)
  {
    int r = 1;
    int aa = a;

    while (true)
    {
      if ((b & 0x01) != 0) r = NextPrime(r, aa, m);
      b = b >> 1;
      if (b == 0) break;
      aa = NextPrime(aa, aa, m);
    }

    return r;
  }

  // return true if n is prime
  public static bool IsPrime(int n)
  {
    if ((n % 2) == 0) return false;

    int r = (int)(Math.Sqrt(n));
    for (int i = 3; i <= r; i += 2)
    {
      if ((n % i) == 0) return false;
    }

    return true;
  }

  // return the prime number immediately after n
  public static int NextPrime(int n)
  {
    do
    {
      n++;
    }
    while (!IsPrime(n));

    return n;
  }

  public static int StartingAt(int n)
  {
    int av = 0;
    int vmax = 0;
    int N = (int)((n + 20) * Math.Log(10) / Math.Log(2));
    int num = 0;
    int den = 0;
    int kq = 0;
    int kq2 = 0;
    int t = 0;
    int v = 0;
    int s = 0;
    double sum = 0.0;

    for (int a = 3; a <= (2 * N); a = NextPrime(a))
    {
      vmax = (int)(Math.Log(2 * N) / Math.Log(a));
      av = 1;

      for (int i = 0; i < vmax; ++i) av = av * a;

      s = 0;
      num = 1;
      den = 1;
      v = 0;
      kq = 1;
      kq2 = 1;

      for (int k = 1; k <= N; ++k)
      {
        t = k;
        if (kq >= a)
        {
          do
          {
            t = t / a;
            --v;
          }
          while ((t % a) == 0);

          kq = 0;
        }

        ++kq;
        num = NextPrime(num, t, av);

        t = (2 * k - 1);
        if (kq2 >= a)
        {
          if (kq2 == a)
          {
            do
            {
              t = t / a;
              ++v;
            }
            while ((t % a) == 0);
          }

          kq2 -= a;
        }

        den = NextPrime(den, t, av);
        kq2 += 2;

        if (v > 0)
        {
          t = InvMod(den, av);
          t = NextPrime(t, num, av);
          t = NextPrime(t, k, av);
          for (int i = v; i < vmax; ++i) t = NextPrime(t, a, av);
          s += t;
          if (s >= av) s -= av;
        }
      }

      t = PowMod(10, n - 1, av);
      s = NextPrime(s, t, av);
      sum = (sum + (double)s / (double)av) % 1.0;
    }

    return (int)(sum * 1e9);
  }
}

