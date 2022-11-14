int brojneslova(char str[]) {
		int neslova = 0;
		int i = 0;
		while(str[i] != '\0') {
			if (!((str[i] >= 'A' && str[i] <= 'Z') ||
				(str[i] >= 'a' && str[i] <= 'z'))) {
					neslova++;
			}
			i++;	
		}
		return neslova;
}

void caesarEncrypt (char *nizUlaz, char *nizIzlaz, int kljucKriptiranja) {
	int i = 0;
	while (nizUlaz[i] != '\0') {
		nizIzlaz[i] = nizUlaz[i];
		if ((nizUlaz[i] >= 'A' && nizUlaz[i] <= 'Z')) {
			nizIzlaz[i] -= 'A';
			nizIzlaz[i] += kljucKriptiranja;
			nizIzlaz[i] %= 26;
			nizIzlaz[i] += 'A';
		} else if ((nizUlaz[i] >= 'a' && nizUlaz[i] <= 'z')) {
			nizIzlaz[i] -= 'a';
			nizIzlaz[i] += kljucKriptiranja;
			nizIzlaz[i] %= 26;
			nizIzlaz[i] += 'a';
		}
		
		i++;
	}
	nizIzlaz[i] = '\0';
}
