// ConsoleApplication6.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "ConsoleApplication6.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 唯一的应用程序对象

CWinApp theApp;

using namespace std;

int main()
{
    int nRetCode = 0;

    HMODULE hModule = ::GetModuleHandle(nullptr);

    if (hModule != nullptr)
    {
        // 初始化 MFC 并在失败时显示错误
        if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
        {
            // TODO: 更改错误代码以符合您的需要
            wprintf(L"错误: MFC 初始化失败\n");
            nRetCode = 1;
        }
        else
        {
            // TODO: 在此处为应用程序的行为编写代码。
        }
    }
    else
    {
        // TODO: 更改错误代码以符合您的需要
        wprintf(L"错误: GetModuleHandle 失败\n");
        nRetCode = 1;
    }

    return nRetCode;
}
# include<stdio.h>
# include<stdlib.h>
# include<string.h>
typedef struct node
{
	char name[10];
	int prio;
	int round;
	int cputime;
	int needtime;
	int count;
	char state;
	struct node*next;
}PCB;

PCB *finish, *ready, *tail, *run;
int N;

firstin()
{
	run = ready;
	run->state = 'R';
	ready = ready->next;
}

void prt1(char a)
{
	if (toupper(a) == 'P')
		printf("进程号cpu时间 所需时间 优先数 状态\n");
	else
		printf("进程号cpu时间 所需时间 记数 时间片 状态\n");
}

void prt2(char a, PCB *q)
{
	if (toupper(a) == 'P')
		printf("%-10s %-10d %-10d %-10d %c\n", q->name, q->cputime, q->needtime, q->prio, q->state);
	else
		printf("%-10s %-10d %-10d %-10d %-10d %-c\n", q->name, q->cputime, q->needtime, q->count, q->round, q->state);
}

void prt(char algo)
{
	PCB *p;
	prt1(algo);
	if (run != NULL)
		prt2(algo, run);
	p = ready;
	while (p != NULL)
	{
		prt2(algo, p);
		p = p->next;
	}
	p = finish;
	while (p != NULL)
	{
		prt2(algo, p);
		p = p->next;
	}
	getchar();
}

insert1(PCB *q)
{
	PCB *p1, *s, *r;
	int b;
	s = q;
	p1 = ready;
	r = p1;
	b = 1;
	while ((p1 != NULL) && b)
		if (p1->prio >= s->prio)
		{
			r = p1;
			p1 = p1->next;
		}
		else
			b = 0;
	if (r != p1)
	{
		r->next = s;
		s->next = p1;
	}
	else
	{
		s->next = p1;
		ready = s;
	}
}

void create1(char alg) {
	PCB *p;
	int i, time;
	char na[10];
	ready = NULL;
	finish = NULL;
	run = NULL;
	printf("输入进程号和运行时间：\n");
	for (i = 1; i <= N; i++) {
		p = (PCB*)malloc(sizeof(PCB));
		scanf("%s", na);
		scanf("%d", &time);
		strcpy(p->name, na);
		p->cputime = 0;
		p->needtime = time;
		p->state = 'w';
		p->prio = 50 - time;
		if (ready != NULL)
			insert1(p);
		else {
			p->next = ready;
			ready = p;
		}
	}
	printf("     优先数算法输出信息：\n");
	printf("********************************************\n");
	prt(alg);
	run = ready;
	ready = ready->next;
	run->state = 'R';
}


priority(char alg) {
	while (run != NULL) {
		run->cputime = run->cputime + 1;
		run->needtime = run->needtime - 1;
		run->prio = run->prio - 3;
		if (run->needtime == 0) {
			run->next = finish;
			finish = run;
			run->state = 'F';
			run = NULL;
			if (ready != NULL) {
				firstin();
			}
		}
		else if ((ready != NULL) && (run->prio<ready->prio)) {
			run->state = 'W';
			insert1(run);
			firstin();
		}
		prt(alg);
	}
}


main() {
	char algo;
	printf("选择算法：P/R(优先数算法/时间片轮转算法)\n");
	scanf("%c", &algo);
	printf("输入进程数：\n");
	scanf("%d", &N);
	if (algo == 'P' || algo == 'p') {
		create1(algo);
		priority(algo);
	}
	else if (algo == 'R' || algo == 'r') {
		create2(algo);
		roundrun(algo);
	}
}
