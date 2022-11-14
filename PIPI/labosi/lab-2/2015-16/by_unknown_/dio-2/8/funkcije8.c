void brojacGranicnihZnakova(char *znNiz, char lijevi, char desni, int *brLijevih, int *brDesnih)
{
	int i = 0;
	while (*(znNiz + i) != '\0') {
		if (*(znNiz + i) == lijevi)
			++(*brLijevih);
		else if (*(znNiz + i) == desni)
			++(*brDesnih);
		++i;
	}
}

int izrazJeIspravan(char *znNiz, char lijevi, char desni)
{
	int brDesnih = 0, brLijevih = 0;
	brojacGranicnihZnakova(znNiz, lijevi, desni, &brLijevih, &brDesnih);
	if (brDesnih == brLijevih)
		return 1;
	else
		return 0;
}