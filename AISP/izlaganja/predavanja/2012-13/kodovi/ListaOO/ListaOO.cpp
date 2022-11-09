#include <iostream>
#include <ctime>

using namespace std;

struct podatak {
	int kljuc;
	int element;
};

class Lista {
private:
	struct atom {
		podatak _stavka;
		atom *_sljed; 
	};
	atom *_glava;
	atom *_rep;

public:
	Lista();
	Lista(const Lista &izvor);
	~Lista();

	void DodajNaPocetak(podatak stavka); 
	void DodajNaKraj(podatak stavka);
	bool DodajSortirano(podatak stavka,bool uzlazno);
	bool NadjiPoKljucu(int kljuc,podatak &stavka);
	bool BrisiSPocetka(podatak &stavka);
	bool BrisiZadanog(int kljuc,podatak &stavka);
	void BrisiSve();
	void IspisiListu();
};


Lista::Lista() {
	_glava = NULL;
	_rep = NULL;
}

Lista::Lista(const Lista &izvor) {
	atom *pAtomPred,*pAtomIzvor;
	if ((izvor._glava==NULL) || (izvor._rep==NULL))
		_glava=_rep=NULL;
	else
	{
		_glava=new atom; // procisceni copy constructor
		_glava->_stavka=izvor._glava->_stavka;
		pAtomPred=_glava;
		for (pAtomIzvor=izvor._glava->_sljed; pAtomIzvor!=NULL; pAtomIzvor=pAtomIzvor->_sljed)
		{
			pAtomPred->_sljed=new atom;
			pAtomPred=pAtomPred->_sljed;
			pAtomPred->_stavka=pAtomIzvor->_stavka;
		}
		pAtomPred->_sljed=NULL;
		_rep=pAtomPred;
	}
}

Lista::~Lista() {
	BrisiSve ();
}

void Lista::DodajNaPocetak(podatak stavka) { 
	atom *novi = new atom;

	novi->_stavka = stavka;
	novi->_sljed = _glava;
	_glava = novi;
	if (_rep == NULL) 
		_rep = novi;
	cout << " na adresu " << novi;
}

void Lista::DodajNaKraj(podatak stavka) {
	atom *novi = new atom;

	novi->_stavka = stavka;
	novi->_sljed = NULL;
	if (_rep != NULL) 
		_rep->_sljed = novi;
	else 
		_glava = novi;
	_rep = novi;
	cout << " na adresu " << novi;
}

bool Lista::DodajSortirano(podatak stavka, bool uzlazno) {  
	atom *novi = new atom;
	atom *p;

	novi->_stavka = stavka;
	if (_glava == NULL || (uzlazno ^ (_glava->_stavka.element < stavka.element))) {
		// Dodavanje na pocetak liste
		// koristi se "ekskluzivno ili" smjera i usporedbe
		DodajNaPocetak (stavka);
	} else {
		// Dodavanje iza postojeceg elementa kad:
		// nema sljedeæeg ili element u sljedeæem je (uzlazno ^ veci od novoga)
		for (p = _glava; (p->_sljed != NULL) && 
			(uzlazno ^ (p->_sljed->_stavka.element > stavka.element)); p = p->_sljed);
		// da li takav vec postoji
		if ((p->_sljed != NULL) && (p->_sljed->_stavka.element == stavka.element))
			return 0;
		novi->_sljed = p->_sljed;
		p->_sljed = novi;
		cout << " na adresu " << novi;
	}

	return 1;
}

bool Lista::NadjiPoKljucu(int kljuc, podatak& stavka) {
	atom *p;

	for (p = _glava; (p != NULL) && (p->_stavka.kljuc != kljuc); p = p->_sljed);
	if (p != NULL) {
		stavka = p->_stavka;
		return true;
	} else
		return false;
}

bool Lista::BrisiSPocetka(podatak& stavka) {
	if (_glava != NULL) {
		stavka = _glava->_stavka;
		_glava = _glava->_sljed;
		// ako je bio jedini
		if (_glava == NULL)
			_rep = NULL;
		return true;
	}
	return false;
}

bool Lista::BrisiZadanog(int kljuc, podatak& stavka) {
#if 0	
	atom **glavap, *p;
	glavap = &_glava;
	for (; *glavap && (*glavap)->_stavka.kljuc != kljuc; glavap = &(*glavap)->_sljed);
	if (*glavap) {
		p = *glavap;
		*glavap = (*glavap)->_sljed;
		stavka = p->_stavka;
		if (p->_sljed == NULL ) 
			_rep = p;
		free (p);
		return true;
	} else
		return false;
#else
	atom *p, *preth = NULL;
	for (p = _glava; (p != NULL); p = p->_sljed){
		if (p->_stavka.kljuc == kljuc){
			if (_glava == p){  // brisanje 1. elementa - promjena glave
				_glava = p->_sljed;
			}else {   // brisanje elementa u tijelu liste
				preth->_sljed = p->_sljed;
			}
			if (_rep == p){  // da li se briše zadnji element?
				_rep = preth;
			}
			stavka = p->_stavka;
			free(p);
			return true;
		}
		preth = p;
	}
	return false;
#endif
}
void Lista::IspisiListu() {
	atom *pom;
	pom = _glava;
	if (pom == NULL) 
		cout <<"Lista je prazna\n";
	else 
		for (pom; pom !=NULL; pom = pom->_sljed)
			cout << "Kljuc=" << pom->_stavka.kljuc << " element="<< pom->_stavka.element << endl;
}

void Lista::BrisiSve() {
	atom *pom;
	while (_glava!=NULL)
	{
		pom = _glava;
		_glava = _glava->_sljed;
		free (pom);
	}
	_rep = NULL;
}

int main () {
	int kljuc = 0, kljucpriv;
	int kuda, sto;
	bool uzlazno;
	char dane;
	podatak stavka;
	Lista lista;
	Lista *pKopijaListe;

	char cSig;

	srand ((unsigned) time (NULL));

	do
	{
		cout << "Upisite oznaku zeljene akcije:\n\t1-dodaj, 2-nadji, 3-brisi, 4-ispisi, 5-zavrsi\n>";
		cin >> sto;
		switch (sto)
		{
			case 1:
				cout << "Slucajni brojevi dodaju se u listu dok se ne upise K\n";
				do
				{
					cout << "Upisite oznaku nacina dodavanja:\n\t1-na pocetak, 2-na kraj, 3-sortirano\n>";
					cin >> kuda;
					switch (kuda)
					{
						case 1:
							cout << "Na pocetak";
							break;
						case 2:
							cout << "Na kraj";
							break;
						case 3:
							cout << "Sortirano - uzlazno (1) ili silazno (0)?\n";
							cin >> uzlazno;
							if (uzlazno)
								cout << "Uzlazno!";
							else
								cout << "Silazno!";
							break;
						default:
							cout << "Pogresna oznaka nacina dodavanja\n";
							break;
					}
				} while ((kuda<1) || (kuda>3));
				do {				
					putchar ('\n');	
					cSig=toupper(getchar());
					if (cSig!='K')
					{
						stavka.kljuc = ++kljuc;
						stavka.element = rand ();
						cout << "Dodaj kljuc=" << stavka.kljuc <<" element=" << stavka.element;
						switch (kuda)
						{
							case 1:
								lista.DodajNaPocetak (stavka);
								break;
							case 2:
								lista.DodajNaKraj (stavka);
								break;
							case 3:
								if (!(lista.DodajSortirano(stavka, uzlazno)))
									cout << "Kljuc " << stavka.kljuc <<" vec postoji!";
								break;
						}
					}
				} while (cSig!='K');
				break;

			case 2:
				cout << "Upisite vrijednost kljuca\n";
				cin >> kljucpriv;
				if (lista.NadjiPoKljucu(kljucpriv, stavka))
					cout << "Kljuc=" << stavka.kljuc <<" element=" << stavka.element << '\n';
				else
					cout << "Stavka s kljucem " << kljucpriv << " nije nadjena!\n";
				break;
			
			case 3:
				do
				{
					cout << "Upisite oznaku nacina brisanja:\n\t1-s pocetka, 2-za zadani kljuc, 3-sve\n>";
					cin >> kuda;
					switch (kuda)
					{
						case 1:
							if (lista.BrisiSPocetka(stavka)) 
								cout << "Izbrisana stavka s pocetka\nKljuc =" << stavka.kljuc << " element =" << stavka.element << '\n';
							else
								cout << "Lista je prazna\n";
							break;
						case 2:
							cout << "Upisite kljuc stavke koja se brise >"; 
							cin >> kljucpriv;
							if (lista.BrisiZadanog(kljucpriv, stavka)) 
								cout << "Izbrisana stavka \n Kljuc =" << stavka.kljuc << " element =" << stavka.element << '\n';
							else
								cout << "Stavka s kljucem " << kljucpriv << " nije nadjena!\n";
							break;
						case 3:
							lista.BrisiSve ();
							break;
						default:
							cout << "Pogresna oznaka nacina brisanja\n";
							break;
					}
				} while ((kuda<1) || (kuda>3));
				break;

			case 4:
				lista.IspisiListu();
				cout << "Zelite li kopirati listu? (D/N)>";
				cin >> dane;
				if (toupper (dane) == 'D')
				{
					cout << "\nKopiranje liste\n";
					pKopijaListe = new Lista(lista);
					cout << "Ispis kopije\n";
					pKopijaListe->IspisiListu();
					delete pKopijaListe;
				}
				break;

			default:
				break;
		}
	} while (sto!=5);

	return 0;
}
