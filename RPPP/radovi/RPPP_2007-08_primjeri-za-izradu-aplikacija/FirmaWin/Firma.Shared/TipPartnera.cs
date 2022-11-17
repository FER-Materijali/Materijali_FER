using System;
using System.Collections.Generic;
using System.Text;

namespace Firma
{
  // Enumerator vrste partnera
  public enum TipPartnera
  {
    Osoba,
    Tvrtka,
    Nedefinirano
  }

  // Klasa za konverziju
  public static class TipPartneraConverter
  {
    public static string ToString(TipPartnera tp)
    {
      switch (tp)
      {
        case TipPartnera.Osoba: return "O";
        case TipPartnera.Tvrtka: return "T";
        default: return string.Empty;
      }
    }

    public static TipPartnera FromString(string tp)
    {
      if (tp.Equals("O", StringComparison.OrdinalIgnoreCase))
      {
        return TipPartnera.Osoba;
      }
      else if (tp.Equals("T", StringComparison.OrdinalIgnoreCase))
      {
        return TipPartnera.Tvrtka;
      }
      else
      {
        throw new InvalidCastException();
      }
    }
  }
}
