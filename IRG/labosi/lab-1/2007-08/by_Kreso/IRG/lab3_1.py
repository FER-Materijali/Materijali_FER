from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *
import math

prozor=[]
eps=m=0
u_min=u_max=v_min=v_max=0.
x_max=y_max=0

def read(filename):
    global eps,m,u_min,u_max,v_min,v_max
    f=open(filename)
    eps=float(f.readline())
    m=int(f.readline())
    u_min=float(f.readline())
    u_max=float(f.readline())
    v_min=float(f.readline())
    v_max=float(f.readline())
    f.close()

def project(x,y):
    u=float(u_max-u_min)*x/x_max+u_min
    v=float(v_max-v_min)*y/y_max+v_min
    return u,v

def draw():
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
    glBegin(GL_POINTS)
    for y in range(0,y_max):
        for x in range(0,x_max):
            u,v=project(x,y)
            k=-1
            r=0.
            c_real=u; c_imag=v
            z_real=0.; z_imag=0.
            # z*z=(x+yi)^2=(x*x+2x*yi-y*y)
            while k < m and r < eps:
                k+=1
                zx=z_real; zy=z_imag
                z_real=zx*zx-zy*zy+c_real
                z_imag=2*zx*zy+c_imag
                r=math.sqrt(z_real*z_real+z_imag*z_imag)
            if k < m/4.:
                glColor3f(k*4/m,0,0)
            elif k < 2*m/4.:
                glColor3f(1,(k-m/4.)*4/m,0)
            elif k < 3*m/4.:
                glColor3f(1-(k-2*m/4.)*4/m,1,0)
            else:
                glColor3f(0,1,(k-3*m/4.)*4/m)
            glVertex2i(x,y)
    glEnd()
    glFlush()

def idle():
    glutPostRedisplay()

def kbd(k, x, y):
    if ord(k) == 27: # Escape
        sys.exit(0)
def reshape(width, height):
    global prozor,x_max,y_max
    x_max=width; y_max=height
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

read('mandelbrot.txt')
glutInit(sys.argv)
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB)
glutInitWindowSize(500,500)
glutInitWindowPosition(100,100)

window = glutCreateWindow("Glut")
glutReshapeFunc(reshape)
glutDisplayFunc(draw)
glutKeyboardFunc(kbd)

glutMainLoop()
