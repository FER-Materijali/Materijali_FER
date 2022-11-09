#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void MergeF (FILE *f1, FILE *f2, FILE *fsort){
	char buf1[4096], buf2[4096], *pb1, *pb2;
	pb1 = fgets(buf1, 4096, f1);
	pb2 = fgets(buf2, 4096, f2);
	while (pb1 || pb2) {
		/* ako u obje datoteke još ima zapisa i 
		   zapis iz prve datoteke manji je od zapisa iz druge ili
		   u prvoj datoteci još ima, a u drugoj više nema zapisa */
		if ((pb1 && pb2 && strcmp(pb1, pb2) <= 0) || (pb1 && !pb2)) {
			fputs(pb1, fsort);
			pb1 = fgets(buf1, 4096, f1);
		}
		/* ako u obje datoteke još ima zapisa i 
		   zapis iz prve datoteke veæi je od zapisa iz druge ili
		   u prvoj datoteci nema, a u drugoj još ima zapisa */
		if ((pb1 && pb2 && strcmp(pb1, pb2) > 0) || (!pb1 && pb2)) {
			fputs(pb2, fsort);
			pb2 = fgets(buf2, 4096, f2);
		}

	}
}
int main() {
	FILE *f1,*f2,*fsort;
	if ((f1 = fopen ("dat1.txt", "r"))==NULL){
		printf("Pogreska kod otvaranja datoteke dat1.txt");
		exit (1);
	}
	if ((f2 = fopen ("dat2.txt", "r"))==NULL){
		printf("Pogreska kod otvaranja datoteke dat2.txt");
		return 1;
	}
	if ((fsort = fopen ("sort.txt", "w"))==NULL){
		printf("Pogreska kod otvaranja datoteke sort.txt");
		return 1;
	}
   MergeF(f1, f2, fsort);
   fclose(f1); fclose(f2); fclose(fsort);	
   return 0;
}

