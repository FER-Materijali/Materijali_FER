#include<stdio.h>

int main()
{
	int i, broj_ucitanih_znakova = 0, pv = 0, broj_varijabla=0, o = 0, popunjenost_registara = -1, prvi_znak = 1, vrijednost, broj_retka=0, R13 = 8;
	char *ulazni_niz, *popis_varijabla, *izlazni_niz, operand[11], znak, posto = '\%';
	FILE *fp, *fp2;

	ulazni_niz = (char *)malloc(sizeof(char));
	popis_varijabla = (char *)malloc(sizeof(char));

	printf("Upiši aritmetièki izraz zadan u postfiks notaciji (operande odvojiti razmakom): ");
	do
	{
		scanf("%c", &ulazni_niz[broj_ucitanih_znakova++]);
		ulazni_niz = (char *)realloc(ulazni_niz, (broj_ucitanih_znakova+1)*sizeof(char));
	}
	while(ulazni_niz[broj_ucitanih_znakova-1] != '\n');

	fp = fopen("sk.a", "w");
	if(fp == NULL)
	{
		printf("Nisam uspio otvoriti datoteku za pisanje.");
		exit(0);
	}

	ulazni_niz[broj_ucitanih_znakova-1] = 0;
	fprintf(fp, "\;%s\n", ulazni_niz);
	fprintf(fp,"\t \`ORG 0\n");
	R13 += 8;

	for(i=0; i<broj_ucitanih_znakova; i++)
	{
		if(ulazni_niz[i] >= '0' && ulazni_niz[i] <= '9')
			if(prvi_znak == 1)
				operand[o++] = ulazni_niz[i];
			else
			{
				popis_varijabla[pv++] = operand[o++] = ulazni_niz[i];
				popis_varijabla = (char *)realloc(popis_varijabla, (pv+1)*sizeof(char));
			}
		else if(ulazni_niz[i] >= 'A' && ulazni_niz[i] <= 'Z' || ulazni_niz[i] >= 'a' && ulazni_niz[i] <= 'z')
		{
			popis_varijabla[pv++] = operand[o++] = ulazni_niz[i];
			popis_varijabla = (char *)realloc(popis_varijabla, (pv+2)*sizeof(char));
			prvi_znak = 0;
		}
		else if(ulazni_niz[i] == ' ')
		{
			if(pv > 0)
				if(popis_varijabla[pv-1] != 0)
				{
					broj_varijabla++;
					popis_varijabla[pv++] = 0;
				}
			operand[o++] = 0;
			popunjenost_registara++;
			if(operand[0] >= '0' && operand[0] <= '9')
			{
				fprintf(fp,"\tLDR R%d, #%s\n", popunjenost_registara%13, operand);
				R13+=4;
			}
			else
			{
				fprintf(fp,"\tLDR R%d, %s\n", popunjenost_registara%13, operand);
				R13+=4;
			}
			o = 0;
			prvi_znak = 1;
			if(popunjenost_registara%12 == 0 && popunjenost_registara != 0)
			{
				fprintf(fp,"\tSTMIA R13!, {R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12}\n");
				R13 += 4;
			}
		}
		else if(ulazni_niz[i] == '+')
		{
			if(popunjenost_registara%12 == 0 && popunjenost_registara>1)
			{
				fprintf(fp, "\tLDMDB R13!, {R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12}\n");
				fprintf(fp,"\tADD R11, R11, R12\n");
				R13 += 8;
			}
			if(popunjenost_registara%12 == 1 && popunjenost_registara>1)
			{
				fprintf(fp,"\tLDR R1, [R13, #-4]\n");
				fprintf(fp,"\tADD R0, R1, R0\n");
				fprintf(fp,"\tSTR R0, [R13]\n");
				R13 += 12;
			}
			else
			{
				fprintf(fp,"\tADD R%d, R%d, R%d\n", popunjenost_registara%13-1, popunjenost_registara%13-1, popunjenost_registara%13);
				R13 += 4;
			}
			popunjenost_registara --;
		}
		else if(ulazni_niz[i] == '-')
		{
			if(popunjenost_registara%12 == 0 && popunjenost_registara>1)
			{
				fprintf(fp, "\tLDMDB R13!, {R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12}\n");
				fprintf(fp,"\tADD R11, R11, R12\n");
				R13 += 8;
			}
			if(popunjenost_registara%12 == 1 && popunjenost_registara>1)
			{
				fprintf(fp,"\tLDR R1, [R13, #-4]\n");
				fprintf(fp,"\tSUB R0, R1, R0\n");
				fprintf(fp,"\tSTR R0, [R13]\n");
				R13 += 12;
			}
			else
			{
				fprintf(fp,"\tSUB R%d, R%d, R%d\n", popunjenost_registara%13-1, popunjenost_registara%13-1, popunjenost_registara%13);
				R13 += 4;
			}
			popunjenost_registara --;
		}
		else if(ulazni_niz[i] == '*')
		{
			if(popunjenost_registara%12 == 0 && popunjenost_registara>1)
			{
				fprintf(fp, "\tLDMDB R13!, {R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12}\n");
				fprintf(fp,"\tSUB R11, R11, R12\n");
				R13 += 8;
			}
			if(popunjenost_registara%12 == 1 && popunjenost_registara>1)
			{
				fprintf(fp,"\tLDR R1, [R13, #-4]\n");
				fprintf(fp,"\tMUL R0, R1, R0\n");
				fprintf(fp,"\tSTR R0, [R13]\n");
				R13 += 12;
			}
			else
			{
				fprintf(fp,"\tMUL R%d, R%d, R%d\n", popunjenost_registara%13-1, popunjenost_registara%13-1, popunjenost_registara%13);
				R13 += 4;
			}
			popunjenost_registara --;
		}
		else if(ulazni_niz[i] == '/')
		{
			if(popunjenost_registara%12 == 0 && popunjenost_registara>1)
			{
				fprintf(fp, "\tLDMDB R13!, {R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12}\n");
				fprintf(fp,"\tMOV R14, #0\n");
				fprintf(fp,"DIV\n");
				fprintf(fp,"\tCMP R12, R11\n");
				fprintf(fp,"\tBHI KRAJ\n");
				fprintf(fp,"\tSUB R11, R11, R12\n");
				fprintf(fp,"\tADD R14, R14, #1\n");
				fprintf(fp,"\tB DIV\n");
				fprintf(fp,"KRAJ\n");
				fprintf(fp,"\tMOV R11, R14\n");
				R13 += 40;
			}

			if(popunjenost_registara%12 == 1 && popunjenost_registara>1)
			{
				fprintf(fp,"\tLDR R1, [R13, #-4]\n");
				fprintf(fp,"\tMOV R14, #0\n");
				fprintf(fp,"DIV\n");
				fprintf(fp,"\tCMP R0, R1\n");
				fprintf(fp,"\tBHI KRAJ\n");
				fprintf(fp,"\tSUB R1, R1, R0\n");
				fprintf(fp,"\tADD R14, R14, #1\n");
				fprintf(fp,"\tB DIV\n");
				fprintf(fp,"KRAJ\n");
				fprintf(fp,"\tMOV R0, R14\n");
				fprintf(fp,"\tSTR R0, [R13]\n");
				R13 += 44;
			}
			else
			{
				fprintf(fp,"\tMOV R14, #0\n");
				fprintf(fp,"DIV\n");
				fprintf(fp,"\tCMP R%d, R%d\n", popunjenost_registara%13-1, popunjenost_registara%13);
				fprintf(fp,"\tBHI KRAJ\n");
				fprintf(fp,"\tSUB R%d, R%d, R%d\n", popunjenost_registara%13-1, popunjenost_registara%13-1, popunjenost_registara%13);
				fprintf(fp,"\tADD R14, R14, #1\n");
				fprintf(fp,"\tB DIV\n");
				fprintf(fp,"KRAJ\n");
				fprintf(fp,"\tMOV R%d, R14\n", popunjenost_registara%13-1);
				R13 += 36;
			}
			popunjenost_registara --;
		}

	}

	fprintf(fp,"kraj\tSWI\t123456\n");
	R13 +=4;

	if(!(pv == 1 && popis_varijabla[0] == 0))
		for(i=0; i<pv; i++)
		{
			if(i == 0)
				printf("Upiši za varijablu ");
			if(popis_varijabla[i] == 0)
			{
				printf(" vrijednost: ");
				scanf("%d", &vrijednost);
				fprintf(fp,"\tDW \%cD%d\n", posto, vrijednost);
				R13 += 4;
				broj_varijabla--;
				if(broj_varijabla > 0)
					printf("Upiši za varijablu ");
			}
			else
			{
				printf("%c", popis_varijabla[i], i);
				fprintf(fp,"%c", popis_varijabla[i], i);
			}
		}

	fclose(fp);
	fp = fopen("sk.a", "r");
	fp2 = fopen("sk1.a", "w");
	while(fscanf(fp, "%c", &znak)!=EOF)
	{
		if(znak == '\n')
			broj_retka++;
		if(broj_retka == 2)
		{
			fprintf(fp2, "\n\tMOV R13, \#%cD%d", posto, R13);
			broj_retka = 3;
		}
		if(broj_retka>0 && !(broj_retka==1 && znak == '\n'))
			fprintf(fp2, "%c", znak);
	}
	fclose(fp);
	fclose(fp2);

	return 0;
}