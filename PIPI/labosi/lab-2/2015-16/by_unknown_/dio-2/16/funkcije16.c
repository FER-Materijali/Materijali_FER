void minMax(int matrica[][20], int red, int stup, int *min, int * max)
{
	int i, j;
	*min = matrica[0][0];
	*max = matrica[0][0];
	for (i = 0; i < red; ++i) {
		for (j = 0; j < stup; ++j) {
			if (matrica[i][j] > *max)
				*max = matrica[i][j];
			if (matrica[i][j] < *min)
				*min = matrica[i][j];
		}
	}
}

int dobreDimenzije(int maxRed, int maxStup, int red, int stup)
{
	if (red > maxRed || stup > maxStup)
		return 0;
	else
		return 1;
}