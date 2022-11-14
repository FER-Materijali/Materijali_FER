#include <GL/glut.h>

/* Kako bi se maksimalizirala efikasnost u izvodjenju programa,
 * sve operacije koje se pozivaju jednom (npr., odabir projekcije ili 
 * boje pozadine) navode se u funkciji init(). Operacije koje sluze 
 * za iscrtavanje scene (pogotovo ako se ono vrsi vise puta) se navode 
 * u funkciji display() (registriranoj GLUT callback funkciji). 
 */

void display(void)
{
// brisanje sadrzaja spremnika boje 
	glClear (GL_COLOR_BUFFER_BIT);

// odabir bijele boje za crtanje kvadrata	
	glColor3f (1.0, 1.0, 1.0);

/* crtanje poligona (kvadrata) sa 
 * sljedecim vrhovima: 
 * (0.25, 0.25, 0.0), (0.75, 0.25, 0.0)
 * (0.75, 0.75, 0.0), (0.25, 0.75, 0.0)  
 */    
	glBegin(GL_LINE_LOOP);
        glVertex3f (0.25, 0.25, 0.0);
        glVertex3f (0.75, 0.25, 0.0);
        glVertex3f (0.75, 0.75, 0.0);
        glVertex3f (0.25, 0.75, 0.0);
	glEnd();

// pocetak obradjivanja naredbi 
    glFlush ();
}

void init (void) 
{
// odabir boje kojom se iscrtava pozadina prozora        
    glClearColor (0.0, 0.0, 0.0, 0.0);

/* inicijalizacija parametara za podesavanje 
 * projekcijskog volumena
 */ 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

/* Deklaracija inicijalne velicine prozora, njegovog polozaja na 
 * ekranu i prikaznog moda (jednostruki spremnik i RGBA).  
 * Otvaranje prozora sa porukom "hello" kao naslovom.  
 * Poziv inicijalizacijske funkcije init().
 * Registracija "callback" funkcije display(). 
 * Ulazak u glavnu petlju ( glutMainLoop() ) u kojoj se vrsi obrada 
 * dogadjaja.
 */
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (800, 800); 
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("hello");
    init ();
    glutDisplayFunc(display); 
    glutMainLoop();
    return 0;//ISO C zahtijeva od funkcije "main" da vrati "int" vrijednost
}

