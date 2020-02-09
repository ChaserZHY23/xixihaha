#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h> 

typedef struct pnode	//�ṹ�嶨�� ���ڴ��ѧ����Ϣ�Ľڵ�
{
	char name[10];           //����
	char num[16];             //ѧ��
	char dor[30];             //�����
	char group[20];           //�༶
	char score[10];
}student;

char filename[200] = "data.txt";            //�ļ���
FILE* fp;                     //ָ���ļ���ָ��

void creat()	// ����һ���ı��ļ�   ���ڴ��ѧ������
{
	student* person;
	person = (student*)malloc(sizeof(student));   //Ϊ�ڵ�����ڴ�
	if ((fp = fopen(filename, "w+")) == NULL) { exit(0); }
	printf("data.txt�ļ��Ѵ�����\n\n");
	printf("\n������ѧ�������� ѧ�� ����� �༶ ���� �ÿո���� ��#����\n");
	scanf("%s", person->name);
	while (strcmp(person->name, "#"))    //��ѭ�����ڿ���ѧ����Ϣ��¼�� ��#����	
	{
		scanf("%s %s %s %s", person->num, person->dor, person->group, person->score);
		fprintf(fp, "%-10s%-10s%-10s%-10s%-10s\n", person->name, person->num, person->dor, person->group, person->score);
		scanf("%s", person->name);
	}
	fclose(fp);
}

void readfile()	//�ļ���ȡ����  
{
	if ((fp = fopen(filename, "r+")) == NULL) { printf("\n�޷��򿪸��ļ�:\n"); exit(0); }
	fclose(fp);
}

void output()	//������� ��������ļ���ȫ����Ϣ
{
	student* person;
	long offset1, offset2;
	char name1[10], name2[10], name3[10];
	char num1[16], num2[16], num3[16];
	char dor1[30], dor2[30], dor3[30];
	char group1[20], group2[20], group3[20];
	char score1[10], score2[10], score3[10];
	person = (student*)malloc(sizeof(student));
	if ((fp = fopen(filename, "r")) == NULL) { printf("\n �޷��򿪸��ļ�"); exit(0); }

	printf("\n****************************************************************\n");
	printf("%40s\n", "����ļ�¼����\n");
	printf("%-20s%-20s%-20s%-20s%-20s\n", "����", "ѧ��", "�����", "�༶", "����");
	while (!feof(fp))                            //��ѭ����������ļ�
	{
		fscanf(fp, "%s%s%s%s%s\n", person->name, person->num, person->dor, person->group, person->score);
		printf("%-20s%-20s%-20s%-20s%-20s\n", person->name, person->num, person->dor, person->group, person->score);
	}
	fclose(fp);
	printf("************************************************************\n\n");
}

void namesearch()	// ��������������
{
	int k = 0;
	char namekey[10];
	student* person;
	person = (student*)malloc(sizeof(student));
	printf("\n ��������Ҫ���ҵ�����:");
	scanf("%s", namekey);
	if ((fp = fopen(filename, "rb")) == NULL) { printf("\n �޷����ļ�"); exit(0); }

	while (!feof(fp))
	{
		fscanf(fp, "%s %s %s %s %s\n", person->name, person->num, person->dor, person->group, person->score);
		if (!strcmp(namekey, person->name))
		{
			printf("\n\n �Ѿ�Ϊ���ҵ� �����Ǽ�¼:\n\n");
			printf("%-20s%-20s%-20s%-20s%-20s\n", "����", "ѧ��", "�����", "�༶", "����");
			printf("%-20s%-20s%-20s%-20s%-20s\n", person->name, person->num, person->dor, person->group, person->score);
			k = 1;
		}
	}
	if (!k) { printf("\n\n û�й��ڴ��������κ���Ϣ�� \n"); }
	fclose(fp);
}

void numsearch()		//��ѧ����������
{
	int k = 0;
	char xhkey[16];
	student* person;
	person = (student*)malloc(sizeof(student));
	printf("\n ����������Ҫ���ҵ�ѧ�ţ�");
	scanf("%s", xhkey);
	if ((fp = fopen(filename, "rb")) == NULL) { printf("\n �޷����ļ� "); exit(0); }

	while (!feof(fp))
	{
		fscanf(fp, "%s %s %s %s %s\n", person->name, person->num, person->dor, person->group, person->score);
		if (!strcmp(xhkey, person->num))
		{
			printf("\n\n �Ѿ�Ϊ���ҵ� �����Ǽ�¼��\n\n");
			printf("%-20s%-20s%-20s%-20s%-20s\n", "����", "�����", "����", "�༶", "����");
			printf("%-20s%-20s%-20s%-20s%-20s\n", person->name, person->num, person->dor, person->group, person->score);
			k = 1;
		}
	}
	if (!k) { printf("\n\n û�й��ڸ�ѧ�ŵ��κ���Ϣ\n"); }
	fclose(fp);
}

void dorsearch()	//���������������
{
	int k = 0;
	char fhkey[30];
	student* person;
	person = (student*)malloc(sizeof(student));
	printf("\n ����������Ҫ���ҵ������");
	scanf("%s", fhkey);
	if ((fp = fopen(filename, "rb")) == NULL) { printf("\n �޷����ļ�"); exit(0); }

	while (!feof(fp))
	{
		fscanf(fp, "%s %s %s %s %s\n", person->name, person->num, person->dor, person->group, person->score);
		if (!strcmp(fhkey, person->dor))
		{
			printf("\n\n �Ѿ�Ϊ���ҵ� �����Ǽ�¼:\n\n");
			printf("%-20s%-20s%-20s%-20s%-20s\n", "����", "ѧ��", "�����", "�༶", "����");
			printf("%-20s%-20s%-20s%-20s%-20s\n", person->name, person->num, person->dor, person->group, person->score);
			k = 1;
		}
	}
	if (!k) { printf("\n\n û�й��ڴ˷��ŵ��κ���Ϣ\n"); }
	fclose(fp);
}
void scoresearch()	// ��������������
{
	int k = 0;
	char scorekey[10];
	student* person;
	person = (student*)malloc(sizeof(student));
	printf("\n ��������Ҫ���ҵ�����:");
	scanf("%s", scorekey);
	if ((fp = fopen(filename, "rb")) == NULL) { printf("\n �޷����ļ�"); exit(0); }

	while (!feof(fp))
	{
		fscanf(fp, "%s %s %s %s %s\n", person->name, person->num, person->dor, person->group, person->score);
		if (!strcmp(scorekey, person->score))
		{
			printf("\n\n �Ѿ�Ϊ���ҵ� �����Ǽ�¼:\n\n");
			printf("%-20s%-20s%-20s%-20s%-20s\n", "����", "ѧ��", "�����", "�༶", "����");
			printf("%-20s%-20s%-20s%-20s%-20s\n", person->name, person->num, person->dor, person->group, person->score);
			k = 1;
		}
	}
	if (!k) { printf("\n\n û�й��ڴ����ֵ��κ���Ϣ�� \n"); }
	fclose(fp);
}
void  add()	//���뺯��  �����������ļ�����һ���µ�ѧ����Ϣ��¼
{
	student* person;
	person = (student*)malloc(sizeof(student));
	if ((fp = fopen(filename, "a")) == NULL) { printf("\n �޷����ļ�"); exit(0); }
	printf("\n ��������ѧ������ ѧ�� ����� �༶ ���� \n");
	scanf("%s %s %s %s %s", person->name, person->num, person->dor, person->group, person->score);
	fprintf(fp, "%-10s%-10s%-10s%-10s%-10s\n", person->name, person->num, person->dor, person->group, person->score);
	fclose(fp);
}

void modify()	//���º��� �����޸�ָ��ѧ�������ļ�¼
{
	int k = 0;
	long offset;
	char namekey[10];
	student* person;
	person = (student*)malloc(sizeof(student));
	printf("\n ����������Ҫ���ĵ�ѧ�������� :");
	scanf("%s", namekey);
	if ((fp = fopen(filename, "r+")) == NULL) { printf("\n �޷����ļ�"); exit(0); }

	while (!feof(fp))
	{
		offset = ftell(fp);
		fscanf(fp, "%s %s %s %s %s\n", person->name, person->num, person->dor, person->group, person->score);
		if (!strcmp(namekey, person->name))    //�Ƚ��Ƿ���ͬ ��
		{
			k = 1; break;
		}
	}
	if (k)                   //��ͬ �����¼�������޸�
	{
		printf("\n ��¼������£�\n\n");
		printf("%-20s%-20s%-20s%-20s%-20s\n", "����", "ѧ��", "�����", "�༶", "����");
		printf("%-20s%-20s%-20s%-20s%-20s\n", person->name, person->num, person->dor, person->group, person->score);
		printf("\n ���������µ�ѧ������ ѧ�� ����� �༶ ���� ��\n");
		scanf("%s %s %s %s %s", person->name, person->num, person->dor, person->group, person->score);
		fseek(fp, offset, SEEK_SET);
		fprintf(fp, "%-10s%-10s%-10s%-10s%-10s\n", person->name, person->num, person->dor, person->group, person->score);
	}
	else { printf("\n û�й��ڸ��������κμ�¼\n"); }
	fclose(fp);
}

void deleted()	//ɾ������ ����ɾ��ָ��ѧ�������ļ�¼
{
	int k = 0;
	char m;
	long offset;
	char namekey[10];
	student* person;
	person = (student*)malloc(sizeof(student));
	printf("\n����������Ҫɾ����������");
	scanf("%s", namekey);
	if ((fp = fopen(filename, "r+")) == NULL) { printf("\n �޷����ļ� "); exit(0); }
	while (!feof(fp))                   //��ѭ�����������ļ� ������Ҫɾ���ļ�¼
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
		printf("\n ��¼������£�\n\n");
		printf("%-20s%-20s%-20s%-20s%-20s\n", "����", "ѧ��", "�����", "�༶", "����");
		printf("%-20s%-20s%-20s%-20s%-20s\n", person->name, person->num, person->dor, person->group, person->score);
		printf("\n  �����ȷ��Ҫɾ��?y/n?");
		scanf("%s", &m);
		if (m == 'y')       //ɾ��ȷ�ϰ�ť 
		{
			fseek(fp, offset, SEEK_SET);   //ɾ����¼
			fprintf(fp, "%-10s%-10s%-10s%-10s%-10s\n", "", "", "", "", "");
		}
		else { rewind(fp); }
	}
	else { printf("\n û�й��ڸ��������κμ�¼\n"); }
	fclose(fp);
}

int main()	//���������������
{
	int m, flag = 1;	// m���ڿ��Ʋ˵���ѡ����     flag���ڿ��Ʋ˵�����
	while (flag)
	{
		printf("%40s\n", "�������̴�ѧ�������ϵͳ");
		printf("--------------------------------------------------------------------------------\n");
		printf("\t\t0 ------------  �����ļ�\n");
		printf("\t\t1 ------------  ���ļ�\n");
		printf("\t\t2 ------------  ������ѯ\n");
		printf("\t\t3 ------------  ѧ�Ų�ѯ\n");
		printf("\t\t4 ------------  ����Ų�ѯ\n");
		printf("\t\t5 ------------  ���ֲ�ѯ\n");
		printf("\t\t6 ------------  �޸ļ�¼\n");
		printf("\t\t7 ------------  ɾ����¼\n");
		printf("\t\t8 ------------  ���Ӽ�¼\n");
		printf("\t\t9 ------------  �����¼\n");
		printf("\t\t10 ------------  �˳�\n");
		printf("--------------------------------------------------------------------------------\n");
		printf("\t ������0-10ѡ�����Ĳ�����\n");
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