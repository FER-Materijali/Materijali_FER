#include <stdio.h>
#include <conio.h>
#define MAXR 30
#define MAXS 30

int ploca[MAXR][MAXS] = {0};

int moze(int maxr, int maxs, int *tr, int *ts, int potez){
	int nr, ns;			
	switch (potez){
		case 0: nr = *tr -2; ns = *ts - 1; break;
		case 1: nr = *tr -2; ns = *ts + 1; break;
		case 2: nr = *tr -1; ns = *ts + 2; break;
		case 3: nr = *tr +1; ns = *ts + 2; break;
		case 4: nr = *tr +2; ns = *ts + 1; break;
		case 5: nr = *tr +2; ns = *ts - 1; break;
		case 6: nr = *tr +1; ns = *ts - 2; break;
		case 7: nr = *tr -1; ns = *ts - 2; break;
	}
	if ( nr>=0 && nr<maxr && ns>=0 && ns<maxs && !ploca[nr][ns]){
		*tr = nr;
		*ts = ns;
		return 1;
	}
	return 0;
}
int fBrojOpcija(int maxr, int maxs, int tr, int ts){
	int rv=0;		
	int nr, ns, potez;
	for (potez=0; potez<8; potez++){
    	switch (potez){
    		case 0: nr = tr -2; ns = ts - 1; break;
    		case 1: nr = tr -2; ns = ts + 1; break;
    		case 2: nr = tr -1; ns = ts + 2; break;
    		case 3: nr = tr +1; ns = ts + 2; break;
    		case 4: nr = tr +2; ns = ts + 1; break;
    		case 5: nr = tr +2; ns = ts - 1; break;
    		case 6: nr = tr +1; ns = ts - 2; break;
    		case 7: nr = tr -1; ns = ts - 2; break;
    	}
    	if ( nr>=0 && nr<maxr && ns>=0 && ns<maxs && !ploca[nr][ns]){
    		rv++;
    	}
    }
	return rv;
}

/*
A technique known as  Warnsdorf's heuristic allows us to make much better choices for next move than random selection.  
The heuristic, discovered by H. C. von Warnsdorf in 1823 tells to select as our next move  the one which has the fewest 
choices for moving on from there.
*/
int WarnsdorfovKonj(int maxr, int maxs, int tr, int ts, int rbr){
	int potez, tr1, ts1, brojOpcija[8] = {0};
	//printf("\npokusavam %d %d %d",rbr, tr, ts);
    int min, i; 
	ploca[tr][ts] = rbr;
	if (rbr == maxr * maxs){		
		return 1;
	}
	for (potez = 0; potez < 8; potez++){
		tr1 = tr; ts1 = ts;
		if (moze(maxr, maxs, &tr1, &ts1, potez)){
			brojOpcija[potez] = fBrojOpcija(maxr, maxs, tr1, ts1);
      }else{
         brojOpcija[potez] = 200;
      }
	}
    
    
   while (1){
     for (i = 0, min = 100; i < 8; i++){
        if (brojOpcija[i]<min){
           min = brojOpcija[i];
           potez = i;
        }
     }
   if (min==100) break;
   brojOpcija[potez] = 200;

   tr1 = tr; ts1 = ts;
   if (moze(maxr, maxs, &tr1, &ts1, potez)){
	   if (WarnsdorfovKonj(maxr, maxs, tr1, ts1, rbr+1) == 1){
		   return 1;
	   }
   }


   }
	ploca[tr][ts] = 0;
	return 0;
}


int konj(int maxr, int maxs, int tr, int ts, int rbr){
	int potez, tr1, ts1;
	//printf("\npokusavam %d %d %d",rbr, tr, ts);
	ploca[tr][ts] = rbr;
	if (rbr == maxr * maxs){		
		return 1;
	}
	for (potez = 0; potez < 8; potez++){
		tr1 = tr; ts1 = ts;
		if (moze(maxr, maxs, &tr1, &ts1, potez)){
			if (konj(maxr, maxs, tr1, ts1, rbr+1) == 1){
				return 1;
			}
		}		
	}
	ploca[tr][ts] = 0;
	return 0;
}

int main(){
	int r, s, i, j;
   printf("\nUpisite broj redaka i stupaca:");
	scanf("%d %d", &r, &s);




   for(i=0;i<MAXR;i++)
      for(j=0;j<MAXS;j++)
         ploca[i][j]=0;

   printf("\nWarnsdorfov konj...");
   if (WarnsdorfovKonj(r, s, 0, 0, 1) == 1){
      printf("\n\n\n");
		for (i=0; i<r; i++){
			printf("\n");
			for (j=0; j<s; j++){
				printf(" %3d", ploca[i][j]);
			}
		}
	}else{
		printf("\nNe moze :(\n");
	}


   for(i=0;i<MAXR;i++)
      for(j=0;j<MAXS;j++)
         ploca[i][j]=0;

   printf("\nObicni konj ('ne moze' preko 6x6)...");
	if (konj(r, s, 0, 0, 1) == 1){
      printf("\n\n\n");
		for (i=0; i<r; i++){
			printf("\n");
			for (j=0; j<s; j++){
				printf(" %3d", ploca[i][j]);
			}
		}
	}else{
		printf("\nNe moze :(\n");
	}
 system("PAUSE");
	return 0;
}
