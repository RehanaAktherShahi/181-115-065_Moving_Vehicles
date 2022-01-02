#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

GLint b=300;
float  counter=600.0,counter1=1000.0,bc=-260.0,cnt=-300.0,r2=0.0,g2=1.0,b2=1;
int d=1;
void  road();
void  grass();
void  grass2();
void  bus();
void  bus2();
void  truck();

void initOpenGl()
{
    glClearColor(0.2,0.6,0.99,0); //Background Color
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,700,0,500);
    glMatrixMode(GL_MODELVIEW);
}

void wheel(int x,int y)
{
   float th;
   glBegin(GL_POLYGON);
   glColor3f(0,0,0);
   for(int i=0;i<360;i++)
   {
       th=i*(3.1416/180);
       glVertex2f(x+20*cos(th),y+20*sin(th));
   }

   glEnd();

}
void window(int w1,int w2)
{
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(w1,160);
    glVertex2f(w1,185);
    glVertex2f(w2,185);
    glVertex2f(w2,160);
    glEnd();
}
void buswindow(int w1,int w2)
{
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(w1,180);
    glVertex2f(w1,205);
    glVertex2f(w2,205);
    glVertex2f(w2,180);
    glEnd();
}

void road()
{
    glLoadIdentity();
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_POLYGON);
    glVertex2f(0,95);
    glVertex2f(0,260);
    glVertex2f(800,260);
    glVertex2f(800,95);
    glEnd();
}

void grass()
{
    glLoadIdentity();
    glColor3f(0.0,0.5,0.1);
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(0,95);
    glVertex2f(800,95);
    glVertex2f(800,0);
    glEnd();
}

void grass2()
{
    glLoadIdentity();
    glColor3f(0.0,0.5,0.1);
    glBegin(GL_POLYGON);
    glVertex2f(0,260);
    glVertex2f(0,300);
    glVertex2f(800,300);
    glVertex2f(800,260);
    glEnd();
}

void line1()
{
    glLoadIdentity();
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(0,190);
    glVertex2f(150,190);
    glEnd();

}

void line2()
{
    glLoadIdentity();
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(200,190);
    glVertex2f(300,190);
    glEnd();

}

void line3()
{
    glLoadIdentity();
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(350,190);
    glVertex2f(500,190);
    glEnd();

}

void line4()
{
    glLoadIdentity();
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(550,190);
    glVertex2f(700,190);
    glEnd();

}
void car()
{

    glColor3f(1.0, 0.0, 0.0);
   //Bottom Part
   glLoadIdentity();
   counter=counter-0.3;
   glTranslated(counter,100,0.0);
   glScaled(0.5,0.5,0.0);
   glBegin(GL_POLYGON);
   glVertex2f(100,100);
   glVertex2f(100,160);
   glVertex2f(450,160);
   glVertex2f(450,100);

   //Top Part
   glBegin(GL_POLYGON);
   glVertex2f(150,160);
   glVertex2f(200,200);
   glVertex2f(400,200);
   glVertex2f(450,160);

   glEnd();

   window(200,270);
   window(280,330);
   window(340,390);
   wheel(200,100);
   wheel(380,100);

}

void bus()
{

   glLoadIdentity();
   bc=bc+0.4;
   glColor3f(1.0,1.0,1.0);
   glTranslated(bc,180,0.0);

   glScaled(0.4,0.4,0.0);
   glBegin(GL_POLYGON);
   glVertex2f(100,100);
   glVertex2f(100,220);
   glVertex2f(470,220);
   glVertex2f(470,100);
   glEnd();

   buswindow(110,160);
   buswindow(170,220);
   buswindow(230,270);
   buswindow(280,330);
   buswindow(340,390);
   buswindow(400,450);
   wheel(200,100);
   wheel(380,100);

}
void bus2()
{

   glLoadIdentity();
   counter1=counter1-0.3;
   glColor3f(0.0, 0.0, 1.0);
   glTranslated(counter1,100,0.0);

   glScaled(0.4,0.4,0.0);
   glBegin(GL_POLYGON);
   glVertex2f(100,100);
   glVertex2f(100,220);
   glVertex2f(470,220);
   glVertex2f(470,100);
   glEnd();

   buswindow(110,160);
   buswindow(170,220);
   buswindow(230,270);
   buswindow(280,330);
   buswindow(340,390);
   buswindow(400,450);
   wheel(200,100);
   wheel(380,100);

}

void truck()
{

   //Bottom Part

   glLoadIdentity();
   glColor4f(1.0, 1.0, 0.0, 0.0);
   cnt=cnt+0.18;
   if(cnt>1300.00)
   {
       //cnt=-250.0;
       d++;
       if(d%2==0)
       {
           r2=r2+d;
           g2=0.0;
           b2=1.0;

       }
       else if(d%3==0)
       {
           r2=0.0;
           g2=3.0+d;
           b2=5.0+d;
       }
       else if(d%5==0)
       {
           r2=5.0;
           g2=0.0;
           b2=1.0;
       }
       else
       {
           r2=0.0;
           g2=1.0;
           b2=0.0;
       }

   }
   glTranslated(cnt,200,0.0);
   glScaled(0.4,0.4,0.0);
   glBegin(GL_POLYGON);
   glVertex2f(100,100);
   glVertex2f(100,160);
   glVertex2f(450,160);
   glVertex2f(450,100);
   glEnd();

   //Top Part
   glBegin(GL_POLYGON);
   glVertex2f(350,160);
   glVertex2f(350,200);
   glVertex2f(400,200);
   glVertex2f(450,160);

   glEnd();

   window(365,400);
   wheel(200,100);
   wheel(380,100);

}

void display()
{

  glClear(GL_COLOR_BUFFER_BIT);
  //Push and pop matrix for separating circle object from Background
  glColor3f(0.0,1.0,0.0);
  road();
  grass();
  grass2();
  line1();
  line2();
  line3();
  line4();
  car();
  bus();
  bus2();
  truck();
  glutSwapBuffers();
  glFlush();


}

int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);
    glutInitWindowSize(700,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Moving Vehicals");
    initOpenGl();
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMainLoop();
    return 0;
}
