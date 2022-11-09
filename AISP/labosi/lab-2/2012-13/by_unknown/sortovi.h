#include <stdlib.h>
void bubble_sort(int *niz, int n, int uzlazno){
	int i, bila_zamjena, pom;
	if(uzlazno)
		do{
			bila_zamjena=0;
			for(i=0;i<n-1;i++){
				if(niz[i]>niz[i+1]){
					pom=niz[i];
					niz[i]=niz[i+1];
					niz[i+1]=pom;
					bila_zamjena=1;
				}
			}
			n--;
		}while(bila_zamjena);
	else
		do{
			bila_zamjena=0;
			for(i=0;i<n-1;i++){
				if(niz[i]<niz[i+1]){
					pom=niz[i];
					niz[i]=niz[i+1];
					niz[i+1]=pom;
					bila_zamjena=1;
				}
			}
			n--;
		}while(bila_zamjena);
}

void selection_sort(int *niz, int n, int uzlazno){
	int i, j, najmanji, pom;
	if(uzlazno)
		for(i=0;i<n-1;i++){
			najmanji=i;
			for(j=i+1;j<n;j++){
				if(niz[j]<niz[i] && niz[j]<niz[najmanji])
					najmanji=j;
			}
			pom=niz[i];
			niz[i]=niz[najmanji];
			niz[najmanji]=pom;		
		}
	else
		for(i=n-1;i>=0;i--){
			najmanji=i;
			for(j=i-1;j>=0;j--){
				if(niz[j]<niz[i] && niz[j]<niz[najmanji])
					najmanji=j;
			}
			pom=niz[i];
			niz[i]=niz[najmanji];
			niz[najmanji]=pom;		
		}
}

void selection_sort_rek(int *niz, int n, int uzlazno){
	int pom, i, najmanji;
	if(uzlazno){
		najmanji=0;
		if(n==0)
		return;
	for(i=1;i<n;i++){
		if(niz[i]<niz[0] && niz[i]<niz[najmanji])
			najmanji=i;
	}
	pom=niz[najmanji];
	niz[najmanji]=niz[0];
	niz[0]=pom;
	selection_sort_rek(niz+1, n-1, uzlazno);
	}
	else{
		najmanji=n-1;
	if(n==0)
		return;
	for(i=n-1;i>=0;i--){
		if(niz[i]<niz[n-1] && niz[i]<niz[najmanji])
			najmanji=i;
	}
	pom=niz[najmanji];
	niz[najmanji]=niz[n-1];
	niz[n-1]=pom;
	selection_sort_rek(niz, n-1, uzlazno);

	}
}

void quicksort(int *niz, int n, int uzlazno){
	int i=1, j=n-1, stozer=0, pom;
	if(uzlazno){
		if(i>j)
			return;
		while(i<=j){
			while(niz[j]>niz[stozer])
				j--;
			while(niz[i]<=niz[stozer])
				i++;
			if(i>=j) 
				break;
			else{
				pom=niz[i];
				niz[i]=niz[j];
				niz[j]=pom;
			}
		}
		pom=niz[stozer];
		niz[stozer]=niz[j];
		niz[j]=pom;
		quicksort(niz, j, uzlazno);
		quicksort(niz+j+1, n-j-1, uzlazno);
	}
	else{
		if(i>j)
			return;
		while(i<=j){
			while(niz[j]<niz[stozer])
				j--;
			while(niz[i]>=niz[stozer])
				i++;
			if(i>=j) 
				break;
			else{
				pom=niz[i];
				niz[i]=niz[j];
				niz[j]=pom;
			}
		}
		pom=niz[stozer];
		niz[stozer]=niz[j];
		niz[j]=pom;
		quicksort(niz, j, uzlazno);
		quicksort(niz+j+1, n-j-1, uzlazno);
	}
}

void merge (int niz[], int pompolje[], int lpoz, int dpoz, int desnikraj, int uzlazno) {
	int i, lijevikraj, n, pom;
	if (uzlazno){
		lijevikraj=dpoz-1;
		pom=lpoz;
		n=desnikraj-lpoz+1;
		while (lpoz<=lijevikraj && dpoz<=desnikraj) {
			if (niz[lpoz]<=niz[dpoz]) 
				pompolje[pom++]=niz[lpoz++];
			else 
				pompolje[pom++]=niz[dpoz++];
		}
		while (lpoz<=lijevikraj) 
			pompolje [pom++]=niz[lpoz++];
		while (dpoz<=desnikraj) 
			pompolje [pom++]=niz[dpoz++];
		for (i=0; i<n; i++, desnikraj--)
			niz[desnikraj]=pompolje[desnikraj];
	}
	else{
		lijevikraj=dpoz-1;
		pom=lpoz;
		n=desnikraj-lpoz+1;
		while (lpoz<=lijevikraj && dpoz<=desnikraj) {
			if (niz[lpoz]>=niz[dpoz]) 
				pompolje[pom++]=niz[lpoz++];
			else 
				pompolje[pom++]=niz[dpoz++];
		}
		while (lpoz<=lijevikraj) 
			pompolje [pom++]=niz[lpoz++];
		while (dpoz<=desnikraj) 
			pompolje [pom++]=niz[dpoz++];
		for (i=0; i<n; i++, desnikraj--)
			niz[desnikraj]=pompolje[desnikraj];
	}
}

void divide(int niz[], int pompolje[], int lijevo, int desno, int uzlazno) {
	int sredina;
	if (lijevo<desno){
		sredina=(lijevo+desno)/2;
		divide(niz, pompolje, lijevo, sredina, uzlazno);
		divide(niz, pompolje, sredina+1, desno, uzlazno);
		merge(niz, pompolje, lijevo, sredina+1, desno, uzlazno);
	}
}

void mergesort (int niz[], int n, int uzlazno) {
	int *pompolje;
	pompolje=(int *)malloc(n*sizeof(int));
	divide(niz, pompolje, 0, n-1, uzlazno);
	free (pompolje);
	}
