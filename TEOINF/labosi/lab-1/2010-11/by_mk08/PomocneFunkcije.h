#ifndef _INC_POMOCNE_FUNKCIJE
#define _INC_POMOCNE_FUNKCIJE

unsigned long int MojStrlen(char *string, int pomak)
{
	unsigned long int brojilo = 0;

	while(string[pomak+brojilo] != '\0')
	{
		brojilo++;
	}

	return brojilo;
}

int JeLiPotencijaBroja2(int broj)
{
	int da = 1; //pretpostavljamo da je broj potencija broja 2
	while(broj != 1) // 1 je takoðer potencija broja 2 (2^0)
	{
		if(broj % 2 == 1)
		{
			da = 0;
			break;
		}
		else
		{
			broj /= 2;
		}
	}

	return da;
}

#endif  /* _INC_POMOCNE_FUNKCIJE */