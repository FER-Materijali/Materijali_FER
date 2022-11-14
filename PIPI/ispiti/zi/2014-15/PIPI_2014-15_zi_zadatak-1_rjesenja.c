#include <stdio.h>

void simulirajIgru(int brigraca, int brbod, int *polje){
	int i;
	for(i=0; i<brigraca; ++i)
		polje[i]=0;
	while(1){
		for(i=0; i<brigraca; ++i){
			polje[i]+=rand()%6+1;
			if(polje[i]>=brbod)
				return i+1;
		}
	}
}
	
	
int main(void){
	int brigraca, brbod=70, i, j, bodovi[10], brigara;
	srand((unsigned)time(NULL));
	scanf("%d", &brigraca);
	printf ("Igra Pobjednik Bodovi igraca");
	for (i=0; i<10; ++i){
		pobjednik = simulirajIgru(brigraca, 70, bodovi);
		printf ("\n%2d. Igrac %2d ", i+1, pobjednik);
		for (j=0; j<brIgraca; ++j)
			printf ("%d%c", bodovi[j], j+1<brIgraca ? ',' : ' ');
	}
	return 0;
}