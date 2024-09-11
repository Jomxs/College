#include<GL/freeglut.h>
#include<iostream>


void inicializa(void) {
    glClearColor(0.5098, 0.8784, 0.9804, 0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-3, 3, -3, 3);
}


void desenha(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(5);
    glColor3f(0.0902f, 0.37f, 0.78f);
    glBegin(GL_LINE_STRIP);


    glVertex2f(-2, 2);
    glVertex2f(-2, 0);
    glVertex2f(-2, 0);
    glVertex2f(-2.5, 0);
    glVertex2f(-2.5, 0);
    glVertex2f(-2.5, 0.5);

    glEnd();
    glBegin(GL_LINES);


    glVertex2f(-1.5, 2);
    glVertex2f(-1.5, 0);
    glVertex2f(-0.5, 2);
    glVertex2f(-0.5, 0);
    glVertex2f(-1.5, 2);
    glVertex2f(-0.5, 2);
    glVertex2f(-1.5, 0);
    glVertex2f(-0.5, 0);

    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2f(0.5, 2);
    glVertex2f(0, 2);
    glVertex2f(0, 1.0);
    glVertex2f(0.5, 1.0);
    glVertex2f(0.5, 0);
    glVertex2f(0, 0);


    glEnd();
    glBegin(GL_LINES);

    glVertex2f(1, 2);
    glVertex2f(1, 0);
    glVertex2f(1, 2);
    glVertex2f(1.5, 2);
    glVertex2f(1, 1);
    glVertex2f(1.5, 1);
    glVertex2f(1, 0);
    glVertex2f(1.5, 0);

    glEnd();
    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(300, 100);
    glutCreateWindow("J O S E");


    inicializa();


    glutDisplayFunc(desenha);

    glutMainLoop();
    return 0;
}
