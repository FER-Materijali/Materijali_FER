void generiraj_rijec(char *rijec, char *novarijec){
	int duljina, i=0;
	char c, niz[]={"aeiouAEIOU"};
	duljina=strlen(rijec);
	while(i<duljina){
		c=rijec[rand()%duljina];
		if(i%2==0){
			if(strchr(niz, c)==NULL){
				novarijec[i]=c;
				++i;
			}
		}
		if(i%2==1){
			if(strchr(niz, c)!=NULL){
				novarijec[i]=c;
				++i;
			}
		}
	}
	novarijec[i]='\0';
}