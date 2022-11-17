using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;

namespace UI2
{
    public partial class Form1 : Form
    {
        public static string output = "";

        public class tree
        {
            public int tip;
            public char oznaka;
            public tree lijevo;
            public tree desno;
            public tree sredina;

            public tree()
            {
                this.tip = 0;
                this.oznaka = '\0';
                this.lijevo = null;
                this.desno = null;
                this.sredina = null;
            }

            public tree(char c)
            {
                if (c >= 'a' && c <= 'm') //konstante
                    this.tip = 1;
                else if (c >= 'n' && c <= 'z') // varijable
                    this.tip = 2;
                else if (c >= 'A' && c <= 'M') //funkcije
                    this.tip = 3;
                else if (c >= 'N' && c <= 'Z') //predikat
                    this.tip = 4;
                else if (c == '#' || c == '$') //kvantifikator
                    this.tip = 5;
                else if (c == '*' || c == '+' || c == '>' || c == '=') //operatori
                    this.tip = 6;
                else if (c == '(') //zagrada
                    this.tip = 7;
                else if (c == '-') //negacija
                    this.tip = 8;

                this.oznaka = c;
                this.lijevo = null;
                this.desno = null;
                this.sredina = null;
            }

            public void dodaj_u_granu(char c, int grana)
            {
                tree t = new tree(c);
                switch (grana)
                {
                    case 1:
                        this.lijevo = t;
                        break;
                    case 2:
                        this.sredina = t;
                        break;
                    case 3:
                        this.desno = t;
                        break;
                };
            }

            public int init_tree(string input)
            {
                int x = 1;
                if (input.Length > 0)
                {
                    int prethodni_znak = this.tip;
                    tree t = new tree(input[0]);
                    this.kopiraj_cvor(t);
                    switch (t.tip)
                    {
                        case 1:
                        case 6:
                            break;
                        case 2:
                            if (prethodni_znak == 5)
                            {
                                x += t.init_tree(input.Substring(x, input.Length - x));
                                this.sredina = t;
                            }
                            break;
                        case 3:
                        case 4:
                        case 5:
                        case 8:
                            x += t.init_tree(input.Substring(x, input.Length - x));
                            this.sredina = t;
                            break;
                        case 7:
                            x += t.init_tree(input.Substring(x, input.Length - x));
                            this.lijevo = t;
                            if (input[x] == ')')
                            {
                                x++;
                                if (prethodni_znak == 3 || prethodni_znak == 4)
                                    break;
                            }
                            tree t1 = new tree(input[x - 1]);
                            x += t1.init_tree(input.Substring(x, input.Length - x));
                            this.sredina = t1;
                            if (input[x] == ')')
                            {
                                x++;
                                if (prethodni_znak == 3 || prethodni_znak == 4)
                                    break;
                            }
                            tree t2 = new tree(input[x - 1]);
                            x += t2.init_tree(input.Substring(x, input.Length - x));
                            this.desno = t2;
                            break;
                    }
                }
                return x;
            }

            public void kopiraj_cvor(tree t)
            {
                this.oznaka = t.oznaka;
                this.tip = t.tip;
                this.lijevo = t.lijevo;
                this.sredina = t.sredina;
                this.desno = t.desno;
            }

            public bool nadi_clan(char c)
            {
                bool znak = false;
                if (this.lijevo != null) znak = this.lijevo.nadi_clan(c);
                if (znak) return znak;
                if (this.sredina != null) znak = this.sredina.nadi_clan(c);
                if (znak) return znak;
                if (this.desno != null) znak = this.desno.nadi_clan(c);
                if (znak) return znak;

                if (this.oznaka == c)
                    znak = true;
                return znak;
            }

            public string rezultat()
            {
                string text = this.oznaka.ToString();
                if (this.lijevo != null) text += this.lijevo.rezultat();
                if (this.sredina != null) text += this.sredina.rezultat();
                if (this.desno != null) text += this.desno.rezultat();
                if (this.oznaka == '(') text += ')';
                return text;
            }

            public void uklanjanje_ekvivalencije()
            {
                if (this.lijevo != null) this.lijevo.uklanjanje_ekvivalencije();
                if (this.sredina != null) this.sredina.uklanjanje_ekvivalencije();
                if (this.desno != null) this.desno.uklanjanje_ekvivalencije();

                if (this.sredina != null)
                {
                    if (this.sredina.oznaka == '=')
                    {
                        tree t1 = new tree();
                        tree t2 = new tree();
                        t1 = this.lijevo;
                        t2 = this.desno;
                        this.dodaj_u_granu('(', 1);
                        this.sredina.oznaka = '*';
                        this.dodaj_u_granu('(', 3);
                        this.lijevo.dodaj_u_granu('-', 1);
                        this.lijevo.lijevo.sredina = t1;
                        this.lijevo.dodaj_u_granu('+', 2);
                        this.lijevo.desno = t2;
                        this.desno.dodaj_u_granu('-', 1);
                        this.desno.lijevo.sredina = t2;
                        this.desno.dodaj_u_granu('+', 2);
                        this.desno.desno = t1;
                    }
                }
            }

            public void uklanjanje_implikacije()
            {
                if (this.lijevo != null) this.lijevo.uklanjanje_implikacije();
                if (this.sredina != null) this.sredina.uklanjanje_implikacije();
                if (this.desno != null) this.desno.uklanjanje_implikacije();

                if (this.sredina != null)
                {
                    if (this.sredina.oznaka == '>')
                    {
                        tree t = new tree('-');
                        t.sredina = this.lijevo;
                        this.lijevo = t;
                        this.sredina.oznaka = '+';
                    }
                }
            }

            public void smanjenje_dosega_operatora()
            {
                if (this.lijevo != null) this.lijevo.smanjenje_dosega_operatora();
                if (this.sredina != null) this.sredina.smanjenje_dosega_operatora();
                if (this.desno != null) this.desno.smanjenje_dosega_operatora();

                if (this.oznaka == '-')
                {
                    tree t = new tree();
                    switch (this.sredina.oznaka)
                    {
                        case ('('):
                            if (this.sredina.sredina.oznaka == '-')
                            {
                                t = this.sredina.sredina.sredina;
                                this.kopiraj_cvor(t);
                                break;
                            }
                            t = this.sredina.lijevo;
                            this.sredina.dodaj_u_granu('-', 1);
                            this.sredina.lijevo.sredina = t;
                            t = this.sredina.desno;
                            this.sredina.dodaj_u_granu('-', 3);
                            this.sredina.desno.sredina = t;
                            t = this.sredina;
                            this.kopiraj_cvor(t);
                            if (this.sredina.oznaka == '+')
                                this.sredina.oznaka = '*';
                            else
                                this.sredina.oznaka = '+';
                            break;
                        case ('-'):
                            t = this.sredina.sredina;
                            this.kopiraj_cvor(t);
                            break;
                        case ('#'):
                        case ('$'):
                            t = this.sredina.sredina.sredina;
                            char c = this.sredina.sredina.oznaka;
                            if (this.sredina.oznaka == '#')
                                this.oznaka = '$';
                            else
                                this.oznaka = '#';
                            this.tip = 5;
                            this.dodaj_u_granu(c, 2);
                            this.sredina.dodaj_u_granu('(', 2);
                            this.sredina.sredina.dodaj_u_granu('-', 2);
                            this.sredina.sredina.sredina.sredina = t;
                            break;
                        default:
                            break;
                    }
                }
            }

            public void preimenuj_varijablu(char[] varijable)
            {
                int i;
                char c;
                if (this.tip == 5)
                {
                    c = this.sredina.oznaka;
                    if (varijable[c - 'n'] == '\0')
                        varijable[c - 'n'] = c;
                    else
                    {
                        for (i = 12; i >= 0; i--)
                            if (varijable[i] == '\0')
                                break;
                        varijable[c - 'n'] = (char)((int)'n' + i);
                        varijable[i] = (char)((int)'n' + i);
                    }
                }

                if (this.lijevo != null) this.lijevo.preimenuj_varijablu(varijable);
                if (this.sredina != null) this.sredina.preimenuj_varijablu(varijable);
                if (this.desno != null) this.desno.preimenuj_varijablu(varijable);

                if (this.tip == 2)
                    this.oznaka = varijable[this.oznaka - 'n'];
            }

            public void skolemizacija(char[] varijable, tree root)
            {
                char c;
                if (this.oznaka == '#')
                {
                    varijable[this.sredina.oznaka - 'n'] = this.sredina.oznaka;
                    tree t = new tree();
                    t = this.sredina.sredina;
                    this.kopiraj_cvor(t);
                }

                if (this.lijevo != null) this.lijevo.skolemizacija(varijable, root);
                if (this.sredina != null) this.sredina.skolemizacija(varijable, root);
                if (this.desno != null) this.desno.skolemizacija(varijable, root);

                if (this.lijevo != null)
                {
                    c = this.lijevo.oznaka;
                    if (c >= 'n' && c <= 'z' && varijable[c - 'n'] == c)
                    {
                        for (c = 'a'; c <= 'm'; c++)
                            if (!root.nadi_clan(c)) break;
                        tree l = new tree(c);
                        this.lijevo = l;
                    }
                }

                if (this.sredina != null)
                {
                    c = this.sredina.oznaka;
                    if (c >= 'n' && c <= 'z' && varijable[c - 'n'] == c)
                    {
                        if (this.lijevo.tip == 2)
                        {
                            for (c = 'A'; c <= 'M'; c++)
                                if (!root.nadi_clan(c)) break;
                            tree s1 = new tree(c);
                            this.sredina = s1;
                            tree s2 = new tree('(');
                            this.sredina.sredina = s2;
                            this.sredina.sredina.lijevo = this.lijevo;
                        }
                        else
                        {
                            for (c = 'a'; c <= 'm'; c++)
                                if (!root.nadi_clan(c)) break;
                            tree s = new tree(c);
                            this.sredina = s;
                        }
                    }
                }

                if (this.desno != null)
                {

                    c = this.desno.oznaka;
                    if (c >= 'n' && c <= 'z' && varijable[c - 'n'] == c)
                    {
                        if (this.lijevo.tip == 2 || this.sredina.tip == 2)
                        {
                            for (c = 'A'; c <= 'M'; c++)
                                if (!root.nadi_clan(c)) break;
                            tree d1 = new tree(c);
                            this.desno = d1;
                            tree d2 = new tree('(');
                            this.sredina.sredina = d2;
                            if (this.lijevo.tip == 2)
                                this.sredina.sredina.lijevo = this.lijevo;
                            if (this.sredina.tip == 2)
                                this.sredina.sredina.sredina = this.sredina;
                        }
                        else
                        {
                            for (c = 'a'; c <= 'm'; c++)
                                if (!root.nadi_clan(c)) break;
                            tree d = new tree(c);
                            this.desno = d;
                        }

                    }
                }
            }

            public void eliminacija_prefiksa()
            {
                if (this.lijevo != null) this.lijevo.eliminacija_prefiksa();
                if (this.sredina != null) this.sredina.eliminacija_prefiksa();
                if (this.desno != null) this.desno.eliminacija_prefiksa();

                if (this.oznaka == '$')
                {
                    tree t = new tree();
                    t = this.sredina.sredina;
                    this.kopiraj_cvor(t);
                    if (this.oznaka == '(')
                    {
                        t = this.sredina;
                        this.kopiraj_cvor(t);
                    }
                }
            }

            public void konjunkcija_disjunkcija()
            {
                if (this.lijevo != null) this.lijevo.konjunkcija_disjunkcija();
                if (this.sredina != null) this.sredina.konjunkcija_disjunkcija();
                if (this.desno != null) this.desno.konjunkcija_disjunkcija();

                tree lijeva_zagrada = new tree('(');
                tree desna_zagrada = new tree('(');
                tree unija = new tree('+');
                tree t1 = new tree();
                tree t2 = new tree();
                tree t3 = new tree();

                if (this.oznaka == '(')
                    if (this.sredina.oznaka == '+')
                    {
                        if (this.lijevo.oznaka == '(')
                        {
                            if (this.lijevo.sredina.oznaka == '*')
                            {
                                t1 = this.desno;
                                t2 = this.lijevo.lijevo;
                                t3 = this.lijevo.desno;
                                this.lijevo = lijeva_zagrada;
                                this.desno = desna_zagrada;
                                this.sredina.oznaka = '*';
                                this.lijevo.lijevo = t1;
                                this.lijevo.sredina = unija;
                                this.lijevo.desno = t2;
                                this.desno.lijevo = t1;
                                this.desno.sredina = unija;
                                this.desno.desno = t3;
                            }
                        }
                        else if (this.desno.oznaka == '(')
                        {
                            if (this.desno.sredina.oznaka == '*')
                            {
                                t1 = this.lijevo;
                                t2 = this.desno.lijevo;
                                t3 = this.desno.desno;
                                this.lijevo = lijeva_zagrada;
                                this.desno = desna_zagrada;
                                this.sredina.oznaka = '*';
                                this.lijevo.lijevo = t1;
                                this.lijevo.sredina = unija;
                                this.lijevo.desno = t2;
                                this.desno.lijevo = t1;
                                this.desno.sredina = unija;
                                this.desno.desno = t3;
                            }
                        }
                    }
            }

            public string skup_klauzula()
            {
                string output_ = "", temp = "";
                if (this.lijevo != null)
                {
                    temp = this.lijevo.skup_klauzula();
                    output_ += temp;
                    if (temp == "")
                        if (this.sredina != null)
                            if (this.sredina.oznaka == '*')
                                output_ += lijevo.rezultat() + '\n';
                    temp = "";

                }
                if (this.sredina != null) output_ += this.sredina.skup_klauzula();
                if (this.desno != null)
                {
                    temp = this.desno.skup_klauzula();
                    output_ += temp;
                    if (temp == "")
                        if (this.sredina != null)
                            if (this.sredina.oznaka == '*')
                                output_ += desno.rezultat() + '\n';
                }
                return output_;
            }
        }

        public string standardizacija(string input, char[] varijable)
        {
            string output_ = "";
            bool u_polju;
            int i, j;
            for (i = 0; i < input.Length; i++)
            {
                if (input[i] >= 'n' && input[i] <= 'z')
                {
                    u_polju = false;
                    for (j = 0; j < 13; j++)
                    {
                        if (varijable[j] == input[i])
                        {
                            u_polju = true;
                            break;
                        }
                    }
                    if (!u_polju)
                    {
                        varijable[input[i] - 'n'] = (char)((int)input[i] - 32);
                        output_ += input[i];
                    }
                    else
                    {
                        u_polju = false;
                        for (j = 0; j < 13; j++)
                        {
                            if (varijable[j] == (char)((int)input[i] - 32))
                            {
                                u_polju = true;
                                break;
                            }
                        }

                        if (!u_polju)
                        {
                            int k;
                            for (k = 12; k >= 0; k--)
                                if (varijable[k] == '\0')
                                {
                                    varijable[k] = (char)((int)input[i] - 32);
                                    break;
                                }
                            output_ += (char)((int)'n' + k);
                        }
                        else
                        {
                            output_ += (char)((int)'n' + j);
                        }
                    }
                }
                else
                    output_ += input[i];

                if (input[i] == '\n')
                {
                    for (j = 0; j < 13; j++)
                        if (varijable[j] != '\0')
                            varijable[j] = (char)((int)varijable[j] + 32);
                }
            }
            return output_;
        }

        /*public Form1()
        {
            InitializeComponent();
        }*/

        public void button1_Click(object sender, EventArgs e)
        {
            char[] polje = new char[13] { '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0' };
            tree t = new tree();
            t.init_tree(textBox1.Text);

            switch (comboBox1.Text)
            {
                case "Cijela pretvorba":
                    label2.Text = "Izlazne klauzule";
                    string s;
                    t.uklanjanje_ekvivalencije();
                    t.uklanjanje_implikacije();
                    t.smanjenje_dosega_operatora();
                    t.preimenuj_varijablu(polje);
                    t.skolemizacija(polje, t);
                    t.eliminacija_prefiksa();
                    t.konjunkcija_disjunkcija();
                    s = t.skup_klauzula();
                    richTextBox1.Text = standardizacija(s, polje);
                    break;

                case "Uklanjanje ekvivalencije":
                    label2.Text = "Izlazna formula";
                    t.uklanjanje_ekvivalencije();
                    richTextBox1.Text = t.rezultat();
                    break;

                case "Uklanjanje implikacije":
                    label2.Text = "Izlazna formula";
                    t.uklanjanje_implikacije();
                    richTextBox1.Text = t.rezultat();
                    break;

                case "Smanjivanje dosega operatora":
                    label2.Text = "Izlazna formula";
                    t.smanjenje_dosega_operatora();
                    richTextBox1.Text = t.rezultat();
                    break;

                case "Preimenovanje varijable":
                    label2.Text = "Izlazna formula";
                    t.preimenuj_varijablu(polje);
                    richTextBox1.Text = t.rezultat();
                    break;

                case "Skolemizacija":
                    label2.Text = "Izlazna formula";
                    t.skolemizacija(polje, t);
                    richTextBox1.Text = t.rezultat();
                    break;

                case "Eliminiranje prefiksa":
                    label2.Text = "Izlazna formula";
                    t.eliminacija_prefiksa();
                    richTextBox1.Text = t.rezultat();
                    break;

                case "Konjunkcija disjunkcija":
                    label2.Text = "Izlazna formula";
                    t.konjunkcija_disjunkcija();
                    richTextBox1.Text = t.rezultat();
                    break;

                case "Skup klauzula":
                    label2.Text = "Izlazne klauzule";
                    richTextBox1.Text = t.skup_klauzula();
                    break;

                case "Standardizacija":
                    label2.Text = "Izlazne klauzule";
                    richTextBox1.Text = standardizacija(richTextBox1.Text, polje);
                    break;

                default:
                    break;
            }
        }
    }
}












