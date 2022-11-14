void postavimine(int *polje, int m, int n, int maxsutp, broj){
	int i;
	static int inic=0;
	if (!inic) {
	srand((unsigned) time(NULL));
	inic = 1;
	}
	for(i=0; i<broj; ++i)
		*(polje+(rand()%m)*maxstup+rand()%n)=1;
}

int staninapolje(int *polje, int r, int s, int maxstup){
	int i, j, brojac=0;
	if(*(polje+r*maxstup+s)==1)
		return -1;
	for(i=r-1; i<=r+1; ++i)
		if(*(polje+i*maxstup+s)==1)
			brojac++;
	for(j=s-1; j<=s+1; ++j)
		if(*(polje+r*maxstup+j)==1)
			++brojac;
	return brojac;
}

int main (void){
	int polje[MAX][MAX];
	int brmina, r, s, m, n, izgubio;
	scanf("%d %d %d", &m, &n, &brmina);
	postavi(polje, m, n, MAX, brmina);
	while(izgubio!=-1){
		do{
			scanf("%d %d", &r, &s);
		}while(r>m && r<0 && s>n && s<0);
		izgubio=staninapolje(polje, r, s, MAX);
		if(izgubio==-1)
			printf("kraj");
		else
			printf("(%d,%d)->%d\n", r, s, izgubio);
	}
	return 0;
}