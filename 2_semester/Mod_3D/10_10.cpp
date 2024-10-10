#include <windows.h>
#include <GL/freeglut.h>
#include <stdio.h>

GLfloat x1 = 100.0f, y1 = 150.0f;  // Posição do quadrado animado
GLsizei rsize = 50;                // Tamanho dos quadrados

GLfloat xstep = 3.0f, ystep = 3.0f; // Passo do movimento do quadrado animado

GLfloat windowWidth, windowHeight;

GLfloat x2 = 300.0f, y2 = 200.0f;  // Posição do quadrado verde controlado pelo usuário

int colisao = 0; // Flag para detectar colisão
int colisaoTimer = 0; // Timer para contar o tempo da colisão (em milissegundos)

// Função para desenhar os quadrados
void Desenha(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClear(GL_COLOR_BUFFER_BIT);

    // Desenha o quadrado animado (vermelho)
    glColor3f(0.1647f, 0.9451f, 0.9608f);

    glBegin(GL_QUADS);
        glVertex2i(x1, y1 + rsize);
        glVertex2i(x1, y1);
        glVertex2i(x1 + rsize, y1);
        glVertex2i(x1 + rsize, y1 + rsize);
    glEnd();

    // Desenha o quadrado verde controlado pelo usuário
    glColor3f(0.9216f, 0.4078f, 0.9686f);

    glBegin(GL_QUADS);
        glVertex2i(x2, y2 + rsize);
        glVertex2i(x2, y2);
        glVertex2i(x2 + rsize, y2);
        glVertex2i(x2 + rsize, y2 + rsize);
    glEnd();

    // Se houver colisão, desenha a mensagem na tela
    if (colisao) {
        glColor3f(0.9098f, 0.8941f, 0.0627f);
        glRasterPos2f(windowWidth / 2 - 100, windowHeight - 30); // Posiciona o texto
        const char *msg = "Colisão detectada! Reiniciando...";
        while (*msg) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *msg++);
        }
    }

    glutSwapBuffers();
}

// Função do timer para movimentar o quadrado animado
void Timer(int value)
{
    // Verificar limites da janela para movimento do quadrado
    if (x1 > windowWidth - rsize || x1 < 0) {
        xstep = -xstep;
    }
    if (y1 > windowHeight - rsize || y1 < 0) {
        ystep = -ystep;
    }

    if (x1 > windowWidth - rsize) {
        x1 = windowWidth - rsize - 1;
    }

    if (y1 > windowHeight - rsize) {
        y1 = windowHeight - rsize - 1;
    }

    // Atualiza a posição do quadrado animado
    x1 += xstep;
    y1 += ystep;

    // Detectar colisão entre os quadrados
    if (x1 < x2 + rsize && x1 + rsize > x2 &&
        y1 < y2 + rsize && y1 + rsize > y2) {
        colisao = 1;  // Define a flag de colisão
        colisaoTimer = 1000; // 1 segundo para exibir a mensagem (1000 milissegundos)
    }

    // Se houve colisão, contar o tempo
    if (colisao) {
        colisaoTimer -= 5; // Diminuir o tempo em 5 ms a cada chamada do Timer
        if (colisaoTimer <= 0) {
            colisao = 0;  // Resetar a colisão após 1 segundo
            x1 = 100.0f; // Posição inicial do quadrado animado
            y1 = 150.0f;
            xstep = 3.0f;
            ystep = 3.0f;
        }
    }

    glutPostRedisplay();
    glutTimerFunc(5, Timer, 0);
}

// Função de redimensionamento da janela
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
    printf("\n w: %d      h: %d ", w, h);
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    windowWidth = w;
    windowHeight = h;
    gluOrtho2D(0.0f, windowWidth, 0.0f, windowHeight);
}

// Função para movimentar o quadrado verde com as teclas A, W, S, D
void Teclado(unsigned char key, int x, int y)
{
    const GLfloat moveSpeed = 10.0f;

    switch (key) {
        case 'a':  // Move para a esquerda
            if (x2 - moveSpeed >= 0) {
                x2 -= moveSpeed;
            }
            break;
        case 'd':  // Move para a direita
            if (x2 + rsize + moveSpeed <= windowWidth) {
                x2 += moveSpeed;
            }
            break;
        case 'w':  // Move para cima
            if (y2 + rsize + moveSpeed <= windowHeight) {
                y2 += moveSpeed;
            }
            break;
        case 's':  // Move para baixo
            if (y2 - moveSpeed >= 0) {
                y2 -= moveSpeed;
            }
            break;
    }

    glutPostRedisplay();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("Atividade - Colisão Controlada");
    glutDisplayFunc(Desenha);
    glutReshapeFunc(AlteraTamanhoJanela);
    glutTimerFunc(5, Timer, 0);
    glutKeyboardFunc(Teclado); // Função para capturar as teclas
    glutMainLoop();
}
