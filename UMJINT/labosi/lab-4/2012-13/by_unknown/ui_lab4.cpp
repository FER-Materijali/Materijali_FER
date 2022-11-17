#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

typedef struct {
	float tezina[13];
} jed;

typedef struct {
	float x;
	float fx;
} funkcija;

int main(){
	int i,j,brtr=0,best,it,k,odabran1,odabran2,l,brkr,brts=0;
	float K=(1/100),p,uzorak,index,izlaz,izlaz1,izlaz2,izlaz3,izlaz4,min=FLT_MAX,pog,ukpog,sumfit,odabir1,odabir2,pom,normrand,*pogreska,*fitness,*granicalo,*granicahi;
	string line,line2;
	string::size_type sz;
	jed *jedinka,*jedinka2,odabranajedinka;
	funkcija *train,*test;
	srand((unsigned)time(0));
	cout << "Unesite broj iteracija:";
	cin >> it;
	cout << "Unesite dopusten iznos pogreske:";
	cin >> pog;
	cout << "Unesite postotak mutacije:";
	cin >> p;
	cout << "Unesite K:";
	cin >> K;
	cout << "Unesite broj kromosoma:";
	cin >> brkr;
	jedinka=(jed *)malloc(brkr*sizeof(jed));
	jedinka2=(jed *)malloc(brkr*sizeof(jed));
	pogreska=(float *)malloc(brkr*sizeof(float));
	fitness=(float *)malloc(brkr*sizeof(float));
	granicalo=(float *)malloc(brkr*sizeof(float));
	granicahi=(float *)malloc(brkr*sizeof(float));
	for(j=0;j<brkr;j++)
		for(i=0;i<13;i++)
			jedinka[j].tezina[i]=-10+(float)rand()/((float)RAND_MAX/20);
	ifstream myfile("train.txt");
	if (myfile.is_open()){
		while ( myfile.good() ){
			getline (myfile,line);
			if (line.length()>0){
				brtr++;
			}
		}
	}
	else {
		cout << "Ne mogu otvoriti datoteku";
		cin.get();
	}

	train=(funkcija *) malloc (brtr*sizeof(funkcija));

	i=0;
	
	myfile.clear();
	myfile.seekg(0);

	if (myfile.is_open()){
		while ( myfile.good() ){
			getline (myfile,line);
			if (line.length()>0){
				train[i].x=stof(line,&sz);
				line2=line.substr(sz+1);
				train[i].fx=stof(line2,&sz);
				i++;
			}
		}
		myfile.close();
	}
	else {
		cout << "Ne mogu otvoriti datoteku";
		cin.get();
	}

	for(k=0;k<it;k++){
		for(i=0;i<brkr;i++){
			pogreska[i]=0;
			fitness[i]=0;
			granicalo[i]=0;
			granicahi[i]=0;
		}
		cout<<"Generacija:"<<k+1<<endl;
		for(i=0;i<brkr;i++){
			for(j=0;j<brtr;j++){
				izlaz1=1/(1+exp(1*(jedinka[i].tezina[0]*train[j].x+jedinka[i].tezina[4])));
				izlaz2=1/(1+exp(1*(jedinka[i].tezina[1]*train[j].x+jedinka[i].tezina[5])));
				izlaz3=1/(1+exp(1*(jedinka[i].tezina[2]*train[j].x+jedinka[i].tezina[6])));
				izlaz4=1/(1+exp(1*(jedinka[i].tezina[3]*train[j].x+jedinka[i].tezina[7])));
				izlaz=izlaz1*jedinka[i].tezina[8]+izlaz2*jedinka[i].tezina[9]+
					izlaz3*jedinka[i].tezina[10]+izlaz4*jedinka[i].tezina[11]+
					jedinka[i].tezina[12];
				pogreska[i]+=(izlaz-train[j].fx)*(izlaz-train[j].fx);
			}
			pogreska[i]=sqrt(pogreska[i]/brkr);
			fitness[i]=1/pogreska[i];
			if(pogreska[i]<min){
				min=pogreska[i];
				best=i;
			}
		}
		ukpog=0;
		sumfit=0;
		for(i=0;i<brkr;i++){
			ukpog+=pogreska[i];
			sumfit+=fitness[i];
		}
		cout<<"Ucenje zavrseno\n";
		cout<<"Iznos ukupne pogreske:"<<ukpog/brkr<<endl;
		if(pogreska[best]<pog){
			cout<<"Pogreska naucene jedinke na skupu za ucenje:"<<pogreska[best]<<endl;
			for(l=0;l<13;l++)
				odabranajedinka.tezina[l]=jedinka[best].tezina[l];
			break;
		}
		pom=0;
		for(i=0;i<brkr;i++){
			granicalo[i]=pom;
			granicahi[i]=pom+fitness[i];
			pom=granicahi[i];
		}
		jedinka2[0]=jedinka[best];
		for(i=1;i<brkr;i++){
			odabir1=(float)rand()/((float)RAND_MAX/sumfit);//[0,sumfit]
			odabir2=(float)rand()/((float)RAND_MAX/sumfit);//[0,sumfit]
			for(j=0;j<brkr;j++){
				if((odabir1<=granicahi[j]) && (odabir1>=granicalo[j]))
					odabran1=j;
				if((odabir2<=granicahi[j]) && (odabir2>=granicalo[j]))
					odabran2=j;
			}
			for(j=0;j<13;j++)
				jedinka2[i].tezina[j]=
					(jedinka[odabran1].tezina[j]+
					jedinka[odabran2].tezina[j])/2;
			for(j=0;j<13;j++){
				index=(float)rand()/((float)RAND_MAX);
				if(index<p){
					normrand=sqrt(K)*(-1+(float)rand()/((float)RAND_MAX/2)-1+(float)rand()/((float)RAND_MAX/2)-1+(float)rand()/((float)RAND_MAX/2));
					jedinka2[i].tezina[j]+=normrand;
				}
			}
		}
		jedinka=jedinka2;
	}
	if(k==it){
		cout<<"Ucenje nije zadovoljilo kriterije\n";
		return 0;
	}

	cout<<"Tezine:\n";
	cout<<"w01:"<<odabranajedinka.tezina[4]<<endl;
	cout<<"w11:"<<odabranajedinka.tezina[0]<<endl;
	cout<<"w02:"<<odabranajedinka.tezina[5]<<endl;
	cout<<"w12:"<<odabranajedinka.tezina[1]<<endl;
	cout<<"w03:"<<odabranajedinka.tezina[6]<<endl;
	cout<<"w13:"<<odabranajedinka.tezina[2]<<endl;
	cout<<"w04:"<<odabranajedinka.tezina[7]<<endl;
	cout<<"w14:"<<odabranajedinka.tezina[3]<<endl;
	cout<<"w05:"<<odabranajedinka.tezina[12]<<endl;
	cout<<"w15:"<<odabranajedinka.tezina[8]<<endl;
	cout<<"w25:"<<odabranajedinka.tezina[9]<<endl;
	cout<<"w35:"<<odabranajedinka.tezina[10]<<endl;
	cout<<"w45:"<<odabranajedinka.tezina[11]<<endl;

	ifstream myfile2("test.txt");
	if (myfile2.is_open()){
		while ( myfile2.good() ){
			getline (myfile2,line);
			if (line.length()>0){
				brts++;
			}
		}
	}
	else {
		cout << "Ne mogu otvoriti datoteku";
		cin.get();
	}

	test=(funkcija *) malloc (brts*sizeof(funkcija));

	i=0;
	
	myfile2.clear();
	myfile2.seekg(0);

	if (myfile2.is_open()){
		while ( myfile2.good() ){
			getline (myfile2,line);
			if (line.length()>0){
				test[i].x=stof(line,&sz);
				line2=line.substr(sz+1);
				test[i].fx=stof(line2,&sz);
				i++;
			}
		}
		myfile2.close();
	}
	else {
		cout << "Ne mogu otvoriti datoteku";
		cin.get();
	}
	for(j=0;j<brts;j++){
				izlaz1=1/(1+exp(1*(odabranajedinka.tezina[0]*test[j].x+odabranajedinka.tezina[4])));
				izlaz2=1/(1+exp(1*(odabranajedinka.tezina[1]*test[j].x+odabranajedinka.tezina[5])));
				izlaz3=1/(1+exp(1*(odabranajedinka.tezina[2]*test[j].x+odabranajedinka.tezina[6])));
				izlaz4=1/(1+exp(1*(odabranajedinka.tezina[3]*test[j].x+odabranajedinka.tezina[7])));
				izlaz=izlaz1*odabranajedinka.tezina[8]+izlaz2*odabranajedinka.tezina[9]+
					izlaz3*odabranajedinka.tezina[10]+izlaz4*odabranajedinka.tezina[11]+
					odabranajedinka.tezina[12];
				pogreska[0]+=(izlaz-train[j].fx)*(izlaz-train[j].fx);
	}
	pogreska[0]=sqrt(pogreska[0]/brkr);
	cout << "Pogreska na skupu za ispitivanje:"<<pogreska[0]<<endl;
	while(1){
		cout<<"Unesite novi uzorak:";
		cin>>uzorak;
		izlaz1=1/(1+exp(1*(odabranajedinka.tezina[0]*uzorak+odabranajedinka.tezina[4])));
		izlaz2=1/(1+exp(1*(odabranajedinka.tezina[1]*uzorak+odabranajedinka.tezina[5])));
		izlaz3=1/(1+exp(1*(odabranajedinka.tezina[2]*uzorak+odabranajedinka.tezina[6])));
		izlaz4=1/(1+exp(1*(odabranajedinka.tezina[3]*uzorak+odabranajedinka.tezina[7])));
		izlaz=izlaz1*odabranajedinka.tezina[8]+izlaz2*odabranajedinka.tezina[9]+
			izlaz3*odabranajedinka.tezina[10]+izlaz4*odabranajedinka.tezina[11]+
			odabranajedinka.tezina[12];
		cout<<"Izlaz:"<<izlaz<<endl;
	}
	return 0;
}
