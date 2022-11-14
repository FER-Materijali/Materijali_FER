int brojpojava(char *niz, int *niz2){
	int duljina=strlen(niz);
	int i, broj=0;
	char c;
	for(i=0; i<duljina; ++i){
		if(toupper(niz[i])>='A' && toupper(niz[i])<='Z'){
			c=toupper(niz[i]);
			c-='A';
			niz2[c]++;
			broj=1;
		}
	}
	for(i=0; i<26; ++i){
		if(niz2[i]>max)
			max=niz2[i];
	}
	if(broj==1)
		return max;
	else
		return 0;
}

int main (void){
	char niz[100+1];
	int niz2[26]={0};
	gets(niz);
	broj=brojpojava(niz, niz2);
	for(i=0; i<26; ++i){
		if(niz2[i]==broj)
			printf("%c %d", 'A'+i, niz2[i]);
	}
	return 0;
}