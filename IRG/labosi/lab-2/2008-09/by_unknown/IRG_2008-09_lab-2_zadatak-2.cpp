#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
#include <malloc.h>

#include <gl/Gl.h>
#include <gl/Glu.h>
#include <gl/glut.h>

#define MAX 100L

float Xo, Yo, Zo;
float Xg, Yg, Zg;
int N = 4;

int Xv[MAX], Yv[MAX], Zv[MAX];
double *Vrhovi = NULL;
int *Poligoni = NULL;
int BrVrhova = 0, BrPoligona = 0;
bool flag = false;

GLuint window; 
GLuint sub_width = 512, sub_height = 512;

void myDisplay();
void myReshape(int width, int height);
void myMouse(int button, int state, int x, int y);
void myKeyboard(unsigned char theKey, int mouseX, int mouseY);

void UcitajOcisteiGlediste();
void Pogled();
void UcitajObjekt(double **Vrhovi, int **Poligoni, char *path);
void UpisiVrijednosti(char *red, void *mat);

void myDisplay() 
{
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glFlush();
}

void myReshape(int width, int height) 
{
        sub_width = width;                       // promjena sirine prozora
    sub_height = height;                     // promjena visine prozora

    glViewport(0, 0, sub_width, sub_height); // otvor u prozoru
        glMatrixMode(GL_PROJECTION);             // matrica projekcije
        glLoadIdentity();                        // jedinicna matrica
        gluOrtho2D(0, sub_width, 0, sub_height); // okomita projekcija
        glClearColor( 1.0f, 1.0f, 1.0f, 0.0f );  // boja pozadine
        glClear( GL_COLOR_BUFFER_BIT );          // brisanje pozadine
        glPointSize(1.0);                        // postavi velicinu tocke
        glColor3f(0.0f, 0.0f, 0.0f);             // postavi boju
}

void myMouse(int button, int state, int x, int y) 
{
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
        {
                if (flag == false) 
                {
                        Pogled();
                        flag = true;
                }
                glFlush();
        } else  // Desna tipka - brise canvas. 
        if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) 
        {
                myReshape(sub_width, sub_height);
        }
}

void myKeyboard(unsigned char theKey, int mouseX, int mouseY) 
{
        switch (theKey) 
        {
                case 'r':
                        glColor3f(1,0,0);
                break;
                case 'g':
                        glColor3f(0,1,0);
                break;
                case 'b':
                        glColor3f(0,0,1);
                break;
                case 'k':
                        glColor3f(0,0,0);
        }
        glFlush();
}

void UcitajOcisteiGlediste() 
{
        FILE *fp;
        
		  char path [101];

		  printf("Datoteka ocista i gledista: ");
		  scanf("%s%*c", path);

        if ((fp = fopen(path, "r")) == NULL) 
        {
                printf("Greska kod otvaranja datoteke!\n");
                getch();
                exit(0);
        }
        
        fscanf(fp, "%f %f %f\n", &Xo, &Yo, &Zo);
        fscanf(fp, "%f %f %f\n", &Xg, &Yg, &Zg);
        fclose(fp);
        
		  printf("Datoteka objekta: ");
		  scanf("%s%*c", path);

        UcitajObjekt(&Vrhovi, &Poligoni, path);
}

void Pomnozi(double *matrica1, double *matrica2, double *rezultat, int N) 
{
        for (int i=0; i<N; i++) 
        {
                for (int j=0; j<N; j++) 
                {
                        double suma = 0.0;
                        for (int k=0; k<N; k++) 
                        {
                                suma += matrica1[i*N + k] * matrica2[k*N + j];
                        }
                        rezultat[i*N + j] = suma;
                }
        }
}

void PomnoziSVektorom(double *vektor, double *matrica, double *rezultat, int N) 
{
        for (int i=0; i<N; i++) 
        {
                double suma = 0.0;
                for (int j=0; j<N; j++) 
                {
                        suma += vektor[j] * matrica[j*N + i];
                }
                rezultat[i] = suma;
        }
}

void KopirajU(double *matricaIzv, double *matricaOdr, int N) 
{
        for (int i=0; i<N; i++) 
        {
                for (int j=0; j<N; j++) 
                {
                        matricaOdr[i*N + j] = matricaIzv[i*N + j];
                }
        }
}

// pogled
void Pogled() {
        double T1[4][4]={0.0}, T2[4][4]={0.0}, T3[4][4]={0.0}, T4[4][4]={0.0}, T5[4][4]={0.0};
        double T[4][4]={0.0};
        double P[4][4]={0.0};

        double Xg1, Yg1, Zg1;
        double Xg2, Yg2, Zg2;
        double H;
        
        for (int i=0; i<N; i++) T1[i][i] = 1.0;
        T1[3][0] = -Xo;
        T1[3][1] = -Yo;
        T1[3][2] = -Zo;
        
        Xg1 = Xg - Xo;
        Yg1 = Yg - Yo;
        Zg1 = Zg - Zo;
        T2[2][2] = T2[3][3] = 1.0;
        T2[0][0] = T2[1][1] = Xg1/sqrt(pow(Xg1, 2.0) + pow(Yg1, 2.0));
        T2[1][0] = Yg1/sqrt(pow(Xg1, 2.0) + pow(Yg1, 2.0));
        T2[0][1] = -T2[1][0];
        
        Xg2 = sqrt(pow(Xg1, 2.0) + pow(Yg1, 2.0));
        Yg2 = 0.0;
        Zg2 = Zg1;
        T3[1][1] = T3[3][3] = 1.0;
        T3[0][0] = T3[2][2] = Zg2/sqrt(pow(Xg2, 2.0) + pow(Zg2, 2.0));
        T3[0][2] = Xg2/sqrt(pow(Xg2, 2.0) + pow(Zg2, 2.0));
        T3[2][0] = -T3[0][2];
        
        T4[1][0] = T4[2][2] = T4[3][3] = 1.0;
        T4[0][1] = -1.0;
        
        T5[0][0] = -1.0;
        T5[1][1] = T5[2][2] = T5[3][3] = 1.0;
        
        Pomnozi(&T1[0][0], &T2[0][0], &T[0][0], N);
        KopirajU(&T[0][0], &T2[0][0], N);
        Pomnozi(&T2[0][0], &T3[0][0], &T[0][0], N);
        KopirajU(&T[0][0], &T3[0][0], N);
        Pomnozi(&T3[0][0], &T4[0][0], &T[0][0], N);
        KopirajU(&T[0][0], &T4[0][0], N);
        Pomnozi(&T4[0][0], &T5[0][0], &T[0][0], N);
        
        double Vrh[4], TransVrh[4];

        for (int i=0; i<BrVrhova; i++) 
        {
                Vrh[0] = Vrhovi[i*3];
                Vrh[1] = Vrhovi[i*3 + 1];
                Vrh[2] = Vrhovi[i*3 + 2];
                Vrh[3] = 1.0;
        
                PomnoziSVektorom(&Vrh[0], &T[0][0], &TransVrh[0], N);
                
                Vrhovi[i*3] = TransVrh[0]/TransVrh[3];
                Vrhovi[i*3 + 1] = TransVrh[1]/TransVrh[3];
                Vrhovi[i*3 + 2] = TransVrh[2]/TransVrh[3];
        }
        
        H = sqrt(pow((double)Xo-Xg, 2.0) + pow((double)Yo-Yg, 2.0) + pow((double)Zo-Zg, 2.0));
        P[0][0] = P[1][1] = 1.0;
        P[2][3] = 1.0/H;
        
        for (int i=0; i<BrPoligona; i++) 
        {               
                for (int j=0; j<3; j++) 
                {
                        int v = Poligoni[3*i + j];
                        double X0 = Vrhovi[3*v]*100;
                        double Y0 = Vrhovi[3*v + 1]*100;
                        double Z0 = Vrhovi[3*v + 2];
                        
                        int Xp1 = (int)(X0/Z0*H);
                        int Yp1 = (int)(Y0/Z0*H);
                        
                        v = Poligoni[3*i + (j+1)%3];
                        X0 = Vrhovi[3*v]*100;
                        Y0 = Vrhovi[3*v + 1]*100;
                        Z0 = Vrhovi[3*v + 2];
                        
                        int Xp2 = (int)(X0/Z0*H);
                        int Yp2 = (int)(Y0/Z0*H);
                        
                        glBegin(GL_LINES);
                        {
                                glVertex2i((Xp1+sub_width)/2, (sub_height-Yp1)/2);
                                glVertex2i((Xp2+sub_width)/2, (sub_height-Yp2)/2);
                        }
                        glEnd();
                }
        }
}

void UcitajObjekt(double **Vrhovi, int **Poligoni, char *path) 
{
        FILE *fp;
        char red[512] = {0};
        
        if (path == NULL) 
        {
                *Vrhovi = NULL;
                printf("Nije zadana datoteka\n");
                return;
        }
        
        if ((fp = fopen(path,"r")) == NULL) 
        {
                *Vrhovi = NULL;
                printf("Greska kod otvaranja!\n");
                return;
        }
        
        while (fscanf(fp, "%[^\n]\n", red) == 1) 
        {
                if (red[0] == 'v') BrVrhova++;
                else if (red[0] == 'f') BrPoligona++;
        }
        
        rewind(fp);
        
        *Vrhovi = (double *)malloc(BrVrhova * 3 * sizeof(double));
        *Poligoni = (int *)malloc(BrPoligona * 3 * sizeof(int));
        
        int pozVrha = 0, pozPol = 0;
        while (fscanf(fp, "%[^\n]\n", red) == 1) 
        {
                if (red[0] == 'v') 
                {
                        UpisiVrijednosti(red, (void *)&(*Vrhovi)[3*pozVrha]);
                        pozVrha++;
                } 
                else
                if (red[0] == 'f') 
                {
                        UpisiVrijednosti(red, (void *)&(*Poligoni)[3*pozPol]);
                        pozPol++;
                }
                
        }
        fclose(fp);
}

void UpisiVrijednosti(char *red, void *mat) 
{
        if (red[0] == 'v') 
        {
                double *b[3] = {(double *)mat, (double *)mat+1, (double *)mat+2};
                
                red = red + 2;
                int brojac = 0;
                while (brojac < 3) 
                {
                        int charBr = 0;
                        char *pom = red;
                        while (*pom != ' ' && *pom != '\0') 
                        {
                                pom = pom + 1;
                                charBr++;
                        }
                        char temp[30] = {0};
                        strncpy(temp, red, charBr);
                        *b[brojac] = atof(temp);
                        red = pom + 1;
                        brojac++;
                }       
        } 
        else
        if (red[0] == 'f') 
        {
                int *b[3] = {(int *)mat, (int *)mat+1, (int *)mat+2};
                
                red = red + 2;
                int brojac = 0;
                while (brojac < 3) 
                {
                        int charBr = 0;
                        char *pom = red;
                        while (*pom != ' ' && *pom != '\0') 
                        {
                                pom = pom + 1;
                                charBr++;
                        }
                        char temp[30] = {0};
                        strncpy(temp, red, charBr);
                        *b[brojac] = atoi(temp) - 1;
                        red = pom + 1;
                        brojac++;
                }
        }
}

int main(int argc, char ** argv) {
        UcitajOcisteiGlediste();

        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(sub_width,sub_height);
        glutInitWindowPosition(100,100);
        glutInit(&argc, argv);

        window = glutCreateWindow("Glut OpenGL");
        glutReshapeFunc(myReshape);
        glutDisplayFunc(myDisplay);
        glutMouseFunc(myMouse);
        glutKeyboardFunc(myKeyboard);

        glutMainLoop(); 
    return 0;
}