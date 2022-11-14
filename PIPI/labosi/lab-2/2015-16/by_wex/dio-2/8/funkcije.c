void brojac(char *niz, char lijevi, char desni, int *brlijevih, int *brdesnih) {
	int i;
	for (i=0; *(niz+i)!=0; i++) {
		if (*(niz+i) == lijevi) (*brlijevih)++;
		else if (*(niz+i) == desni) (*brdesnih)++;
	}
	return;
}
int ispravan(char *niz, char lijevi, char desni) {
	int broj_lijevih = 0;
	int broj_desnih = 0;
	brojac(niz, lijevi, desni, &broj_lijevih, &broj_desnih);
	return (broj_desnih == broj_lijevih ? 1 : 0);
}