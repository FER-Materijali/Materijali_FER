void zamijeniuzastopniznak(char niz[], char stariznak, char noviznak){
	int i, j;
	while(niz[i]!='\0'){
		if(niz[i]==stariznak){
			j=i;
			while(niz[j+1]==stariznak && niz[j+1]!='\0'){
				niz[j]=niz[j+1];
				++j;
			}
			niz[i]=noviznak;
		}
		++i;
	}
}