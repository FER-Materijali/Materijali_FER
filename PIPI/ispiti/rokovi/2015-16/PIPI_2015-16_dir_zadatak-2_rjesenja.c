void spoji(char *niz1, char *niz2, char *rez){
	int i, j, k, duljina1, duljina2, duljuk;
	duljina1=strlen(niz1);
	duljina2=strlen(niz2);
	duljuk=duljina1+duljina2;
	for(i=0, j=0, k=0; i<duljuk; ++i){
		if(i%2==0 || k>=duljina2)
			rez[i]=niz1[j++];
		else if(i%2!=0 || j>=duljina1)
			rez[i]=niz[k++];
	}
	rez[i]='\0';
}