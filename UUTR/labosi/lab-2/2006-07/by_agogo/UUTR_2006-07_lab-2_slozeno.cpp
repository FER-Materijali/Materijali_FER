#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

#define N 10
#define M 2

void delta(class PA, char &, int);

char inj(char);

class PA{
private:
	int x, y;
	int prihvatljivost[N][M];
public:
	stack<char> stog;
	stack<char> temp;
	PA();
	void ispisi_stanje();
	int vrati_x();
	int vrati_y();
	int prihvaceno();
	void prom_stanje(int a, int b);
	void ispisi_stog();
};

PA::PA() : x(0), y(0), prihvatljivost(){
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
		{
			if(i==0 && j==1)
				prihvatljivost[i][j]=1;
			else
				prihvatljivost[i][j]=0;
		}
	stog.push(\\'K\\');
};

void PA::ispisi_stanje()
{
	cout << "[" << x << "," << y << "]";
};

int PA::vrati_x()
{
	return x;
};

int PA::vrati_y()
{
	return y;
};

int PA::prihvaceno()
{
	return prihvatljivost[x][y];
};

void PA::prom_stanje(int a, int b)
{
	x=a;
	y=b;
};

void PA::ispisi_stog()
{
	while( !stog.empty() )
	{
		if(stog.top()!=\\'e\\')
			cout << stog.top();
		temp.push(stog.top());
		stog.pop();
	}
	while( !temp.empty())
	{
		stog.push(temp.top());
		temp.pop();
	}
};

int main()
{
	FILE *f;
	f=fopen("ulaz.txt","r");

	PA potisni;

	char *ulaz = new char [100];

	while(fscanf(f,"%s",ulaz)==1)
	{
		cout << endl << endl << "ULAZNI NIZ: " << ulaz << endl;
		cout << "--------------------------------------" << endl;
		delta(potisni, *ulaz, 0);
	}

	char kraj;

	scanf("%c",&kraj);

	delete [] ulaz;

	return 0;
}

void delta(class PA potisni, char &str, int k)
{
	class PA temp;

	int stanje_x, stanje_y;
	char vrh_stoga, ulazni_znak;

	stanje_x=potisni.vrati_x();
	stanje_y=potisni.vrati_y();
	if( !potisni.stog.empty() )
		vrh_stoga=potisni.stog.top();
	else
		vrh_stoga= \\'e\\';
	ulazni_znak=(&str)[k];

	if( ((unsigned int)k <= strlen(&str)) && (potisni.stog.size()>0) )
	{
		if( vrh_stoga == \\'K\\' )
		{
			cout << endl << endl << "NEDETERMINIZAM - e prijelaz" << endl;

			cout << endl << "Ucitavam znak: " << ulazni_znak << endl;
			cout << "Nalazim se u stanju: "; potisni.ispisi_stanje(); cout << endl;
			cout << "Trenutno stanje stoga: "; potisni.ispisi_stog(); cout << endl;
			
			cout << "Obavljam prijelaz: delta("; potisni.ispisi_stanje(); cout << ",e," << vrh_stoga << ") = {([" << stanje_x << ",1],e)}";

			temp = potisni;
			temp.prom_stanje( temp.vrati_x(), 1);
			temp.stog.pop();

			cout << endl << "Presao sam u stanje: "; temp.ispisi_stanje(); cout << endl;
			cout << "Novo stanje stoga: "; temp.ispisi_stog(); cout << endl;

			if( (temp.stog.empty()) && (k == strlen(&str)) && (temp.prihvaceno() == 1) ) 
				cout << "Dosadasnji niz je PRIHVATLJIV" << endl;
			else
				cout << "Dosadasnji niz je NEPRIHVATLJIV" << endl;

			delta(temp, str, k);

			cout << endl << "KRAJ GRANE" << endl;
		}

		switch ( ulazni_znak - 48 )
		{
		case 0:
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
			{
				cout << endl << "Ucitavam znak: " << ulazni_znak << endl;
				cout << "Nalazim se u stanju: "; potisni.ispisi_stanje(); cout << endl;
				cout << "Trenutno stanje stoga: "; potisni.ispisi_stog(); cout << endl;
				
				cout << "Obavljam prijelaz: delta("; potisni.ispisi_stanje(); cout << "," << ulazni_znak << "," << vrh_stoga << ") = {([" << (stanje_x*10 + ulazni_znak - 48)%9  << "," << potisni.vrati_y() << "]," << vrh_stoga << ")}";

				potisni.prom_stanje( (stanje_x*10 + ulazni_znak - 48)%9 , potisni.vrati_y() );

				cout << endl << "Presao sam u stanje: "; potisni.ispisi_stanje(); cout << endl;
				cout << "Novo stanje stoga: "; potisni.ispisi_stog(); cout << endl;

				if( (potisni.stog.empty()) && (k == strlen(&str)) && (potisni.prihvaceno() == 1) ) 
					cout << "Dosadasnji niz je PRIHVATLJIV" << endl;
				else
					cout << "Dosadasnji niz je NEPRIHVATLJIV" << endl;

				delta(potisni, str, k+1);

				break;
			}
		default:
			{
				if(potisni.vrati_y() == 0)
				{
					if( inj(ulazni_znak) != vrh_stoga )
					{
						if( (unsigned int)k < strlen(&str) )
						{
							cout << endl << "Ucitavam znak: " << ulazni_znak << endl;
							cout << "Nalazim se u stanju: "; potisni.ispisi_stanje(); cout << endl;
							cout << "Trenutno stanje stoga: "; potisni.ispisi_stog(); cout << endl;
							
							cout << "Obavljam prijelaz: delta("; potisni.ispisi_stanje(); cout << "," << ulazni_znak << "," << vrh_stoga << ") = {([" << (stanje_x*10 + ulazni_znak - 48)%9  << ",0]," << inj(ulazni_znak) << vrh_stoga << ")}";

							potisni.prom_stanje( (stanje_x*10 + ulazni_znak - 48)%9 , potisni.vrati_y() );
							potisni.stog.push(inj(ulazni_znak));

							cout << endl << "Presao sam u stanje: "; potisni.ispisi_stanje(); cout << endl;
							cout << "Novo stanje stoga: "; potisni.ispisi_stog(); cout << endl;

							if( (potisni.stog.empty()) && (k == strlen(&str)) && (potisni.prihvaceno() == 1) ) 
								cout << "Dosadasnji niz je PRIHVATLJIV" << endl;
							else
								cout << "Dosadasnji niz je NEPRIHVATLJIV" << endl;

							delta(potisni, str, k+1);
						}
					}
					else if( inj(ulazni_znak) == vrh_stoga)
					{
						cout << endl << endl << "NEDETERMINIZAM - skidam sa stoga" << endl;
						cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl;

						cout << endl << "Ucitavam znak: " << ulazni_znak << endl;
						cout << "Nalazim se u stanju: "; potisni.ispisi_stanje(); cout << endl;
						cout << "Trenutno stanje stoga: "; potisni.ispisi_stog(); cout << endl;
						
						cout << "Obavljam prijelaz: delta("; potisni.ispisi_stanje(); cout << "," << ulazni_znak << "," << vrh_stoga << ") = {([" << (stanje_x*10 + ulazni_znak - 48)%9  << ",1],e)}";

						temp=potisni;
						temp.prom_stanje( (temp.vrati_x()*10 + ulazni_znak - 48)%9 , 1);
						temp.stog.pop();

						cout << endl << "Presao sam u stanje: "; temp.ispisi_stanje(); cout << endl;
						cout << "Novo stanje stoga: "; temp.ispisi_stog(); cout << endl;

						if( (temp.stog.empty()) && (k == strlen(&str)) && (temp.prihvaceno() == 1) ) 
							cout << "Dosadasnji niz je PRIHVATLJIV" << endl;
						else
							cout << "Dosadasnji niz je NEPRIHVATLJIV" << endl;

						delta(temp, str, k+1);

						cout << endl << endl << "////////////////////////////" << endl;
						cout << "KRAJ GRANE" << endl;

						cout << endl << endl << "NEDETERMINIZAM - stavljam dalje" << endl;
						cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl;

						cout << endl << "Ucitavam znak: " << ulazni_znak << endl;
						cout << "Nalazim se u stanju: "; potisni.ispisi_stanje(); cout << endl;
						cout << "Trenutno stanje stoga: "; potisni.ispisi_stog(); cout << endl;
						
						cout << "Obavljam prijelaz: delta("; potisni.ispisi_stanje(); cout << "," << ulazni_znak << "," << vrh_stoga << ") = {([" << (stanje_x*10 + ulazni_znak - 48)%9  << ",0]," << inj(ulazni_znak) << vrh_stoga << ")}";

						temp=potisni;
						temp.prom_stanje( (temp.vrati_x()*10 + ulazni_znak - 48)%9 , temp.vrati_y() );
						temp.stog.push( inj(ulazni_znak) );

						cout << endl << "Presao sam u stanje: "; temp.ispisi_stanje(); cout << endl;
						cout << "Novo stanje stoga: "; temp.ispisi_stog(); cout << endl;

						if( (temp.stog.empty()) && (k == strlen(&str)) && (temp.prihvaceno() == 1) ) 
							cout << "Dosadasnji niz je PRIHVATLJIV" << endl;
						else
							cout << "Dosadasnji niz je NEPRIHVATLJIV" << endl;

						delta(temp, str, k+1);

						cout << endl << endl << "////////////////////////////" << endl;
						cout << "KRAJ GRANE" << endl;
					}
				}
				else if(potisni.vrati_y() == 1)
				{
					if( inj(ulazni_znak) == vrh_stoga)
					{

						cout << endl << "Ucitavam znak: " << ulazni_znak << endl;
						cout << "Nalazim se u stanju: "; potisni.ispisi_stanje(); cout << endl;
						cout << "Trenutno stanje stoga: "; potisni.ispisi_stog(); cout << endl;

						cout << "Obavljam prijelaz: delta("; potisni.ispisi_stanje(); cout << "," << ulazni_znak << "," << vrh_stoga << ") = {([" << (stanje_x*10 + ulazni_znak - 48)%9  << ",1],e)}";

						potisni.prom_stanje( (stanje_x*10 + ulazni_znak - 48)%9 , potisni.vrati_y() );
						potisni.stog.pop();

						cout << endl << "Presao sam u stanje: "; potisni.ispisi_stanje(); cout << endl;
						cout << "Novo stanje stoga: "; potisni.ispisi_stog(); cout << endl;

						if( (potisni.stog.empty()) && (k == strlen(&str)) && (potisni.prihvaceno() == 1) ) 
							cout << "Dosadasnji niz je PRIHVATLJIV" << endl;
						else
							cout << "Dosadasnji niz je NEPRIHVATLJIV" << endl;

						delta(potisni, str, k+1);
					}
				}
				break;
			}
		}
	}
}

char inj(char a)
{
	if(a == \\'2\\')
		return \\'T\\';
	if(a == \\'4\\')
		return \\'F\\';
	if(a == \\'6\\')
		return \\'S\\';
	if(a == \\'9\\')
		return \\'N\\';
	return \\'e\\';
}