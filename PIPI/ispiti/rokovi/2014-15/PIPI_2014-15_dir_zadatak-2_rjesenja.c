char *kombiniraj(char *novi, char *prvi, char *drugi, int n){
	int i;
	char *p=novi;
	while(*prvi || *drugi){
		for(i=0; *prvi && i<n; ++i)
			*novi ++ = *prvi++;
		for(i=0; *drugi && i<n; ++i)
			*novi ++ = *drugi++;
	}
	*novi='\0';
	return p;
}