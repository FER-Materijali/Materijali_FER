/**
Napišite razred SanitizedString koji sadrži privatnu varijablu str tipa std::string (ili char*), i public
metode removeDuplicateWhitespace i removeNonAlphaChars.
Metoda removeDuplicateWhitespace modificira str tako da iz ulaznog stringa izbacuje sve pojave
višestrukih praznina. Primjerice, za string „Sunce nam dolazi!“, metoda će ga prepraviti u niz „Sunce
nam dolazi!“ (umjesto višestrukih praznina je ostala samo po jedna praznina između riječi). Metoda
removeNonAlphaChars izbacuje sve znakove koji nisu slova abecede (dovoljno je da program radi
samo za znakove engleske abecede). Npr. ako je str = „M~ir4ko&“, funkcija ga treba prepraviti u „Mirko“.
Po potrebi napisati dodatne metode koje trebaju za ostvarenje funkcionalnosti (konstruktore, destruktor,
gettere, settere…)
Razred treba omogućiti i ispis sanitiziranih stringova pomoću operatora <<.
Potrebno je napisati glavni program koji od korisnika učitava string (ili znakovni niz). Program zatim stvara
objekt tipa SanitizedString i ispisuje početni i sanitizirani string.
*/
#include <iostream>
#include <cstring>

using namespace std;

class SanitizedString {
    private:
        string str;
    public:
        SanitizedString(string str){
            this->str = str;
            removeDuplicateWhitespace();
            removeNonAlphaChars();
        }

        void removeDuplicateWhitespace(){
            for(int i = 1; i < str.size(); i++)
            {
                if(str[i] == ' ' && str[i - 1] == ' ')
                {
                    str.erase(i, 1);
                    i--;
                }
            }
        }

        void removeNonAlphaChars(){
            for(int i = 0; i < str.size(); i++)
            {
                if(!(isalpha(str[i]) || str[i] == ' '))
                {
                    str.erase(i, 1);
                    i--;
                }
            }
        }

friend ostream& operator<<(ostream& os, const SanitizedString& str);
};

ostream& operator<<(ostream& os, const SanitizedString& str)
{
    os << str.str;
    return os;
}

int main() {

    string ulaz;
    cout << "upisi string:";
    getline(cin, ulaz);

    SanitizedString novistring(ulaz);

    cout << "pocetni string: " << ulaz << endl;
    cout << "uredeni string: " << novistring << endl;

    return 0;
}