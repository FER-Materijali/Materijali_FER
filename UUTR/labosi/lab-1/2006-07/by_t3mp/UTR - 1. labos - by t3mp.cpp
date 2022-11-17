#include <cstdlib>
#include <iostream>
#include <stdio.h>

using namespace std;

int DKA(char *ulaz)
{
    int tabla[24][7]={ {1,2,3,23,23,23,0},
                       {23,23,23,4,5,6,0},
                       {23,23,23,7,8,9,0},
                       {23,23,23,10,11,12,0},
                       {23,13,14,23,23,23,1},
                       {23,23,15,23,23,23,1},
                       {23,16,14,23,23,23,1},
                       {17,23,18,23,23,23,1},
                       {23,23,23,23,23,23,1},
                       {19,23,20,23,23,23,1},
                       {21,13,23,23,23,23,1},
                       {22,23,23,23,23,23,1},
                       {21,16,23,23,23,23,1},
                       {23,23,23,23,23,9,0},
                       {23,23,23,23,11,23,0},
                       {23,23,23,10,23,12,0},
                       {23,23,23,7,23,23,0},
                       {23,23,23,23,23,6,0},
                       {23,23,23,23,23,12,0},
                       {23,23,23,4,23,23,0},
                       {23,23,23,10,23,23,0},
                       {23,23,23,23,5,23,0},
                       {23,23,23,4,23,6,0},
                       {23,23,23,23,23,23,0}
                       };
    int i=0,j,proslo_stanje,stanje=0;
    char znakovi[6]={\\'A\\',\\'B\\',\\'C\\',\\'1\\',\\'2\\',\\'3\\'};
    while (ulaz[i]!=\\'\0\\')
    {
          proslo_stanje=stanje;
          for (j=0;j<6;j++)
              if (ulaz[i]==znakovi[j]) stanje=tabla[stanje][j];
          cout<<"Procitani znak: "<<ulaz[i]<<endl;
          cout<<"Staro stanje: S"<<proslo_stanje<<endl;
          cout<<"Novo stanje: S"<<stanje<<endl;
          cout<<"Novo stanje ";
          if (tabla[stanje][6]) cout<<"je";
             else cout<<"nije";
          cout<<" prihvatljivo"<<endl<<endl;
          i++;
    }
    return tabla[stanje][6];
}

int main(int argc, char *argv[])
{

    FILE *fajl;
    char niz[512];

    if ((fajl = fopen ("c:/nizovi.txt","r")) == NULL)
    {
       cout<<"Ne mogu otvoriti datoteku"<<endl;
       system("PAUSE");
       exit(1);
    }
    while ((fscanf (fajl, "%s", &niz))!=EOF)
    {
          cout<<"Novi niz "<<niz<<endl<<endl;
          if (DKA(niz)) cout<<"Niz "<<niz<<" je prihvacen\n\n\n\n\n";
             else cout<<"Niz "<<niz<<" nije prihvacen\n\n\n\n\n";
    }

    system("PAUSE");
    return EXIT_SUCCESS;
}