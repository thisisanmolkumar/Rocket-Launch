#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <cmath>

#define w 480
#define h 480

void init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, w, 0.0, h);
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

void delay(unsigned int seconds)
{
	clock_t goal = seconds + clock();
	while (goal > clock());
}

void drawArc(int xc, int yc, int r, int arc1=0, int arc2=100, int num=100)
{
	glBegin(GL_POLYGON);
    for(int i = arc1; i < arc2; i++)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(num);

        float x = r * cosf(theta);
        float y = r * sinf(theta);

        glVertex2f(x + xc, y + yc);
    }
    glEnd();
}

void fire(int x)
{
    glColor3f(1.0f, 0.271f, 0.0f);
    drawArc(260.9 + x, 110.0, 50, 45, 70);
    drawArc(219.1 + x, 110.0, 50, -19, 6);

    glBegin(GL_POLYGON);
    glVertex2f(267.9 + x, 125.0);
    glVertex2f(240.0 + x, 63.0);
    glVertex2f(212.1 + x, 125.0);
    glEnd();

    glColor3f(1.0f, 0.843f, 0.0f);
    drawArc(260.9 + x, 110.0, 40, 44, 68);
    drawArc(219.1 + x, 110.0, 40, -17, 7);

    glBegin(GL_POLYGON);
    glVertex2f(257.9 + x, 125.0);
    glVertex2f(240.0 + x, 76.0);
    glVertex2f(222.1 + x, 125.0);
    glEnd();
}

void rocket(int x)
{
    glColor3f(0.6f, 0.6f, 0.6f);
    glBegin(GL_POLYGON);
    glVertex2f(209.1 + x, 129.0);
    glVertex2f(189.1 + x, 109.0);
    glVertex2f(174.1 + x, 189.0);
    glVertex2f(209.1 + x, 209.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(270.9 + x, 129.0);
    glVertex2f(290.9 + x, 109.0);
    glVertex2f(305.9 + x, 189.0);
    glVertex2f(270.9 + x, 209.0);
    glEnd();

    glColor3f(0.8f, 0.8f, 0.8f);
    drawArc(-3 + x, 5 * h / 11, 3 * w / 5, -5, 10);
    drawArc(w + 3 + x, 5 * h / 11, 3 * w / 5, 41, 56);

    glBegin(GL_POLYGON);
    glVertex2f(270.9 + x, 129.0);
    glVertex2f(240.0 + x, 374.0);
    glVertex2f(209.1 + x, 129.0);
    glEnd();

    glColor3f(0.2f, 0.2f, 0.4f);
    drawArc((w / 2) + x, 4 * h / 7, 20);
    glColor3f(0.2f, 0.824f, 1.0f);
    drawArc((w / 2) + x, 4 * h / 7, 15);

    fire(x);
}

void rocketVibrate()
{
    glClear(GL_COLOR_BUFFER_BIT);
    rocket(0);
    delay(5);
    glFlush();
    glClear(GL_COLOR_BUFFER_BIT);
    rocket(2);
    delay(5);
    glFlush();
    glClear(GL_COLOR_BUFFER_BIT);
    rocket(0);
    delay(5);
    glFlush();
    glClear(GL_COLOR_BUFFER_BIT);
    rocket(-2);
    delay(5);
    glFlush();
}

void num(int a, int b, int c, int d)
{
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(w / 2 + a, h / 2 + b);
    glVertex2f(w / 2 + c, h / 2 + d);
    glEnd();
}

void box()
{
    glColor3f(0.7f, 0.7f, 0.7f);
    glBegin(GL_POLYGON);
    glVertex2f(w / 2 + 50, h / 2 + 60);
    glVertex2f(w / 2 - 50, h / 2 + 60);
    glVertex2f(w / 2 - 50, h / 2 - 60);
    glVertex2f(w / 2 + 50, h / 2 - 60);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(w / 2 + 30, h / 2 + 40);
    glVertex2f(w / 2 - 30, h / 2 + 40);
    glVertex2f(w / 2 - 30, h / 2 - 40);
    glVertex2f(w / 2 + 30, h / 2 - 40);
    glEnd();
}

void countdown()
{
    glClearColor(0.2f, 0.824f, 1.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);  //5
    box();
    num(10, 20, -10, 20);
    num(-10, 20, -10, 0);
    num(-10, 0, 10, 0);
    num(10, 0, 10, -20);
    num(10, -20, -10, -20);
    glFlush();
    delay(1000);
    glClearColor(0.2f, 0.824f, 1.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);  //4
    box();
    num(-10, 20, -10, 0);
    num(-10, 0, 10, 0);
    num(10, 20, 10, -20);
    glFlush();
    delay(1000);
    glClearColor(0.2f, 0.824f, 1.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);  //3
    box();
    num(10, 20, -10, 20);
    num(10, 20, 10, 0);
    num(-10, 0, 10, 0);
    num(10, 0, 10, -20);
    num(10, -20, -10, -20);
    glFlush();
    delay(1000);
    glClearColor(0.2f, 0.824f, 1.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);  //2
    box();
    num(10, 20, -10, 20);
    num(10, 20, 10, 0);
    num(-10, 0, 10, 0);
    num(-10, 0, -10, -20);
    num(10, -20, -10, -20);
    glFlush();
    delay(1000);
    glClearColor(0.2f, 0.824f, 1.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);  //1
    box();
    num(10, 20, 10, -20);
    glFlush();
    delay(1000);
}

void display()
{
    GLfloat colors[][3] = {{0.2f, 0.824f, 1.0f}, {0.05f, 0.05f, 0.05f}};
    GLfloat bk[3] = {colors[0][0], colors[0][1], colors[0][2]};

    int i, n = 36;

    float x = (colors[0][0] - colors[1][0]) / n;
    float y = (colors[0][1] - colors[1][1]) / n;
    float z = (colors[0][2] - colors[1][2]) / n;

    countdown();

    for (i = 0; i < n; i++)
    {
        glClearColor(bk[0], bk[1], bk[2], 0.0);
        glClear(GL_COLOR_BUFFER_BIT);

        bk[0] -= x;
        bk[1] -= y;
        bk[2] -= z;

        rocketVibrate();

        if (i < 10)
        {
            glColor3f(0.0f, 0.5f, 0.0f);
            drawArc(w / 2, -3 * h / 4 - (i * 12), h);
        }

        glFlush();
        delay(100);
    }

    glFlush();
}

int main()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(w, h);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("OpenEndedProject");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
