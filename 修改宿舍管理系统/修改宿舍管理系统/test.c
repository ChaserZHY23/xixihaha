#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h> 

typedef struct pnode	//结构体定义 用于存放学生信息的节点
{
	char name[10];           //姓名
	char num[16];             //学号
	char dor[30];             //宿舍号
	char group[20];           //班级
	char score[10];
}student;

char filename[200] = "data.txt";            //文件名
FILE* fp;                     //指向文件的指针

void creat()	// 创建一个文本文件   用于存放学生数据
{
	student* person;
	person = (student*)malloc(sizeof(student));   //为节点分配内存
	if ((fp = fopen(filename, "w+")) == NULL) { exit(0); }
	printf("data.txt文件已创建。\n\n");
	printf("\n请输入学生的姓名 学号 宿舍号 班级 评分 用空格隔开 以#结束\n");
	scanf("%s", person->name);
	while (strcmp(person->name, "#"))    //该循环用于控制学生信息的录入 遇#结束	
	{
		scanf("%s %s %s %s", person->num, person->dor, person->group, person->score);
		fprintf(fp, "%-10s%-10s%-10s%-10s%-10s\n", person->name, person->num, person->dor, person->group, person->score);
		scanf("%s", person->name);
	}
	fclose(fp);
}

void readfile()	//文件读取函数  
{
	if ((fp = fopen(filename, "r+")) == NULL) { printf("\n无法打开该文件:\n"); exit(0); }
	fclose(fp);
}

void output()	//输出函数 用于输出文件的全部信息
{
	student* person;
	long offset1, offset2;
	char name1[10], name2[10], name3[10];
	char num1[16], num2[16], num3[16];
	char dor1[30], dor2[30], dor3[30];
	char group1[20], group2[20], group3[20];
	char score1[10], score2[10], score3[10];
	person = (student*)malloc(sizeof(student));
	if ((fp = fopen(filename, "r")) == NULL) { printf("\n 无法打开该文件"); exit(0); }

	printf("\n****************************************************************\n");
	printf("%40s\n", "输出的记录如下\n");
	printf("%-20s%-20s%-20s%-20s%-20s\n", "姓名", "学号", "宿舍号", "班级", "评分");
	while (!feof(fp))                            //次循环用于输出文件
	{
		fscanf(fp, "%s%s%s%s%s\n", person->name, person->num, person->dor, person->group, person->score);
		printf("%-20s%-20s%-20s%-20s%-20s\n", person->name, person->num, person->dor, person->group, person->score);
	}
	fclose(fp);
	printf("************************************************************\n\n");
}

void namesearch()	// 按姓名搜索函数
{
	int k = 0;
	char namekey[10];
	student* person;
	person = (student*)malloc(sizeof(student));
	printf("\n 请输入您要查找的姓名:");
	scanf("%s", namekey);
	if ((fp = fopen(filename, "rb")) == NULL) { printf("\n 无法打开文件"); exit(0); }

	while (!feof(fp))
	{
		fscanf(fp, "%s %s %s %s %s\n", person->name, person->num, person->dor, person->group, person->score);
		if (!strcmp(namekey, person->name))
		{
			printf("\n\n 已经为您找到 以下是记录:\n\n");
			printf("%-20s%-20s%-20s%-20s%-20s\n", "姓名", "学号", "宿舍号", "班级", "评分");
			printf("%-20s%-20s%-20s%-20s%-20s\n", person->name, person->num, person->dor, person->group, person->score);
			k = 1;
		}
	}
	if (!k) { printf("\n\n 没有关于此姓名的任何信息！ \n"); }
	fclose(fp);
}

void numsearch()		//按学号搜索函数
{
	int k = 0;
	char xhkey[16];
	student* person;
	person = (student*)malloc(sizeof(student));
	printf("\n 请您输入需要查找的学号：");
	scanf("%s", xhkey);
	if ((fp = fopen(filename, "rb")) == NULL) { printf("\n 无法打开文件 "); exit(0); }

	while (!feof(fp))
	{
		fscanf(fp, "%s %s %s %s %s\n", person->name, person->num, person->dor, person->group, person->score);
		if (!strcmp(xhkey, person->num))
		{
			printf("\n\n 已经为您找到 以下是记录：\n\n");
			printf("%-20s%-20s%-20s%-20s%-20s\n", "姓名", "宿舍号", "房号", "班级", "评分");
			printf("%-20s%-20s%-20s%-20s%-20s\n", person->name, person->num, person->dor, person->group, person->score);
			k = 1;
		}
	}
	if (!k) { printf("\n\n 没有关于该学号的任何信息\n"); }
	fclose(fp);
}

void dorsearch()	//按宿舍号搜索函数
{
	int k = 0;
	char fhkey[30];
	student* person;
	person = (student*)malloc(sizeof(student));
	printf("\n 请您输入想要查找的宿舍号");
	scanf("%s", fhkey);
	if ((fp = fopen(filename, "rb")) == NULL) { printf("\n 无法打开文件"); exit(0); }

	while (!feof(fp))
	{
		fscanf(fp, "%s %s %s %s %s\n", person->name, person->num, person->dor, person->group, person->score);
		if (!strcmp(fhkey, person->dor))
		{
			printf("\n\n 已经为您找到 以下是记录:\n\n");
			printf("%-20s%-20s%-20s%-20s%-20s\n", "姓名", "学号", "宿舍号", "班级", "评分");
			printf("%-20s%-20s%-20s%-20s%-20s\n", person->name, person->num, person->dor, person->group, person->score);
			k = 1;
		}
	}
	if (!k) { printf("\n\n 没有关于此房号的任何信息\n"); }
	fclose(fp);
}
void scoresearch()	// 按评分搜索函数
{
	int k = 0;
	char scorekey[10];
	student* person;
	person = (student*)malloc(sizeof(student));
	printf("\n 请输入您要查找的评分:");
	scanf("%s", scorekey);
	if ((fp = fopen(filename, "rb")) == NULL) { printf("\n 无法打开文件"); exit(0); }

	while (!feof(fp))
	{
		fscanf(fp, "%s %s %s %s %s\n", person->name, person->num, person->dor, person->group, person->score);
		if (!strcmp(scorekey, person->score))
		{
			printf("\n\n 已经为您找到 以下是记录:\n\n");
			printf("%-20s%-20s%-20s%-20s%-20s\n", "姓名", "学号", "宿舍号", "班级", "评分");
			printf("%-20s%-20s%-20s%-20s%-20s\n", person->name, person->num, person->dor, person->group, person->score);
			k = 1;
		}
	}
	if (!k) { printf("\n\n 没有关于此评分的任何信息！ \n"); }
	fclose(fp);
}
void  add()	//插入函数  用于像已有文件插入一条新的学生信息记录
{
	student* person;
	person = (student*)malloc(sizeof(student));
	if ((fp = fopen(filename, "a")) == NULL) { printf("\n 无法打开文件"); exit(0); }
	printf("\n 请您输入学生姓名 学号 宿舍号 班级 评分 \n");
	scanf("%s %s %s %s %s", person->name, person->num, person->dor, person->group, person->score);
	fprintf(fp, "%-10s%-10s%-10s%-10s%-10s\n", person->name, person->num, person->dor, person->group, person->score);
	fclose(fp);
}

void modify()	//更新函数 用于修改指定学生姓名的记录
{
	int k = 0;
	long offset;
	char namekey[10];
	student* person;
	person = (student*)malloc(sizeof(student));
	printf("\n 请您输入想要更改的学生的姓名 :");
	scanf("%s", namekey);
	if ((fp = fopen(filename, "r+")) == NULL) { printf("\n 无法打开文件"); exit(0); }

	while (!feof(fp))
	{
		offset = ftell(fp);
		fscanf(fp, "%s %s %s %s %s\n", person->name, person->num, person->dor, person->group, person->score);
		if (!strcmp(namekey, person->name))    //比较是否相同 如
		{
			k = 1; break;
		}
	}
	if (k)                   //相同 输出记录并进行修改
	{
		printf("\n 记录输出如下：\n\n");
		printf("%-20s%-20s%-20s%-20s%-20s\n", "姓名", "学号", "宿舍号", "班级", "评分");
		printf("%-20s%-20s%-20s%-20s%-20s\n", person->name, person->num, person->dor, person->group, person->score);
		printf("\n 请您输入新的学生姓名 学号 宿舍号 班级 评分 ：\n");
		scanf("%s %s %s %s %s", person->name, person->num, person->dor, person->group, person->score);
		fseek(fp, offset, SEEK_SET);
		fprintf(fp, "%-10s%-10s%-10s%-10s%-10s\n", person->name, person->num, person->dor, person->group, person->score);
	}
	else { printf("\n 没有关于该姓名的任何记录\n"); }
	fclose(fp);
}

void deleted()	//删除函数 用于删除指定学生姓名的记录
{
	int k = 0;
	char m;
	long offset;
	char namekey[10];
	student* person;
	person = (student*)malloc(sizeof(student));
	printf("\n请您输入想要删除的姓名：");
	scanf("%s", namekey);
	if ((fp = fopen(filename, "r+")) == NULL) { printf("\n 无法打开文件 "); exit(0); }
	while (!feof(fp))                   //此循环遍历整个文件 查找需要删除的记录
	{
		offset = ftell(fp);
		fscanf(fp, "%s %s %s %s %s\n", person->name, person->num, person->dor, person->group, person->score);
		if (!strcmp(namekey, person->name))
		{
			k = 1; break;
		}
	}
	if (k)
	{
		printf("\n 记录输出如下：\n\n");
		printf("%-20s%-20s%-20s%-20s%-20s\n", "姓名", "学号", "宿舍号", "班级", "评分");
		printf("%-20s%-20s%-20s%-20s%-20s\n", person->name, person->num, person->dor, person->group, person->score);
		printf("\n  您真的确定要删除?y/n?");
		scanf("%s", &m);
		if (m == 'y')       //删除确认按钮 
		{
			fseek(fp, offset, SEEK_SET);   //删除记录
			fprintf(fp, "%-10s%-10s%-10s%-10s%-10s\n", "", "", "", "", "");
		}
		else { rewind(fp); }
	}
	else { printf("\n 没有关于该姓名的任何记录\n"); }
	fclose(fp);
}

int main()	//主函数，程序入口
{
	int m, flag = 1;	// m用于控制菜单的选择项     flag用于控制菜单弹出
	while (flag)
	{
		printf("%40s\n", "西安工程大学宿舍管理系统");
		printf("--------------------------------------------------------------------------------\n");
		printf("\t\t0 ------------  创建文件\n");
		printf("\t\t1 ------------  打开文件\n");
		printf("\t\t2 ------------  姓名查询\n");
		printf("\t\t3 ------------  学号查询\n");
		printf("\t\t4 ------------  宿舍号查询\n");
		printf("\t\t5 ------------  评分查询\n");
		printf("\t\t6 ------------  修改记录\n");
		printf("\t\t7 ------------  删除记录\n");
		printf("\t\t8 ------------  增加纪录\n");
		printf("\t\t9 ------------  输出记录\n");
		printf("\t\t10 ------------  退出\n");
		printf("--------------------------------------------------------------------------------\n");
		printf("\t 请输入0-10选择您的操作：\n");
		scanf("%d", &m);
		switch (m)
		{
		case 0:creat();
			break;
		case 1:readfile();
			break;
		case 2:namesearch();
			break;
		case 3:numsearch();
			break;
		case 4:dorsearch();
			break;
		case 5:scoresearch();
			break;
		case 6:modify();
			break;
		case 7: deleted();
			break;
		case 8:add();
			break;
		case 9:output();
			break;
		case 10:exit(0);
		default:break;
		}
	}
}