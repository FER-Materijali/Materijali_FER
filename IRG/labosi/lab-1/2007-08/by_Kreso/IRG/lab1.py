from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *

tocke=[]
prozor=[]

def draw():
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
    glFlush()

def idle():
    global angle
    angle += 2.0
    glutPostRedisplay()

def kbd(k, x, y):
    if ord(k) == 27: # Escape
        sys.exit(0)
    if k == 'r':
	glColor3f(1,0,0)
    if k == 'g':
	glColor3f(0,1,0)
    if k == 'b':
	glColor3f(0,0,1)
    if k == 'k':
	glColor3f(0,0,0)
    glRecti(prozor[0]-15, prozor[1]-15, prozor[0], prozor[1])
    glFlush()



def myLine(x0,y0,x1,y1):
    glBegin(GL_LINES)
    glVertex2i(x0,y0+20)
    glVertex2i(x1,y1+20)
    glEnd()
  
    # Bresenham
    steep = abs(y1 - y0) > abs(x1 - x0)
    if steep:
	x0, y0=y0, x0
	x1, y1=y1,x1
    if x0 > x1:
	x0, x1=x1,x0
	y0, y1=y1,y0
    deltax = x1 - x0
    deltay = abs(y1 - y0)
    error = 0.
    deltaerr = float(deltay) / deltax
    y = y0
    if y0 < y1:
	ystep = 1.
    else:
	ystep = -1.
	
    glBegin(GL_POINTS)
    for x in range(x0,x1):
	if steep:
	    glVertex2f(y,x)
	else:
	    glVertex2f(x,y)
	error +=deltaerr
	if error >= 0.5:
	    y +=ystep
	    error-=1.

    glEnd()



def mouse(button,state,x,y):
    if state == GLUT_DOWN:
	print 'click (%i, %i)' % (x,y)
    global tocke
    if button == GLUT_LEFT_BUTTON and state == GLUT_DOWN:
	tocke.append((x,y))
	if len(tocke) == 2:
	    print 'crtam liniju'
	    myLine(tocke[0][0],tocke[0][1],tocke[1][0],tocke[1][1])
	    tocke=[]
	    glFlush()

    elif button == GLUT_RIGHT_BUTTON and state == GLUT_DOWN:
	reshape(prozor[0],prozor[1])
	print 'brisem canvas'


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
