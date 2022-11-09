#include<stdio.h>
#include<stdlib.h>

double pi(int n)								//n je broj iteracija, sto je veci, to je nas pi precizniji.
{												//Dobro proucite formulu da bi dobro skuzili zadatak, ova rekurzija ide od posljednjeg clana prema prvom
	if(n-1)										//Dok je n veci od 1, ista fora kao i u Z1
	{
		if(n%2)									//Ako smo na neparnom clanu, 1., 3. ili 5. itd.,
		return 4.0/(n*2 - 1) + pi(--n);			//onda je on sa + predznakom, i zovemo prethodni clan, u slucaju 3. i 5. - 2. i 4. clan
		else									//Ako smo na parnom clanu (n%2 = 0), onda je trenutni clan sa - predznakom, i zovemo prethodni clan
		return -4.0/(n*2 - 1) + pi(--n);		//Razlog ovo 4/ je zato sto je formula za pi/4. Ako sve pomnozimo sa 4, dobivamo formulu za pi.
	}
	else
	return 4.0;									//Prvi clan je uvijek 4.0. Radje napisite 4.0 da ne bi bilo problema sa returnom (vracamo double). Oni koji su ikad radili u C# znaju struggle.
}

void spc(int x)
{
     while(x--)
     printf("\n");
}

int main()
{
    int i, n;
    float *A;
	
	printf("Unesite cijelobrojnu velicinu polja: ");
	scanf("%d", &n);
	spc(2);
	
	A = (float*)malloc(n * sizeof(float));
	
	printf("Clanovi polja su:");
	
	for(i = 0; i < n; i++)
	{
		if(i%15 == 0)							//Razlog ovome je format, u jednom retku ce ostaviti 15 proracunatih pi-eva
		spc(1);
		
		A[i] = pi(i+1);							//Na 0. clan dolazi pi(1), jer je argument broj clanova.
		printf("%f ", A[i]);					//Npr. pi(1) je na A[0]. Nas indeks ne predstavlja argument n.
		
	}
	
	free(A);									//Ako vec niste shvatili, ovo je OBAVEZNO za alokacije!!!!!

    spc(2);
    system("pause");
    return 0;
}
