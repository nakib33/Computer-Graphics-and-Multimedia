#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

double X1, Y1, X2, Y2;

float round_value(float v)
{
    return floor(v + 0.5);
}
void LineDDA(void)
{
    double dx = (X2 - X1);
    double dy = (Y2 - Y1);
    double steps;
    float xinc, yinc, x=X1, y=Y1;

    if(abs(dx)< abs(dy))
    {
        steps = abs(dy);
    }
    else
    {
        steps = abs(dx);
    }
    xinc= dx /(float)steps;
    yinc= dy /(float)steps;


    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POINTS);

    glVertex2d(x,y);

    for(int i=0; i<steps; i++)
    {
        x+=xinc;
        y+=yinc;

        glVertex2d(round_value(x), round_value(y));
    }
    glEnd();

    glFlush();
}
void Init()
{
    glClearColor(1.0,1.0,1.0,0);
    glColor3f(0.0,0.0,0.0);
    gluOrtho2D(0, 640, 0, 480);
}

int  main(int argc, char **argv)
{
    printf("Enter First Point (x1,y1): ");
    scanf("%lf%lf",&X1,&Y1);
    printf("Enter First Point (x2,y2): ");;
    scanf("%lf%lf",&X2,&Y2);

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(640,480);
    glutCreateWindow("DDA_Line");
    Init();
    glutDisplayFunc(LineDDA);
    glutMainLoop();
}
