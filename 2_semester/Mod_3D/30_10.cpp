#ifdef __APPLE__
#include <GLUT/freeglut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

typedef struct{
    int x, y, z;
} Ponto;

Ponto pEsfera2;

void inicialiaVars(){
    pEsfera2.x = -2;
    pEsfera2.y = -2;
    pEsfera2.z = 0;
}

float alpha = 0;
float beta = 0;
float delta = 1;

void init() {
    glClearColor(0, 0, 0, 0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-4, 4, -4, 4, -4, 4);
}

void drawGoal(float xPos) {

    glPushMatrix();
    glTranslatef(xPos, -1.0f, 0);

    glColor3f(1, 1, 1);

    // Desenha o poste esquerdo
    glBegin(GL_LINES);
    glVertex3f(0, 0, -1.5f);   // Parte inferior
    glVertex3f(0, 1.0f, -1.5f); // Parte superior (aumenta a altura)
    glEnd();

    // Desenha o poste direito
    glBegin(GL_LINES);
    glVertex3f(0, 0, 1.5f);    // Parte inferior
    glVertex3f(0, 1.0f, 1.5f); // Parte superior (aumenta a altura)
    glEnd();

    // Desenha a trave superior
    glBegin(GL_LINES);
    glVertex3f(0, 1.0f, -1.5f); // Conecta o topo do poste esquerdo
    glVertex3f(0, 1.0f, 1.5f);  // Conecta o topo do poste direito
    glEnd();

    glPopMatrix();
}



void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glRotatef(beta, 0, 1, 0);
    glRotatef(alpha, 1, 0, 0);
    glScalef(delta, delta, delta);

    glPushMatrix();
    glTranslatef(0, -0.75f, 0);
    glColor3f(1, 1, 1);
    glutSolidSphere(0.2f, 20, 20);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0, -1, 0);
    glScalef(7, 0.1f, 4);
    glColor3f(0, 1, 0.6);
    glutSolidCube(1.0f);
    glPopMatrix();

    drawGoal(-3.5f);
    drawGoal(3.5f);

    glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == 'q')
        delta = delta * 1.1f;
    if (key == 'w')
        delta = delta * 0.9f;
    glutPostRedisplay();
}

void listeningSpKey(GLint tecla, GLint x, GLint y) {
    switch(tecla) {
        case GLUT_KEY_UP:
            alpha = alpha - 1;
            break;
        case GLUT_KEY_DOWN:
            alpha = alpha + 1;
            break;
        case GLUT_KEY_LEFT:
            beta = beta + 1;
            break;
        case GLUT_KEY_RIGHT:
            beta = beta - 1;
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Exemplo Esfera 3D com Gols");
    gluOrtho2D(0.0, 400, 0.0, 600);
    init();
    inicialiaVars();
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(listeningSpKey);
    glutDisplayFunc(display);
    glutMainLoop();
}
