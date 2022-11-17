#include <iostream>
#include<string>
using namespace std;
char ulica[100][100];
int matrica[20][20];
int xp_ulica[100];
int xk_ulica[100];
int yp_ulica[100];
int yk_ulica[100];
int O=0;			//broj ulica
int X=0,Y=0, smjer=1, Xc,Yc; //polozaj autica
//pretpostavka je da je auticu p nadesno gledajuci kartu

void koja_ulica(){
	cout<<endl<<"auto se nalazi u ulici: ";
	int krizanje=0;
	for (int i=0; i<O;i++)
	{
		if ((((xp_ulica[i]==xk_ulica[i])&&(xk_ulica[i]==X)) && ((yp_ulica[i]<=Y)&&(Y<=yk_ulica[i]))) ||
			(((yp_ulica[i]==yk_ulica[i])&&(yk_ulica[i]==Y)) && ((xp_ulica[i]<=X)&&(X<=xk_ulica[i]))))
		{
			if (krizanje==1) cout<<" krizanje ";
			for (int j=0; ulica[i][j]!='\0'; j++) 
				printf("%c",ulica[i][j]);
			krizanje=1;
		}
		cout<<" ";
	}
}
void inicijaliziraj_matricu(){
	for (int i=0; i<20; i++)
		for (int j=0;j<20; j++)
			matrica[i][j]=0;}

void ispisi_matricu(){
	for (int i=0; i<20; i++){
			for (int j=0;j<20; j++) {
				printf("%d",matrica[i][j]);}
			printf("\n");}}

void ucitaj_datoteku(){
	 FILE *f;
	 int x0,y0,x1,y1,p,i,j;
	 char ulica_naziv[100];
     if ( (f=fopen("ulice.txt","r"))== NULL){
                                        printf("NAPRAVI JEBENU DATOTEKUUU");
                                        exit(-1);
                                        }
	 else{
     while(fscanf(f,"%[^,], %d, %d, %d, %d\n",ulica_naziv,&x0,&y0,&x1,&y1)!=EOF){ 
		 for (int k=0; k<100;k++){
			 ulica[O][k]=ulica_naziv[k];}
		 for (k=0; ulica[O][k]!='\0';k++){
			 printf("%c",ulica[O][k]); }
			 cout<<endl;
			 if (x0<=x1) {
				 xp_ulica[O]=x0/50;
				 xk_ulica[O]=x1/50;}
			 else{
				 xp_ulica[O]=x1/50;
				 xk_ulica[O]=x0/50;}
			 if (y0<=y1) {
				 yp_ulica[O]=y0/50;
				 yk_ulica[O]=y1/50;}
			 else{
				 yp_ulica[O]=y1/50;
				 yk_ulica[O]=y0/50;}
		 O++;
        if (x0>x1){p=x0;x0=x1,x1=p;}               
		 if (y0>y1){p=y0;y0=y1,y1=p;}                       
			 for (i=(x0/50);i<=(x1/50);i++)                             
			    for (j=(y0/50);j<=(y1/50);j++) matrica[j][i]=1;
	 ispisi_matricu();
	 }
	 printf("\n");
	 ispisi_matricu();
	 }}

int ide_DESNO(char akcija){ //desno
	int Xp=X, Yp=Y;
	if (akcija=='P') { Xp++;}
	if (akcija=='L') { Xp; Yp--; smjer=4;}
	if (akcija=='D') { Xp; Yp++; smjer=2;}
	if ((matrica[Yp][Xp])==0){
		printf("stanje greske"); 
		return -1;
	}
	X=Xp;	Y=Yp;
	return 0;}

int ide_LIJEVO(char akcija){ //lijevo
	int Xp=X, Yp=Y;
	if (akcija=='P') { Xp--;}
	if (akcija=='L') { Yp++; Yp; smjer=2;}
	if (akcija=='D') { Yp--; Yp; smjer=4;}
	if ((matrica[Yp][Xp])==0){
		printf("stanje greske"); 
		return -1;
	}
	X=Xp;	Y=Yp;
	return 0;}

int ide_GORE(char akcija){//gore
	int Xp=X, Yp=Y;
	if (akcija=='P') { Yp--;}
	if (akcija=='L') { Xp--; smjer=3;}
	if (akcija=='D') { Xp++; smjer=1;}
	if ((matrica[Yp][Xp])==0){
		printf("stanje greske"); 
		return -1;
	}
	X=Xp;	Y=Yp;
	return 0;}

int ide_DOLJE(char akcija){
	int Xp=X, Yp=Y;
	if (akcija=='P') { Yp++;}
	if (akcija=='L') { Xp++; smjer=1;}
	if (akcija=='D') { Xp--; smjer=3;}
	if ((matrica[Yp][Xp])==0){
		printf("stanje greske"); 
		return -1;
	}
	X=Xp;	Y=Yp;
	return 0;}

int main(){
	inicijaliziraj_matricu();
	ispisi_matricu();
	ucitaj_datoteku();
	int a;
	scanf("%d",&a);
	char slovo;
	while (1){
		//scanf("%c", &slovo);
		cin>>slovo;
		if (slovo!='x') {
			Xc=X; Yc=Y;
		if (smjer==1) {
			if (ide_DESNO(slovo)==-1) break;
		}
		else if (smjer==2) {
			if (ide_DOLJE(slovo)==-1) break;
		}
		else if (smjer==3) {
			if (ide_LIJEVO(slovo)==-1) break;
		}
		else if (smjer==4) {
			if (ide_GORE(slovo)==-1) break;
		}		
		matrica[Yc][Xc]=1;
		matrica[Y][X]=5;
		ispisi_matricu();
		koja_ulica(); 
		}
		else break;
	}
	cout<<"Zavrsio sam... kraj"<<endl;
	scanf("%d",X);//ucitaj nest' da uspijem procitat
	return 0;
}