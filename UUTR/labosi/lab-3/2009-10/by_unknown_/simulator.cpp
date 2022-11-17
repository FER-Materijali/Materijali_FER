#include <cstdio>
#include <algorithm>
#include <map>
#include <utility>
#include <string>
using namespace std;
int main (){
    
    FILE *fdef = fopen ("definicija_3_labos.txt","r");
    FILE *ftraka = fopen ("traka.txt", "r");
    char tren_stanje[500], ulaz_trake[500], novo_stanje[500], novi_znak_trake[500], pomak[500], buff[500];
    map <pair <string, string>, pair <pair <string, string>, string> > automat;
    while (fscanf (fdef, "delta(%[^,],%[^)]) = (%[^,],%[^,],%[^)])\n", tren_stanje, ulaz_trake, novo_stanje, novi_znak_trake, pomak)!=EOF){
          automat[make_pair((string)tren_stanje, (string)ulaz_trake)] = make_pair(make_pair((string)novo_stanje, (string)novi_znak_trake), (string)pomak);
    }
    fgets (buff, sizeof(buff), ftraka);
    string traka = (string) buff + "B";
    int indeks = 0;
    string trenutno_stanje = "q0";
    string znak_trake = "";
    znak_trake += traka[0];
    while (automat.find(make_pair(trenutno_stanje, znak_trake)) != automat.end()){
          pair < pair <string, string>, string> prijelaz = automat[make_pair(trenutno_stanje, znak_trake)];
          printf ("\ntraka: %s\ntrenutno stanje: %s\nznak trake: %s\nindeks na traci: %d\nnovo stanje: %s\nnovi znak trake: %s\npomak: %s\n\n",
                   traka.c_str(), trenutno_stanje.c_str(), znak_trake.c_str(), indeks, prijelaz.first.first.c_str(), prijelaz.first.second.c_str(), prijelaz.second.c_str());
          trenutno_stanje = prijelaz.first.first;
          traka[indeks] = prijelaz.first.second[0];
          if (prijelaz.second == "R") indeks++;
          else indeks--;
          if (traka[traka.length()-1]!='B') traka+="B";
          znak_trake = "";
          znak_trake += traka[indeks];
    }
    system("PAUSE");
    return 0;
}
