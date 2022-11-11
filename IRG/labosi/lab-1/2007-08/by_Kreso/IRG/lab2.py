from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *

class Brid:
    def __init__(self,x0,y0,x1,y1):
        self.a=y0-y1
        self.b=-x0+x1
        self.c=x0*y1-x1*y0
        self.lijevi=(y0 >= y1)
        
    def sijecisteX(self,y):
        return float(-self.b*y-self.c)/self.a

tocke=[]
prozor=[]
bojati=True
bridovi=[]
miny=0
maxy=0

def obojaj():
    glColor3f(1,0,0)
    glBegin(GL_POINTS)

    for y in range(miny,maxy):
        #x=bridovi[2].sijecisteX(y)
        #glVertex2f(x,y)
        minx,maxx=getminmaxX(y)
        for x in range(int(minx),int(maxx)):
            glVertex2i(x,y)
    glEnd()

def getminmaxX(y):
    dmin,lmax=100000, -100000
    for i in bridovi:
        if i.a != 0:
            x=i.sijecisteX(y)
            if i.lijevi and x > lmax: lmax=x
            if not i.lijevi and x < dmin: dmin=x
    return lmax,dmin

def jelTockaUPoligonu(x,y):
    for b in bridovi:
        if b.a*x+b.b*y+b.c < 0: return False
    return True

def generirajBridove():
    global bridovi,miny,maxy
    bridovi=[]
    if len(tocke) < 3: return
    miny=maxy=tocke[0][1]
    for i in range(0,len(tocke)):
        if tocke[i][1] < miny: miny=tocke[i][1]
        if tocke[i][1] > maxy: maxy=tocke[i][1]
        try:
            bridovi.append(Brid(tocke[i][0],tocke[i][1],tocke[i+1][0],tocke[i+1][1]))
        except IndexError:
            bridovi.append(Brid(tocke[i][0],tocke[i][1],tocke[0][0],tocke[0][1]))

def draw():
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)

    if len(tocke) > 2:
        if bojati:
            obojaj()
        glColor3f(0,0,0)
        glBegin(GL_LINE_LOOP)
        for i in tocke:
            glVertex2i(i[0],i[1])
        glEnd()    
    glFlush()

def idle():
    global angle
    angle += 2.0
    glutPostRedisplay()

def kbd(k, x, y):
    global tocke
    if ord(k) == 27: # Escape
        sys.exit(0)
    if k == 'c':
        tocke=[]
        reshape(prozor[0],prozor[1])
        print 'brisem canvas'
    if k == 'b':
        global bojati
        bojati=True
        print 'bojam poligon'
        draw()

def mouse(button,state,x,y):
    global tocke
    if button == GLUT_LEFT_BUTTON and state == GLUT_DOWN:
        tocke.append((x,y))
        print 'zadana tocka (%i,%i)' % (x,y)
        generirajBridove()
        draw()
        

    elif button == GLUT_RIGHT_BUTTON and state == GLUT_DOWN:
        ret=jelTockaUPoligonu(x,y)
        if ret: print 'tocka (%i,%i) je unutar poligona' % (x,y)
        else: print 'tocka (%i,%i) nije unutar poligona' % (x,y)


def reshape(width, height):
    global prozor
    prozor=[width,height]
    h = float(height) / float(width)
    glViewport(0, 0, width, height)
    glMatrixMode(GL_PROJECTION)
    glLoadIdentity()
    gluOrtho2D(0, width, height, 0)
    glClearColor( 1., 1., 1., 0.)
    glClear( GL_COLOR_BUFFER_BIT )
    glPointSize(1.0)
    glColor3f(0., 0., 0.)
    glFlush()


glutInit(sys.argv)
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB)
glutInitWindowSize(500,500)
glutInitWindowPosition(100,100)

window = glutCreateWindow("Glut OpenGL Linija")
glutReshapeFunc(reshape)
glutDisplayFunc(draw)
glutMouseFunc(mouse)
glutKeyboardFunc(kbd)
print "Lijevom tipkom misa zadaj tocke - algoritam Bresenham-a"
print "Tipke r, g, b, k mijenjaju boju."

glutMainLoop()
