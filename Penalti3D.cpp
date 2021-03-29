// Trabalho realizado por Gustavo Do Nascimento e Elson José de Oliveira Jr


#include <GL/glut.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

int chute;
int placar;
GLfloat posmirax = 0;
GLfloat posmiray = -0.5;

GLfloat posbolax = 0;
GLfloat posbolay = -1.5;
GLfloat posbolaz = -5;

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

void Timer(int value)
{
    glutPostRedisplay();
    glutTimerFunc(5,Timer, 0);
}

void desenha(void *font,const char s[],float x,float y, float z)
{
	unsigned int i;
	glRasterPos3f(x,y,z);
	for(i=0;i<strlen(s);i++)
	{
		glutBitmapCharacter(font,s[i]);
	}
}


void teclado(unsigned char teclas, GLint x, GLint y)
{
    switch(teclas)
    {

        case 'd':
        posmiray = posmiray + 1;
        break;

        case 'a':
        posmiray= posmiray - 1;
        break;

        case 's':
        posmirax = posmirax - 1;
        break;

        case 'w':
        posmirax = posmirax + 1;
        break;

        case ' ':
        chute == true;
        posbolax = posmiray;
        posbolay = posmirax;
        posbolaz = -10;
        if((posmiray <= 4.5) || (posmiray >= -4.5) && (posmirax <= 2) || (posmirax >=-2.5)){
            placar = 1;
        }
        else{
            placar = 2;
        }
        break;
        }

}

void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}


void desenhar(void)
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(0.0,0.5,0.2);
    glLoadIdentity();

    //gramado
    {
    glPushMatrix();
    glTranslated(0,-5,-5);
    glutSolidCube(5);
    glPopMatrix();

    glPushMatrix();
    glTranslated(2.5,-5,-5);
    glutSolidCube(5);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-2.5,-5,-5);
    glutSolidCube(5);
    glPopMatrix();

    glColor3d(0.0,0.8,0.7);
    glPushMatrix();
    glTranslated(0,-5,-10);
    glutSolidCube(5);
    glPopMatrix();

    glPushMatrix();
    glTranslated(2.5,-5,-10);
    glutSolidCube(5);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-2.5,-5,-10);
    glutSolidCube(5);
    glPopMatrix();

    glColor3d(0.0,0.5,0.2);
    glPushMatrix();
    glTranslated(0,-5,-15);
    glutSolidCube(5);
    glPopMatrix();

    glPushMatrix();
    glTranslated(2.5,-5,-15);
    glutSolidCube(5);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-2.5,-5,-15);
    glutSolidCube(5);
    glPopMatrix();
    }
     {

    glColor3d(0.0,0.5,0.2);
    glPushMatrix();
    glTranslated(-7.5,-3,-8);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-7.5,-3,-10);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-7.5,-3,-12);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-7.5,-3,-14);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-7.5,-3,-16);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-7.5,-3,-18);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-7.5,-3,-20);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-7.5,-3,-22);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glTranslated(7.5,-3,-8);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(7.5,-3,-10);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(7.5,-3,-12);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(7.5,-3,-14);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(7.5,-3,-16);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(7.5,-3,-18);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(7.5,-3,-20);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(7.5,-3,-22);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glTranslated(5.5,-3,-22);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(3.5,-3,-22);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(1.5,-3,-22);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0,-3,-22);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-1.5,-3,-22);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-3.5,-3,-22);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-5.5,-3,-22);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-7.5,-3,-22);
    glutSolidCube(2);
    glPopMatrix();

    }

    //Bola
    {
    glColor3d(1,1,1);
    glPushMatrix();
    glTranslated(posbolax,posbolay,posbolaz);
    glutSolidSphere(0.6,30,30);
    glPopMatrix();
    }

    //trave
    {
    glColor3d(1,1,1);
    glBegin(GL_LINES);

    glVertex3f(-4.5, -2.5, -15);
    glVertex3f(-4.5, 2, -15);
    glVertex3f(4.5, 2, -15);
    glVertex3f(-4.5, 2, -15);
    glVertex3f(4.5, 2, -15);
    glVertex3f(4.5, -2.5, -15);

    glEnd();
    }

    //crosshair
    {
    glLoadIdentity();
    glColor3d(1,1,1);
    glTranslatef(posmiray, posmirax,-15);
    glutSolidSphere(0.1,30,30);
    glLoadIdentity();
    }

    glLoadIdentity();
    glutSwapBuffers();


}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1366, 768);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("Pênalti!!!");

    if(chute == true)
    {
        glColor3f(0.8,0.1,0.3);
        desenha(GLUT_BITMAP_HELVETICA_18, "Bota o Pé na forma", 0, 0, -15);
        if(placar == 1)
        desenha(GLUT_BITMAP_HELVETICA_18, "Gol!", 0, 0, -15);

    glutSwapBuffers();
}

    glutReshapeFunc(resize);
    glutDisplayFunc(desenhar);
    glutKeyboardFunc(teclado);
    glutTimerFunc(5, Timer, 0);


    glClearColor(0.1,0.1,0.1,0.1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();

    return EXIT_SUCCESS;
}
