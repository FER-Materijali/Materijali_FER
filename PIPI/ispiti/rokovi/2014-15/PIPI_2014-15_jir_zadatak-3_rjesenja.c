void izbaci_oct_brojeve(char *niz){
	int i=0;
	char c='x';
	while(niz[i]!='\0'){
		if(niz[i]>='0' && niz[i]<='9'){
			if(niz[i]==0){
				while(niz[i+1]>='0' && niz[i+1]<='7' && niz[i+1]!='\0'){
					niz[i]=c;
					++i;
				}
			}
			else
				while(niz[i]!='\0' && niz[i]>='0' && niz[i]<='9')
					++i;
		}
		else
			++i;
	}
}