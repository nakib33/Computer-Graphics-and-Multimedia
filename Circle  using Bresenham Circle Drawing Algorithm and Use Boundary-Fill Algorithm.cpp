#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include<iostream>
using namespace std;

int center_x, center_y, r, x=0, y, p;

struct Colour
{
    float r,g,b;
};

struct Colour getPixelColor(int x, int y)
{
    struct Colour colour;
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &colour);
    return colour;
}

void setPixelColor(int x, int y, struct Colour colour)
{
    glBegin(GL_POINTS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

void flood(int x, int y, struct Colour fill_col, struct Colour boundary_col)
{
    struct Colour colour;
    colour = getPixelColor(x, y);

    if (colour.r != fill_col.r && colour.g != fill_col.g && colour.b != fill_col.b && colour.r != boundary_col.r && colour.g != boundary_col.g && colour.b != boundary_col.b)
    {
        glBegin(GL_POINTS);
        glColor3f(1, 1, 0);
        glVertex2i(x, y);
        glEnd();
        glFlush();

        flood(x + 1, y, fill_col, boundary_col);
        flood(x - 1, y, fill_col, boundary_col);
        flood(x, y + 1, fill_col, boundary_col);
        flood(x, y - 1, fill_col, boundary_col);
        return;
    }

    return;
}

void draw_pixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}


void createcircle(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    x=0;
    y=r;
    p=3-2*r;

    while(x<=y)
    {
        glBegin(GL_POINTS);
        glVertex2d(center_x+x, center_y+y);
        glVertex2d(center_x+y, center_y+x);

        glVertex2d(center_x-y, center_y+x);
        glVertex2d(center_x-x, center_y+y);

        glVertex2d(center_x-x, center_y-y);
        glVertex2d(center_x-y, center_y-x);

        glVertex2d(center_x+y, center_y-x);
        glVertex2d(center_x+x, center_y-y);
        glEnd();
        glFlush();
        if (p<0)
        {
            p =p+4*x+6;
        }
        else
        {
            p =p+4*(x-y)+10;
            y--;
        }
        x++;
    }

    struct Colour fill_col = {0.0, 0.0, 0.0};
    struct Colour boundary_col = {0.0, 0.0, 0.0};
    int x,y;
    x = center_x;
    y = center_y;
    flood(x, y, fill_col, boundary_col);
    glFlush();
}

void Init()
{
    glClearColor(1.0, 1.0, 1.0, 0);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char **argv)
{
    printf("Enter radius : ");
    scanf("%d", &r);
    printf("\nEnter X center and Y center : ");
    scanf("%d %d", &center_x, &center_y);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Boundary Fill");
    glutDisplayFunc(createcircle);
    Init();
    glutMainLoop();
}
