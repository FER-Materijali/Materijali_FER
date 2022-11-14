char *moj_strncpy(char *destination, char *source, int maxlen){
	int i;
	for(i=0; i<maxlen; ++i){
			destination[i]=source[i];
			if (source[i] == '\0'){
				break;
			}
	}
	return 0