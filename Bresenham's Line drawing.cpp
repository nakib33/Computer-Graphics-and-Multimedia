#include <stdio.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<math.h>

int X1, Y1, X2, Y2;

void BLDA()
{
    int dx,dy;
    dx = fabs(X2 - X1), dy = fabs(Y2 - Y1);
    int p = 2*dy - dx;
    int X, Y;

    if(X1 > X2)
    {
        X = X2;
        Y = Y2;
        X2 = X1;
    }
    else
    {
        X = X1;
        Y = Y1;
    }

    glBegin(GL_POINTS);
    glColor3f(0,0,0);
    glVertex2i(X,Y);
    glEnd();

    while(X < X2)
    {
        X++;
        if(p<0)
        {
            p = p + 2*dy;
        }
        else
        {
            p= p + 2*dy - 2*dx;
            Y++;
        }

        glBegin(GL_POINTS);

        glColor3f(0,0,0);
        glVertex2i(X,Y);

        glEnd();

    }

}

void bresenham_line()
{
    glClear(GL_COLOR_BUFFER_BIT);
    BLDA();
    glutSwapBuffers();
}


void Myinit()
{
    glClearColor(1.0,1.0,1.0,0);
    glColor3f(0.0,0.0,0.0);
    gluOrtho2D(0, 640, 0, 600);
}

int main(int argc, char* argv[])
{
    printf("Enter First Point (x1, y1): ");
    scanf("%d %d", &X1, &Y1);
    printf("Enter First Point (x2, y2): ");;
    scanf("%d %d", &X2, &Y2);

    glutInit(&argc, argv);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Bresenham's Algo");
    Myinit();
    glutDisplayFunc(bresenham_line);
    glutMainLoop();

    return 0;
}
