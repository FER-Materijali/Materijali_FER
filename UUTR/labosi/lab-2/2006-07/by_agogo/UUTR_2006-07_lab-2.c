#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

void funkcija_prijelaza(class Potisni_automat, char &, int);

char f(char);

class Potisni_automat{
private:
	int tren_stanje;
public:
	stack<char> stog; // kreiranje stoga, <char> je tip podatak koji je na stogu
	stack<char> stog_temp; // sluzi za kasnije ispisivanje stoga
	Potisni_automat(); //konstruktor
	void ispis_stanja()
	{
		cout << tren_stanje;
	}
	int stanje()
	{
		return tren_stanje;
	}
	void prom_stanje(int novo_stanje)
	{
		tren_stanje=novo_stanje;
	}
	//f-ja ispisuje tako da prebaci s jednog stoga na drugi i pritom ispisuje te onda
	//vraca sa drugog na prvi (sjecate se toga sa asp-a...?)
	void ispisi_stog()
	{
		while( !stog.empty() )
		{
			if(stog.top()!=\\'e\\')
				cout << stog.top();
			stog_temp.push(stog.top());
			stog.pop();
		}
		while( !stog_temp.empty())
		{
			stog.push(stog_temp.top());
			stog_temp.pop();
		}
	}
};
//konstruktor, pocinjemo u q0 i na stogu je K
Potisni_automat::Potisni_automat(){
	tren_stanje=0;
	stog.push(\\'K\\');
};

int main()
{
	FILE *f;
	f=fopen("ulaz.txt","r");

	Potisni_automat pot;

	char *s = new char [100];
	
	//cita iz datoteke niz po niz
	while(fscanf(f,"%s",s)==1)
	{
		cout << endl << endl << "---Ulazni niz: " << s << endl << endl;
		funkcija_prijelaza(pot, *s, 0);
	}

	delete [] s;

	return 0;
}

void funkcija_prijelaza(class Potisni_automat pot, char &s, int a)
{
	class Potisni_automat temp;

	//ovaj uvijet je svojevrsan izlaz iz rekurzije. odn., kad dode do kraja jedne grane
	//(nedeterministicki je i moramo sve moguce grane proci!) opet ce se rekurzivno pozvati
	//funkcija no na ovim uvijtima ce pasti te ce skociti do kraja nase funkcije, sto u
	//prijevodu znaci, nece nista ispisati niti rekurzivno pozvati samu sebe.
	if( ((unsigned int)a <= strlen(&s)) && (pot.stog.size()>0) )
	{
		//prva funkcija prijelaza, nedeterministicka je, zato je u posebnom if-u
		//jer se moze i nemora odigrati a ako se izvrsi i ode u tu granu, nakon sto ju zavrsi
		//otici ce u drugu granu. slican primjer je i nesto nize.
		if( pot.stog.top() == \\'K\\' )
		{
			cout << endl << endl << "NEDETERMINIZAM 1) - e prijelaz za K" << endl;

			cout << endl << endl;
			cout << "Trenutno ucitavam: " << (&s)[a] << endl;
			cout << "Nalazim se u stanju: q" << pot.stanje() << endl;
			cout << "Stanje stoga: ";
			pot.ispisi_stog();
			cout << endl << "d(q" << pot.stanje() << ",e,K)";
			cout << " = {(q1,e)}" << endl;

			//mijenjanje stanja, temp se koristi da mi u pot ostano sacuvana prijasnja
			//stanja kako bi kasnije mogao otici u drugu granu
			temp = pot;
			temp.prom_stanje(1);
			temp.stog.pop();

			cout << "Novo stanje: q" << temp.stanje() << endl;
			cout << "Novi stog: ";
			temp.ispisi_stog();

			if( (temp.stog.empty()) && (a == strlen(&s)) ) 
				cout << "\nDosadasnji niz je PRIHVATLJIV";
			else
				cout << "\nDosadasnji niz je NEPRIHVATLJIV";

			funkcija_prijelaza(temp, s, a); //rekurzivni poziv

			cout << endl << endl << "KRAJ GRANE 1)" << endl;
		}

		//drugi f-ja prijelaza
		if(pot.stanje() == 0)
		{
			if( f((&s)[a]) != pot.stog.top() )
			{
				cout << endl << endl;
				cout << "Trenutno ucitavam: " << (&s)[a] << endl;
				cout << "Nalazim se u stanju: q" << pot.stanje() << endl;
				cout << "Stanje stoga: ";
				pot.ispisi_stog();
				cout << endl << "d(q0," << (&s)[a] << ",";
				if( pot.stog.size()!=0)
					cout  << pot.stog.top();
				else
					cout << \\'e\\';
				cout << ") = {(q0," << f((&s)[a]);
				if( pot.stog.size()!=0)
					cout  << pot.stog.top();
				else
					cout << \\'e\\';
				cout << ")}" << endl;

				pot.prom_stanje(0);
				pot.stog.push(f((&s)[a]));

				cout << "Novo stanje: q" << pot.stanje() << endl;
				cout << "Novi stog: ";
				pot.ispisi_stog();

				if( (pot.stog.empty()) && (a == strlen(&s)) ) 
					cout << "\nDosadasnji niz je PRIHVATLJIV";
				else
					cout << "\nDosadasnji niz je NEPRIHVATLJIV";

				funkcija_prijelaza(pot, s, a+1);
			}
			//treca f-ja prijelaza, ponovno nedeterministicka
			else if( f((&s)[a]) == pot.stog.top())
			{
				//prvi slucaj

				cout << endl << endl << "NEDETERMINIZAM 2a) - pocinjem skidati sa stoga" << endl;

				cout << endl << endl;
				cout << "Trenutno ucitavam: " << (&s)[a] << endl;
				cout << "Nalazim se u stanju: q" << pot.stanje() << endl;
				cout << "Stanje stoga: ";
				pot.ispisi_stog();
				cout << endl << "d(q0," << (&s)[a] << "," << f((&s)[a]);
				cout << ") = {(q1,e)" << endl;

				temp=pot;
				temp.prom_stanje(1);
				temp.stog.pop();

				cout << "Novo stanje: q" << temp.stanje() << endl;
				cout << "Novi stog: ";
				temp.ispisi_stog();

				if( (temp.stog.empty()) && (a == strlen(&s)) ) 
					cout << "\nDosadasnji niz je PRIHVATLJIV";
				else
					cout << "\nDosadasnji niz je NEPRIHVATLJIV";

				funkcija_prijelaza(temp, s, a+1);

				//nakon sto prvu granu zavrsi krece u drugu

				cout << endl << endl << "KRAJ GRANE 2a)" << endl;

				cout << endl << endl << "NEDETERMINIZAM 2b) - dalje stavljam" << endl;

				cout << endl << endl;
				cout << "Trenutno ucitavam: " << (&s)[a] << endl;
				cout << "Nalazim se u stanju: q" << pot.stanje() << endl;
				cout << "Stanje stoga: ";
				pot.ispisi_stog();
				cout << endl << "d(q0," << (&s)[a] << "," << f((&s)[a]) << endl;
				cout << ") = {(q0," << f((&s)[a]) << f((&s)[a]) << ")}" << endl;

				temp=pot;
				temp.prom_stanje(0);
				temp.stog.push(f((&s)[a]));

				cout << "Novo stanje: q" << temp.stanje() << endl;
				cout << "Novi stog: ";
				temp.ispisi_stog();

				if( (temp.stog.empty()) && (a == strlen(&s)) ) 
					cout << "\nDosadasnji niz je PRIHVATLJIV";
				else
					cout << "\nDosadasnji niz je NEPRIHVATLJIV";

				funkcija_prijelaza(temp, s, a+1);

				cout << endl << endl << "KRAJ GRANE 2b)" << endl;
			}
		}
		//i zadnja funkcija prijelaza
		else if(pot.stanje() == 1)
		{
			if( f((&s)[a]) == pot.stog.top())
			{
				cout << endl << endl;
				cout << "Trenutno ucitavam: " << (&s)[a] << endl;
				cout << "Nalazim se u stanju: q" << pot.stanje() << endl;
				cout << "Stanje stoga: ";
				pot.ispisi_stog();
				cout << endl << "d(q1," << (&s)[a] << "," << f((&s)[a]);
				cout << ") = {(q1,e)}" << endl;

				pot.prom_stanje(1);
				pot.stog.pop();

				cout << "Novo stanje: q" << pot.stanje() << endl;
				cout << "Novi stog: ";
				pot.ispisi_stog();

				if( (pot.stog.empty()) && (a == strlen(&s)) ) 
					cout << "\nDosadasnji niz je PRIHVATLJIV";
				else
					cout << "\nDosadasnji niz je NEPRIHVATLJIV";

				funkcija_prijelaza(pot, s, a+1);
			}
		}
	}
}

char f(char ulazni_znak)
{
	switch (ulazni_znak)
	{
	case \\'0\\':
		return \\'N\\';
	case \\'1\\':
		return \\'J\\';
	case \\'2\\':
		return \\'D\\';
	case \\'3\\':
		return \\'T\\';
	case \\'4\\':
		return \\'C\\';
	case \\'5\\':
		return \\'P\\';
	case \\'6\\':
		return \\'S\\';
	case \\'7\\':
		return \\'M\\';
	case \\'8\\':
		return \\'O\\';
	case \\'9\\':
		return \\'V\\';
	default:
		return \\'e\\';
	}
}