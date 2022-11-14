char *moj_strrchr(char *s, int c){
	int i, j=-1;
	while(s[i]!='\0'){
		if(s[i]==c)
			j=i;
		++i;
	}
	if(j==-1)
		return NULL;
	else
		return s+j;
}

int main (void){
	char s[30+1], c;
	gets(s);
	getc(c);
	j=moj_strrchr(s, c);
	do{
		printf("%c", s);
		++s;
	}while(s!=j);
	return 0;
}