void odredidvoranu(int *sifdvorane, int brdvorana, char *nazdat){
	int i;
	char c;
	i=sifdvorane[rand()%brdvorana];
	itoa(i, nazdat, 10);
	strcat(nazdat, ".txt");
}