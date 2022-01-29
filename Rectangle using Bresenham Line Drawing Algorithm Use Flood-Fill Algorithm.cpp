#include <GL/glut.h>
#include <bits/stdc++.h>
#include <math.h>
#include <stdlib.h>

using namespace std;

int X_Min, Y_Min, X_Max, Y_Max;

struct Color
{
    float r,g,b;
};


struct Color getPixelColor(int X, int Y)
{
    struct Color color;
    glReadPixels(X, Y, 1, 1, GL_RGB, GL_FLOAT, &color);
    return color;
}

void init()
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 400, 0, 400);
}

void setPixelColor(int x, int y, struct Color color)
{

    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}


void Flood_Fill_Algorithm(int X, int Y, struct Color Old_Color, struct Color New_color)
{
    struct Color color;
    color = getPixelColor(X, Y);

    if (color.r==New_color.r && color.g==New_color.g && color.b==New_color.b)
        return;
    if (color.r == Old_Color.r && color.g == Old_Color.g && color.b == Old_Color.b)
    {
        glBegin(GL_POINTS);

        glColor3f(1, 0, 0);

        glVertex2i(X, Y);

        glEnd();
        glFlush();

        //8 Connected
        Flood_Fill_Algorithm(X+1, Y, Old_Color, New_color);
        Flood_Fill_Algorithm(X-1, Y, Old_Color, New_color);
        Flood_Fill_Algorithm(X, Y+1, Old_Color, New_color);
        Flood_Fill_Algorithm(X, Y-1, Old_Color, New_color);
        Flood_Fill_Algorithm(X+1, Y+1,Old_Color, New_color);
        Flood_Fill_Algorithm(X-1, Y+1,Old_Color, New_color);
        Flood_Fill_Algorithm(X+1, Y-1,Old_Color, New_color);
        Flood_Fill_Algorithm(X-1, Y-1,Old_Color, New_color);


        return;
    }

    return;
}

void Draw_Pixel(int X, int Y)
{
    glBegin(GL_POINTS);
    glVertex2i(X, Y);
    glEnd();
}

void Draw_Line(int X1, int Y1, int X2, int Y2)
{
    int dx, dy, P;
    int incx, incy;
    int P1, P2;
    int X, Y;

    dx = X2 - X1;
    dy = Y2 - Y1;

    if (dx < 0)
        dx = -dx;
    if (dy < 0)
        dy = -dy;
    incx = 1;
    if (X2 < X1)
        incx = -1;
    incy = 1;
    if (Y2 < Y1)
        incy = -1;
    X = X1;
    Y = Y1;
    if (dx > dy)
    {
        Draw_Pixel(X, Y);
        P = 2*dy - dx;
        P1 = 2 * (dy-dx);
        P2 = 2*dy;
        for (int i=0; i<dx; i++)
        {
            if (P >= 0)
            {
                Y += incy;
                P += P1;
            }
            else
            {
                P += P2;
            }
            X += incx;
            Draw_Pixel(X, Y);
        }
    }
    else
    {
        Draw_Pixel(X, Y);
        P = 2*dx - dy;
        P1 = 2 * (dx-dy);
        P2 = 2*dx;
        for (int i=0; i<dy; i++)
        {
            if (P >= 0)
            {
                X += incx;
                P += P1;
            }
            else
            {
                P += P2;
            }
            Y += incy;
            Draw_Pixel(X, Y);
        }
    }
}

void Create_rectangle_Bresenham_line_Drawing(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    int A1, B1, A2, B2;
    int X1, X2, Y1, Y2;
    int X, Y;

    X1 = X_Min;
    X2 = X_Max;
    Y1 = Y_Min;
    Y2 = Y_Max;

    for (int i=1; i<=4; i++)
    {
        if (i==1)
        {
            A1 = X1;
            B1 = Y1;
            A2 = X2;
            B2 = Y1;
        }
        if (i==2)
        {
            A1=X1;
            B1= Y1;
            A2=X1;
            B2=Y2;
        }
        if (i==2)
        {
            A1=X1;
            B1=Y1;
            A2=X1;
            B2=Y2;
        }
        if (i==3)
        {
            A1=X1;
            B1=Y2;
            A2=X2;
            B2=Y2;
        }
        if (i==4)
        {
            A1=X2;
            B1=Y1;
            A2=X2;
            B2=Y2;
        }
        Draw_Line(A1, B1, A2, B2);
    }

    // its a colour of the filler and also old color of the object
    struct Color Old_Color = {0.0, 0.0, 0.0};
    struct Color New_color = {1.0, 1.0, 1.0};

    X = X_Min+1;
    Y = Y_Min+1;

    Flood_Fill_Algorithm(X, Y, Old_Color, New_color);

    glFlush();
}


int main(int argc, char **argv)
{
    cout << "Enter Lower-Left Co-ordinate of rectangle : " ;
    cin>>X_Min>>Y_Min;

    cout<< "Enter Upper-Right Co-ordinate of rectangle : ";
    cin>>X_Max>>Y_Max;


    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400,400);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Flood Fill Algorithm");
    glutDisplayFunc(Create_rectangle_Bresenham_line_Drawing);
    init();
    glutMainLoop();
}
