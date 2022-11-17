%s unarni, unarni_zagrada
%namespace LexScanner
%option noparser, verbose, summary, minimize
%namespace ListCollection

%using System.Linq;
%using System.Collections;
%using System.Text;






%{
    static int lineTot = 1;

    static int Adr_IDN = 0;
    static int Adr_KONS = 0;
    static int pointer = 0;
    static ULAZ ulazno_Polje = new ULAZ();
    static Liste Lists = new Liste();

    public TUZ Tabl_unif_znak;
   


public class C_KROS
{

    private int pokazivac;
    private string naziv;

    // Constructor
    public C_KROS(int pokazivac, string naziv)
    {
        this.pokazivac = pokazivac;
        this.naziv = naziv;
    }

    private bool Exists(string ime)
    {
        if (this.naziv == ime)
            return true;
        else
            return false;
    }
    public int Pointer(string ime)
    {
        if (this.Exists(ime))
        {
            return this.pokazivac;
        }
        else
        {
            return 0;
        }
    }
    public void PrintToConsole()
    {
        Glavni.mojaForma.KROSdataGrid.Rows.Add(this.pokazivac, this.naziv);
    }


    public string Give_Back_naziv()
    {
        return this.naziv;
    }
    public int Give_Back_pokazivac()
    {
        return this.pokazivac;
    }
}

public class C_KONST : IComparable<C_KONST>
{

    private int pokazivac;
    private string vrijednost;
    private string tip;

    // Constructor
    public C_KONST(int pokazivac, string vrijednost, string tip)
    {
        this.pokazivac = pokazivac;
        this.vrijednost = vrijednost;
        this.tip = tip;
    }
    private bool Exists(string ime)
    {
        if (this.vrijednost == ime)
            return true;
        else
            return false;
    }
    public int Pointer(string ime)
    {
        if (this.Exists(ime))
        {
            return this.pokazivac;
        }
        else
        {
            return 0;
        }
    }
    public void PrintToConsole()
    {
        Glavni.mojaForma.KonstDataGrid.Rows.Add(this.pokazivac.ToString(), this.vrijednost, this.tip);
    }
    public int CompareTo(C_KONST rhs)
    {
        return this.vrijednost.CompareTo(rhs.vrijednost);
    }
    public string Give_Back_vrijednost()
    {
        return this.vrijednost;
    }
    public string Give_Back_tip()
    {
        return this.tip;
    }
    public int Give_Back_pokazivac()
    {
        return this.pokazivac;
    }

    public void Set_tip(string novi_tip)
    {
        this.tip = novi_tip;
    }

}

public class C_IDENT : IComparable<C_IDENT>
{

    private int pokazivac;
    private string naziv;
    private string tip;

    // Constructor
    public C_IDENT(int pokazivac, string naziv, string tip)
    {
        this.pokazivac = pokazivac;
        this.naziv = naziv;
        this.tip = tip;
    }

    private bool Exists(string ime)
    {
        if (this.naziv == ime)
            return true;
        else
            return false;
    }
    public int Pointer(string ime)
    {
        if (this.Exists(ime))
        {
            return this.pokazivac;
        }
        else
        {
            return 0;
        }
    }
    public int CompareTo(C_IDENT rhs)
    {
        return this.naziv.CompareTo(rhs.naziv);
    }
    public void PrintToConsole()
    {
        Glavni.mojaForma.IdentDataGrid.Rows.Add(this.pokazivac.ToString(), this.naziv, this.tip);
    }
    public int Give_Back_pokazivac()
    {
        return this.pokazivac;
    }

    public string Give_Back_naziv()
    {
        return this.naziv;
    }
    public string Give_Back_tip()
    {
        return this.tip;
    }
    public void Set_tip(string novi_tip)
    {
        this.tip = novi_tip;
    }
}

public class C_UNIFORM_Z
{
    private string klasa;
    private int pokazivac;
    private int redak;

    // Constructor
    public C_UNIFORM_Z(string klasa, int pokazivac, int redak)
    {
        this.klasa = klasa;
        this.pokazivac = pokazivac;
        this.redak = redak;
    }
    public void PrintToConsole()
    {
        Glavni.mojaForma.UZdataGrid.Rows.Add(this.klasa, this.pokazivac.ToString(), this.redak.ToString());
    }
    public string Give_Back_Klasa()
    {
        return this.klasa;
    }
    public int Give_Back_Pokazivac()
    {
        return this.pokazivac;
    }

    public int Give_Back_Redak()
    {
        return this.redak;
    }
}

public class Liste
{
    public List<C_KROS> KROS_List;
    public List<C_IDENT> IDENT_List;
    public List<C_KONST> KONST_List;

    public Liste()
    {
        this.KROS_List = new List<C_KROS>();
        this.IDENT_List = new List<C_IDENT>();
        this.KONST_List = new List<C_KONST>();
    }

    
    public void AddKrosList()
    {

                ArrayList KrosZnak = new ArrayList();
                KrosZnak.Add(";");
				KrosZnak.Add(",");
				KrosZnak.Add(".");
				KrosZnak.Add(":");
                KrosZnak.Add("{");
                KrosZnak.Add("}");
                KrosZnak.Add("(");
                KrosZnak.Add(")");
                KrosZnak.Add("=");
                KrosZnak.Add("AND");
                KrosZnak.Add("OR");				
                KrosZnak.Add("EQ");
				KrosZnak.Add("NEQ");
				KrosZnak.Add("LE");
				KrosZnak.Add("GE");
				KrosZnak.Add("!");
                KrosZnak.Add("<");
                KrosZnak.Add(">");
                KrosZnak.Add("[");
                KrosZnak.Add("]");
                KrosZnak.Add("+");
                KrosZnak.Add("-");
                KrosZnak.Add("*");
                KrosZnak.Add("/");
				KrosZnak.Add("IF");
				KrosZnak.Add("ELSE");
                KrosZnak.Add("WHILE");
                KrosZnak.Add("DO");
				KrosZnak.Add("FOR");
                KrosZnak.Add("RETURN");
				KrosZnak.Add("CONTINUE");
				KrosZnak.Add("BREAK");
				KrosZnak.Add("DEFAULT");
				KrosZnak.Add("SWITCH");
				KrosZnak.Add("CASE");
				KrosZnak.Add("VAR");
				KrosZnak.Add("NEW");
				KrosZnak.Add("THIS");
				KrosZnak.Add("FUNCTION");


                for (int i = 1; i <= KrosZnak.Count; i++)
                {
                    KROS_List.Add(new C_KROS(i, KrosZnak[i - 1].ToString()));
                }

    }

    public int Find_Indx(string ime, int lista)
    {

        int pok = 0;
        switch (lista)
        {
            case 1: //KROS tablica 
                {
                    for (int i = 0; i < KROS_List.Count; i++)
                    {
                        if ((pok = KROS_List[i].Pointer(ime)) != 0)
                        {
                            return pok;
                        }
                    }
                    return 0;
                }
            case 2: //Tablica identifikatora
                {
                    for (int i = 0; i < IDENT_List.Count; i++)
                    {
                        if ((pok = IDENT_List[i].Pointer(ime)) != 0)
                        {
                            return pok;
                        }
                    }
                    return 0;

                }
            case 3: //Tablica konstanti
                {
                    for (int i = 0; i < KONST_List.Count; i++)
                    {
                        if ((pok = KONST_List[i].Pointer(ime)) != 0)
                        {
                            return pok;
                        }
                    }
                    return 0;

                }
            default:
                return 0;
        };
    }
    public void Sort()
    {
        KONST_List.Sort();
        IDENT_List.Sort();
    }
    public void Ispsi_KROS()
            {
                for (int i = 0; i < KROS_List.Count; i++)
                {
                    KROS_List[i].PrintToConsole();
                }
            }
   public void Ispsi_IDEN()
            {
                for (int i = 0; i < IDENT_List.Count; i++)
                {
                    IDENT_List[i].PrintToConsole();
                }
            }
   public void Ispsi_KONS()
            {
                for (int i = 0; i < KONST_List.Count; i++)
                {
                    KONST_List[i].PrintToConsole();
                }
            }
   public int Binary_Search_for_Index(string lista_switch, int vrijednost)
   {


       int donja_granica = 0;
       int gornja_granica = 0;
       int srednji = 0;
       switch (lista_switch)
       {
           case "KROS": //KROS tablica 
               {
                   gornja_granica = KROS_List.Count;
                   while (true)
                   {
                       srednji = (int)((donja_granica + gornja_granica) / 2);
                       if (KROS_List[srednji].Give_Back_pokazivac() == vrijednost)
                       {
                           return srednji;
                       }
                       if (donja_granica >= gornja_granica)
                       {
                           return 0;
                       }
                       if (KROS_List[srednji].Give_Back_pokazivac() < vrijednost)
                       {
                           donja_granica = srednji + 1;
                       }
                       if (KROS_List[srednji].Give_Back_pokazivac() > vrijednost)
                       {
                           gornja_granica = srednji - 1;
                       }

                   }
               }
           case "IDENT": //Tablica identifikatora
               {
                   gornja_granica = IDENT_List.Count;
                   while (true)
                   {
                       srednji = (int)((donja_granica + gornja_granica) / 2);
                       if (IDENT_List[srednji].Give_Back_pokazivac() == vrijednost)
                       {
                           return srednji;
                       }
                       if (donja_granica >= gornja_granica)
                       {
                           return 0;
                       }
                       if (IDENT_List[srednji].Give_Back_pokazivac() < vrijednost)
                       {
                           donja_granica = srednji + 1;
                       }
                       if (IDENT_List[srednji].Give_Back_pokazivac() > vrijednost)
                       {
                           gornja_granica = srednji - 1;
                       }

                   }
               }
           case "KONST": //Tablica konstanti
               {
                   gornja_granica = KONST_List.Count;
                   while (true)
                   {
                       srednji = (int)((donja_granica + gornja_granica) / 2);
                       if (KONST_List[srednji].Give_Back_pokazivac() == vrijednost)
                       {
                           return srednji;
                       }
                       if (donja_granica >= gornja_granica)
                       {
                           return 0;
                       }
                       if (KONST_List[srednji].Give_Back_pokazivac() < vrijednost)
                       {
                           donja_granica = srednji + 1;
                       }
                       if (KONST_List[srednji].Give_Back_pokazivac() > vrijednost)
                       {
                           gornja_granica = srednji - 1;
                       }

                   }
               }
           default:
               return 0;
       };
   }
    


}

public class C_Details
{
    public int pokazivac;
    public string naziv;
    public string tip;
    public int redak;
    public string klasa;

    public C_Details(int pokazivac, string naziv, string tip, int redak, string klasa)
    {
        this.pokazivac = pokazivac;
        this.naziv = naziv;
        this.tip = tip;
        this.redak = redak;
        this.klasa = klasa;
    }
}

public class TUZ
{

    public List<C_UNIFORM_Z> UNIFORM_Z_List;

    private int SljedProcZnak;
    
    public string SljedZnak()
    {
        string sljed_znak;
        if (this.UNIFORM_Z_List.Count>this.SljedProcZnak) sljed_znak = this.UNIFORM_Z_List[SljedProcZnak].Give_Back_Klasa();
        else return "EOF";
        if (sljed_znak == "KROS") sljed_znak = this.naziv(SljedProcZnak, Lists); 
        this.SljedProcZnak++;
        return sljed_znak;
        
    }

    public TUZ()
    {
        this.UNIFORM_Z_List = new List<C_UNIFORM_Z>();
        this.SljedProcZnak = 0;
    }


    public void Add_Unif_Konst(ULAZ ulazno_Polje, Liste Lists, string tip_K){
	
	int pointer = 0;
	string name = ulazno_Polje.izvorno;

	pointer = Lists.Find_Indx(name, 3); //3 je switch za KON
                                if (pointer != 0) // dodaj u TUZ, povezi
                                {
                                    UNIFORM_Z_List.Add(new C_UNIFORM_Z(ulazno_Polje.uniformno, pointer, ulazno_Polje.redak));
                                }
                                else //dodaj u tab konst, dodaj u TUZ, povezi
                                {
                                    Adr_KONS++;
                                    Lists.KONST_List.Add(new C_KONST(Adr_KONS, name, tip_K));
                                    UNIFORM_Z_List.Add(new C_UNIFORM_Z(ulazno_Polje.uniformno, Adr_KONS, ulazno_Polje.redak));
                                }
	}
    

	
    public void Add_Unif_Ident(ULAZ ulazno_Polje, Liste Lists){
	
	string name = ulazno_Polje.izvorno;
	int pointer = 0;

	pointer = Lists.Find_Indx(name, 2); // 2 je switch za IDENT
                        if (pointer != 0) // dodaj u TUZ, povezi
                        {
                            UNIFORM_Z_List.Add(new C_UNIFORM_Z(ulazno_Polje.uniformno, pointer, ulazno_Polje.redak));
                        }
                        else //dodaj u tab ident, dodaj u TUZ, povezi
                        {
                            Adr_IDN++;
                            Lists.IDENT_List.Add(new C_IDENT(Adr_IDN, name, ""));
                            UNIFORM_Z_List.Add(new C_UNIFORM_Z(ulazno_Polje.uniformno, Adr_IDN, ulazno_Polje.redak));
                        }
	}


    public void Add_Unif_KROS(ULAZ ulazno_Polje, Liste Lists){
	
	int pointer = 0;
	string name = ulazno_Polje.izvorno;

	 pointer = Lists.Find_Indx(name, 1); // 1 je switch za KROS
                                
	if (pointer != 0)
                        {
                            UNIFORM_Z_List.Add(new C_UNIFORM_Z(ulazno_Polje.uniformno, pointer, ulazno_Polje.redak));
                        }else{
			//greska
		}
    }

           public void Ispis()
    {
        for (int i = 0; i < UNIFORM_Z_List.Count; i++)
        {
            UNIFORM_Z_List[i].PrintToConsole();
        }
       
    }
           private void Search_for_Details(int POK, Liste Lists, ref C_Details detalji)
           {
               int pokazivac = 0;
               if (UNIFORM_Z_List[POK].Give_Back_Klasa() == "KROS")
               {
                   pokazivac = Lists.Binary_Search_for_Index("KROS", UNIFORM_Z_List[POK].Give_Back_Pokazivac());
                   if (pokazivac >= 0)
                   {
                       detalji.naziv = Lists.KROS_List[pokazivac].Give_Back_naziv();
                       detalji.tip = "";
                       detalji.pokazivac = POK;
                       detalji.redak = UNIFORM_Z_List[POK].Give_Back_Redak();
                       detalji.klasa = "KROS";
                   }
                   else
                   {
                       //pogreska
                   }
               }
               if (UNIFORM_Z_List[POK].Give_Back_Klasa() == "KONST")
               {
                   pokazivac = Lists.Binary_Search_for_Index("KONST", UNIFORM_Z_List[POK].Give_Back_Pokazivac());
                   if (pokazivac >= 0)
                   {
                       detalji.naziv = Lists.KONST_List[pokazivac].Give_Back_vrijednost();
                       detalji.tip = Lists.KONST_List[pokazivac].Give_Back_tip();
                       detalji.pokazivac = POK;
                       detalji.redak = UNIFORM_Z_List[POK].Give_Back_Redak();
                       detalji.klasa = "KONST";
                   }
                   else
                   {
                       //pogreska
                   }
               }
               if (UNIFORM_Z_List[POK].Give_Back_Klasa() == "IDENT")//promijeniti u Identifikator
               {
                   pokazivac = Lists.Binary_Search_for_Index("IDENT", UNIFORM_Z_List[POK].Give_Back_Pokazivac());
                   if (pokazivac >= 0)
                   {
                       detalji.naziv = Lists.IDENT_List[pokazivac].Give_Back_naziv();
                       detalji.tip = Lists.IDENT_List[pokazivac].Give_Back_tip();
                       detalji.pokazivac = POK;
                       detalji.redak = UNIFORM_Z_List[POK].Give_Back_Redak();
                       detalji.klasa = "IDENT";
                   }
                   else
                   {
                       //pogreska
                   }
               }
           }
           public string naziv(int POK, Liste Lists)
           {
               C_Details pom_detalji = new C_Details(0, "", "", 0, "");
               this.Search_for_Details(POK, Lists, ref pom_detalji);
               return pom_detalji.naziv;
           }
           public string tip(int POK, Liste Lists)
           {
               if (UNIFORM_Z_List[POK].Give_Back_Klasa() == "IDENT" || UNIFORM_Z_List[POK].Give_Back_Klasa() == "KONST")
               {
                   C_Details pom_detalji = new C_Details(0, "", "", 0, "");
                   this.Search_for_Details(POK, Lists, ref pom_detalji);
                   return pom_detalji.tip;
               }
               else return "";
           }
           public string klasa(int POK, Liste Lists)
           {
               C_Details pom_detalji = new C_Details(0, "", "", 0, "");
               this.Search_for_Details(POK, Lists, ref pom_detalji);
               return pom_detalji.klasa;
           }
           public void postavi_tip(int POK, Liste Lists, string novi_tip)
           {
               int pokazivac = 0;
               if (UNIFORM_Z_List[POK].Give_Back_Klasa() == "KONST")
               {
                   pokazivac = Lists.Binary_Search_for_Index("KROS", UNIFORM_Z_List[POK].Give_Back_Pokazivac());
                   if (pokazivac != 0)
                   {
                       Lists.KONST_List[pokazivac].Set_tip(novi_tip);
                   }
                   else
                   {
                       //pogreska
                   }
               }
               if (UNIFORM_Z_List[POK].Give_Back_Klasa() == "Identifikator")
               {
                   pokazivac = Lists.Binary_Search_for_Index("Identifikator", UNIFORM_Z_List[POK].Give_Back_Pokazivac());
                   if (pokazivac != 0)
                   {
                       Lists.IDENT_List[pokazivac].Set_tip(novi_tip);
                   }
                   else
                   {
                       //pogreska
                   }
               }
               else
               {
                   //pogreska
               }

           } 
}

public class ULAZ
{
    public string izvorno;
    public string uniformno;
    public int redak;

	public ULAZ(){
	}
	public  void  Dodaj_izvorno(string izv){
	izvorno = izv;
	}

	public  void  Dodaj_uniformno(string unif){
	uniformno = unif;
	}
	public  void  Dodaj_redak(int red){
	redak = red;
	}

    // Constructor
    public ULAZ(string izvorno, string uniformno, int redak)
    {
        this.izvorno = izvorno;
        this.uniformno = uniformno;
        this.redak = redak;
    }
}
%}

slovo [a-zA-Z]
znamenka [0-9]
broj_decimalni {znamenka}+\.{znamenka}*
broj_cijeli {znamenka}+



%%
%{
    // local variables
%}

\n|\r\n?              {lineTot++;}
\(                    { ulazno_Polje.Dodaj_izvorno(yytext); ulazno_Polje.Dodaj_uniformno("KROS");  ulazno_Polje.Dodaj_redak(lineTot); Tabl_unif_znak.Add_Unif_KROS(ulazno_Polje, Lists);}
\)                    { ulazno_Polje.Dodaj_izvorno(yytext); ulazno_Polje.Dodaj_uniformno("KROS");  ulazno_Polje.Dodaj_redak(lineTot); Tabl_unif_znak.Add_Unif_KROS(ulazno_Polje, Lists);}
\{                    { ulazno_Polje.Dodaj_izvorno(yytext); ulazno_Polje.Dodaj_uniformno("KROS");  ulazno_Polje.Dodaj_redak(lineTot); Tabl_unif_znak.Add_Unif_KROS(ulazno_Polje, Lists);}
\}                    { ulazno_Polje.Dodaj_izvorno(yytext); ulazno_Polje.Dodaj_uniformno("KROS");  ulazno_Polje.Dodaj_redak(lineTot); Tabl_unif_znak.Add_Unif_KROS(ulazno_Polje, Lists);}
\[                    { ulazno_Polje.Dodaj_izvorno(yytext); ulazno_Polje.Dodaj_uniformno("KROS");  ulazno_Polje.Dodaj_redak(lineTot); Tabl_unif_znak.Add_Unif_KROS(ulazno_Polje, Lists);}
\]                    { ulazno_Polje.Dodaj_izvorno(yytext); ulazno_Polje.Dodaj_uniformno("KROS");  ulazno_Polje.Dodaj_redak(lineTot); Tabl_unif_znak.Add_Unif_KROS(ulazno_Polje, Lists);}
;                     {ulazno_Polje.Dodaj_izvorno(yytext); ulazno_Polje.Dodaj_uniformno("KROS");  ulazno_Polje.Dodaj_redak(lineTot); Tabl_unif_znak.Add_Unif_KROS(ulazno_Polje, Lists);}
,                     {ulazno_Polje.Dodaj_izvorno(yytext); ulazno_Polje.Dodaj_uniformno("KROS");  ulazno_Polje.Dodaj_redak(lineTot); Tabl_unif_znak.Add_Unif_KROS(ulazno_Polje, Lists);}
:                     {ulazno_Polje.Dodaj_izvorno(yytext); ulazno_Polje.Dodaj_uniformno("KROS");  ulazno_Polje.Dodaj_redak(lineTot); Tabl_unif_znak.Add_Unif_KROS(ulazno_Polje, Lists);}
\.                     {ulazno_Polje.Dodaj_izvorno(yytext); ulazno_Polje.Dodaj_uniformno("KROS");  ulazno_Polje.Dodaj_redak(lineTot); Tabl_unif_znak.Add_Unif_KROS(ulazno_Polje, Lists);}
if                    {ulazno_Polje.Dodaj_izvorno("IF"); ulazno_Polje.Dodaj_uniformno("KROS");  ulazno_Polje.Dodaj_redak(lineTot); Tabl_unif_znak.Add_Unif_KROS(ulazno_Polje, Lists);}
else                  {ulazno_Polje.Dodaj_izvorno("ELSE"); ulazno_Polje.Dodaj_uniformno("KROS");  ulazno_Polje.Dodaj_redak(lineTot); Tabl_unif_znak.Add_Unif_KROS(ulazno_Polje, Lists);}
while                 {ulazno_Polje.Dodaj_izvorno("WHILE"); ulazno_Polje.Dodaj_uniformno("KROS");  ulazno_Polje.Dodaj_redak(lineTot); Tabl_unif_znak.Add_Unif_KROS(ulazno_Polje, Lists);}
return                {ulazno_Polje.Dodaj_izvorno("RETURN"); ulazno_Polje.Dodaj_uniformno("KROS");  ulazno_Polje.Dodaj_redak(lineTot); Tabl_unif_znak.Add_Unif_KROS(ulazno_Polje, Lists);}
do                {ulazno_Polje.Dodaj_izvorno("DO"); ulazno_Polje.Dodaj_uniformno("KROS");  ulazno_Polje.Dodaj_redak(lineTot); Tabl_unif_znak.Add_Unif_KROS(ulazno_Polje, Lists);}
for                {ulazno_Polje.Dodaj_izvorno("FOR"); ulazno_Polje.Dodaj_uniformno("KROS");  ulazno_Polje.Dodaj_redak(lineTot); Tabl_unif_znak.Add_Unif_KROS(ulazno_Polje, Lists);}
continue               {ulazno_Polje.Dodaj_izvorno("CONTINUE"); ulazno_Polje.Dodaj_uniformno("KROS");  ulazno_Polje.Dodaj_redak(lineTot); Tabl_unif_znak.Add_Unif_KROS(ulazno_Polje, Lists);}
break              {ulazno_Polje.Dodaj_izvorno("BREAK"); ulazno_Polje.Dodaj_uniformno("KROS");  ulazno_Polje.Dodaj_redak(lineTot); Tabl_unif_znak.Add_Unif_KROS(ulazno_Polje, Lists);}
default                {ulazno_Polje.Dodaj_izvorno("DEFAULT"); ulazno_Polje.Dodaj_uniformno("KROS");  ulazno_Polje.Dodaj_redak(lineTot); Tabl_unif_znak.Add_Unif_KROS(ulazno_Polje, Lists);}
switch                {ulazno_Polje.Dodaj_izvorno("SWITCH"); ulazno_Polje.Dodaj_uniformno("KROS");  ulazno_Polje.Dodaj_redak(lineTot); Tabl_unif_znak.Add_Unif_KROS(ulazno_Polje, Lists);}
case                {ulazno_Polje.Dodaj_izvorno("CASE"); ulazno_Polje.Dodaj_uniformno("KROS");  ulazno_Polje.Dodaj_redak(lineTot); Tabl_unif_znak.Add_Unif_KROS(ulazno_Polje, Lists);}
var                {ulazno_Polje.Dodaj_izvorno("VAR"); ulazno_Polje.Dodaj_uniformno("KROS");  ulazno_Polje.Dodaj_redak(lineTot); Tabl_unif_znak.Add_Unif_KROS(ulazno_Polje, Lists);}
new                {ulazno_Polje.Dodaj_izvorno("NEW"); ulazno_Polje.Dodaj_uniformno("KROS");  ulazno_Polje.Dodaj_redak(lineTot); Tabl_unif_znak.Add_Unif_KROS(ulazno_Polje, Lists);}
this                {ulazno_Polje.Dodaj_izvorno("THIS"); ulazno_Polje.Dodaj_uniformno("KROS");  ulazno_Polje.Dodaj_redak(lineTot); Tabl_unif_znak.Add_Unif_KROS(ulazno_Polje, Lists);}
function                {ulazno_Polje.Dodaj_izvorno("FUNCTION"); ulazno_Polje.Dodaj_uniformno("KROS");  ulazno_Polje.Dodaj_redak(lineTot); Tabl_unif_znak.Add_Unif_KROS(ulazno_Polje, Lists);}


\'{slovo}({slovo}|{znamenka})*\'     {ulazno_Polje.Dodaj_izvorno(yytext); ulazno_Polje.Dodaj_uniformno("KONST");  ulazno_Polje.Dodaj_redak(lineTot); Tabl_unif_znak.Add_Unif_Konst(ulazno_Polje, Lists, "string");}

+                     {ulazno_Polje.Dodaj_izvorno(yytext); ulazno_Polje.Dodaj_uniformno("KROS");  ulazno_Polje.Dodaj_redak(lineTot); Tabl_unif_znak.Add_Unif_KROS(ulazno_Polje, Lists);}
-                     {ulazno_Polje.Dodaj_izvorno(yytext); ulazno_Polje.Dodaj_uniformno("KROS");  ulazno_Polje.Dodaj_redak(lineTot); Tabl_unif_znak.Add_Unif_KROS(ulazno_Polje, Lists);}
/                     {ulazno_Polje.Dodaj_izvorno(yytext); ulazno_Polje.Dodaj_uniformno("KROS");  ulazno_Polje.Dodaj_redak(lineTot); Tabl_unif_znak.Add_Unif_KROS(ulazno_Polje, Lists);}
*                     {ulazno_Polje.Dodaj_izvorno(yytext); ulazno_Polje.Dodaj_uniformno("KROS");  ulazno_Polje.Dodaj_redak(lineTot); Tabl_unif_znak.Add_Unif_KROS(ulazno_Polje, Lists);}
=                     {ulazno_Polje.Dodaj_izvorno(yytext); ulazno_Polje.Dodaj_uniformno("KROS");  ulazno_Polje.Dodaj_redak(lineTot); Tabl_unif_znak.Add_Unif_KROS(ulazno_Polje, Lists);}

&&					{ulazno_Polje.Dodaj_izvorno("AND"); ulazno_Polje.Dodaj_uniformno("KROS");  ulazno_Polje.Dodaj_redak(lineTot); Tabl_unif_znak.Add_Unif_KROS(ulazno_Polje, Lists);}
||					{ulazno_Polje.Dodaj_izvorno("OR"); ulazno_Polje.Dodaj_uniformno("KROS");  ulazno_Polje.Dodaj_redak(lineTot); Tabl_unif_znak.Add_Unif_KROS(ulazno_Polje, Lists);}
==                    {ulazno_Polje.Dodaj_izvorno("EQ"); ulazno_Polje.Dodaj_uniformno("KROS");  ulazno_Polje.Dodaj_redak(lineTot); Tabl_unif_znak.Add_Unif_KROS(ulazno_Polje, Lists);}
!=                    {ulazno_Polje.Dodaj_izvorno("NEQ"); ulazno_Polje.Dodaj_uniformno("KROS");  ulazno_Polje.Dodaj_redak(lineTot); Tabl_unif_znak.Add_Unif_KROS(ulazno_Polje, Lists);}
!				 	{ulazno_Polje.Dodaj_izvorno(yytext); ulazno_Polje.Dodaj_uniformno("KROS");  ulazno_Polje.Dodaj_redak(lineTot); Tabl_unif_znak.Add_Unif_KROS(ulazno_Polje, Lists);}
>                     {ulazno_Polje.Dodaj_izvorno(yytext); ulazno_Polje.Dodaj_uniformno("KROS");  ulazno_Polje.Dodaj_redak(lineTot); Tabl_unif_znak.Add_Unif_KROS(ulazno_Polje, Lists);}
\<                     {ulazno_Polje.Dodaj_izvorno(yytext); ulazno_Polje.Dodaj_uniformno("KROS");  ulazno_Polje.Dodaj_redak(lineTot); Tabl_unif_znak.Add_Unif_KROS(ulazno_Polje, Lists);}
>=					{ulazno_Polje.Dodaj_izvorno("GE"); ulazno_Polje.Dodaj_uniformno("KROS");  ulazno_Polje.Dodaj_redak(lineTot); Tabl_unif_znak.Add_Unif_KROS(ulazno_Polje, Lists);}
/<=					{ulazno_Polje.Dodaj_izvorno("LE"); ulazno_Polje.Dodaj_uniformno("KROS");  ulazno_Polje.Dodaj_redak(lineTot); Tabl_unif_znak.Add_Unif_KROS(ulazno_Polje, Lists);}

{slovo}({slovo}|{znamenka})*   {ulazno_Polje.Dodaj_izvorno(yytext); ulazno_Polje.Dodaj_uniformno("IDENT");  ulazno_Polje.Dodaj_redak(lineTot); Tabl_unif_znak.Add_Unif_Ident(ulazno_Polje, Lists);}
\'{slovo}({slovo}|{znamenka})*\'     {ulazno_Polje.Dodaj_izvorno(yytext); ulazno_Polje.Dodaj_uniformno("KONST");  ulazno_Polje.Dodaj_redak(lineTot); Tabl_unif_znak.Add_Unif_Konst(ulazno_Polje, Lists, "string");}
{broj_decimalni}    {ulazno_Polje.Dodaj_izvorno(yytext); ulazno_Polje.Dodaj_uniformno("KONST");  ulazno_Polje.Dodaj_redak(lineTot); Tabl_unif_znak.Add_Unif_Konst(ulazno_Polje, Lists, "decimalni");}
{broj_cijeli}   {ulazno_Polje.Dodaj_izvorno(yytext); ulazno_Polje.Dodaj_uniformno("KONST");  ulazno_Polje.Dodaj_redak(lineTot); Tabl_unif_znak.Add_Unif_Konst(ulazno_Polje, Lists, "cijeli");}
[" "\t,]         {}
.               {Glavni.Ispisi("Greska: nepoznata leksicka jedinka u retku "+lineTot);}

%%


public void Analiziraj()
        {
            lineTot = 1;
            Adr_IDN = 0;
            Adr_KONS = 0;
            pointer = 0;
            ulazno_Polje.Dodaj_izvorno("");
            ulazno_Polje.Dodaj_redak(0);
            ulazno_Polje.Dodaj_uniformno("");
            Lists.IDENT_List.Clear();
            Lists.KONST_List.Clear();
            Lists.KROS_List.Clear();
            Tabl_unif_znak = new TUZ();
            Tabl_unif_znak.UNIFORM_Z_List.Clear();
            
            Lists.AddKrosList();

            int tok;
            this.SetSource(Glavni.mojaForma.editbox.Text, 0);
            do
                {
                    tok = this.yylex();
                } while (tok > (int)Tokens.EOF);
            Lists.Ispsi_KROS();
            Lists.Ispsi_IDEN();
            Lists.Ispsi_KONS();
            Tabl_unif_znak.Ispis();
            Parser mojParser = new Parser();
            mojParser.Parsiraj(); 
        }
