#include<GL/freeglut.h>
#include<iostream>
void desenha(void) {
glClear( GL_COLOR_BUFFER_BIT );
glFlush();
}
int main(int argc, char* argv[]) {
glutInit(&argc, argv);
glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
glutInitWindowSize(800,600);
glutCreateWindow("Hello_World");
glutDisplayFunc(desenha);
glClearColor( 0, 0, 1, 0);
glutMainLoop();
return 0;
}
