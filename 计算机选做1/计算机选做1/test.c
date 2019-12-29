#define _CRT_SECURE_NO_WARNINGS 1
#include<GL\glut.h>
#include<iostream>
#include<cmath>
//using namespace std;
//DDA算法绘制直线
void swapvalue(int* a, int* b);//函数的预定义
void DrowDDA(int x1, int y1, int x2, int y2)
{
	glColor3f(1.0, 0.0, 0.0);       //所要画线的颜色为红色
	glPointSize(3.0f);
	int m = 0;
	//选择两个点的坐标的距离的最大值
	if (abs(x2 - x1) >= abs(y2 - y1))
	{
		m = abs(x2 - x1);              // x 为计长方向
	}
	else
	{
		m = abs(y2 - y1);              // y 为计长方向
	}
	float dx = (float)(x2 - x1) / m;   // 当 x 为计长方向，dx = 1
	float dy = (float)(y2 - y1) / m;   // 当 y 为计长方向，dy = 1
	float x = x1;
	float y = y1;
	for (int i = 0; i < m; ++i)//循环设置定点
	{
		glBegin(GL_POINTS);//把每一个顶点做为一个定点处理，绘制N个定点
		glVertex2f((int)x, (int)y);//设置定点
		glEnd();
		glFlush();
		x += dx;
		y += dy;
	}
}

/*
Bresenham 画直线法
*/
void DrowBres(int x1, int y1, int x2, int y2)
{
	glColor3f(0.0, 0.0, 1.0);       // 蓝色
	glPointSize(2.0f);
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	// 两点重合
	if (dx == 0 && dy == 0)
	{
		glBegin(GL_POINTS);
		glVertex2f(x1, y1);
		glEnd();
		glFlush();
		return;
	}
	int flag = 0;       // 将斜率变换到 0 <= |k| <= 1 区间
	if (dx < dy)
	{
		flag = 1;
		swapvalue(&x1, &y1);//交换两个变量的值
		swapvalue(&x2, &y2);//交换两个变量的值
		swapvalue(&dx, &dy);//交换两个变量的值
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
			glVertex2f(cury, curx);//画点
			glEnd();
			glFlush();
		}
		else
		{
			glBegin(GL_POINTS);
			glVertex2f(curx, cury);//画点
			glEnd();
			glFlush();
		}
		curx += tx;
	}
}
/*
交换两个int 类型的变量的值
*/
void swapvalue(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void display(void)
{
	// 用当前背景色填充窗口，如果不写这句会残留之前的图像
	glClear(GL_COLOR_BUFFER_BIT);
	int x1 = 0, y1 = 0, x2 = 500, y2 = 500;
	int x12 = 0, y12 = 0, x22 = 500, y22 = 500;
	DrowDDA(x1, y1, x2, y2);//使用DDA算法绘制直线
	DrowBres(x12, y12, x22, y22);//使用Bresenham画直线
}
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);//初始化glut的库
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//使用单缓存或者RGB moshi
	glutInitWindowPosition(200, 200);//窗口的位置
	glutInitWindowSize(400, 400);//窗口的大小
	glutCreateWindow("张扬的OpenGl程序");
	glutDisplayFunc(display);//调用函数
	glClearColor(1.0, 1.0, 1.0, 0.0);  //窗口的背景为白色
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 200.0, 0.0, 150.0);
	glutMainLoop();//让 glut 程序进入事件循环。在一个glut程序中最多只能调用一次。一旦调用，会直到程序结束才返回。
	return 0;
}
