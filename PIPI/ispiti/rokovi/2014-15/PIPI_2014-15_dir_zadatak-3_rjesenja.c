int prosiri(long *mat, int r, int s, int novir, int novis, int maxr, int maxs){
	int i=0, j=0;
	static int prvi=1;
	if(novir > maxr || novis > maxs )
		return 0;
	if(prvi==1){
		srand((unsigned)time(NULL));
		prvi=0;
	}
	min=*(mat+i*maxs+j);
	max=min;
	for(i=0; i<r; ++i){
		for(j=0; j<s; ++j){
			if(*(mat+i*maxs+j)<min)
				min=*(mat+i*maxs+j);
			else if(*(mat+i*maxs+j)>max)
				max=*(mat+i*maxs+j);
		}
	}
	for(i=r; i<novir; ++i){
		for(j=s; j<novis; ++j){
			*(mat+i*maxs+j)=rand()%(max-min)+min;
		}
	}
	return 1;
}