void ispisi_max_srednjih(int *polje, int m, int n, int maxstup){
	int i, j;
	float srednja, max;
	for(j=0; j<n; ++j){
		max=(*(polje+0*maxstup+j)+*(polje+1*maxstup+j))/2;
		for(i=1; i<m-1; ++i){
			srednja=(*(polje+i*maxstup+j)+*(polje+(i+1)*maxstup+j))/2.;
			if(max<srednja)
				max=srednja;
		}
		printf("%.1f\n", max);
	}
}