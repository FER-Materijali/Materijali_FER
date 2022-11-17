using System;
using System.Collections.Generic;
using System.Text;

public enum Kontinent { Europa, Amerika, Azija, Afrika, Australija }

class Naredbe
{

    static void Main(string[] args)
    {

        List<Drzava> PopisDrzava = new List<Drzava>();
        Drzava DrzavaPrivremeno;

        DrzavaPrivremeno = new Drzava("HR", "Hrvatska", Kontinent.Europa);
        PopisDrzava.Add(DrzavaPrivremeno);
        DrzavaPrivremeno = new Drzava("GB", "Velika Britanija", Kontinent.Europa);
        PopisDrzava.Add(DrzavaPrivremeno);

        Console.WriteLine("Ukupno država na popisu: " + PopisDrzava.Count);
        foreach (Drzava d in PopisDrzava)
        {
            Console.WriteLine(d.ToString()); 
        }

    }
}

public class Drzava
{
    #region varijable
    string _OznakaDrzave;
    string _NazivDrzave;
    Kontinent _Kontinent;

    public string OznakaDrzave
    {
        set { _OznakaDrzave = value; }
        get { return _OznakaDrzave; }
    }

    public string NazivDrzave
    {
        set { _NazivDrzave = value; }
        get { return _NazivDrzave; }
    }
    public Kontinent Kontinent
    {
        set { _Kontinent = value; }
        get { return _Kontinent; }
    }

    #endregion

    #region konstruktor
    public Drzava(string OznakaDrzave, string NazivDrzave, Kontinent Kontinent)
    {
        _OznakaDrzave = OznakaDrzave;
        _NazivDrzave = NazivDrzave;
        _Kontinent = Kontinent;
    }
    #endregion

    #region metode
    public override string ToString()
    {
        return _OznakaDrzave + " " + _NazivDrzave;
    }

    #endregion
}



