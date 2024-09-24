#include <GL/freeglut.h>
#include <iostream>
#include <cstring>

GLfloat escalaY = 0.2f;
GLfloat escalaX = 0.2f;
GLfloat deslocamentoY = 0.0f;
GLfloat deslocamentoX = 0.0f;
GLfloat anguloRotacao = 0.0f;

void inicializa(void) {
    glClearColor(0.5098f, 0.8784f, 0.9804f, 0);//coloquei ciano
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-3, 3, -3, 3);
}

void desenhaNome() {
    glLineWidth(3);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0902f, 0.37f, 0.78f);
    glVertex2f(-2, 2);
    glVertex2f(-2, 0);
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

void desenha(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(deslocamentoX, deslocamentoY, 0.0f);
    glRotatef(anguloRotacao, 0.0f, 0.0f, 1.0f);
    glScalef(escalaX, escalaY, 1.0f);

    desenhaNome();

    glFlush();
}

void listeningKey(unsigned char tecla, GLint x, GLint y) {
    switch (tecla) {
    case '+':
        escalaX += 0.1f;
        escalaY += 0.1f;
        break;
    case '-':
        escalaX -= 0.1f;
        escalaY -= 0.1f;
        if (escalaX < 0.1f) escalaX = 0.1f;
        if (escalaY < 0.1f) escalaY = 0.1f;
        break;
    case '1':
        escalaY -= 0.1f;
        if (escalaY < 0.1f) escalaY = 0.1f;
        break;
    case '2':
        escalaX -= 0.1f;
        if (escalaX < 0.1f) escalaX = 0.1f;
        break;
    case '3':
        escalaX += 0.1f;
        break;
    case '4':
        escalaY += 0.1f;
        break;
    case 'w':
        deslocamentoY += 0.1f;
        break;
    case 's':
        deslocamentoY -= 0.1f;
        break;
    case 'd':
        deslocamentoX += 0.1f;
        break;
    case 'a':
        deslocamentoX -= 0.1f;
        break;
    case 'q':
        anguloRotacao -= 5.0f;
        break;
    case 'e':
        anguloRotacao += 5.0f;
        break;
    }

    desenha();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-3, 3, -3, 3);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(300, 100);
    glutCreateWindow("José");

    inicializa();

    glutKeyboardFunc(listeningKey);
    glutDisplayFunc(desenha);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}
