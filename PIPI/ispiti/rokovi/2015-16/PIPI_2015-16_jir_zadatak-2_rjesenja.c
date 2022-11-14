int lok(int *polje, int m, int n, int r, int s, int maxstup){
	int i, j;
	float suma=0, ukupan;
	for(i=-1; i<=1; ++i){
		for(j=-1; j<=1; ++j){
			if((r+i)>=0 && (r+i)<m){
				if((s+j)>=0 && (s+j)<n){
					suma+=*(polje+i*maxstup+j);
					++brojac;
				}
			}
		}
	}
	suma/=brojac;
	brojac=0;
	for(i=0; i<m; ++i){
		for(j=0; j<n; ++j){
			ukupan+=*(polje+i*maxstup+j);
			++brojac;
		}
	}
	ukupan/=brojac;
	if(suma>ukupan)
		return 0
	else
		return 1;
}