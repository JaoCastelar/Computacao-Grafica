#include <GL/glut.h>

void desenhaTabuleiro() {
    int i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            
            if ((i + j) % 2 == 0) {
                glColor3f(1.0f, 1.0f, 1.0f);
            } else {
                glColor3f(0.0f, 0.0f, 0.0f);
            }

            
            glBegin(GL_QUADS);
            glVertex2f(i, j);
            glVertex2f(i + 1, j);
            glVertex2f(i + 1, j + 1);
            glVertex2f(i, j + 1);
            glEnd();
        }
    }
}


void tela() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    desenhaTabuleiro();
    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 8, 0, 8, -1, 1);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Tabuleiro de Xadrez");
    glutDisplayFunc(tela);
    glutReshapeFunc(reshape);


    glutMainLoop();

    return 0;
}