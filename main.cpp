#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include<GL/glut.h>

int matrix[3][3];
int jogador;
int resultado;
bool gameover;

//inicializa o game
void initgame()
{
	jogador = 1; //x começa primeiro

	//"limpa" a matriz
	for(int i = 0; i <= 2; i++)
	{
		for(int j = 0; j <= 2; j++)
		{
			matrix[i][j] = 0;
		}
	}
}

//Quando a tecla é apertada ele reinicia ou sai
void tecla(unsigned char key, int x, int y ){
    switch(key){
		case 's':
			if(gameover == true)
			{
				gameover = false;
				initgame();
			}
			break;
		case 'n':
			if(gameover == true)
				exit(0);
			break;
		case 27:
			exit(0);

	}
}

// Coloca x ou "o" no espaço em branco
void click(int button, int state, int x, int y)
{
	if(gameover == false && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if(jogador == 1)
		{
			if(matrix[(y - 50) / 100][x / 100] == 0)
			{
				matrix[(y - 50) / 100][x / 100] = 1;
				jogador = 2;
			}
		}
		else
		{
			if(matrix[(y - 50) / 100][x / 100] == 0)
			{
				matrix[(y - 50) / 100][x / 100] = 2;
				jogador = 1;
			}
		}
	}
}

//Escreve texto na janela OpenGL
void drawString (void * font, char *s, float x, float y){
    unsigned int i;
    glRasterPos2f(x, y);
    for (i = 0; i < strlen (s); i++)
        glutBitmapCharacter (font, s[i]);
}


void linhas()
{
	glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    //2 linhas verticais

    glVertex2f(100, 50);
    glVertex2f(100, 340);
    glVertex2f(200, 340);
    glVertex2f(200, 50);
    //2 linhas horizontais

    glVertex2f(10, 150);
    glVertex2f(290, 150);
    glVertex2f(10, 250);
    glVertex2f(290, 250);
	glEnd();
}

//Desenha x e "o"
void desenhaXeO()
{
	for(int i = 0; i <= 2; i++)
	{
		for(int j = 0; j <= 2; j++)
		{
			if(matrix[i][j] == 1) //desenha o x
			{
				glBegin(GL_LINES);
                glVertex2f(50 + j * 100 - 25, 100 + i * 100 - 25);
                glVertex2f(50 + j * 100 + 25, 100 + i * 100 + 25);
                glVertex2f(50 + j * 100 - 25, 100 + i * 100 + 25);
                glVertex2f(50 + j * 100 + 25, 100 + i * 100 - 25);
				glEnd();
			}
			else if(matrix[i][j] == 2) //Desenha o mais próximo do "o"
			{
				glBegin(GL_LINE_LOOP);
                glVertex2f(50 + j * 100 - 25, 100 + i * 100 - 25);
                glVertex2f(50 + j * 100 - 25, 100 + i * 100 + 25);
                glVertex2f(50 + j * 100 + 25, 100 + i * 100 + 25);
                glVertex2f(50 + j * 100 + 25, 100 + i * 100 - 25);
				glEnd();
			}
		}
	}
}

//Checa se houve vencedor
bool checagem()
{
	int i, j;

	//chaca as horizontais
	for(i = 0; i <= 2; i++)
	{
		for(j = 1; j <= 2; j++)
		{
			if(matrix[i][0] != 0 && matrix[i][0] == matrix[i][j])
			{
				if(j == 2)
					return true;
			}
			else
				break;
		}
	}

	//checa as veticais
	for(i = 0; i <= 2; i++)
	{
		for(j = 1; j <= 2; j++)
		{
			if(matrix[0][i] != 0 && matrix[0][i] == matrix[j][i])
			{
				if(j == 2)
					return true;
			}
			else
				break;
		}
	}

	//checa as diagonais
	for(i = 1; i <= 2; i++)
	{
		if(matrix[0][0] != 0 && matrix[0][0] == matrix[i][i])
		{
			if(i == 2)
				return true;
		}
		else
            break;
	}
	for(i = 1; i <= 2; i++)
	{
		if(matrix[2][0] != 0 && matrix[2][0] == matrix[2 - i][i])
		{
			if(i == 2)
				return true;
		}
		else
            break;
	}
}

//Checa se foi um empate
bool checagemEmpate()
{
	int i, j;
	bool draw;

	for(i = 0; i <= 2; i++)
	{
		for(j = 0; j <= 2; j++)
		{
			if(matrix[i][j] == 0)
				return false;
		}
	}
	return true;
}

//This is the idle call back function
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1, 1, 1, 1);
	glColor3f(254, 253, 0);
	if(jogador == 1)
		drawString(GLUT_BITMAP_HELVETICA_18, "Jogador 1 joga", 100, 30);
	else
		drawString(GLUT_BITMAP_HELVETICA_18, "Jogador 2 joga", 100, 30);

	linhas();
	desenhaXeO();

	if(checagem() == true)
	{
		//jogador que fez o último movimento venceu, ou não.
		if(jogador == 1)
		{
			gameover = true;
			resultado = 2; //JOGADOR 2 VENCEU
		}
		else
		{
			gameover = true;
			resultado = 1; //JOGADOR 1 VENCEU
		}
	}
	else if(checagemEmpate() == true)
	{
		gameover = true;
		resultado = 0;
	}

	if(gameover == true)
	{
		drawString(GLUT_BITMAP_HELVETICA_18, "Game Over", 100, 160);

		if(resultado == 0)
			drawString(GLUT_BITMAP_HELVETICA_18, "Velha!", 110, 185);

		if(resultado == 1)
			drawString(GLUT_BITMAP_HELVETICA_18, "Jogador 1 Venceu !!!", 95, 185);

		if(resultado == 2)
			drawString(GLUT_BITMAP_HELVETICA_18, "Jogador 2 venceu!!!", 95, 185);

		drawString(GLUT_BITMAP_HELVETICA_18, "Deseja jogar novamente?(s/n)", 40, 210);
	}

	glutSwapBuffers();
}



void reshape(int x, int y)
{
	glViewport(0, 0, x, y);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, x, y, 0, 0, 1);
	glMatrixMode(GL_MODELVIEW);
}


//função main
int main(int argc, char **argv)
{
	initgame();
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(390,360);
	glutCreateWindow("Jogo Da Velha - Gustavo Do Nascimento");
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(tecla);
	glutMouseFunc(click);
	glutIdleFunc(display);
    glutMainLoop();
}
