#define _CRT_SECURE_NO_WARNINGS 1
#include<GL\glut.h>
#include<iostream>
#include<cmath>
//using namespace std;
//DDA�㷨����ֱ��
void swapvalue(int* a, int* b);//������Ԥ����
void DrowDDA(int x1, int y1, int x2, int y2)
{
	glColor3f(1.0, 0.0, 0.0);       //��Ҫ���ߵ���ɫΪ��ɫ
	glPointSize(3.0f);
	int m = 0;
	//ѡ�������������ľ�������ֵ
	if (abs(x2 - x1) >= abs(y2 - y1))
	{
		m = abs(x2 - x1);              // x Ϊ�Ƴ�����
	}
	else
	{
		m = abs(y2 - y1);              // y Ϊ�Ƴ�����
	}
	float dx = (float)(x2 - x1) / m;   // �� x Ϊ�Ƴ�����dx = 1
	float dy = (float)(y2 - y1) / m;   // �� y Ϊ�Ƴ�����dy = 1
	float x = x1;
	float y = y1;
	for (int i = 0; i < m; ++i)//ѭ�����ö���
	{
		glBegin(GL_POINTS);//��ÿһ��������Ϊһ�����㴦������N������
		glVertex2f((int)x, (int)y);//���ö���
		glEnd();
		glFlush();
		x += dx;
		y += dy;
	}
}

/*
Bresenham ��ֱ�߷�
*/
void DrowBres(int x1, int y1, int x2, int y2)
{
	glColor3f(0.0, 0.0, 1.0);       // ��ɫ
	glPointSize(2.0f);
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	// �����غ�
	if (dx == 0 && dy == 0)
	{
		glBegin(GL_POINTS);
		glVertex2f(x1, y1);
		glEnd();
		glFlush();
		return;
	}
	int flag = 0;       // ��б�ʱ任�� 0 <= |k| <= 1 ����
	if (dx < dy)
	{
		flag = 1;
		swapvalue(&x1, &y1);//��������������ֵ
		swapvalue(&x2, &y2);//��������������ֵ
		swapvalue(&dx, &dy);//��������������ֵ
	}
	int tx = (x2 - x1) > 0 ? 1 : -1;
	int ty = (y2 - y1) > 0 ? 1 : -1;
	int curx = x1;
	int cury = y1;
	int dS = 2 * dy;
	int dT = 2 * (dy - dx);
	int d = dS - dx;
	while (curx != x2)
	{
		if (d < 0)
			d += dS;
		else
		{
			cury += ty;
			d += dT;
		}
		if (flag)
		{
			glBegin(GL_POINTS);
			glVertex2f(cury, curx);//����
			glEnd();
			glFlush();
		}
		else
		{
			glBegin(GL_POINTS);
			glVertex2f(curx, cury);//����
			glEnd();
			glFlush();
		}
		curx += tx;
	}
}
/*
��������int ���͵ı�����ֵ
*/
void swapvalue(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void display(void)
{
	// �õ�ǰ����ɫ��䴰�ڣ������д�������֮ǰ��ͼ��
	glClear(GL_COLOR_BUFFER_BIT);
	int x1 = 0, y1 = 0, x2 = 500, y2 = 500;
	int x12 = 0, y12 = 0, x22 = 500, y22 = 500;
	DrowDDA(x1, y1, x2, y2);//ʹ��DDA�㷨����ֱ��
	DrowBres(x12, y12, x22, y22);//ʹ��Bresenham��ֱ��
}
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);//��ʼ��glut�Ŀ�
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//ʹ�õ��������RGB moshi
	glutInitWindowPosition(200, 200);//���ڵ�λ��
	glutInitWindowSize(400, 400);//���ڵĴ�С
	glutCreateWindow("�����OpenGl����");
	glutDisplayFunc(display);//���ú���
	glClearColor(1.0, 1.0, 1.0, 0.0);  //���ڵı���Ϊ��ɫ
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 200.0, 0.0, 150.0);
	glutMainLoop();//�� glut ��������¼�ѭ������һ��glut���������ֻ�ܵ���һ�Ρ�һ�����ã���ֱ����������ŷ��ء�
	return 0;
}
