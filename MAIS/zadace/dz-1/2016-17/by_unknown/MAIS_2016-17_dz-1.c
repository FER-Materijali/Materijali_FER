#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	unsigned char crvena, zelena, plava;
} pixel;

typedef struct {
     int x, y;
     pixel *podatak;
} PPMslika;

int main(int argc, char* argv[])
{
	//constant tables
	const float K1TABLE[8][8] = 
	{
		{16, 11, 10, 16, 24, 40, 51, 61},
		{12, 12, 14, 19, 26, 58, 60, 55},
		{14, 13, 16, 24, 40, 57, 69, 56},
		{14, 17, 22, 29, 51, 87, 80, 62},
        {18, 22, 37, 56, 68, 109, 103, 77},
		{24, 35, 55, 64, 81, 104, 113, 92},
        {49, 64, 78, 87, 103, 121, 120, 101},
        {72, 92, 95, 98, 112, 100, 103, 99}
	};
	const float K2TABLE[8][8] =
	{
		{17, 18, 24, 47, 99, 99, 99, 99},
        {18, 21, 26, 66, 99, 99, 99, 99},
		{24, 26, 56, 99, 99, 99, 99, 99},
		{47, 66, 99, 99, 99, 99, 99, 99},
		{99, 99, 99, 99, 99, 99, 99, 99},
		{99, 99, 99, 99, 99, 99, 99, 99},
        {99, 99, 99, 99, 99, 99, 99, 99},
		{99, 99, 99, 99, 99, 99, 99, 99}
	};
	//variable declaration
	char *imeSlike, *imeIzlazne;
	char buffer[16];
	FILE *ulaznaDatoteka, *izlaznaDatoteka;
	imeSlike = argv[1];
	int blok = atoi(argv[2]);
	int broj, rgb_comp;
	unsigned char c;
	PPMslika *slika;
	imeIzlazne = argv[3];
	
	//open output file asap because reasons
	izlaznaDatoteka = fopen(imeIzlazne, "w+");
	
	if (izlaznaDatoteka == NULL)
	{
		printf("Failed to open output file\n");
		return 0;
	}
	
	ulaznaDatoteka = fopen(imeSlike,  "rb");
	if (ulaznaDatoteka == NULL)
	{
		printf("Failed to open input file\n");
		return 0;
	}
	
	// check image format
	if (!fgets(buffer, sizeof(buffer), ulaznaDatoteka))
	{
		printf("Error occured trying to read image data\n");
		return 0;
	}
	
	if (buffer[0] != 'P' || buffer[1] != '6')
	{
		printf("Image is in wrong format- must be 'P6'\n");
		return 0;
	}
	
	//allocate memory for image
	slika = (PPMslika*) malloc(sizeof(PPMslika));
	//check for comments
	c = getc(ulaznaDatoteka);
    while (c == '#') 
	{
    while (getc(ulaznaDatoteka) != '\n');
         c = getc(ulaznaDatoteka);
    }

    ungetc(c, ulaznaDatoteka);
	
	//read image size information
	fscanf(ulaznaDatoteka, "%d %d", &slika->x, &slika->y);

	//read rgb component
	fscanf(ulaznaDatoteka, "%d", &rgb_comp);
	
	if (rgb_comp != 255)
	{
		printf("Image does not have 8-bit components\n");
		return 0;
	}
	
	while (fgetc(ulaznaDatoteka) != '\n');	
	//memory allocation for pixel data
	slika->podatak = (pixel*)malloc(slika->x*slika->y*sizeof(pixel));

	//read data from input file
	fread(slika->podatak, 3*slika->x, slika->y, ulaznaDatoteka);
	fclose(ulaznaDatoteka);
	
	int pomak = blok/64;
	int yos = 512*8*pomak;
	int xos = 0;
	int crveno[8][8] = {0};
	int zeleno[8][8] = {0};
	int plavo[8][8] = {0};
	float Y[8][8] = {0};
	float Cb[8][8] = {0};
	float Cr[8][8] = {0};
	int k = 0;
	int i;
	int j;
	for (i =0; i<8; i++)
	{
		for (j = (blok % 64)*8 + yos + xos; j<(blok % 64) * 8 + yos + xos +8; j++)
		{
			crveno[i][k] = slika->podatak[j].crvena;
			zeleno[i][k] = slika->podatak[j].zelena;
			plavo[i][k] = slika->podatak[j].plava;
			
			Y[i][k] = 0.299*crveno[i][k] + 0.587*zeleno[i][k] + 0.114*plavo[i][k] - 128;
			Cb[i][k] = -0.1687*crveno[i][k] - 0.3313*zeleno[i][k] + 0.5*plavo[i][k];
			Cr[i][k] = 0.5*crveno[i][k] - 0.4187*zeleno[i][k] - 0.0813*plavo[i][k];
			++k;
		}
		xos +=512;
		k = 0;
	}
	
	printf("Crvena boja:\n");
    for(i=0;i<8;i++)
	{
            for(j=0;j<8;j++)
			{
                printf("%d  ", crveno[i][j]);
            }
            printf("\n");
    }
    printf("\n\n");

    printf("Zelena boja:\n");
    for(i=0;i<8;i++)
	{
            for(j=0;j<8;j++)
			{
                printf("%d  ", zeleno[i][j]);
            }
            printf("\n");
    }
    printf("\n\n");

    printf("Plava boja:\n");
    for(i=0;i<8;i++)
	{
            for(j=0;j<8;j++)
			{
                printf("%d  ", plavo[i][j]);
            }
            printf("\n");
    }
    printf("\n\n");
	
	printf("Y:\n");
    for(i=0;i<8;i++)
	{
            for(j=0;j<8;j++)
			{
                printf("%3.2f  ", Y[i][j]);
            }
            printf("\n");
    }
    printf("\n\n");

    printf("Cb:\n");
    for(i=0;i<8;i++)
	{
            for(j=0;j<8;j++)
			{
                printf("%3.2f  ", Cb[i][j]);
            }
            printf("\n");
    }
    printf("\n\n");

    printf("Cr:\n");
    for(i=0;i<8;i++)
	{
            for(j=0;j<8;j++)
			{
                printf("%3.2f  ", Cr[i][j]);
            }
            printf("\n");
    }
    printf("\n\n");
	
	//discrete cosine transform
	printf("DCT matrice:\n");
	float dctY[8][8] = {0};
	float dctCb[8][8] = {0};
	float dctCr[8][8] = {0};
	double cu, cv, sivaZona1, sivaZona2, sivaZona3;
	double suma1, suma2, suma3;
	double dct1, dct2, dct3;
	int l;
	
	for(i=0;i<8;++i)
	{
        for(j=0;j<8;++j)
		{
            if (i==0)
				{
                cu = 1.0/sqrt(2.0);
            }
            else 
			{
                cu = 1.0;
            }
            if (j == 0)
			{
                cv=1.0/sqrt(2.0);
            }
            else
			{
                cv=1.0;
            }
            suma1 = 0;
            suma2 = suma1;
            suma3 = suma2;
            for(k=0;k<8;k++)
			{
                for(l=0;l<8;l++)
				{
                    sivaZona1=Y[k][l];
                    sivaZona2=Cb[k][l];
                    sivaZona3=Cr[k][l];
                    dct1 = sivaZona1 * cos((2 * k + 1) * i * M_PI / 16.0) * cos((2 * l + 1) * j * M_PI / 16.0);
                    dct2 = sivaZona2 * cos((2 * k + 1) * i * M_PI / 16.0) * cos((2 * l + 1) * j * M_PI / 16.0);
                    dct3 = sivaZona3 * cos((2 * k + 1) * i * M_PI / 16.0) * cos((2 * l + 1) * j * M_PI / 16.0);
                    suma1 += dct1;
                    suma2 += dct2;
                    suma3 += dct3;
                }
            }
            dctY[i][j]=0.25*cu*cv*suma1;
            dctCb[i][j]=0.25*cu*cv*suma2;
            dctCr[i][j]=0.25*cu*cv*suma3;
        }
    }
	
	printf("dctY:\n");
    for(i=0;i<8;i++)
	{
            for(j=0;j<8;j++)
			{
                printf("%3.2f  ", dctY[i][j]);
            }
            printf("\n");
    }
    printf("\n\n");

    printf("dctCb:\n");
    for(i=0;i<8;i++)
	{
            for(j=0;j<8;j++)
			{
                printf("%3.2f  ", dctCb[i][j]);
            }
            printf("\n");
    }
    printf("\n\n");

    printf("dctCr:\n");
    for(i=0;i<8;i++)
	{
            for(j=0;j<8;j++)
			{
                printf("%3.2f  ", dctCr[i][j]);
            }
            printf("\n");
    }
    printf("\n\n");
	
	//quantisation
	int kY[8][8] = {0};
	int kCb[8][8] = {0};
	int kCr[8][8] = {0};
	
	for (i=0;i<8;i++)
	{
		for (j=0;j<8;j++)
		{
			kY[i][j] = (round)(dctY[i][j]/K1TABLE[i][j]);
			kCb[i][j] = (round)(dctCb[i][j]/K2TABLE[i][j]);
			kCr[i][j] = (round)(dctCr[i][j]/K2TABLE[i][j]);
		}
	}
	
	//write to output file
    for(i=0;i<8;i++)
	{
            for(j=0;j<8;j++)
			{
                fprintf(izlaznaDatoteka, "%d ", kY[i][j]);
            }
            fprintf(izlaznaDatoteka, "\n");
    }
    fprintf(izlaznaDatoteka, "%s ", "\n");
	
    for(i=0;i<8;i++)
	{
            for(j=0;j<8;j++)
			{
                fprintf(izlaznaDatoteka, "%d ", kCb[i][j]);
            }
            fprintf(izlaznaDatoteka, "\n");
    }
    fprintf(izlaznaDatoteka, "%s ", "\n");
	
    for(i=0;i<8;i++)
	{
            for(j=0;j<8;j++)
			{
                fprintf(izlaznaDatoteka, "%d ", kCr[i][j]);
            }
            fprintf(izlaznaDatoteka, "\n");
    }
    fprintf(izlaznaDatoteka, "%s ", "\n");
	
	fclose(izlaznaDatoteka);
	return 0;
}