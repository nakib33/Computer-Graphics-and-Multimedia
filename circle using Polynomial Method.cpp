#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
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


void PolynomialMethod(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 1.0, 1.0);

    glBegin(GL_POINTS);
    glVertex2s(h,k);

    double n, sum;
    int i,j;
    n = r/sqrt(2);

    for( i=0 ; i<=n ; i++)
    {
        sum = sqrt(r*r - i*i);
        j=(int)(sum);

        glVertex2s(h+i,k+j);
        glVertex2s(h+j,k+i);
        glVertex2s(h-i,k+j);
        glVertex2s(h-j,k+i);
        glVertex2s(h-j,k-i);
        glVertex2s(h-i,k-j);
        glVertex2s(h+i,k-j);
        glVertex2s(h+j,k-i);
    }

    glEnd();
    glFlush();
}



int main(int argc, char** argv)
{
    printf("Enter the center of circle: ");
    scanf("%d %d",&h,&k);
    printf("Enter the radius: ");
    scanf("%d",&r);

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Circle : Polynomial Method ");
    Init ();
    glutDisplayFunc(PolynomialMethod);
    glutMainLoop();
    return 0;
}
