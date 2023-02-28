#include<stdio.h>
#include<GL/glut.h>
int x,y;
float th=0.0,trX=0.0,trY=0.0;
int rflag=0,option=0;
void draw_pixel(float x1,float y1)
{
glColor3f(0.0,0.0,1.0);
glPointSize(5.0);
glBegin(GL_POINTS);
glVertex2f(x1,y1);
glEnd();
}

void triangle()
{
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(100,100);
glVertex2f(250,400);
glVertex2f(400,100);
glEnd();
}

void display()
{
glClear(GL_COLOR_BUFFER_BIT);
glLoadIdentity();
if(rflag==1)
{
trX=0.0;
trY=0.0;
th+=0.1;
draw_pixel(0.0,0.0);
}
if(rflag==1)
{
trX=0.0;
trY=0.0;
th+=0.1;
draw_pixel(0.0,0.0);
}
if(rflag==2)
{
trX=x;
trY=y;
th+=0.1;
draw_pixel(x,y);
}
glTranslatef(trX,trY,0.0);
glRotatef(th,0.0,0.0,1.0);
glTranslatef(-trX,-trY,0.0);
triangle();
glutPostRedisplay();

}

void myInit()
{
glClearColor(0.0,0.0,0.0,1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-500.0,500.0,-500.0,500.0,1,-1);
glMatrixMode(GL_MODELVIEW);
}

void rotatemenu(int option)
{
if(option==1)
rflag=1;
if(option==2)
rflag=2;
if(option==3)
rflag=3;
}

int main(int argc,char **argv)
{
printf("enter the fixed point (x,y) for rotation");
scanf("%d%d",&x,&y);
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
glutInitWindowSize(500,500);
glutInitWindowPosition(0,0);
glutCreateWindow("create and rotate triangle");
myInit();
glutDisplayFunc(display);
glutCreateMenu(rotateMenu);
glutAddMenuEntry("Rotate around origin",1);
glutAddMenuEntry("Rotate around fixed point",2);
glutAddMenuEntry("stop rotation",3);
glutAttachMenu(GLUT_RIGHT_BUTTON);
glutMainLoop();
}





