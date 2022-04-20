#include <math.h>
#include <Windows.h>
#include <gl\glut.h>
#include <stdlib.h> 
#include <stdio.h>


#define PI 3.14159  //�]�m��P�v
int n = 10, R = 10;  //�h����ܼơA�~����b�|
float speed = 1.0; //�V�p�V��
float theta = 0.0;  //�����l���׭�

void Keyboard(unsigned char key, int x, int y);
void Display(void);
void Reshape(int w, int h);
void myidle();
void KeyBoards(unsigned char key, int x, int y);
void idle(void);

int main(int argc, char** argv)
{
	// must/should match the number of strings in argv
	glutInit(&argc, argv);  //��l��GLUT�w�F
	glutInitWindowSize(400, 400);  //�]�m��ܵ��f�j�p
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);  //�]�m��ܼҦ��F�]�`�N���w�ġ^
	glutCreateWindow("A Rotating Square"); // �Ы���ܵ��f
	glutKeyboardFunc(&KeyBoards);  //���U��L�ƥ�
	glutDisplayFunc(Display);  //���U��ܦ^�ը��
	glutReshapeFunc(Reshape);  //���U���f���ܦ^�ը��
	glutIdleFunc(myidle);    //���U���m�^�ը��
	glutMainLoop();  //�i�J�ƥ�B�z�`��
	return 0;
}

void Display(void)
{
	float tmp_color = 0.0;
	float tmp_vertex1 = 0.0;
	float tmp_vertex2 = 0.0;
	glClearColor(0, 0, 0, 0);//�]�m�L�Ŧ�ø�ϭI���C��(�M���C��^
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 1); //�]�m�`�Ŧ�ø���C��
	glBegin(GL_POLYGON);  //�}�lø�s�����

	//Sleep(speed);
	for (int i = 0; i <= n; i++)
	{
		glColor3f(tmp_color, tmp_color, tmp_color);
		glVertex2f(tmp_vertex1, tmp_vertex2);
		tmp_vertex1 = R * cos(theta + i * 2 * PI / n);
		tmp_vertex2 = R * sin(theta + i * 2 * PI / n);
		glVertex2f(tmp_vertex1, tmp_vertex2);
		glVertex2f(0.0, 0.0);
		tmp_color += i * 0.05;
	}
	glEnd();
	glutSwapBuffers();   //���w�Ī���s�Ҧ��F
}

void myidle()
{
	//�q�L�ɶ��Ȱ��ӧ�����ʳt��
	Sleep(speed);
	theta += 0.5;   //���ਤ�׼W�[1��
	//if (theta >= 2 * PI) {
	//	theta -= 2 * PI;   //�p�G���ਤ�פj��360�סA�h�_��
	//}
	glutPostRedisplay();  //���e�A�۷�󭫷s�ե�Display(),��s�᪺�ܶq�o�H�ǵ�ø�s���
}

void Reshape(GLsizei w, GLsizei h)
{
	glMatrixMode(GL_PROJECTION);  //��v�x�}�Ҧ�
	glLoadIdentity();  //�x�}��̲M��
	gluOrtho2D(-1.5 * R * w / h, 1.5 * R * w / h, -1.5 * R, 1.5 * R);  //�]�m���ŵ��f�j�p
	glViewport(0, 0, w, h); //�]�m���Ϥj�p
	glMatrixMode(GL_MODELVIEW);  //�ҫ��x�}�Ҧ� 
}


void KeyBoards(unsigned char key, int x, int y)
{
	switch (key)
	{
		//�h�X�{��
	case 'a':
		exit(0);
		break;

	case 'A':
		exit(0);
		break;

		//�W�[���
	case 'z':
		n = n + 1;
		break;

	case 'Z':
		n = n + 1;
		break;

		//������
	case 'x':
		n = n - 1;
		break;

	case 'X':
		n = n - 1;
		break;

		//�W�[�t��
	case 'c':
		//����speed�L�p�쬰�t��
		if (speed <= 5)
			break;
		speed -= 5;
		break;

	case 'C':
		//����speed�L�p�쬰�t��
		if (speed <= 5)
			break;
		speed -= 5;
		break;

		//��ֳt��
	case 'v':
		speed += 5;
		break;

	case 'V':
		speed += 5;
		break;
	}
}


