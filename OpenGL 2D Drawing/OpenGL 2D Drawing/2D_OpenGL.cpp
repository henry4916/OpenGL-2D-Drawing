#include <math.h>
#include <Windows.h>
#include <gl\glut.h>
#include <stdlib.h> 
#include <stdio.h>


#define PI 3.14159  //設置圓周率
int n = 10, R = 10;  //多邊形變數，外接圓半徑
float speed = 1.0; //越小越快
float theta = 0.0;  //旋轉初始角度值

void Keyboard(unsigned char key, int x, int y);
void Display(void);
void Reshape(int w, int h);
void myidle();
void KeyBoards(unsigned char key, int x, int y);
void idle(void);

int main(int argc, char** argv)
{
	// must/should match the number of strings in argv
	glutInit(&argc, argv);  //初始化GLUT庫；
	glutInitWindowSize(400, 400);  //設置顯示窗口大小
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);  //設置顯示模式；（注意雙緩衝）
	glutCreateWindow("A Rotating Square"); // 創建顯示窗口
	glutKeyboardFunc(&KeyBoards);  //註冊鍵盤事件
	glutDisplayFunc(Display);  //註冊顯示回調函數
	glutReshapeFunc(Reshape);  //註冊窗口改變回調函數
	glutIdleFunc(myidle);    //註冊閒置回調函數
	glutMainLoop();  //進入事件處理循環
	return 0;
}

void Display(void)
{
	float tmp_color = 0.0;
	float tmp_vertex1 = 0.0;
	float tmp_vertex2 = 0.0;
	glClearColor(0, 0, 0, 0);//設置淺藍色繪圖背景顏色(清屏顏色）
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 1); //設置深藍色繪圖顏色
	glBegin(GL_POLYGON);  //開始繪製六邊形

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
	glutSwapBuffers();   //雙緩衝的刷新模式；
}

void myidle()
{
	//通過時間暫停來改變轉動速度
	Sleep(speed);
	theta += 0.5;   //旋轉角度增加1度
	//if (theta >= 2 * PI) {
	//	theta -= 2 * PI;   //如果旋轉角度大於360度，則復原
	//}
	glutPostRedisplay();  //重畫，相當於重新調用Display(),改編後的變量得以傳給繪製函數
}

void Reshape(GLsizei w, GLsizei h)
{
	glMatrixMode(GL_PROJECTION);  //投影矩陣模式
	glLoadIdentity();  //矩陣堆棧清空
	gluOrtho2D(-1.5 * R * w / h, 1.5 * R * w / h, -1.5 * R, 1.5 * R);  //設置裁剪窗口大小
	glViewport(0, 0, w, h); //設置視區大小
	glMatrixMode(GL_MODELVIEW);  //模型矩陣模式 
}


void KeyBoards(unsigned char key, int x, int y)
{
	switch (key)
	{
		//退出程式
	case 'a':
		exit(0);
		break;

	case 'A':
		exit(0);
		break;

		//增加邊數
	case 'z':
		n = n + 1;
		break;

	case 'Z':
		n = n + 1;
		break;

		//減少邊數
	case 'x':
		n = n - 1;
		break;

	case 'X':
		n = n - 1;
		break;

		//增加速度
	case 'c':
		//防止speed過小到為負數
		if (speed <= 5)
			break;
		speed -= 5;
		break;

	case 'C':
		//防止speed過小到為負數
		if (speed <= 5)
			break;
		speed -= 5;
		break;

		//減少速度
	case 'v':
		speed += 5;
		break;

	case 'V':
		speed += 5;
		break;
	}
}


