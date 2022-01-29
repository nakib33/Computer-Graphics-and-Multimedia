#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>
int h,k,r;

void Init(void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    gluOrtho2D(-300, 300, 0, 600);
}


void TrigonometricFunction(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 1.0, 1.0);

    glBegin(GL_POINTS);
    glVertex2s(h,k);

    int x, y, x1, y1, theta;
    float n=3.14159/180;


    for(theta=0; theta<=45; theta++)
    {
        x1 = r*cos(theta*n);
        y1 = r*sin(theta*n);

        x = int(x1+0.5);
        y = int(y1+0.5);

        glVertex2s(x+h,y+k);
        glVertex2s(x+h,-y+k);
        glVertex2s(-x+h,y+k);
        glVertex2s(-x+h,-y+k);
        glVertex2s(y+h,x+k);
        glVertex2s(y+h,-x+k);
        glVertex2s(-y+h,x+k);
        glVertex2s(-y+h,-x+k);
    }



    glEnd();
    glFlush();
}


int main(int argc, char** argv)
{
    printf("Enter the center of circle h & k: ");
    scanf("%d %d",&h,&k);
    printf("Enter the radius: ");
    scanf("%d",&r);

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Circle : Trigonometric Function ");
    Init ();
    glutDisplayFunc(TrigonometricFunction);
    glutMainLoop();
    return 0;
}
