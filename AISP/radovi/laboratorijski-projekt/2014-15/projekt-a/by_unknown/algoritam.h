/* 
	algoritam.h - zaglavlje s funkcijama koje enkapsuliraju algoritam pretrage 
	datoteke za trazenim blokom te funkciju koja definira naziv izlazne datoteke
*/

/*
	U datoteci zadanoj tokom podataka ulaz trazi blok kojem pripada zapis 
	s imenom zadanim argumentom ime_prezime. Implementira binarno pretrazivanje
	rekurzivnim pozivima.
*/
long nadji_blok_r(char *ime_prezime, FILE *ulaz, long lijevo, long desno);

/*
	Wrapper funkcija oko nadji_blok_r, osigurava ispravan prvi poziv rekurzivne
	nadji_blok_r funkcije s adresama prvog i posljednjeg bloka u datoteci.
*/
long nadji_blok(char *ime_prezime, FILE *ulaz);

/*
	Inicijalizacija pretrage. U prvom dijelu projekta ova funkcija ima banalnu
	implementaciju - ne cini nista.
*/
void inicijaliziraj(FILE *ulaz);

/*
	Vraca naziv izlazne datoteke.
*/
char *izl_naziv();
