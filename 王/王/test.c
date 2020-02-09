#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <wincon.h>
#include <conio.h>
#include <string.h>
#include <io.h>
#include <fcntl.h>
#include <sys\stat.h>
#include <ctype.h>
#include <time.h>

#ifndef TYPE_H_INCLUDED
#define TYPE_H_INCLUDED

#define SCR_ROW 25             /*��Ļ����*/
#define SCR_COL 80             /*��Ļ����*/


			/**
			*�ɷ���Ϣ�����ṹ
			*/
	typedef struct charge_node {
	char stu_id[12];           /**< ѧ��*/
	char name[10];             /**< ����*/
	char date[12];             /**< �ɷ�����*/
	float sum;                 /**< �ɷѽ��*/
	char payee[10];            /**< �շ���*/
	char notes[5];             /**< ��ע*/
	struct charge_node *next;  /**< ָ����һ����ָ��*/
} CHARGE_NODE;

*ѧ��������Ϣ�����ṹ
* /
typedef struct stu_node {
	char stu_id[12];            /**< ѧ��*/
	char name[10];              /**< ����*/
	char sex[4];                   /**< �Ա�*/
	char birthday[12];          /**< ��������*/
	char type[5];               /**< ѧ�����*/
	char term;                  /**< ѧ��*/
	char enroll_date[10];        /**< ��ѧ����*/
	char class_id[10];          /**< �༶*/
	char dorm_id[5];            /**< ����¥��*/
	char room[5];               /**< �����*/
	char tel[20];               /**< ��ϵ�绰*/
	struct charge_node *cnext;  /**< ָ��ɷ���Ϣ֧����ָ��*/
	struct stu_node *next;      /**< ָ����һ����ָ��*/
} STU_NODE;

/**
*����¥��Ϣ�����ṹ
*/
typedef struct dorm_node {
	char dorm_id[5];         /**< ����¥��*/
	char name[10];           /**< ����*/
	char tel[20];            /**< ��ϵ�绰*/
	short room_amount;       /**< ������Ŀ*/
	short bed_amount;        /**< ��λ��Ŀ*/
	float fee;               /**< ÿ��λÿ��ס�޷�*/
	struct stu_node *snext;  /**< ָ��ѧ��������Ϣ֧����ָ��*/
	struct dorm_node *next;  /**< ָ����һ����ָ��*/
} DORM_NODE;

/**
*����¥��ס��ͳ����Ϣ�����ṹ
*/
typedef struct use_rate_node {
	char dorm_id[5];            	/**< ����¥��*/
	unsigned short total_num;     	/**< ��סѧ����*/
	unsigned short used_num;     	/**< ��סѧ����*/
	unsigned short free_num;     	/**< �մ�λ��*/
	float use_rate;              	/**< ��ס��*/
	struct use_rate_node *next;   	/**< ָ����һ����ָ��*/
} USE_RATE_NODE;

/**
*��סѧ������ͳ����Ϣ�����ṹ
*/
typedef struct stu_type_node {
	char grade[5];               	/**< �꼶*/
	unsigned short school_boy1;   	/**< ��ר������*/
	unsigned short school_girl1;   	/**< Ůר������*/
	unsigned short school_boy2;   	/**< �б�������*/
	unsigned short school_girl2;   	/**< Ů��������*/
	unsigned short school_boy3;   	/**< ��˶ʿ����*/
	unsigned short school_girl3;   	/**< Ů˶ʿ����*/
	unsigned short school_boy4;   	/**< �в�ʿ����*/
	unsigned short school_girl4;   	/**< Ů��ʿ����*/
	unsigned short school_boy5;   	/**< ����������*/
	unsigned short school_girl5;   	/**< ����Ů����*/
	struct stu_type_node *next;    	/**< ָ����һ����ָ��*/
} STU_TYPE_NODE;

/**
*����¥���ס�޷�����ͳ����Ϣ�����ṹ
*/
typedef struct income_node {
	char dorm_id[5];            	/**< ����¥��*/
	float year1_income;          	/**< ���1����*/
	float year2_income;          	/**< ���2����*/
	float year3_income;          	/**< ���3����*/
	float year4_income;          	/**< ���4����*/
	struct income_node *next;     	/**< ָ����һ����ָ��*/
} INCOME_NODE;

/**
*��סѧ��Ƿ��ͳ����Ϣ�����ṹ
*/
typedef struct uncharge_node {
	char stu_id[12];             	/**< ѧ��*/
	char name[10];             	    /**< ����*/
	char dorm_id[5];            	/**< ����¥��*/
	char room_num[5];               /**< �����*/
	float amount;               	/**< Ƿ�ɽ��*/
	struct uncharge_node *next;   	/**< ָ����һ����ָ��*/
} UNCHARGE_NODE;

/**
*��Ļ������Ϣ�������ṹ
*/
typedef struct layer_node {
	char LayerNo;            /**< �������ڲ���*/
	SMALL_RECT rcArea;       /**< ����������������*/
	CHAR_INFO *pContent;     /**< �������������ַ���Ԫԭ��Ϣ�洢������*/
	char *pScrAtt;           /**< �������������ַ���Ԫԭ����ֵ�洢������*/
	struct layer_node *next; /**< ָ����һ����ָ��*/
} LAYER_NODE;

/**
*��ǩ���ṹ
*/
typedef struct labe1_bundle {
	char **ppLabel;        /**< ��ǩ�ַ��������׵�ַ*/
	COORD *pLoc;           /**< ��ǩ��λ�����׵�ַ*/
	int num;               /**< ��ǩ����*/
} LABEL_BUNDLE;

/**
*�����ṹ
*/
typedef struct hot_area {
	SMALL_RECT *pArea;     /**< ������λ�����׵�ַ*/
	char *pSort;           /**< �������(�������ı���ѡ���)�����׵�ַ*/
	char *pTag;            /**< ������������׵�ַ*/
	int num;               /**< ��������*/
} HOT_AREA;

LAYER_NODE *gp_top_layer = NULL;               /*����������Ϣ����ͷ*/
DORM_NODE *gp_head = NULL;                     /*����ͷָ��*/

char *gp_sys_name = "ѧ��ס����Ϣ����ϵͳ";    /*ϵͳ����*/
char *ga_main_menu[] = { "�ļ�(F)",             /*ϵͳ���˵���*/
"����ά��(M)",
"���ݲ�ѯ(Q)",
"����ͳ��(S)",
"����(H)"
};

char *ga_sub_menu[] = { "[S] ���ݱ���",          /*ϵͳ�Ӳ˵���*/
"[B] ���ݱ���",
"[R] ���ݻָ�",

"[X] �˳�    Alt+X",
"[A] �������¥��Ϣ",
"[M] �޸�����¥��Ϣ",
"[D] ɾ������¥��Ϣ",
"",
"[L] ���ѧ��������Ϣ",
"[V] �޸�ѧ��������Ϣ",
"[H] ɾ��ѧ��������Ϣ",
"",
"[C] ���ס�޽ɷ���Ϣ",
"[T] �޸�ס�޽ɷ���Ϣ",
"[X] ɾ��ס�޽ɷ���Ϣ",
"[D] ����¥��Ϣ",
"[P] ѧ��������Ϣ",
"[C] ѧ��ס�޽ɷ���Ϣ",
"[U] �༶ס�޽ɷ���Ϣ",
"[I] ����¥��ס��",
"[T] ��סѧ������",
"[C] ����¥����������",
"[U] ס�޷�Ƿ�����",
"[T] ��������",
"",
"[A] ����..."
};

int ga_sub_menu_count[] = { 4, 11, 4, 4, 3 };  /*�����˵������Ӳ˵��ĸ���*/
int gi_sel_menu = 1;                        /*��ѡ�е����˵����,��ʼΪ1*/
int gi_sel_sub_menu = 0;                    /*��ѡ�е��Ӳ˵����,��ʼΪ0,��ʾδѡ��*/
char *FileName[3] = { "Dorm.dat","Stu.dat","Charge.dat" }; /*�������������Ϣ�����ļ�*/
char *BeiFen_FileName[3] = { "Bdorm.dat","Bstu.dat","Bcharge.dat" }; /*�������������Ϣ�����ļ�*/
char * IP_FileName = "Ip.txt";/*�ʺ�������Ϣ�����ļ�*/

CHAR_INFO *gp_buff_menubar_info = NULL;     /*��Ų˵�����Ļ���ַ���Ϣ�Ļ�����*/
CHAR_INFO *gp_buff_stateBar_info = NULL;    /*���״̬����Ļ���ַ���Ϣ�Ļ�����*/

char *gp_scr_att = NULL;    /*�����Ļ���ַ���Ԫ����ֵ�Ļ�����*/

HANDLE gh_std_out;          /*��׼����豸���*/
HANDLE gh_std_in;           /*��׼�����豸���*/

void CreatList(DORM_NODE **pphead, char *fn[3]);              /*�����������*/
void InitInterface(void);                 /*ϵͳ�����ʼ��*/
void ClearScreen(void);                         /*����*/
inline void Gotoxy(COORD pos);                  /*��λ���*/
inline void ScreenFresh(void);                  /*ˢ��*/
void ShowMenu(void);                            /*��ʾ�˵���*/
void PopMenu(int num);                          /*��ʾ�����˵�*/
void PopPrompt(int num);                        /*��ʾ��������*/
void PopUp(SMALL_RECT *, WORD, LABEL_BUNDLE *, HOT_AREA *);  /*����������Ļ��Ϣά��*/
void PopOff(void);                              /*�رն��㵯������*/
void DrawBox(SMALL_RECT *parea);                /*���Ʊ߿�*/
void LocSubMenu(int num, SMALL_RECT *parea);    /*���˵������˵���λ*/
void ShowState(void);                           /*��ʾ״̬��*/
void TagMainMenu(int num);                      /*��Ǳ�ѡ�е����˵���*/
void TagSubMenu(int num);                       /*��Ǳ�ѡ�е��Ӳ˵���*/
int DealConInput(HOT_AREA *phot_area, int *pihot_num);  /*����̨���봦��*/
void SetHotPoint(HOT_AREA *phot_area, int hot_num);     /*��������*/
void RunSys(DORM_NODE **pphd);                  /*ϵͳ����ģ���ѡ�������*/
BOOL ExeFunction(int main_menu_num, int sub_menu_num);  /*����ģ��ĵ���*/
void CloseSys(DORM_NODE *phd);                  /*�˳�ϵͳ*/
void  Start(void);		/* ���뻶ӭ����*/
void  Login(IP *head);		/* ���뺯��*/
void  PrintBox(void);		/* ������*/
void  Welcome(void); 		/* ����ע�����*/
void  Register(IP **head);		/* ע�����ʺ�*/
void  SaveIp(IP *head);		/* �����ʺ���������.*/
void  LoadIp(IP **head);	/* �����ʺ���������.*/


BOOL LoadData(void);           /*���ݼ���*/
BOOL SaveData(void);           /*��������*/
BOOL BackupData(void);         /*��������*/
BOOL RestoreData(void);        /*�ָ�����*/
BOOL ExitSys(void);            /*�˳�ϵͳ*/
BOOL HelpTopic(void);          /*��������*/
BOOL AboutDorm(void);          /*����ϵͳ*/

BOOL InsertDormInfo(void);   /*�������¥��Ϣ*/
void InsertDormNode(DORM_NODE **hd); /*��������¥��Ϣ���*/
BOOL DelDormInfo(void);      /*ɾ������¥��Ϣ*/
int DelDormNode(DORM_NODE **hd, char *dorm_id); /*ɾ������¥��Ϣ���*/
BOOL ModifDormInfo(void);    /*�޸�����¥��Ϣ*/
int ModifDormNode(DORM_NODE *hd, char *dorm_id, DORM_NODE *pdorm_node); /*�޸�����¥��Ϣ*/

BOOL InsertStuInfo(void);    /*���ѧ��������Ϣ*/
int InsertStuNode(DORM_NODE *hd); /*����ѧ��������Ϣ���*/
BOOL DelStuInfo(void);       /*ɾ��ѧ��������Ϣ*/
int DelStuNode(DORM_NODE *hd, char *stu_id); /*ɾ��ѧ��������Ϣ���*/
BOOL ModifStuInfo(void);     /*�޸�ѧ��������Ϣ*/
int ModifStuNode(DORM_NODE *hd, char *stu_id, STU_NODE *pstu_node); /*�޸�ѧ��������Ϣ*/

BOOL InsertChargeInfo(void); /*��ӽɷ���Ϣ*/
int InsertChargeNode(DORM_NODE *hd, CHARGE_NODE *pcharge_node);/*����ɷ���Ϣ���*/
BOOL DelChargeInfo(void);    /*ɾ���ɷ���Ϣ*/
int DelChargeNode(DORM_NODE *hd, char *stu_id, char *date);  /*ɾ���ɷ���Ϣ���*/
BOOL ModifChargeInfo(void);/*�޸Ľɷ���Ϣ*/
int ModifChargeNode(DORM_NODE *hd, char *stu_id, char *date, CHARGE_NODE *pcharge_node);/*�޸Ľɷ���Ϣ*/

BOOL QueryDormInfo(void); /*��ѯ����¥��Ϣ*/
DORM_NODE *SeekDormNode(DORM_NODE *hd, char *dorm_id);/*��������¥��Ϣ���*/
BOOL QueryStuInfo(void);   /*��ѯѧ��������Ϣ*/
STU_NODE *SeekStuNode(DORM_NODE *hd, char *stu_id);  /*����ѧ��������Ϣ���*/
BOOL QueryChargeInfo(void); /*��ѯѧ���ɷ���Ϣ*/
CHARGE_NODE *SeekChargeNode(DORM_NODE *hd, char *stu_id, char *date); /*����ѧ���ɷ���Ϣ���*/
BOOL QueryClassChargeInfo(void); /*��ѯ�༶�ɷ���Ϣ*/
CLASS_CHARGE_NODE *SeekClassChargeNode(DORM_NODE *hd, char *class_id, char *date); /*ͳ�ư༶�ɷ���Ϣ*/
void SortClasschargeInfo(CLASS_CHARGE_NODE *class_charge_hd); /*�༶�ɷ���Ϣ����*/

BOOL StatUsedRate(void); /*ͳ������¥��ס��*/
USE_RATE_NODE *StatUseRateInfo(DORM_NODE *hd); /*ͳ������¥��ס��*/
void SortUseRateInfo(USE_RATE_NODE *use_rate_hd);/*����¥��ס������*/
BOOL StatStuType(void); /*ѧ������ͳ��*/
STU_TYPE_NODE *StatStuTypeInfo(DORM_NODE *hd); /*ѧ������ͳ��*/
BOOL StatDormCharge(void); /*����¥�������ͳ��*/
INCOME_NODE *StatDormIncomeInfo(DORM_NODE *hd); /*����¥�������ͳ��*/
BOOL StatClassCharge(void); /*�༶�ɷ����ͳ��*/
BOOL StatUncharge(void);   /*Ƿ�ɷ����ͳ��*/
UNCHARGE_NODE *StatUnchargeInfo(DORM_NODE *hd);/*Ƿ�ɷ����ͳ��*/
void SortUnchargeInfo(UNCHARGE_NODE *uncharge_hd);/*Ƿ�ɷ����ͳ������*/


STU_NODE *SeekStuNodeM(DORM_NODE *phd, int cond_num, ...);/*ģ����ѯѧ����Ϣ���*/
BOOL JudgeStuNodeItem(STU_NODE *pstu_node, char *pcond);/*�ж�ѧ����Ϣ�������Ƿ������ѯ����*/
BOOL MatchString(char *string_item, char *pcond);/*�ַ������ѯ�����Ƿ�����ָ���������ϵ*/
BOOL MatchChar(char char_item, char *pcond);/*�ַ����ѯ�����Ƿ�����ָ���������ϵ*/


void SaveSysData(DORM_NODE *phd, char *fn[3]);                       /*����ϵͳ����*/

#endif /**< TYPE_H_INCLUDED*/


																	 /**< Main����.*/
#include "dorm.h"

unsigned long ul;

int main()
{
	COORD size = { SCR_COL, SCR_ROW };              /*���ڻ�������С*/

	Start();                                      /*���뻶ӭ����*/
	gh_std_out = GetStdHandle(STD_OUTPUT_HANDLE); /* ��ȡ��׼����豸���*/
	gh_std_in = GetStdHandle(STD_INPUT_HANDLE);   /* ��ȡ��׼�����豸���*/

	SetConsoleTitle(gp_sys_name);                 /*���ô��ڱ���*/
	SetConsoleScreenBufferSize(gh_std_out, size); /*���ô��ڻ�������С80*25*/

	LoadData();                   /*���ݼ���*/
	InitInterface();          /*�����ʼ��*/
	RunSys(&gp_head);             /*ϵͳ����ģ���ѡ������*/
	CloseSys(gp_head);            /*�˳�ϵͳ*/

	return 0;
}

/**< ��ʼ����ϵͳ��ӭ����.*/
void Start(void)
{
	COORD pos = { 18,8 };
	int goal;
	CONSOLE_CURSOR_INFO lpCur;
	Gotoxy(pos);
	printf("*  * ");
	Delay();
	printf(" *  * ");
	Delay();
	printf(" *  * ");
	Delay();
	printf(" *  * ");
	Delay();
	printf(" *   * ");
	Delay();
	printf(" *  * ");
	Delay();
	printf(" *  *\n\n");
	Delay();
	printf("%15s��%10s", " ", " ");
	printf("  �� ");
	Delay();
	printf(" �� ");
	Delay();
	printf(" ӭ ");
	Delay();
	printf(" �� ");
	Delay();
	printf(" �� ");
	Delay();
	printf(" ��\n\n");
	Delay();
	printf("%15s��", " ");
	printf("     ѧ ");
	Delay();
	printf(" �� ");
	Delay();
	printf(" ס ");
	Delay();
	printf(" �� ");
	Delay();
	printf(" �� ");
	Delay();
	printf(" �� ");
	Delay();
	printf(" ϵ ");
	Delay();
	printf(" ͳ\n\n");
	Delay();
	printf("%15s��", " ");
	printf(" ��");
	Delay();
	printf("Ȩ");
	Delay();
	printf("��");
	Delay();
	printf("��");
	Delay();
	printf(" (C)");
	Delay();
	printf(" 2016/09 ");
	Delay();
	printf("��");
	Delay();
	printf(" ");
	Delay();
	printf("U201514588 ���� \n\n");
	printf("%15s��", " ");
	printf("  *  * ");
	Delay();
	printf(" *  * ");
	Delay();
	printf(" *  * ");
	Delay();
	printf(" *  * ");
	Delay();
	printf(" *   * ");
	Delay();
	printf(" *  * ");
	Delay();
	printf(" *  *\n");
	Sleep(1000);
	printf("\n%15s��%13s�����������ϵͳ...", " ", " ");
	getch();
	ScreenFresh();
	return;
}

/**< ʱ������0.05s.*/
inline void Delay(void)
{
	int goal;
	goal = 50 + clock();
	while (goal > clock());
}

/**
* ��������: LoadData
* ��������: ������������ݴ������ļ����뵽ʮ��������.
* �������: ��
* �������: ��
* �� �� ֵ: BOOL����, ���ܺ����г��˺���ExitSys�ķ���ֵ����ΪFALSE��,
*           ���������ķ���ֵ����ΪTRUE.
*
* ����˵��:
*/
BOOL LoadData()
{
	BOOL bRet = TRUE;

	CreatList(&gp_head, FileName);
	printf("���سɹ���\n");
	return bRet;
}
/**
* ��������: LoadCode
* ��������: �������������ļ����뵽�ڴ滺����, �����������ȥ���ո�.
* �������: FileName ��Ŵ����������ļ���.
* �������: pBuffer ָ���ڴ滺������ָ������ĵ�ַ.
* �� �� ֵ: ��Ŵ������ڴ滺������С(���ֽ�Ϊ��λ).
*
* ����˵��:
*/
int LoadCode(char *FileName, char **pBuffer)
{
	char *pTemp, *pStr1, *pStr2;
	int handle;
	int BufferLen, len, loc1, loc2, i;
	long filelen;

	if ((handle = open(FileName, O_RDONLY | O_TEXT)) == -1) /*�����ֻ����ʽ��ʧ�� */
	{
		handle = open(FileName, O_CREAT | O_TEXT, S_IREAD); /*�Դ�����ʽ��*/
	}
	filelen = filelength(handle);      /*�����ļ��ĳ���*/
	pTemp = (char *)calloc(filelen + 1, sizeof(char)); /*����ͬ����С�Ķ�̬�洢��*/
	BufferLen = read(handle, pTemp, filelen); /*�������ļ�������ȫ�����뵽�ڴ�*/
	close(handle);

	*(pTemp + BufferLen) = '\0'; /*�ڶ�̬�洢��β��һ�����ַ�����Ϊ�ַ���������־*/
	BufferLen++;

	for (i = 0; i<BufferLen; i++) /*����̬�洢���е����л��з��滻�ɿ��ַ�*/
	{
		if (*(pTemp + i) == '\n')
		{
			*(pTemp + i) = '\0';
		}
	}

	/*������һ��ͬ����С�Ķ�̬�洢�������ڴ�������Ĵ��봮*/
	*pBuffer = (char *)calloc(BufferLen, sizeof(char));
	loc2 = 0;
	pStr1 = pTemp;
	len = strlen(pStr1);

	while (BufferLen > len + 1) /*ѡ������*/
	{
		loc1 = len + 1;
		while (BufferLen > loc1) /*ÿ���ҵ���������С���봮���׵�ַ����pStr1*/
		{
			pStr2 = pTemp + loc1;
			if (strcmp(pStr1, pStr2) > 0)
			{
				pStr1 = pStr2;
			}
			loc1 += strlen(pStr2) + 1;
		}
		len = strlen(pStr1);  /*��һ�����ҵ�����С���봮����*/

							  /*������ǿմ�������и��ƣ�loc2����һ����С���봮��ŵ�ַ��ƫ����*/
		if (len > 0)
		{
			strcpy(*pBuffer + loc2, pStr1);
			loc2 += len + 1;  /*�Ѹ��ƵĴ��봮��ռ�洢�ռ��С*/
		}

		/*����С���봮��������ɾ����*/
		for (i = 0; i<BufferLen - (pStr1 - pTemp) - (len + 1); i++)
		{
			*(pStr1 + i) = *(pStr1 + i + len + 1);
		}

		BufferLen -= len + 1; /*��һ���������������еĳ���*/
		pStr1 = pTemp;  /*�ٶ����еĵ�һ�����봮Ϊ��С���봮*/
		len = strlen(pStr1);
	} /*������ֻʣ��һ�����봮ʱ���������*/

	  /*�������������봮*/
	len = strlen(pStr1);
	strcpy(*pBuffer + loc2, pStr1);

	/*�޸Ķ�̬�洢����С��ʹ�����÷����������봮*/
	loc2 += len + 1;
	*pBuffer = (char *)realloc(*pBuffer, loc2);
	free(pTemp);  /*�ͷ���������Ķ�̬�洢��*/

	return loc2;  /*���ش�Ŵ��봮���ڴ滺����ʵ�ʴ�С*/
}

/**
* ��������: CreatList
* ��������: �������ļ���ȡ��������, ����ŵ���������ʮ��������.
* �������: ��
* �������: phead ����ͷָ��ĵ�ַ, ����������������ʮ����.
* �� �� ֵ: int����ֵ, ��ʾ�����������.
*           0  ����, ������
*           4  �Ѽ�������¥��Ϣ���ݣ���ѧ��������Ϣ�ͽɷ���Ϣ����
*           12 �Ѽ�������¥��Ϣ��ѧ��������Ϣ���ݣ��޽ɷ���Ϣ����
*           28 ����������ݶ��Ѽ���
*
* ����˵��:
*/
void CreatList(DORM_NODE **phead, char*fn[3])
{
	DORM_NODE *hd = NULL, *pDormNode, tmp1;
	STU_NODE *pStuNode, tmp2;
	CHARGE_NODE *pChargeNode, tmp3;
	FILE *pFile;
	int find;
	int re = 0;

	if ((pFile = fopen(fn[0], "rb")) == NULL)
	{
		printf("����¥��Ϣ�����ļ���ʧ��!\n");
		return re;
	}


	/*�������ļ��ж�����¥��Ϣ���ݣ������Ժ���ȳ���ʽ������������*/
	while (fread(&tmp1, sizeof(DORM_NODE), 1, pFile) == 1)
	{
		pDormNode = (DORM_NODE *)malloc(sizeof(DORM_NODE));
		*pDormNode = tmp1;
		pDormNode->snext = NULL;
		pDormNode->next = hd;
		hd = pDormNode;
	}
	fclose(pFile);
	if (hd == NULL)
	{
		printf("����¥��Ϣ�����ļ�����ʧ��!\n");
		return re;
	}
	printf("����¥��Ϣ�����ļ����سɹ�!\n");
	*phead = hd;
	re += 4;

	if ((pFile = fopen(fn[1], "rb")) == NULL)
	{
		printf("ѧ��������Ϣ�����ļ���ʧ��!\n");
		return re;
	}
	printf("ѧ��������Ϣ�����ļ��򿪳ɹ�!\n");
	re += 8;

	/*�������ļ��ж�ȡѧ��������Ϣ���ݣ�����������Ӧ����ѧ��������Ϣ֧����*/
	while (fread(&tmp2, sizeof(STU_NODE), 1, pFile) == 1)
	{
		/*������㣬��Ŵ������ļ��ж�����ѧ��������Ϣ*/
		pStuNode = (STU_NODE *)malloc(sizeof(STU_NODE));
		*pStuNode = tmp2;
		pStuNode->cnext = NULL;

		/*�������ϲ��Ҹ�ѧ����ס����¥��Ӧ���������*/
		pDormNode = hd;
		while (pDormNode != NULL
			&& strcmp(pDormNode->dorm_id, pStuNode->dorm_id) != 0)
		{
			pDormNode = pDormNode->next;
		}
		if (pDormNode != NULL) /*����ҵ����򽫽���Ժ���ȳ���ʽ����ѧ����Ϣ֧��*/
		{
			pStuNode->next = pDormNode->snext;
			pDormNode->snext = pStuNode;
		}
		else  /*���δ�ҵ������ͷ������������ڴ�ռ�*/
		{
			free(pStuNode);
		}
	}
	fclose(pFile);

	if ((pFile = fopen(fn[2], "rb")) == NULL)
	{
		printf("ס�޽ɷ���Ϣ�����ļ���ʧ��!\n");
		return re;
	}
	printf("ס�޽ɷ���Ϣ�����ļ��򿪳ɹ�!\n");
	re += 16;

	/*�������ļ��ж�ȡѧ���ɷ���Ϣ���ݣ�����ѧ��������Ϣ֧����Ӧ���Ľɷ�֧����*/
	while (fread(&tmp3, sizeof(CHARGE_NODE), 1, pFile) == 1)
	{
		/*������㣬��Ŵ������ļ��ж�����ѧ���ɷ���Ϣ*/
		pChargeNode = (CHARGE_NODE *)malloc(sizeof(CHARGE_NODE));
		*pChargeNode = tmp3;

		/*����ѧ����Ϣ֧���϶�Ӧѧ����Ϣ���*/
		pDormNode = hd;
		find = 0;
		while (pDormNode != NULL && find == 0)
		{
			pStuNode = pDormNode->snext;
			while (pStuNode != NULL && find == 0)
			{
				if (strcmp(pStuNode->stu_id, pChargeNode->stu_id) == 0)
				{
					find = 1;
					break;
				}
				pStuNode = pStuNode->next;
			}
			pDormNode = pDormNode->next;
		}
		if (find)  /*����ҵ����򽫽���Ժ���ȳ���ʽ����ѧ���ɷ���Ϣ֧����*/
		{
			pChargeNode->next = pStuNode->cnext;
			pStuNode->cnext = pChargeNode;
		}
		else /*���δ�ҵ������ͷ������������ڴ�ռ�*/
		{
			free(pChargeNode);
		}
	}
	fclose(pFile);

	return re;
}

/**
* ��������: InitInterface
* ��������: ��ʼ������.
* �������: ��
* �������: ��
* �� �� ֵ: ��
*
* ����˵��:
*/
void InitInterface()
{
	WORD att = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY
		| BACKGROUND_BLUE;  /*��ɫǰ������ɫ����*/

	SetConsoleTextAttribute(gh_std_out, att);  /*���ÿ���̨��Ļ�������ַ�����*/

	ClearScreen();  /* ����*/

					/*��������������Ϣ��ջ������ʼ�������Ļ���ڵ�����һ�㵯������*/
	gp_scr_att = (char *)calloc(SCR_COL * SCR_ROW, sizeof(char));  /*��Ļ�ַ�����*/
	gp_top_layer = (LAYER_NODE *)malloc(sizeof(LAYER_NODE));
	gp_top_layer->LayerNo = 0;      /*�������ڵĲ��Ϊ0*/
	gp_top_layer->rcArea.Left = 0;  /*�������ڵ�����Ϊ������Ļ����*/
	gp_top_layer->rcArea.Top = 0;
	gp_top_layer->rcArea.Right = SCR_COL - 1;
	gp_top_layer->rcArea.Bottom = SCR_ROW - 1;
	gp_top_layer->pContent = NULL;
	gp_top_layer->pScrAtt = gp_scr_att;
	gp_top_layer->next = NULL;

	ShowMenu();     /*��ʾ�˵���*/
	ShowState();    /*��ʾ״̬��*/

	return;
}

/**
* ��������: ClearScreen
* ��������: �����Ļ��Ϣ.
* �������: ��
* �������: ��
* �� �� ֵ: ��
*
* ����˵��:
*/
void ClearScreen(void)
{
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	COORD home = { 0, 0 };
	unsigned long size;

	GetConsoleScreenBufferInfo(gh_std_out, &bInfo);/*ȡ��Ļ��������Ϣ*/
	size = bInfo.dwSize.X * bInfo.dwSize.Y; /*������Ļ�������ַ���Ԫ��*/

											/*����Ļ���������е�Ԫ���ַ���������Ϊ��ǰ��Ļ�������ַ�����*/
	FillConsoleOutputAttribute(gh_std_out, bInfo.wAttributes, size, home, &ul);

	/*����Ļ���������е�Ԫ���Ϊ�ո��ַ�*/
	FillConsoleOutputCharacter(gh_std_out, ' ', size, home, &ul);

	return;
}

/**
* ��������: ShowMenu
* ��������: ����Ļ����ʾ���˵�, ����������, �����˵���һ������ѡ�б��.
* �������: ��
* �������: ��
* �� �� ֵ: ��
*
* ����˵��:
*/
void ShowMenu()
{
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	CONSOLE_CURSOR_INFO lpCur;
	COORD size;
	COORD pos = { 0, 0 };
	int i, j;
	int PosA = 2, PosB;
	char ch;

	GetConsoleScreenBufferInfo(gh_std_out, &bInfo);
	size.X = bInfo.dwSize.X;
	size.Y = 1;
	SetConsoleCursorPosition(gh_std_out, pos);
	for (i = 0; i < 5; i++) /*�ڴ��ڵ�һ�е�һ�д�������˵���*/
	{
		printf("  %s  ", ga_main_menu[i]);
	}

	GetConsoleCursorInfo(gh_std_out, &lpCur);
	lpCur.bVisible = FALSE;
	SetConsoleCursorInfo(gh_std_out, &lpCur);  /*���ع��*/

											   /*���붯̬�洢����Ϊ��Ų˵�����Ļ���ַ���Ϣ�Ļ�����*/
	gp_buff_menubar_info = (CHAR_INFO *)malloc(size.X * size.Y * sizeof(CHAR_INFO));
	SMALL_RECT rcMenu = { 0, 0, size.X - 1, 0 };

	/*�����ڵ�һ�е����ݶ��뵽��Ų˵�����Ļ���ַ���Ϣ�Ļ�������*/
	ReadConsoleOutput(gh_std_out, gp_buff_menubar_info, size, pos, &rcMenu);

	/*����һ����Ӣ����ĸ��Ϊ��ɫ�������ַ���Ԫ��Ϊ�׵׺���*/
	for (i = 0; i<size.X; i++)
	{
		(gp_buff_menubar_info + i)->Attributes = BACKGROUND_BLUE | BACKGROUND_GREEN
			| BACKGROUND_RED;
		ch = (char)((gp_buff_menubar_info + i)->Char.AsciiChar);
		if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
		{
			(gp_buff_menubar_info + i)->Attributes |= FOREGROUND_RED;
		}
	}

	/*�޸ĺ�Ĳ˵����ַ���Ϣ��д�����ڵĵ�һ��*/
	WriteConsoleOutput(gh_std_out, gp_buff_menubar_info, size, pos, &rcMenu);
	COORD endPos = { 0, 1 };
	SetConsoleCursorPosition(gh_std_out, endPos);  /*�����λ�������ڵ�2�е�1��*/

												   /*���˵�����Ϊ�������������Ϊ�˵���ţ���������Ϊ0(��ť��)*/
	i = 0;
	do
	{
		PosB = PosA + strlen(ga_main_menu[i]);  /*��λ��i+1�Ų˵������ֹλ��*/
		for (j = PosA; j<PosB; j++)
		{
			gp_scr_att[j] |= (i + 1) << 2; /*���ò˵��������ַ���Ԫ������ֵ*/
		}
		PosA = PosB + 4;
		i++;
	} while (i<5);

	TagMainMenu(gi_sel_menu);  /*��ѡ�����˵���������ǣ�gi_sel_menu��ֵΪ1*/

	return;
}

/**
* ��������: ShowState
* ��������: ��ʾ״̬��.
* �������: ��
* �������: ��
* �� �� ֵ: ��
*
* ����˵��: ״̬���ַ�����Ϊ�׵׺���, ��ʼ״̬��״̬��Ϣ.
*/
void ShowState()
{
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	COORD size;
	COORD pos = { 0, 0 };
	int i;

	GetConsoleScreenBufferInfo(gh_std_out, &bInfo);
	size.X = bInfo.dwSize.X;
	size.Y = 1;
	SMALL_RECT rcMenu = { 0, bInfo.dwSize.Y - 1, size.X - 1, bInfo.dwSize.Y - 1 };

	if (gp_buff_stateBar_info == NULL)
	{
		gp_buff_stateBar_info = (CHAR_INFO *)malloc(size.X * size.Y * sizeof(CHAR_INFO));
		ReadConsoleOutput(gh_std_out, gp_buff_stateBar_info, size, pos, &rcMenu);
	}

	for (i = 0; i<size.X; i++)
	{
		(gp_buff_stateBar_info + i)->Attributes = BACKGROUND_BLUE | BACKGROUND_GREEN
			| BACKGROUND_RED;
		/*
		ch = (char)((gp_buff_stateBar_info+i)->Char.AsciiChar);
		if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
		{
		(gp_buff_stateBar_info+i)->Attributes |= FOREGROUND_RED;
		}
		*/
	}

	WriteConsoleOutput(gh_std_out, gp_buff_stateBar_info, size, pos, &rcMenu);

	return;
}

/**
* ��������: TagMainMenu
* ��������: ��ָ�����˵�������ѡ�б�־.
* �������: num ѡ�е����˵����
* �������: ��
* �� �� ֵ: ��
*
* ����˵��:
*/
void TagMainMenu(int num)
{
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	COORD size;
	COORD pos = { 0, 0 };
	int PosA = 2, PosB;
	char ch;
	int i;

	if (num == 0) /*numΪ0ʱ������ȥ�����˵���ѡ�б��*/
	{
		PosA = 0;
		PosB = 0;
	}
	else  /*���򣬶�λѡ�����˵������ֹλ��: PosAΪ��ʼλ��, PosBΪ��ֹλ��*/
	{
		for (i = 1; i<num; i++)
		{
			PosA += strlen(ga_main_menu[i - 1]) + 4;
		}
		PosB = PosA + strlen(ga_main_menu[num - 1]);
	}

	GetConsoleScreenBufferInfo(gh_std_out, &bInfo);
	size.X = bInfo.dwSize.X;
	size.Y = 1;

	/*ȥ��ѡ�в˵���ǰ��Ĳ˵���ѡ�б��*/
	for (i = 0; i<PosA; i++)
	{
		(gp_buff_menubar_info + i)->Attributes = BACKGROUND_BLUE | BACKGROUND_GREEN
			| BACKGROUND_RED;
		ch = (gp_buff_menubar_info + i)->Char.AsciiChar;
		if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
		{
			(gp_buff_menubar_info + i)->Attributes |= FOREGROUND_RED;
		}
	}

	/*��ѡ�в˵���������ǣ��ڵװ���*/
	for (i = PosA; i<PosB; i++)
	{
		(gp_buff_menubar_info + i)->Attributes = FOREGROUND_BLUE | FOREGROUND_GREEN
			| FOREGROUND_RED;
	}

	/*ȥ��ѡ�в˵������Ĳ˵���ѡ�б��*/
	for (i = PosB; i<bInfo.dwSize.X; i++)
	{
		(gp_buff_menubar_info + i)->Attributes = BACKGROUND_BLUE | BACKGROUND_GREEN
			| BACKGROUND_RED;
		ch = (char)((gp_buff_menubar_info + i)->Char.AsciiChar);
		if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
		{
			(gp_buff_menubar_info + i)->Attributes |= FOREGROUND_RED;
		}
	}

	/*�����ñ�ǵĲ˵�����Ϣд�����ڵ�һ��*/
	SMALL_RECT rcMenu = { 0, 0, size.X - 1, 0 };
	WriteConsoleOutput(gh_std_out, gp_buff_menubar_info, size, pos, &rcMenu);

	return;
}

/**
* ��������: CloseSys
* ��������: �ر�ϵͳ.
* �������: hd ����ͷָ��
* �������: ��
* �� �� ֵ: ��
*
* ����˵��:
*/
void CloseSys(DORM_NODE *hd)
{
	DORM_NODE *pDormNode1 = hd, *pDormNode2;
	STU_NODE *pStuNode1, *pStuNode2;
	CHARGE_NODE *pChargeNode1, *pChargeNode2;

	while (pDormNode1 != NULL) /*�ͷ�ʮ�ֽ�������Ķ�̬�洢��*/
	{
		pDormNode2 = pDormNode1->next;
		pStuNode1 = pDormNode1->snext;
		while (pStuNode1 != NULL) /*�ͷ�ѧ��������Ϣ֧���Ķ�̬�洢��*/
		{
			pStuNode2 = pStuNode1->next;
			pChargeNode1 = pStuNode1->cnext;
			while (pChargeNode1 != NULL) /*�ͷŽɷ���Ϣ֧���Ķ�̬�洢��*/
			{
				pChargeNode2 = pChargeNode1->next;
				free(pChargeNode1);
				pChargeNode1 = pChargeNode2;
			}
			free(pStuNode1);
			pStuNode1 = pStuNode2;
		}
		free(pDormNode1);  /*�ͷ��������Ķ�̬�洢��*/
		pDormNode1 = pDormNode2;
	}

	ClearScreen();        /*����*/

						  /*�ͷŴ�Ų˵�����״̬�����Ա�����ѧ�����������Ϣ��̬�洢��*/
	free(gp_buff_menubar_info);
	free(gp_buff_stateBar_info);

	/*�رձ�׼���������豸���*/
	CloseHandle(gh_std_out);
	CloseHandle(gh_std_in);

	/*�����ڱ�������Ϊ���н���*/
	SetConsoleTitle("���н���");

	return;
}

/**
* ��������: RunSys
* ��������: ����ϵͳ, ��ϵͳ�������������û���ѡ��Ĺ���ģ��.
* �������: ��
* �������: phead ����ͷָ��ĵ�ַ
* �� �� ֵ: ��
*
* ����˵��:
*/
void RunSys(DORM_NODE **phead)
{
	INPUT_RECORD inRec;
	DWORD res;
	COORD pos = { 0, 0 };
	BOOL bRet = TRUE;
	int i, loc, num;
	int cNo, cAtt;      /*cNo:�ַ���Ԫ���, cAtt:�ַ���Ԫ����*/
	char vkc, asc;      /*vkc:���������, asc:�ַ���ASCII��ֵ*/

	while (bRet)
	{
		/*�ӿ���̨���뻺�����ж�һ����¼*/
		ReadConsoleInput(gh_std_in, &inRec, 1, &res);

		if (inRec.EventType == MOUSE_EVENT) /*�����¼������¼�����*/
		{
			pos = inRec.Event.MouseEvent.dwMousePosition;  /*��ȡ�������λ��*/
			cNo = gp_scr_att[pos.Y * SCR_COL + pos.X] & 3; /*ȡ��λ�õĲ��*/
			cAtt = gp_scr_att[pos.Y * SCR_COL + pos.X] >> 2;/*ȡ���ַ���Ԫ����*/
			if (cNo == 0) /*���Ϊ0��������λ��δ�������Ӳ˵�����*/
			{
				/* cAtt > 0 ������λ�ô�������(���˵����ַ���Ԫ)
				* cAtt != gi_sel_menu ������λ�õ����˵���δ��ѡ��
				* gp_top_layer->LayerNo > 0 ������ǰ���Ӳ˵�����
				*/
				if (cAtt > 0 && cAtt != gi_sel_menu && gp_top_layer->LayerNo > 0)
				{
					PopOff();            /*�رյ������Ӳ˵�*/
					gi_sel_sub_menu = 0; /*��ѡ���Ӳ˵���������Ϊ0*/
					PopMenu(cAtt);       /*��������������˵����Ӧ���Ӳ˵�*/
				}
			}
			else if (cAtt > 0) /*�������λ��Ϊ�����Ӳ˵��Ĳ˵����ַ���Ԫ*/
			{
				TagSubMenu(cAtt); /*�ڸ��Ӳ˵�������ѡ�б��*/
			}

			if (inRec.Event.MouseEvent.dwButtonState
				== FROM_LEFT_1ST_BUTTON_PRESSED) /*������������ߵ�һ��*/
			{
				if (cNo == 0) /*���Ϊ0��������λ��δ�������Ӳ˵�����*/
				{
					if (cAtt > 0) /*�����λ�ô�������(���˵����ַ���Ԫ)*/
					{
						PopMenu(cAtt);   /*��������������˵����Ӧ���Ӳ˵�*/
					}
					/*�����λ�ò��������˵����ַ���Ԫ�������Ӳ˵�����*/
					else if (gp_top_layer->LayerNo > 0)
					{
						PopOff();            /*�رյ������Ӳ˵�*/
						gi_sel_sub_menu = 0; /*��ѡ���Ӳ˵���������Ϊ0*/
					}
				}
				else /*��Ų�Ϊ0��������λ�ñ������Ӳ˵�����*/
				{
					if (cAtt > 0) /*�����λ�ô�������(�Ӳ˵����ַ���Ԫ)*/
					{
						PopOff(); /*�رյ������Ӳ˵�*/
						gi_sel_sub_menu = 0; /*��ѡ���Ӳ˵���������Ϊ0*/

											 /*ִ�ж�Ӧ���ܺ���:gi_sel_menu���˵����,cAtt�Ӳ˵����*/
						bRet = ExeFunction(gi_sel_menu, cAtt);
					}
				}
			}
			else if (inRec.Event.MouseEvent.dwButtonState
				== RIGHTMOST_BUTTON_PRESSED) /*�����������Ҽ�*/
			{
				if (cNo == 0) /*���Ϊ0��������λ��δ�������Ӳ˵�����*/
				{
					PopOff();            /*�رյ������Ӳ˵�*/
					gi_sel_sub_menu = 0; /*��ѡ���Ӳ˵���������Ϊ0*/
				}
			}
		}
		else if (inRec.EventType == KEY_EVENT  /*�����¼�ɰ�������*/
			&& inRec.Event.KeyEvent.bKeyDown) /*�Ҽ�������*/
		{
			vkc = inRec.Event.KeyEvent.wVirtualKeyCode; /*��ȡ�������������*/
			asc = inRec.Event.KeyEvent.uChar.AsciiChar; /*��ȡ������ASC��*/

														/*ϵͳ��ݼ��Ĵ���*/
			if (vkc == 112) /*�������F1��*/
			{
				if (gp_top_layer->LayerNo != 0) /*�����ǰ���Ӳ˵�����*/
				{
					PopOff();            /*�رյ������Ӳ˵�*/
					gi_sel_sub_menu = 0; /*��ѡ���Ӳ˵���������Ϊ0*/
				}
				bRet = ExeFunction(5, 1);  /*���а������⹦�ܺ���*/
			}
			else if (inRec.Event.KeyEvent.dwControlKeyState
				& (LEFT_ALT_PRESSED | RIGHT_ALT_PRESSED))
			{
				/*������������Alt��*/
				switch (vkc)  /*�ж���ϼ�Alt+��ĸ*/
				{
				case 88:  /*Alt+X �˳�*/
					if (gp_top_layer->LayerNo != 0)
					{
						PopOff();
						gi_sel_sub_menu = 0;
					}
					bRet = ExeFunction(1, 4);
					break;
				case 70:  /*Alt+F*/
					PopMenu(1);
					break;
				case 77: /*Alt+M*/
					PopMenu(2);
					break;
				case 81: /*Alt+Q*/
					PopMenu(3);
					break;
				case 83: /*Alt+S*/
					PopMenu(4);
					break;
				case 72: /*Alt+H*/
					PopMenu(5);
					break;
				}
			}
			else if (asc == 0) /*�������Ƽ��Ĵ���*/
			{
				if (gp_top_layer->LayerNo == 0) /*���δ�����Ӳ˵�*/
				{
					switch (vkc) /*�������(���ҡ���)������Ӧ�������Ƽ�*/
					{
					case 37:
						gi_sel_menu--;
						if (gi_sel_menu == 0)
						{
							gi_sel_menu = 5;
						}
						TagMainMenu(gi_sel_menu);
						break;
					case 39:
						gi_sel_menu++;
						if (gi_sel_menu == 6)
						{
							gi_sel_menu = 1;
						}
						TagMainMenu(gi_sel_menu);
						break;
					case 40:
						PopMenu(gi_sel_menu);
						TagSubMenu(1);
						break;
					}
				}
				else  /*�ѵ����Ӳ˵�ʱ*/
				{
					for (loc = 0, i = 1; i<gi_sel_menu; i++)
					{
						loc += ga_sub_menu_count[i - 1];
					}  /*������Ӳ˵��еĵ�һ�����Ӳ˵��ַ��������е�λ��(�±�)*/
					switch (vkc) /*�����(���ҡ��ϡ���)�Ĵ���*/
					{
					case 37:
						gi_sel_menu--;
						if (gi_sel_menu < 1)
						{
							gi_sel_menu = 5;
						}
						TagMainMenu(gi_sel_menu);
						PopOff();
						PopMenu(gi_sel_menu);
						TagSubMenu(1);
						break;
					case 38:
						num = gi_sel_sub_menu - 1;
						if (num < 1)
						{
							num = ga_sub_menu_count[gi_sel_menu - 1];
						}
						if (strlen(ga_sub_menu[loc + num - 1]) == 0)
						{
							num--;
						}
						TagSubMenu(num);
						break;
					case 39:
						gi_sel_menu++;
						if (gi_sel_menu > 5)
						{
							gi_sel_menu = 1;
						}
						TagMainMenu(gi_sel_menu);
						PopOff();
						PopMenu(gi_sel_menu);
						TagSubMenu(1);
						break;
					case 40:
						num = gi_sel_sub_menu + 1;
						if (num > ga_sub_menu_count[gi_sel_menu - 1])
						{
							num = 1;
						}
						if (strlen(ga_sub_menu[loc + num - 1]) == 0)
						{
							num++;
						}
						TagSubMenu(num);
						break;
					}
				}
			}
			else if ((asc - vkc == 0) || (asc - vkc == 32))   /*������ͨ��*/
			{
				if (gp_top_layer->LayerNo == 0)  /*���δ�����Ӳ˵�*/
				{
					switch (vkc)
					{
					case 70: /*f��F*/
						PopMenu(1);
						break;
					case 77: /*m��M*/
						PopMenu(2);
						break;
					case 81: /*q��Q*/
						PopMenu(3);
						break;
					case 83: /*s��S*/
						PopMenu(4);
						break;
					case 72: /*h��H*/
						PopMenu(5);
						break;
					case 13: /*�س�*/
						PopMenu(gi_sel_menu);
						TagSubMenu(1);
						break;
					}
				}
				else /*�ѵ����Ӳ˵�ʱ�ļ������봦��*/
				{
					if (vkc == 27) /*�������ESC��*/
					{
						PopOff();
						gi_sel_sub_menu = 0;
					}
					else if (vkc == 13) /*������»س���*/
					{
						num = gi_sel_sub_menu;
						PopOff();
						gi_sel_sub_menu = 0;
						bRet = ExeFunction(gi_sel_menu, num);
					}
					else /*������ͨ���Ĵ���*/
					{
						/*������Ӳ˵��еĵ�һ�����Ӳ˵��ַ��������е�λ��(�±�)*/
						for (loc = 0, i = 1; i<gi_sel_menu; i++)
						{
							loc += ga_sub_menu_count[i - 1];
						}

						/*�����뵱ǰ�Ӳ˵���ÿһ��Ĵ����ַ����бȽ�*/
						for (i = loc; i<loc + ga_sub_menu_count[gi_sel_menu - 1]; i++)
						{
							if (strlen(ga_sub_menu[i])>0 && vkc == ga_sub_menu[i][1])
							{
								/*���ƥ��ɹ�*/
								PopOff();
								gi_sel_sub_menu = 0;
								bRet = ExeFunction(gi_sel_menu, i - loc + 1);
							}
						}
					}
				}
			}
		}
	}
}

void PopPrompt(int num)
{

}

/**
* ��������: PopMenu
* ��������: ����ָ�����˵����Ӧ���Ӳ˵�.
* �������: num ָ�������˵����
* �������: ��
* �� �� ֵ: ��
*
* ����˵��:
*/
void PopMenu(int num)
{
	LABEL_BUNDLE labels;
	HOT_AREA areas;
	SMALL_RECT rcPop;
	COORD pos;
	WORD att;
	char *pCh;
	int i, j, loc = 0;

	if (num != gi_sel_menu)       /*���ָ�����˵�������ѡ�в˵�*/
	{
		if (gp_top_layer->LayerNo != 0) /*�����ǰ�����Ӳ˵�����*/
		{
			PopOff();
			gi_sel_sub_menu = 0;
		}
	}
	else if (gp_top_layer->LayerNo != 0) /*���ѵ������Ӳ˵����򷵻�*/
	{
		return;
	}

	gi_sel_menu = num;    /*��ѡ�����˵�����Ϊָ�������˵���*/
	TagMainMenu(gi_sel_menu); /*��ѡ�е����˵����������*/
	LocSubMenu(gi_sel_menu, &rcPop); /*���㵯���Ӳ˵�������λ��, �����rcPop��*/

									 /*������Ӳ˵��еĵ�һ�����Ӳ˵��ַ��������е�λ��(�±�)*/
	for (i = 1; i<gi_sel_menu; i++)
	{
		loc += ga_sub_menu_count[i - 1];
	}
	/*�������Ӳ˵������������ǩ���ṹ����*/
	labels.ppLabel = ga_sub_menu + loc;   /*��ǩ����һ����ǩ�ַ����ĵ�ַ*/
	labels.num = ga_sub_menu_count[gi_sel_menu - 1]; /*��ǩ���б�ǩ�ַ����ĸ���*/
	COORD aLoc[labels.num];/*����һ���������飬���ÿ����ǩ�ַ������λ�õ�����*/
	for (i = 0; i<labels.num; i++) /*ȷ����ǩ�ַ��������λ�ã����������������*/
	{
		aLoc[i].X = rcPop.Left + 2;
		aLoc[i].Y = rcPop.Top + i + 1;
	}
	labels.pLoc = aLoc; /*ʹ��ǩ���ṹ����labels�ĳ�ԱpLocָ�������������Ԫ��*/
						/*����������Ϣ*/
	areas.num = labels.num;       /*�����ĸ��������ڱ�ǩ�ĸ��������Ӳ˵�������*/
	SMALL_RECT aArea[areas.num];                    /*������������������λ��*/
	char aSort[areas.num];                      /*��������������������Ӧ���*/
	char aTag[areas.num];                         /*����������ÿ�������ı��*/
	for (i = 0; i<areas.num; i++)
	{
		aArea[i].Left = rcPop.Left + 2;  /*������λ*/
		aArea[i].Top = rcPop.Top + i + 1;
		aArea[i].Right = rcPop.Right - 2;
		aArea[i].Bottom = aArea[i].Top;
		aSort[i] = 0;       /*�������Ϊ0(��ť��)*/
		aTag[i] = i + 1;           /*������˳����*/
	}
	areas.pArea = aArea;/*ʹ�����ṹ����areas�ĳ�ԱpAreaָ������λ��������Ԫ��*/
	areas.pSort = aSort;/*ʹ�����ṹ����areas�ĳ�ԱpSortָ���������������Ԫ��*/
	areas.pTag = aTag;   /*ʹ�����ṹ����areas�ĳ�ԱpTagָ���������������Ԫ��*/

	att = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED;  /*�׵׺���*/
	PopUp(&rcPop, att, &labels, &areas);
	DrawBox(&rcPop);  /*���������ڻ��߿�*/
	pos.X = rcPop.Left + 2;
	for (pos.Y = rcPop.Top + 1; pos.Y<rcPop.Bottom; pos.Y++)
	{
		/*��ѭ�������ڿմ��Ӳ���λ�û����γɷָ�����ȡ���˲˵������������*/
		pCh = ga_sub_menu[loc + pos.Y - rcPop.Top - 1];
		if (strlen(pCh) == 0) /*����Ϊ0������Ϊ�մ�*/
		{
			/*���Ȼ�����*/
			FillConsoleOutputCharacter(gh_std_out, '-', rcPop.Right - rcPop.Left - 3, pos, &ul);
			for (j = rcPop.Left + 2; j<rcPop.Right - 1; j++)
			{
				/*ȡ���������ַ���Ԫ����������*/
				gp_scr_att[pos.Y*SCR_COL + j] &= 3; /*��λ��Ľ�������˵���λ*/
			}
		}

	}
	/*���Ӳ˵���Ĺ��ܼ���Ϊ�׵׺���*/
	pos.X = rcPop.Left + 3;
	att = FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED;
	for (pos.Y = rcPop.Top + 1; pos.Y<rcPop.Bottom; pos.Y++)
	{
		if (strlen(ga_sub_menu[loc + pos.Y - rcPop.Top - 1]) == 0)
		{
			continue;  /*�����մ�*/
		}
		FillConsoleOutputAttribute(gh_std_out, att, 1, pos, &ul);
	}
	return;
}

/**
* ��������: PopUp
* ��������: ��ָ�������������������Ϣ, ͬʱ��������, ����������λ����Ϣ��ջ.
* �������: pRc ��������λ�����ݴ�ŵĵ�ַ
*           att �������������ַ�����
*           pLabel ���������б�ǩ����Ϣ��ŵĵ�ַ
pHotArea ����������������Ϣ��ŵĵ�ַ
* �������: ��
* �� �� ֵ: ��
*
* ����˵��:
*/
void PopUp(SMALL_RECT *pRc, WORD att, LABEL_BUNDLE *pLabel, HOT_AREA *pHotArea)
{
	LAYER_NODE *nextLayer;
	COORD size;
	COORD pos = { 0, 0 };
	char *pCh;
	int i, j, row;

	/*������������λ���ַ���Ԫ��Ϣ��ջ*/
	size.X = pRc->Right - pRc->Left + 1;    /*�������ڵĿ��*/
	size.Y = pRc->Bottom - pRc->Top + 1;    /*�������ڵĸ߶�*/
											/*�����ŵ������������Ϣ�Ķ�̬�洢��*/
	nextLayer = (LAYER_NODE *)malloc(sizeof(LAYER_NODE));
	nextLayer->next = gp_top_layer;
	nextLayer->LayerNo = gp_top_layer->LayerNo + 1;
	nextLayer->rcArea = *pRc;
	nextLayer->pContent = (CHAR_INFO *)malloc(size.X*size.Y * sizeof(CHAR_INFO));
	nextLayer->pScrAtt = (char *)malloc(size.X*size.Y * sizeof(char));
	pCh = nextLayer->pScrAtt;
	/*���������ڸ���������ַ���Ϣ���棬�����ڹرյ�������ʱ�ָ�ԭ��*/
	ReadConsoleOutput(gh_std_out, nextLayer->pContent, size, pos, pRc);
	for (i = pRc->Top; i <= pRc->Bottom; i++)
	{
		/*�˶���ѭ�����������ַ���Ԫ��ԭ������ֵ���붯̬�洢���������Ժ�ָ�*/
		for (j = pRc->Left; j <= pRc->Right; j++)
		{
			*pCh = gp_scr_att[i*SCR_COL + j];
			pCh++;
		}
	}
	gp_top_layer = nextLayer;  /*��ɵ������������Ϣ��ջ����*/
							   /*���õ������������ַ���������*/
	pos.X = pRc->Left;
	pos.Y = pRc->Top;
	for (i = pRc->Top; i <= pRc->Bottom; i++)
	{
		FillConsoleOutputAttribute(gh_std_out, att, size.X, pos, &ul);
		pos.Y++;
	}
	/*����ǩ���еı�ǩ�ַ������趨��λ�����*/
	for (i = 0; i<pLabel->num; i++)
	{
		pCh = pLabel->ppLabel[i];
		if (strlen(pCh) != 0)
		{
			WriteConsoleOutputCharacter(gh_std_out, pCh, strlen(pCh),
				pLabel->pLoc[i], &ul);
		}
	}
	/*���õ������������ַ���Ԫ��������*/
	for (i = pRc->Top; i <= pRc->Bottom; i++)
	{
		/*�˶���ѭ�������ַ���Ԫ�Ĳ��*/
		for (j = pRc->Left; j <= pRc->Right; j++)
		{
			gp_scr_att[i*SCR_COL + j] = gp_top_layer->LayerNo;
		}
	}

	for (i = 0; i<pHotArea->num; i++)
	{
		/*�˶���ѭ�����������������ַ���Ԫ���������ͺ��������*/
		row = pHotArea->pArea[i].Top;
		for (j = pHotArea->pArea[i].Left; j <= pHotArea->pArea[i].Right; j++)
		{
			gp_scr_att[row*SCR_COL + j] |= (pHotArea->pSort[i] << 6)
				| (pHotArea->pTag[i] << 2);
		}
	}
	return;
}

/**
* ��������: PopOff
* ��������: �رն��㵯������, �ָ���������ԭ��ۺ��ַ���Ԫԭ����.
* �������: ��
* �������: ��
* �� �� ֵ: ��
*
* ����˵��:
*/
void PopOff(void)
{
	LAYER_NODE *nextLayer;
	COORD size;
	COORD pos = { 0, 0 };
	char *pCh;
	int i, j;

	if ((gp_top_layer->next == NULL) || (gp_top_layer->pContent == NULL))
	{
		/*ջ�״�ŵ���������Ļ��Ϣ�����ùر�*/
		return;
	}
	nextLayer = gp_top_layer->next;
	/*�ָ�������������ԭ���*/
	size.X = gp_top_layer->rcArea.Right - gp_top_layer->rcArea.Left + 1;
	size.Y = gp_top_layer->rcArea.Bottom - gp_top_layer->rcArea.Top + 1;
	WriteConsoleOutput(gh_std_out, gp_top_layer->pContent, size, pos, &(gp_top_layer->rcArea));
	/*�ָ��ַ���Ԫԭ����*/
	pCh = gp_top_layer->pScrAtt;
	for (i = gp_top_layer->rcArea.Top; i <= gp_top_layer->rcArea.Bottom; i++)
	{
		for (j = gp_top_layer->rcArea.Left; j <= gp_top_layer->rcArea.Right; j++)
		{
			gp_scr_att[i*SCR_COL + j] = *pCh;
			pCh++;
		}
	}
	free(gp_top_layer->pContent);    /*�ͷŶ�̬�洢��*/
	free(gp_top_layer->pScrAtt);
	free(gp_top_layer);
	gp_top_layer = nextLayer;
	gi_sel_sub_menu = 0;
	return;
}

/**
* ��������: DrawBox
* ��������: ��ָ�����򻭱߿�.
* �������: pRc �������λ����Ϣ�ĵ�ַ
* �������: ��
* �� �� ֵ: ��
*
* ����˵��:
*/
void DrawBox(SMALL_RECT *pRc)
{
	char chBox[] = { '+','-','|' };  /*�����õ��ַ�*/
	COORD pos = { pRc->Left, pRc->Top };  /*��λ����������Ͻ�*/

	WriteConsoleOutputCharacter(gh_std_out, &chBox[0], 1, pos, &ul);/*���߿����Ͻ�*/
	for (pos.X = pRc->Left + 1; pos.X < pRc->Right; pos.X++)
	{
		/*��ѭ�����ϱ߿����*/
		WriteConsoleOutputCharacter(gh_std_out, &chBox[1], 1, pos, &ul);
	}
	pos.X = pRc->Right;
	WriteConsoleOutputCharacter(gh_std_out, &chBox[0], 1, pos, &ul);/*���߿����Ͻ�*/
	for (pos.Y = pRc->Top + 1; pos.Y < pRc->Bottom; pos.Y++)
	{
		/*��ѭ�����߿�����ߺ��ұ���*/
		pos.X = pRc->Left;
		WriteConsoleOutputCharacter(gh_std_out, &chBox[2], 1, pos, &ul);
		pos.X = pRc->Right;
		WriteConsoleOutputCharacter(gh_std_out, &chBox[2], 1, pos, &ul);
	}
	pos.X = pRc->Left;
	pos.Y = pRc->Bottom;
	WriteConsoleOutputCharacter(gh_std_out, &chBox[0], 1, pos, &ul);/*���߿����½�*/
	for (pos.X = pRc->Left + 1; pos.X < pRc->Right; pos.X++)
	{
		/*���±߿����*/
		WriteConsoleOutputCharacter(gh_std_out, &chBox[1], 1, pos, &ul);
	}
	pos.X = pRc->Right;
	WriteConsoleOutputCharacter(gh_std_out, &chBox[0], 1, pos, &ul);/*���߿����½�*/
	return;
}

/**
* ��������: TagSubMenu
* ��������: ��ָ���Ӳ˵�������ѡ�б��.
* �������: num ѡ�е��Ӳ˵����
* �������: ��
* �� �� ֵ: ��
*
* ����˵��:
*/
void TagSubMenu(int num)
{
	SMALL_RECT rcPop;
	COORD pos;
	WORD att;
	int width;

	LocSubMenu(gi_sel_menu, &rcPop);  /*���㵯���Ӳ˵�������λ��, �����rcPop��*/
	if ((num<1) || (num == gi_sel_sub_menu) || (num>rcPop.Bottom - rcPop.Top - 1))
	{
		/*����Ӳ˵����Խ�磬������Ӳ˵��ѱ�ѡ�У��򷵻�*/
		return;
	}

	pos.X = rcPop.Left + 2;
	width = rcPop.Right - rcPop.Left - 3;
	if (gi_sel_sub_menu != 0) /*����ȡ��ԭѡ���Ӳ˵����ϵı��*/
	{
		pos.Y = rcPop.Top + gi_sel_sub_menu;
		att = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED;  /*�׵׺���*/
		FillConsoleOutputAttribute(gh_std_out, att, width, pos, &ul);
		pos.X += 1;
		att |= FOREGROUND_RED;/*�׵׺���*/
		FillConsoleOutputAttribute(gh_std_out, att, 1, pos, &ul);
	}
	/*���ƶ��Ӳ˵�������ѡ�б��*/
	pos.X = rcPop.Left + 2;
	pos.Y = rcPop.Top + num;
	att = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED;  /*�ڵװ���*/
	FillConsoleOutputAttribute(gh_std_out, att, width, pos, &ul);
	gi_sel_sub_menu = num;  /*�޸�ѡ���Ӳ˵����*/
	return;
}


/**
* ��������: LocSubMenu
* ��������: ���㵯���Ӳ˵��������ϽǺ����½ǵ�λ��.
* �������: num ѡ�е����˵����
* �������: rc �������λ����Ϣ�ĵ�ַ
* �� �� ֵ: ��
*
* ����˵��:
*/
void LocSubMenu(int num, SMALL_RECT *rc)
{
	int i, len, loc = 0;

	rc->Top = 1; /*������ϱ߶��ڵ�2�У��к�Ϊ1*/
	rc->Left = 1;
	for (i = 1; i<num; i++)
	{
		/*����������߽�λ��, ͬʱ�����һ���Ӳ˵������Ӳ˵��ַ��������е�λ��*/
		rc->Left += strlen(ga_main_menu[i - 1]) + 4;
		loc += ga_sub_menu_count[i - 1];
	}
	rc->Right = strlen(ga_sub_menu[loc]);/*��ʱ��ŵ�һ���Ӳ˵����ַ�������*/
	for (i = 1; i<ga_sub_menu_count[num - 1]; i++)
	{
		/*������Ӳ˵��ַ��������䳤�ȴ����rc->Right*/
		len = strlen(ga_sub_menu[loc + i]);
		if (rc->Right < len)
		{
			rc->Right = len;
		}
	}
	rc->Right += rc->Left + 3;  /*����������ұ߽�*/
	rc->Bottom = rc->Top + ga_sub_menu_count[num - 1] + 1;/*���������±ߵ��к�*/
	if (rc->Right >= SCR_COL)  /*�ұ߽�Խ��Ĵ���*/
	{
		len = rc->Right - SCR_COL + 1;
		rc->Left -= len;
		rc->Right = SCR_COL - 1;
	}
	return;
}

/**
* ��������: DealInput
* ��������: �ڵ�������������������, �ȴ�����Ӧ�û�����.
* �������: pHotArea
*           piHot ����������ŵĴ�ŵ�ַ, ��ָ�򽹵�������ŵ�ָ��
* �������: piHot ����굥�������س���ո�ʱ���ص�ǰ�������
* �� �� ֵ:
*
* ����˵��:
*/
int DealInput(HOT_AREA *pHotArea, int *piHot)
{
	INPUT_RECORD inRec;
	DWORD res;
	COORD pos = { 0, 0 };
	int num, arrow, iRet = 0;
	int cNo, cTag, cSort;/*cNo:���, cTag:�������, cSort: ��������*/
	char vkc, asc;       /*vkc:���������, asc:�ַ���ASCII��ֵ*/

	SetHotPoint(pHotArea, *piHot);
	while (TRUE)
	{
		/*ѭ��*/
		ReadConsoleInput(gh_std_in, &inRec, 1, &res);
		if ((inRec.EventType == MOUSE_EVENT) &&
			(inRec.Event.MouseEvent.dwButtonState
				== FROM_LEFT_1ST_BUTTON_PRESSED))
		{
			pos = inRec.Event.MouseEvent.dwMousePosition;
			cNo = gp_scr_att[pos.Y * SCR_COL + pos.X] & 3;
			cTag = (gp_scr_att[pos.Y * SCR_COL + pos.X] >> 2) & 15;
			cSort = (gp_scr_att[pos.Y * SCR_COL + pos.X] >> 6) & 3;

			if ((cNo == gp_top_layer->LayerNo) && cTag > 0)
			{
				*piHot = cTag;
				SetHotPoint(pHotArea, *piHot);
				if (cSort == 0)
				{
					iRet = 13;
					break;
				}
			}
		}
		else if (inRec.EventType == KEY_EVENT && inRec.Event.KeyEvent.bKeyDown)
		{
			vkc = inRec.Event.KeyEvent.wVirtualKeyCode;
			asc = inRec.Event.KeyEvent.uChar.AsciiChar;;
			if (asc == 0)
			{
				arrow = 0;
				switch (vkc)
				{
					/*�����(���ϡ��ҡ���)�Ĵ���*/
				case 37:
					arrow = 1;
					break;
				case 38:
					arrow = 2;
					break;
				case 39:
					arrow = 3;
					break;
				case 40:
					arrow = 4;
					break;
				}
				if (arrow > 0)
				{
					num = *piHot;
					while (TRUE)
					{
						if (arrow < 3)
						{
							num--;
						}
						else
						{
							num++;
						}
						if ((num < 1) || (num > pHotArea->num) ||
							((arrow % 2) && (pHotArea->pArea[num - 1].Top
								== pHotArea->pArea[*piHot - 1].Top)) || ((!(arrow % 2))
									&& (pHotArea->pArea[num - 1].Top
										!= pHotArea->pArea[*piHot - 1].Top)))
						{
							break;
						}
					}
					if (num > 0 && num <= pHotArea->num)
					{
						*piHot = num;
						SetHotPoint(pHotArea, *piHot);
					}
				}
			}
			else if (vkc == 27)
			{
				/*ESC��*/
				iRet = 27;
				break;
			}
			else if (vkc == 13 || vkc == 32)
			{
				/*�س�����ո��ʾ���µ�ǰ��ť*/
				iRet = 13;
				break;
			}
		}
	}
	return iRet;
}


void SetHotPoint(HOT_AREA *pHotArea, int iHot)
{
	CONSOLE_CURSOR_INFO lpCur;
	COORD pos = { 0, 0 };
	WORD att1, att2;
	int i, width;

	att1 = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED;  /*�ڵװ���*/
	att2 = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED;  /*�׵׺���*/
	for (i = 0; i<pHotArea->num; i++)
	{
		/*����ť��������Ϊ�׵׺���*/
		pos.X = pHotArea->pArea[i].Left;
		pos.Y = pHotArea->pArea[i].Top;
		width = pHotArea->pArea[i].Right - pHotArea->pArea[i].Left + 1;
		if (pHotArea->pSort[i] == 0)
		{
			/*�����ǰ�ť��*/
			FillConsoleOutputAttribute(gh_std_out, att2, width, pos, &ul);
		}
	}

	pos.X = pHotArea->pArea[iHot - 1].Left;
	pos.Y = pHotArea->pArea[iHot - 1].Top;
	width = pHotArea->pArea[iHot - 1].Right - pHotArea->pArea[iHot - 1].Left + 1;
	if (pHotArea->pSort[iHot - 1] == 0)
	{
		/*�����������ǰ�ť��*/
		FillConsoleOutputAttribute(gh_std_out, att1, width, pos, &ul);
	}
	else if (pHotArea->pSort[iHot - 1] == 1)
	{
		/*�������������ı�����*/
		SetConsoleCursorPosition(gh_std_out, pos);
		GetConsoleCursorInfo(gh_std_out, &lpCur);
		lpCur.bVisible = TRUE;
		SetConsoleCursorInfo(gh_std_out, &lpCur);
	}
}

/**
* ��������: ExeFunction
* ��������: ִ�������˵��ź��Ӳ˵���ȷ���Ĺ��ܺ���.
* �������: m ���˵����
*           s �Ӳ˵����
* �������: ��
* �� �� ֵ: BOOL����, TRUE �� FALSE
*
* ����˵��: ����ִ�к���ExitSysʱ, �ſ��ܷ���FALSE, ������������Ƿ���TRUE
*/
BOOL ExeFunction(int m, int s)
{
	void ShowMenu();
	BOOL bRet = TRUE;
	/*����ָ�����飬����������й��ܺ�������ڵ�ַ*/
	BOOL(*pFunction[ga_sub_menu_count[0] + ga_sub_menu_count[1] + ga_sub_menu_count[2] + ga_sub_menu_count[3] + ga_sub_menu_count[4]])(void);
	int i, loc;

	/*�����ܺ�����ڵ�ַ�����빦�ܺ����������˵��ź��Ӳ˵��Ŷ�Ӧ�±������Ԫ��*/
	pFunction[0] = SaveData;
	pFunction[1] = BackupData;
	pFunction[2] = RestoreData;
	pFunction[3] = ExitSys;
	pFunction[4] = InsertDormInfo;
	pFunction[5] = ModifDormInfo;
	pFunction[6] = DelDormInfo;
	pFunction[7] = NULL;
	pFunction[8] = InsertStuInfo;
	pFunction[9] = ModifStuInfo;
	pFunction[10] = DelStuInfo;
	pFunction[11] = NULL;
	pFunction[12] = InsertChargeInfo;
	pFunction[13] = ModifChargeInfo;
	pFunction[14] = DelChargeInfo;
	pFunction[15] = QueryDormInfo;
	pFunction[16] = QueryStuInfo;
	pFunction[17] = QueryChargeInfo;
	pFunction[18] = QueryClassChargeInfo;
	pFunction[19] = StatUsedRate;
	pFunction[20] = StatStuType;
	pFunction[21] = StatDormCharge;
	pFunction[22] = StatUncharge;
	pFunction[23] = HelpTopic;
	pFunction[24] = NULL;
	pFunction[25] = AboutDorm;

	for (i = 1, loc = 0; i<m; i++)  /*�������˵��ź��Ӳ˵��ż����Ӧ�±�*/
	{
		loc += ga_sub_menu_count[i - 1];
	}
	loc += s - 1;

	if (pFunction[loc] != NULL)
	{
		bRet = (*pFunction[loc])();  /*�ú���ָ�������ָ��Ĺ��ܺ���*/
	}

	return bRet;
}

/**<���������posλ�ô�*/
inline void Gotoxy(COORD pos)
{
	gh_std_out = GetStdHandle(STD_OUTPUT_HANDLE);/*��ȡ��׼����豸���*/
	SetConsoleCursorPosition(gh_std_out, pos);
}

/**<ˢ������*/
inline void ScreenFresh(void)
{
	COORD home = { 0,1 };
	int i;
	Gotoxy(home);
	for (i = 0; i<100; i++)
	{
		printf("%80s", " ");
	}
	Gotoxy(home);
}


BOOL SaveData(void)
{
	BOOL bRet = TRUE;
	ScreenFresh();
	SaveSysData(gp_head, FileName);
	return bRet;
}


BOOL BackupData(void)
{
	BOOL bRet = TRUE;
	ScreenFresh();
	CreatList(&gp_head, FileName);
	SaveSysData(gp_head, BeiFen_FileName);
	printf("ϵͳ���ݱ��ݳɹ�");
	return bRet;
}

BOOL RestoreData(void)
{
	BOOL bRet = TRUE;
	ScreenFresh();
	printf("ע�⣺����ָ��������ݣ���ǰ�����ݽ������ǣ�ȷ�������ָ���ȷ��(Y) ȡ��(N):\n");
	char ch;
	ch = getchar();
	getchar();
	if (ch != 'y'&&ch != 'Y') return bRet;
	CreatList(&gp_head, BeiFen_FileName);
	SaveSysData(gp_head, FileName);
	printf("�������ݻָ��ɹ�");
	return bRet;
}

BOOL ExitSys(void)
{
	LABEL_BUNDLE labels;
	HOT_AREA areas;
	BOOL bRet = TRUE;
	SMALL_RECT rcPop;
	COORD pos;
	WORD att;
	char *pCh[] = { "ȷ���˳�ϵͳ��", "ȷ��    ȡ��" };
	int iHot = 1;

	pos.X = strlen(pCh[0]) + 6;
	pos.Y = 7;
	rcPop.Left = (SCR_COL - pos.X) / 2;
	rcPop.Right = rcPop.Left + pos.X - 1;
	rcPop.Top = (SCR_ROW - pos.Y) / 2;
	rcPop.Bottom = rcPop.Top + pos.Y - 1;

	att = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED;  /*�׵׺���*/
	labels.num = 2;
	labels.ppLabel = pCh;
	COORD aLoc[] = { { rcPop.Left + 3, rcPop.Top + 2 },
	{ rcPop.Left + 5, rcPop.Top + 5 }
	};
	labels.pLoc = aLoc;

	areas.num = 2;
	SMALL_RECT aArea[] = { {
			rcPop.Left + 5, rcPop.Top + 5,
			rcPop.Left + 8, rcPop.Top + 5
		},
		{
			rcPop.Left + 13, rcPop.Top + 5,
			rcPop.Left + 16, rcPop.Top + 5
		}
	};
	char aSort[] = { 0, 0 };
	char aTag[] = { 1, 2 };
	areas.pArea = aArea;
	areas.pSort = aSort;
	areas.pTag = aTag;
	PopUp(&rcPop, att, &labels, &areas);

	pos.X = rcPop.Left + 1;
	pos.Y = rcPop.Top + 4;
	FillConsoleOutputCharacter(gh_std_out, '-', rcPop.Right - rcPop.Left - 1, pos, &ul);

	if (DealInput(&areas, &iHot) == 13 && iHot == 1)
	{
		bRet = FALSE;
	}
	else
	{
		bRet = TRUE;
	}
	PopOff();

	return bRet;
}

/**
* ��������: InsertDormInfo
* ��������: ����һ��ס����Ϣ.
* �������:
*
* �������:
* �� �� ֵ:
*
* ����˵��:
*/
BOOL InsertDormInfo(void)
{
	BOOL bRet = TRUE;
	ScreenFresh();
	InsertDormNode(&gp_head);
	SaveSysData(gp_head, FileName);
	return bRet;
}

/**
* ��������: InsertDormNode
* ��������: ��ʮ�������в���һ������¥��Ϣ���.
* �������: hd ����ͷָ��
*           pdorm_node ָ����Ҫ�������ָ��
* �������: ��
* �� �� ֵ:
*
* ����˵��:
*/
void InsertDormNode(DORM_NODE **hd)
{
	DORM_NODE *p1, *pterm = *hd;
	p1 = (DORM_NODE *)malloc(sizeof(DORM_NODE));
	printf("����������¥��:\n");
	scanf("%s", p1->dorm_id);
	getchar();
	printf("���������Ա����:\n");
	scanf("%s", p1->name);
	getchar();
	printf("������绰����:\n");
	scanf("%s", p1->tel);
	getchar();
	printf("�����뷿����Ŀ:\n");
	scanf("%hu", &p1->room_amount);
	getchar();
	printf("�����봲λ��Ŀ:\n");
	scanf("%hu", &p1->bed_amount);
	getchar();
	printf("������ס�޷�:\n");
	scanf("%f", &p1->fee);
	getchar();
	p1->snext = NULL;
	while (pterm != NULL&&strcmp(pterm->dorm_id, p1->dorm_id) != 0) /*��������¥��Ϣ*/
	{
		pterm = pterm->next;
	}
	if (pterm == NULL) /*����¥��Ϣ�����ڣ���������¥��Ϣ*/
	{
		p1->next = *hd;
		*hd = p1;
		printf("��������¥��Ϣ�ɹ���\n");
	}
	else
	{
		printf("����Ϣ�Ѵ��ڣ�\n");
	}
}


BOOL DelDormInfo(void)
{
	void ShowMenu();
	BOOL bRet = TRUE;
	ScreenFresh();
	char s[20];
	printf("����������¥��:\n");
	scanf("%s", s);
	getchar();
	if (DelDormNode(&gp_head, s) == 1)
	{
		printf("ɾ���ɹ���\n");
	}
	else
	{
		printf("������¥��Ϣ������,ɾ��ʧ�ܣ�\n");
	}
	SaveSysData(gp_head, FileName);
	return bRet;
}


/**
* ��������: DelDormNode
* ��������: ��ʮ��������ɾ��ָ��������¥��Ϣ���.
* �������: hd ����ͷָ��
*           dorm_id����¥��
* �������: ��
* �� �� ֵ:
*
* ����˵��: ��������¥�ſ���ȷ��Ψһ������¥��Ϣ
*/
int DelDormNode(DORM_NODE **hd, char *dorm_id)
{
	void ShowMenu();
	DORM_NODE *pdorm_node_current;
	DORM_NODE *pdorm_node_prior;
	STU_NODE *pstu_node_prior;
	STU_NODE *pstu_node_current;
	CHARGE_NODE *pcharge_node_prior;
	CHARGE_NODE *pcharge_node_current;
	int bRet = 0;
	for (pdorm_node_current = *hd, pdorm_node_prior = NULL; pdorm_node_current != NULL; pdorm_node_prior = pdorm_node_current,
		pdorm_node_current = pdorm_node_current->next)
	{
		if (strcmp(pdorm_node_current->dorm_id, dorm_id) == 0)
		{
			bRet = 1;
			break;
		}
	}
	if (pdorm_node_current != NULL)  /*����ҵ�*/
	{
		if (pdorm_node_prior == NULL) /*���������ͷ*/
		{
			*hd = pdorm_node_current->next;
		}
		else
		{
			pdorm_node_prior->next = pdorm_node_current->next;
		}
		pstu_node_current = pdorm_node_current->snext;
		free(pdorm_node_current);
		while (pstu_node_current != NULL)   /*ɾ��ѧ��������Ϣ֧��*/
		{
			pcharge_node_current = pstu_node_current->cnext;
			pstu_node_prior = pstu_node_current;
			while (pcharge_node_current != NULL) /*ɾ���ɷ���Ϣ֧��*/
			{
				pcharge_node_prior = pcharge_node_current;
				pcharge_node_current = pcharge_node_current->next;
				free(pcharge_node_prior);
			}
			pstu_node_current = pstu_node_current->next;
			free(pstu_node_prior);
		}
	}
	return bRet;
}
BOOL ModifDormInfo(void)
{
	BOOL bRet = TRUE;
	ScreenFresh();
	char s[20];
	printf("������Ҫ�޸ĵ�����¥��Ϣ������¥��:\n");
	scanf("%s", s);
	getchar();
	DORM_NODE *p1;
	p1 = (DORM_NODE *)malloc(sizeof(DORM_NODE));

	printf("�������޸ĺ������¥��:\n");
	scanf("%s", p1->dorm_id);
	getchar();
	printf("�������޸ĺ������:\n");
	scanf("%s", p1->name);
	getchar();
	printf("�������޸ĺ�ĵ绰����:\n");
	scanf("%s", p1->tel);
	getchar();
	printf("�������޸ĺ�ķ�����Ŀ:\n");
	scanf("%hd", &p1->room_amount);
	getchar();
	printf("�������޸ĺ�Ĵ�λ��Ŀ:\n");
	scanf("%hd", &p1->bed_amount);
	getchar();
	printf("�������޸ĺ��ס�޷�:\n");
	scanf("%f", &p1->fee);
	getchar();
	p1->snext = NULL;
	if (ModifDormNode(gp_head, s, p1) == 1)
	{
		printf("�޸ĳɹ���\n");
	}
	else
	{
		printf("������¥��Ϣ�����ڣ��޸�ʧ�ܣ�\n");
	}
	SaveSysData(gp_head, FileName);
	return bRet;
}

/**
* ��������: ModifDormNode
* ��������: ��ָ��������¥��Ϣ������ݽ����޸�.
* �������: hd ����ͷָ��
*           dorm_id ѧ��ѧ��
*           pdorm_node ָ�����޸����ݽ���ָ��
* �������: ��
* �� �� ֵ:int ��
*
* ����˵��:
*/
int ModifDormNode(DORM_NODE *hd, char *dorm_id, DORM_NODE *pdorm_node)
{
	DORM_NODE *pdorm_node_temp = hd;
	DORM_NODE *pdorm_node_next;
	STU_NODE *pstu_node_temp;
	int bRet = 0;
	pdorm_node_temp = SeekDormNode(hd, dorm_id); /*��������¥��Ϣ���*/
	if (pdorm_node_temp != NULL) /*����ҵ���������޸�*/
	{
		pdorm_node_next = pdorm_node_temp->next;
		pstu_node_temp = pdorm_node_temp->snext;
		*pdorm_node_temp = *pdorm_node;
		pdorm_node_temp->next = pdorm_node_next;
		pdorm_node_temp->snext = pstu_node_temp;
		bRet = 1;
	}
	return bRet;
}


/**
* ��������: SeekDormNode
* ��������: ������¥�Ų�ѯ����¥��Ϣ���.
* �������: hd ����ͷָ��
*           dorm_id ����¥��
* �������: ��
* �� �� ֵ: ����ʱ���ؽ��ĵ�ַ, ���򷵻�NULL
*
* ����˵��:
*/
DORM_NODE *SeekDormNode(DORM_NODE *hd, char *dorm_id)
{
	DORM_NODE *pdorm_node;
	int find = 0;
	for (pdorm_node = hd; pdorm_node != NULL; pdorm_node = pdorm_node->next)
	{
		if (strcmp(pdorm_node->dorm_id, dorm_id) == 0)
		{
			find = 1;
			break;
		}
	}
	if (find)
	{
		return pdorm_node;
	}
	else
	{
		return NULL;
	}
}


BOOL InsertStuInfo(void)
{
	BOOL bRet = TRUE;
	ScreenFresh();
	if (InsertStuNode(gp_head) == 1)
	{
		printf("����ɹ���\n");
	}
	else if (InsertStuNode(gp_head) == -1)
	{
		printf("����Ϣ�Ѵ��ڣ�����ʧ�ܣ�\n");
	}
	else
	{
		printf("��ѧ��������¥��Ϣ�����ڣ�\n");
	}
	SaveSysData(gp_head, FileName);
	return bRet;
}


/**
* ��������: InsertStuNode
* ��������: ��ʮ�������в���һ��ѧ��������Ϣ���.
* �������: hd ����ͷָ��
*           pstu_node ָ����Ҫ�������ָ��
* �������: ��
* �� �� ֵ:
* ����˵��:
*/
int InsertStuNode(DORM_NODE *hd)
{
	DORM_NODE *pdorm_node;
	STU_NODE *p1, *pterm;
	int find = 0;
	p1 = (STU_NODE *)malloc(sizeof(STU_NODE));
	printf("������ѧ��:\n");
	scanf("%s", p1->stu_id);
	getchar();
	printf("����������:\n");
	scanf("%s", p1->name);
	getchar();
	printf("�������Ա�:\n");
	scanf("%s", &p1->sex);
	getchar();
	printf("������������ڣ�\n");
	scanf("%s", p1->birthday);
	getchar();
	printf("������ѧ�����:\n");
	scanf("%s", p1->type);
	getchar();
	printf("������ѧ��:\n");
	scanf("%c", &p1->term);
	getchar();
	printf("��������ѧ����:\n");
	scanf("%s", p1->enroll_date);
	getchar();
	printf("������༶:\n");
	scanf("%s", p1->class_id);
	getchar();
	printf("����������¥��:\n");
	scanf("%s", p1->dorm_id);
	getchar();
	printf("�����뷿���:\n");
	scanf("%s", p1->room);
	getchar();
	printf("��������ϵ�绰:\n");
	scanf("%s", p1->tel);
	p1->cnext = NULL;
	pterm = SeekStuNode(hd, p1->stu_id); /*����ѧ��������Ϣ*/
	if (pterm != NULL) /*ѧ��������Ϣ�Ѵ���*/
	{
		find = -1;
	}
	else  /*��������¥��Ϣ*/
	{
		for (pdorm_node = hd; pdorm_node != NULL; pdorm_node = pdorm_node->next)
		{
			if (strcmp(pdorm_node->dorm_id, p1->dorm_id) == 0)
			{
				find = 1;
				break;
			}
		}
	}

	if (find)  /*����ѧ��������Ϣ*/
	{
		p1->next = pdorm_node->snext;
		pdorm_node->snext = p1;
	}
	else
	{
		free(p1);
	}
	return find;
}

BOOL DelStuInfo(void)
{
	BOOL bRet = TRUE;
	ScreenFresh();
	char s[20];
	printf("������ѧ��:\n");
	scanf("%s", s);
	getchar();
	if (DelStuNode(gp_head, s) == 1)
	{
		printf("ɾ���ɹ���\n");
	}
	else
	{
		printf("��ѧ��������Ϣ�����ڣ�ɾ��ʧ�ܣ�\n");
	}
	SaveSysData(gp_head, FileName);
	return bRet;
}


/**
* ��������: DelStuNode
* ��������: ��ʮ��������ɾ��ָ����ѧ��������Ϣ���.
* �������: hd ����ͷָ��
*           stu_id ѧ��������Ϣ��ѧ��,dorm_id����¥��
* �������: ��
* �� �� ֵ:
*
* ����˵��: ����ѧ�ź�����¥�ſ���ȷ��Ψһ��ѧ��������Ϣ
*/
int DelStuNode(DORM_NODE *hd, char *stu_id)
{
	DORM_NODE *pdorm_node = hd;
	STU_NODE *pstu_node_current;
	STU_NODE *pstu_node_prior;
	CHARGE_NODE *pcharge_node_current;
	CHARGE_NODE *pcharge_node_prior;
	int bRet = 0;

	while (pdorm_node != NULL)/*��ʮ�����в��Ҹ�ѧ��������¥��Ϣ���*/
	{
		pstu_node_current = pdorm_node->snext;
		pstu_node_prior = NULL;
		while (pstu_node_current != NULL&&strcmp(pstu_node_current->stu_id, stu_id))
		{
			pstu_node_prior = pstu_node_current;
			pstu_node_current = pstu_node_current->next;
		}
		if (pstu_node_current != NULL)
		{
			bRet = 1;
			break;
		}
		pdorm_node = pdorm_node->next;
	}
	if (pdorm_node != NULL)  /*����ҵ�*/
	{
		if (pstu_node_prior == NULL)  /*���λ��ѧ��������Ϣ֧����һ�����λ��*/
		{
			pdorm_node->snext = pstu_node_current->next;
		}
		else
		{
			pstu_node_prior->next = pstu_node_current->next;
		}
		pcharge_node_current = pstu_node_current->cnext;
		free(pstu_node_current);
		while (pcharge_node_current != NULL) /*ɾ���ɷ���Ϣ֧��*/
		{
			pcharge_node_prior = pcharge_node_current;
			pcharge_node_current = pcharge_node_current->next;
			free(pcharge_node_prior);
		}
	}
	return bRet;
}



BOOL ModifStuInfo(void)
{
	BOOL bRet = TRUE;
	ScreenFresh();
	char s[20];
	printf("������Ҫ�޸ĵ�ѧ��������Ϣ��ѧ��:\n");
	scanf("%s", s);
	getchar();
	STU_NODE *p1;
	p1 = (STU_NODE *)malloc(sizeof(STU_NODE));

	printf("�������޸ĺ��ѧ��:\n");
	scanf("%s", p1->stu_id);
	getchar();
	printf("�������޸ĺ������:\n");
	scanf("%s", p1->name);
	getchar();
	printf("�������޸ĺ���Ա�:\n");
	scanf("%c", &p1->sex);
	getchar();
	printf("�������޸ĺ�ĳ������ڣ�\n");
	scanf("%s", p1->birthday);
	getchar();
	printf("�������޸ĺ��ѧ�����:\n");
	scanf("%s", p1->type);
	getchar();
	printf("�������޸ĺ��ѧ��:\n");
	scanf("%c", &p1->term);
	getchar();
	printf("�������޸ĺ����ѧ����:\n");
	scanf("%s", p1->enroll_date);
	getchar();
	printf("�������޸ĺ�İ༶:\n");
	scanf("%s", p1->class_id);
	getchar();
	printf("�������޸ĺ������¥��:\n");
	scanf("%s", p1->dorm_id);
	getchar();
	printf("�������޸ĺ�ķ����:\n");
	scanf("%s", p1->room);
	getchar();
	printf("�������޸ĺ����ϵ�绰:\n");
	scanf("%s", p1->tel);
	getchar();
	p1->cnext = NULL;
	if (ModifStuNode(gp_head, s, p1) == 1)
	{
		printf("�޸ĳɹ���\n");
	}
	else
	{
		printf("�˻���ѧ����Ϣ�����ڣ��޸�ʧ�ܣ�\n");
		free(p1);
	}
	SaveSysData(gp_head, FileName);
	return bRet;
}


/**
* ��������: ModifStuNode
* ��������: ��ָ����ѧ��������Ϣ������ݽ����޸�.
* �������: hd ����ͷָ��
*           stu_id ѧ��ѧ��
*           pstu_node ָ�����޸����ݽ���ָ��
* �������: ��
* �� �� ֵ: int �ͣ�
*
* ����˵��:
*/
int ModifStuNode(DORM_NODE *hd, char *stu_id, STU_NODE *pstu_node)
{
	STU_NODE *pstu_node_temp;
	STU_NODE *pstu_node_next;
	CHARGE_NODE *pcharge_node_temp;
	int bRet = 0;
	pstu_node_temp = SeekStuNode(hd, stu_id); /*����ָ��ѧ��������Ϣ���*/
	if (pstu_node_temp != NULL)  /*����ҵ���������޸�*/
	{
		pstu_node_next = pstu_node_temp->next;
		pcharge_node_temp = pstu_node_temp->cnext;
		*pstu_node_temp = *pstu_node;
		pstu_node_temp->next = pstu_node_next;
		pstu_node_temp->cnext = pcharge_node_temp;
		bRet = 1;
	}
	return bRet;
}


/**
* ��������: InsertChargeNode
* ��������: ��ʮ�������в���һ���ɷ���Ϣ���.
* �������: hd ����ͷָ��
*           pcharge_node ָ����Ҫ�������ָ��
* �������: ��
* �� �� ֵ:
*
* ����˵��:
*/
int InsertChargeNode(DORM_NODE *hd, CHARGE_NODE *pcharge_node)
{
	STU_NODE *pstu_node;
	CHARGE_NODE *pterm;
	int bRet = 0;

	pterm = SeekChargeNode(hd, pcharge_node->stu_id, pcharge_node->date);/*���ҽɷ���Ϣ*/
	pstu_node = SeekStuNode(hd, pcharge_node->stu_id); /*�������ѧ��������Ϣ*/
	if (pterm != NULL) /*�˽ɷ���Ϣ�Ѵ���*/
	{
		bRet = -1;
	}
	else
	{
		if (pstu_node != NULL) /*����ɷ���Ϣ*/
		{
			pcharge_node->next = pstu_node->cnext;
			pstu_node->cnext = pcharge_node;
			bRet = 1;
		}
	}
	return bRet;
}


BOOL InsertChargeInfo(void)
{
	BOOL bRet = TRUE;
	ScreenFresh();
	CHARGE_NODE *p1;
	p1 = (CHARGE_NODE *)malloc(sizeof(CHARGE_NODE));
	printf("������ѧ�ţ�\n");
	scanf("%s", p1->stu_id);
	getchar();
	printf("������������\n");
	scanf("%s", p1->name);
	getchar();
	printf("������ɷ����ڣ�\n");
	scanf("%s", p1->date);
	getchar();
	printf("������ɷѽ��:\n");
	scanf("%f", &p1->sum);
	getchar();
	printf("�������շ�������:\n");
	scanf("%s", p1->payee);
	getchar();
	printf("�����뱸ע:\n");
	scanf("%s", p1->notes);
	getchar();
	if (InsertChargeNode(gp_head, p1) == 1)
	{
		printf("����ɹ���\n");
	}
	else if (InsertChargeNode(gp_head, p1) == -1)
	{
		printf("�ýɷ���Ϣ�Ѵ��ڣ�\n");
	}
	else
	{
		printf("�ýɷ���Ϣ��ѧ���Ļ�����Ϣ�����ڣ�����ʧ�ܣ�\n");
	}
	SaveSysData(gp_head, FileName);
	return bRet;
}

BOOL DelChargeInfo(void)
{
	void ShowMenu();
	BOOL bRet = TRUE;
	ScreenFresh();
	char s[20];
	char p[20];
	printf("������ѧ��:\n");
	scanf("%s", s);
	getchar();
	printf("������ɷ�����:\n");
	scanf("%s", p);
	getchar();
	if (DelStuNode(gp_head, s) == 1)
	{
		printf("ɾ���ɹ���\n");
	}
	else
	{
		printf("�ýɷ���Ϣ������,ɾ��ʧ�ܣ�\n");
	}
	SaveSysData(gp_head, FileName);
	return bRet;
}

BOOL ModifChargeInfo(void)
{
	BOOL bRet = TRUE;
	ScreenFresh();
	char s[20];
	char p[20];
	printf("������Ҫ�޸ĵ�ѧ���ɷ���Ϣ��ѧ��:\n");
	scanf("%s", s);
	getchar();
	printf("������Ҫ�޸ĵ�ѧ���ɷ���Ϣ������:\n");
	scanf("%s", p);
	getchar();
	CHARGE_NODE *p1;
	p1 = (CHARGE_NODE *)malloc(sizeof(CHARGE_NODE));
	printf("�������޸ĺ��ѧ�ţ�\n");
	scanf("%s", p1->stu_id);
	getchar();
	printf("�������޸ĺ��������\n");
	scanf("%s", p1->name);
	getchar();
	printf("�������޸ĺ�Ľɷ����ڣ�\n");
	scanf("%s", p1->date);
	getchar();
	printf("�������޸ĺ�Ľɷѽ��:\n");
	scanf("%f", &p1->sum);
	getchar();
	printf("�������޸ĺ���շ�������:\n");
	scanf("%s", p1->payee);
	getchar();
	printf("�������޸ĺ�ı�ע:\n");
	scanf("%s", p1->notes);
	getchar();
	if (ModifChargeNode(gp_head, s, p, p1) == 1)
	{
		printf("�޸ĳɹ���\n");
	}
	else
	{
		printf("�˽ɷ���Ϣ�����ڣ��޸�ʧ�ܣ�\n");
		free(p1);
	}
	SaveSysData(gp_head, FileName);
	return bRet;
}


BOOL QueryDormInfo(void)
{
	BOOL bRet = TRUE;
	ScreenFresh();
	char s[20];
	DORM_NODE *p;
	printf("�������ѯ������¥��:\n");
	scanf("%s", s);
	p = SeekDormNode(gp_head, s);
	if (p == NULL)
	{
		printf("������¥��Ϣ�����ڣ�\n");
		return FALSE;
	}
	printf("\n\n");
	printf("\t\t����¥��:%21s\t\n", p->dorm_id);
	printf("\t\t����Ա����:%19s\t\n", p->name);
	printf("\t\t��ϵ�绰:%21s\t\n", p->tel);
	printf("\t\t������Ŀ:%21d\t\n", p->room_amount);
	printf("\t\t��λ��Ŀ:%21d\t\n", p->bed_amount);
	printf("\t\tס�޷�:%19.2f(Ԫ)\t\n", p->fee);

	return bRet;
}

BOOL QueryStuInfo(void)
{
	BOOL bRet = TRUE;
	ScreenFresh();
	char s[20];
	STU_NODE *p;
	printf("������ѧ��:\n");
	scanf("%s", s);
	p = SeekStuNode(gp_head, s);
	if (p == NULL)
	{
		printf("��ѧ��������Ϣ�����ڣ�\n");
		return FALSE;
	}
	printf("\n\n");
	printf("\t\tѧ��:%25s\t\n", p->stu_id);
	printf("\t\t����:%25s\t\n", p->name);
	printf("\t\t�Ա�:%25s\t\n", p->sex);
	printf("\t\t��������:%21s\t\n", p->birthday);
	printf("\t\tѧ�����:%21s\t\n", p->type);
	printf("\t\tѧ��:%25c\t\n", p->term);
	printf("\t\t��ѧ����:%21s\t\n", p->enroll_date);
	printf("\t\t�༶:%25s\t\n", p->class_id);
	printf("\t\t����¥��:%21s\t\n", p->dorm_id);
	printf("\t\t�����:%23s\t\n", p->room);
	printf("\t\t��ϵ�绰:%21s\t\n", p->tel);
	return bRet;
}

BOOL QueryClassChargeInfo(void)
{
	BOOL bRet = TRUE;
	ScreenFresh();
	char s[20];
	char t[20];
	CLASS_CHARGE_NODE *p;
	printf("������༶:\n");
	scanf("%s", s);
	printf("������ɷ�����:\n");
	scanf("%s", t);
	p = SeekClassChargeNode(gp_head, s, t);
	if (p == NULL)
	{
		printf("�˽ɷ���Ϣ�����ڣ�\n");
		return FALSE;
	}

	printf("\n\n");
	printf("\t\tѧ�ţ�%25s\t\n", p->stu_id);
	printf("\t\t������%25s\t\n", p->name);
	printf("\t\t�༶��%25s\t\n", p->class_id);
	printf("\t\t�ɷ����ڣ�%25s\t\n", p->date);
	printf("\t\t�ɷѽ�%25s\t\n", p->sum);
	printf("\t\t�տ��ˣ�%25s\t\n", p->payee);
	printf("\t\t��ע��%25s\t\n", p->notes);

	return bRet;
}

BOOL QueryChargeInfo(void)
{

	BOOL bRet = TRUE;
	ScreenFresh();
	char s[20];
	char t[20];
	CHARGE_NODE *p;
	printf("������ѧ��:\n");
	scanf("%s", s);
	getchar();
	printf("������ɷ�����:\n");
	scanf("%s", t);
	getchar();
	p = SeekChargeNode(gp_head, s, t);
	if (p == NULL)
	{
		printf("�˽ɷ���Ϣ�����ڣ�\n");
		return FALSE;
	}
	printf("\n\n");
	printf("\t\tѧ��:%25s\t\n", p->stu_id);
	printf("\t\t����:%25s\t\n", p->name);
	printf("\t\t�ɷ�����:%21s\t\n", p->date);
	printf("\t\t�ɷѽ��:%19.2f\t\n", p->sum);
	printf("\t\t�շ���:%23s\t\n", p->payee);
	printf("\t\t��ע:%25s\t\n", p->notes);
	return bRet;
}


BOOL StatUsedRate(void)
{
	BOOL bRet = TRUE;
	ScreenFresh();
	USE_RATE_NODE *p;
	p = StatUseRateInfo(gp_head);
	if (p == NULL)
	{
		printf("����Ϣ�����ڣ�\n");
		return FALSE;
	}
	printf("\n\n");
	printf("\t��������������������������������������������������������������\n");
	printf("\t��  ����¥�ũ���סѧ��������סѧ������  �մ�λ����    ��ס�ʩ�\n");

	while (p != NULL)
	{
		printf("\t��������������������������������������������������������������\n");
		printf("\t��%10s��%10hu��%10hu��%10hu��%10.6f��\n", p->dorm_id, p->total_num, p->used_num, p->free_num, p->use_rate);
		p = p->next;
	}
	printf("\t��������������������������������������������������������������\n");
	return bRet;
}


/**
* ��������: StatUseRateInfo
* ��������: ͳ������¥��ס����Ϣ.
* �������: hd ����ͷ���ָ��
* �������: ��
* �� �� ֵ: ����ͳ�ƽ����ͷ����ַ
*
* ����˵��:
*/
USE_RATE_NODE *StatUseRateInfo(DORM_NODE *hd)
{
	DORM_NODE *pdorm_node = hd;
	STU_NODE *pstu_node;
	USE_RATE_NODE *puse_rate_node_ret = NULL;
	USE_RATE_NODE *puse_rate_node_temp;

	int total;
	for (pdorm_node = hd; pdorm_node != NULL; pdorm_node = pdorm_node->next)
	{
		int num = 0;
		total = pdorm_node->bed_amount;
		pstu_node = pdorm_node->snext;
		while (pstu_node != NULL)
		{
			if (strcmp(pstu_node->dorm_id, pdorm_node->dorm_id) == 0)
			{
				num++;
			}
			pstu_node = pstu_node->next;
		}
		puse_rate_node_temp = (USE_RATE_NODE *)malloc(sizeof(USE_RATE_NODE));
		strcpy(puse_rate_node_temp->dorm_id, pdorm_node->dorm_id);
		puse_rate_node_temp->total_num = total;
		puse_rate_node_temp->used_num = num;
		puse_rate_node_temp->free_num = total - num;
		puse_rate_node_temp->use_rate = num*1.0 / total;
		puse_rate_node_temp->next = puse_rate_node_ret;
		puse_rate_node_ret = puse_rate_node_temp;
	}
	SortUseRateInfo(puse_rate_node_ret);  /*��ͳ�ƽ������������*/
	return puse_rate_node_ret;
}

/**
* ��������: SortUseRateInfo
* ��������: ������¥��ס����Ϣ����������.
* �������: use_rate_hd ��ס����Ϣ��ͷ���ָ��
* �������: use_rate_hd ������ͬʱͨ��ͷ���ָ�뷵��
* �� �� ֵ: ��
*
* ����˵��:
*/
void SortUseRateInfo(USE_RATE_NODE *use_rate_hd)
{
	USE_RATE_NODE *puse_rate_node_prior;
	USE_RATE_NODE *puse_rate_node_after;
	USE_RATE_NODE *puse_rate_node_cur;
	USE_RATE_NODE *puse_rate_node_temp;
	puse_rate_node_prior = use_rate_hd;
	if (puse_rate_node_prior == NULL) /*����*/
	{
		return;
	}

	/*����ʱ�����ڽ��������Ϣ��ʱ���*/
	puse_rate_node_temp = (USE_RATE_NODE *)malloc(sizeof(USE_RATE_NODE));
	while (puse_rate_node_prior->next != NULL)   /*ѡ������*/
	{
		puse_rate_node_cur = puse_rate_node_prior;
		puse_rate_node_after = puse_rate_node_prior->next;
		while (puse_rate_node_after != NULL)
		{
			if (puse_rate_node_cur->use_rate<puse_rate_node_after->use_rate)
			{
				puse_rate_node_cur = puse_rate_node_after;
			}
			puse_rate_node_after = puse_rate_node_after->next;
		}
		if (puse_rate_node_cur != puse_rate_node_prior)
		{
			/*������������е���Ϣ��ָ���򲻽���*/
			*puse_rate_node_temp = *puse_rate_node_prior;
			*puse_rate_node_prior = *puse_rate_node_cur;
			puse_rate_node_prior->next = puse_rate_node_temp->next;
			puse_rate_node_temp->next = puse_rate_node_cur->next;
			*puse_rate_node_cur = *puse_rate_node_temp;
		}
		puse_rate_node_prior = puse_rate_node_prior->next;
	}
	free(puse_rate_node_temp);
	return;
}


BOOL StatStuType(void)
{
	ScreenFresh();
	BOOL bRet = TRUE;
	STU_TYPE_NODE *p;

	p = StatStuTypeInfo(gp_head);
	if (p == NULL)
	{
		printf("����Ϣ�����ڣ�\n");
		return FALSE;
	}
	printf("\n\n");
	printf("\t��������������������������������������������������������������������\n");
	printf("\t���꼶����ר��Ůר���б���Ů������˶��Ů˶���в���Ů����������Ů����\n");
	while (p != NULL)
	{
		printf("\t��������������������������������������������������������������������\n");
		printf("\t��%4s��%4hd��%4hd��%4hd��%4hd��%4hd��%4hd��%4hd��%4hd��%4hd��%4hd��\n", p->grade, p->school_boy1, p->school_girl1, p->school_boy2,
			p->school_girl2, p->school_boy3, p->school_girl3, p->school_boy4, p->school_girl4, p->school_boy5, p->school_girl5);
		p = p->next;
	}
	printf("\t��������������������������������������������������������������������");
	return bRet;
}


/**
* ��������: StatStuTypeInfo
* ��������: ͳ����סѧ��������Ϣ.
* �������: hd ����ͷ���ָ��
* �������: ��
* �� �� ֵ: ����ͳ�ƽ����ͷ����ַ
*
* ����˵��:
*/
STU_TYPE_NODE *StatStuTypeInfo(DORM_NODE *hd)
{
	DORM_NODE *pdorm_node = hd;
	STU_NODE *pstu_node;
	STU_TYPE_NODE *pstu_type_node_ret = NULL;
	STU_TYPE_NODE *pstu_type_node_temp;

	char *pctemp1;
	char p1[5];
	char *p2;
	char p3;
	int i, n;
	int enroll_year;
	int stu_type;
	int stu_sex;
	int c[2] = { 0,1 };
	int today_year;
	time_t current_time;
	struct tm *current_tm;
	time(&current_time);
	current_tm = localtime(&current_time);
	today_year = current_tm->tm_year + 1900;

	for (i = today_year - 1; i >= today_year - 4; i--)
	{
		pstu_type_node_temp = (STU_TYPE_NODE *)malloc(sizeof(STU_TYPE_NODE));
		int s[10] = { 0,0,0,0,0,0,0,0,0,0 };
		for (pdorm_node = hd; pdorm_node != NULL; pdorm_node = pdorm_node->next)
		{
			pstu_node = pdorm_node->snext;
			while (pstu_node != NULL)
			{
				pctemp1 = pstu_node->enroll_date;/*ȡ��ѧ����Ϣ�������ѧ������Ϣ*/
				strncpy(p1, pctemp1, 4);
				p1[4] = '\0';
				p2 = pstu_node->type;  /*ȡ��ѧ����Ϣ�����ѧ�������Ϣ*/
				p3 = pstu_node->sex;   /*ȡ��ѧ����Ϣ�����ѧ���Ա���Ϣ*/
				enroll_year = atoi(p1);
				stu_type = atoi(p2);
				stu_sex = p3 - '0';
				if (enroll_year == i)
				{
					strcpy(pstu_type_node_temp->grade, p1); /*��ѧ��ݼ�Ϊѧ�����꼶*/
					switch (stu_type)
					{
					case 10:
						if (stu_sex == c[0])
						{
							s[0]++;
							break;
						}
						else
						{
							s[1]++;
							break;
						}
					case 20:
						if (stu_sex == c[0])
						{
							s[2]++;
							break;
						}
						else
						{
							s[3]++;
							break;
						}
					case 30:
						if (stu_sex == c[0])
						{
							s[4]++;
							break;
						}
						else
						{
							s[5]++;
							break;
						}
					case 40:
						if (stu_sex == c[0])
						{
							s[6]++;
							break;
						}
						else
						{
							s[7]++;
							break;
						}
					case 50:
						if (stu_sex == c[0])
						{
							s[8]++;
							break;
						}
						else
						{
							s[9]++;
							break;
						}
					}
				}
				pstu_node = pstu_node->next;
			}
		}
		pstu_type_node_temp->school_boy1 = s[0];
		pstu_type_node_temp->school_girl1 = s[1];
		pstu_type_node_temp->school_boy2 = s[2];
		pstu_type_node_temp->school_girl2 = s[3];
		pstu_type_node_temp->school_boy3 = s[4];
		pstu_type_node_temp->school_girl3 = s[5];
		pstu_type_node_temp->school_boy4 = s[6];
		pstu_type_node_temp->school_girl4 = s[7];
		pstu_type_node_temp->school_boy5 = s[8];
		pstu_type_node_temp->school_girl5 = s[9];
		pstu_type_node_temp->next = pstu_type_node_ret;
		pstu_type_node_ret = pstu_type_node_temp;
	}

	return pstu_type_node_ret;
}


BOOL StatDormCharge(void)
{
	BOOL bRet = TRUE;
	ScreenFresh();
	INCOME_NODE *p;
	p = StatDormIncomeInfo(gp_head);
	if (p == NULL)
	{
		printf("����Ϣ�����ڣ�\n");
		return FALSE;
	}
	printf("\n\n");
	printf("\t��������������������������������������������������������������\n");
	printf("\t��  ����¥�ũ����һ���멦��ȶ����멦��������멦��������멦\n");
	while (p != NULL)
	{
		printf("\t��������������������������������������������������������������\n");
		printf("\t��%10s��%10.2f��%10.2f��%10.2f��%10.2f��\n", p->dorm_id, p->year1_income, p->year2_income, p->year3_income, p->year4_income);
		p = p->next;
	}
	printf("\t��������������������������������������������������������������\n");
	return bRet;
}

/**
* ��������: StatDormIncomeInfo
* ��������: ͳ������¥������Ϣ.
* �������: hd ����ͷ���ָ��

* �������: ��
* �� �� ֵ: ����ͳ�ƽ����ͷ����ַ
*
* ����˵��:
*/
INCOME_NODE *StatDormIncomeInfo(DORM_NODE *hd)
{
	DORM_NODE *pdorm_node;
	STU_NODE *pstu_node;
	CHARGE_NODE *pcharge_node;
	INCOME_NODE *pincome_node_ret = NULL;
	INCOME_NODE *pincome_node_temp;
	char date[12];
	char *pctemp;

	int today_year;
	int paid_year;
	time_t current_time;
	struct tm *current_tm;
	time(&current_time);
	current_tm = localtime(&current_time);
	today_year = current_tm->tm_year + 1900;

	for (pdorm_node = hd; pdorm_node != NULL; pdorm_node = pdorm_node->next)
	{
		float m[4] = { 0.0,0.0,0.0,0.0 };
		pstu_node = pdorm_node->snext;
		while (pstu_node != NULL)
		{
			pcharge_node = pstu_node->cnext;
			while (pcharge_node != NULL)
			{
				pctemp = pcharge_node->date;
				strncpy(date, pctemp, 4);
				paid_year = atoi(date);
				switch (today_year - paid_year)
				{
				case 1:
					m[0] += pcharge_node->sum;
					break;
				case 2:
					m[1] += pcharge_node->sum;
					break;
				case 3:
					m[2] += pcharge_node->sum;
					break;
				case 4:
					m[3] += pcharge_node->sum;
					break;
				default:
					break;
				}
				pcharge_node = pcharge_node->next;
			}
			pstu_node = pstu_node->next;
		}
		pincome_node_temp = (INCOME_NODE *)malloc(sizeof(INCOME_NODE));
		strcpy(pincome_node_temp->dorm_id, pdorm_node->dorm_id);
		pincome_node_temp->year1_income = m[0];
		pincome_node_temp->year2_income = m[1];
		pincome_node_temp->year3_income = m[2];
		pincome_node_temp->year4_income = m[3];
		pincome_node_temp->next = pincome_node_ret;
		pincome_node_ret = pincome_node_temp;
	}
	return pincome_node_ret;
}

BOOL StatClassCharge(void)
{
	BOOL bRet = TRUE;
	ScreenFresh();
	char s[20];
	char t[20];
	CLASS_CHARGE_NODE *p;
	printf("������༶:\n");
	scanf("%s", s);
	getchar();
	printf("������ɷ�����:\n");
	scanf("%s", t);
	getchar();
	p = SeekClassChargeNode(gp_head, s, t);
	if (p == NULL)
	{
		printf("����Ϣ�����ڣ�\n");
		return FALSE;
	}
	printf("\n\n");
	printf(" ������������������������������������������������������������������������\n");
	printf(" ��    �༶��    ѧ�ũ�    �������ɷ����ک��ɷѽ�  �շ��˩�    ��ע��\n");
	while (p != NULL)
	{
		printf(" ������������������������������������������������������������������������\n");
		printf(" ��%8s��%8s��%8s��%8s��%8.2f��%8s��%8s��\n", p->class_id, p->stu_id, p->name, p->date, p->sum, p->payee, p->notes);
		p = p->next;
	}
	printf(" ������������������������������������������������������������������������\n");
	return bRet;
}


/**
* ��������: SeekClassChargeNode
* ��������: ���༶��ѯѧ���ɷ���Ϣ.
* �������: hd ����ͷָ��
class_id  �༶
date  �ɷ�����
* �������: ��
* �� �� ֵ: ���������������Ľ�㸴�Ƶ�����������ؽ�������ͷ����ַ
*
* ����˵��:
*/
CLASS_CHARGE_NODE *SeekClassChargeNode(DORM_NODE *hd, char *class_id, char *date)
{
	DORM_NODE *pdorm_node = hd;
	STU_NODE *pstu_node;
	CHARGE_NODE *pcharge_node;
	CLASS_CHARGE_NODE *pclass_charge_node_ret = NULL;
	CLASS_CHARGE_NODE *pclass_charge_node_temp;
	for (pdorm_node = hd; pdorm_node != NULL; pdorm_node = pdorm_node->next)
	{
		pstu_node = pdorm_node->snext;
		while (pstu_node != NULL)
		{
			if (strcmp(pstu_node->class_id, class_id) == 0) /*��ѧ����Ҫ��ѯ�İ༶��*/
			{
				pcharge_node = SeekChargeNode(gp_head, pstu_node->stu_id, date);
				/*���ɷ���Ϣ�����½�㣬�����½�����ͳ�ƽ����*/
				pclass_charge_node_temp = (CLASS_CHARGE_NODE *)malloc(sizeof(CLASS_CHARGE_NODE));
				strcpy(pclass_charge_node_temp->class_id, pstu_node->class_id);
				strcpy(pclass_charge_node_temp->stu_id, pcharge_node->stu_id);
				strcpy(pclass_charge_node_temp->name, pcharge_node->name);
				strcpy(pclass_charge_node_temp->date, pcharge_node->date);
				pclass_charge_node_temp->sum = pcharge_node->sum;
				strcpy(pclass_charge_node_temp->payee, pcharge_node->payee);
				strcpy(pclass_charge_node_temp->notes, pcharge_node->notes);
				pclass_charge_node_temp->next = pclass_charge_node_ret;
				pclass_charge_node_ret = pclass_charge_node_temp;
			}
			pstu_node = pstu_node->next;
		}
	}
	return pclass_charge_node_ret;
}



BOOL StatUncharge(void)
{
	BOOL bRet = TRUE;
	ScreenFresh();
	UNCHARGE_NODE *p;
	p = StatUnchargeInfo(gp_head);
	if (p == NULL)
	{
		printf("����Ϣ�����ڣ�\n");
		return FALSE;
	}
	printf("\n\n");
	printf("\t��������������������������������������������������������\n");
	printf("\t��    ѧ��  ��    ���� ������¥�ũ�  ����ũ�Ƿ�ɽ�� ��\n");
	while (p != NULL)
	{
		printf("\t���������������������� ������������������������������ ��\n");
		printf("\t��%8s��%8s ��%8s��%8s��%8.2f ��\n", p->stu_id, p->name, p->dorm_id, p->room_num, p->amount);
		p = p->next;
	}
	printf("\t��������������������������������������������������������\n");
	return bRet;
}

BOOL HelpTopic(void)
{
	BOOL bRet = TRUE;
	ScreenFresh();
	printf("\n");
	printf("��ϵͳ��ݲ���ָ�ϡ�\n");
	Delay();
	printf(" 1��   F1    ��ʾ��������\n");
	Delay();
	printf(" 2��Alt + X  �˳�ϵͳ;\n");
	Delay();
	printf(" 3��Alt + C  �����Ļ;\n");
	Delay();
	printf(" 4��Alt + F  ����\"�ļ�(F)\"�������˵�;\n");
	Delay();
	printf(" 5��Alt + E  ����\"�༭(E)\"�������˵�;\n");
	Delay();
	printf(" 6��Alt + I  ����\"��ѯ(I)\"�������˵�;\n");
	Delay();
	printf(" 7��Alt + S  ����\"ͳ��(S)\"�������˵�;\n");
	Delay();
	printf(" 8��Alt + H  ����\"����(H)\"�������˵�;\n");
	Delay();
	printf(" 9��ESC  ��  �رյ�������,�ص����˵���;\n");
	Delay();
	printf("10��Enter��  ִ����Ӧ�Ĺ��ܺ���;\n");
	Delay();
	return bRet;
}

BOOL AboutDorm(void)
{
	BOOL bRet = TRUE;
	ScreenFresh();
	printf("\n\t\t   ��** Programming Instructions **��\n");
	Delay();
	printf(" \t������������������������������������������������������������\n");
	Delay();
	printf(" \t���� ��ϵͳ����VC 6.0��CODE:BLOCKS��C-Free������;         ��\n");
	Delay();
	printf(" \t���� ϵͳ֧�ֿ�ݼ�����,�򵥵��������ͼ��̲���;         ��\n");
	Delay();
	printf(" \t���� ��ϵͳ����ʹ���˱�ע,����ʹ���������׶�;             ��\n");
	Delay();
	printf(" \t���� ���ý϶�Ľṹ,���������ʮ�ֽ�����������Ϣ;       ��\n");
	Delay();
	printf(" \t���� ��������,ָ��,�ṹ�����ϼ��ļ��������,����̨��֪ʶ����\n");
	Delay();
	printf(" \t���� ϵͳ��Ҫ�ṩѧ����Ϣ�Ŀ��ٲ�ѯ��������ͳ��;          ��\n");
	Delay();
	printf(" \t���� ��������ѧ��������Ϣ��ѯ,��Ϣ¼��,�޸�,ɾ���ȹ���.   ��\n");
	Delay();
	printf("    ��������������������������������������������������������������������\n");
	Delay();
	printf("    �����ο����ס�:\t\t\t\t\t\t      ��\n    �� [1]�ܼƲ�,¬Ƽ,�. C���Գ������,��������ѧ������,2008;      ��\n");
	Delay();
	printf("    �� [2]�,¬Ƽ,�ܼƲ�. C����ʵ����γ����,��������ѧ������,2011;��\n");
	printf("    ��������������������������������������������������������������������\n");
	return bRet;
}


/**
* ��������: DelChargeNode
* ��������: ��ʮ��������ɾ��ָ���Ľɷ���Ϣ���.
* �������: hd ����ͷָ��
*           stu_id �ɷ�ѧ��ѧ��
*           date �ɷ�����
* �������: ��
* �� �� ֵ: BOOL����, TRUE��ʾɾ���ɹ�, FALSE��ʾɾ��ʧ��
*
* ����˵��: ����ѧ�źͽɷ����ڿ���ȷ��Ψһ�Ľɷ���Ϣ
*/
BOOL DelChargeNode(DORM_NODE *hd, char *stu_id, char *date)
{
	STU_NODE *pstu_node;
	CHARGE_NODE *pcharge_node_prior;
	CHARGE_NODE *pcharge_node_current;
	int bRet = 0;
	pstu_node = SeekStuNode(hd, stu_id);/*��ʮ�������в��Ҹ�ѧ��������Ϣ���*/
	if (pstu_node != NULL)/*����ҵ�*/
	{
		/*�ڽɷ���Ϣ֧���ϲ��Ҹ����ɷ����ڵĽɷ���Ϣ���*/
		pcharge_node_prior = NULL;
		pcharge_node_current = pstu_node->cnext;
		while (pcharge_node_current != NULL&&strcmp(pcharge_node_current->date, date) != 0)
		{
			pcharge_node_prior = pcharge_node_current;
			pcharge_node_current = pcharge_node_current->next;
		}
		if (pcharge_node_current != NULL)/*����ҵ�*/
		{
			bRet = 1;
			if (pcharge_node_prior == NULL)/*���λ�ڽɷ�֧���ϵ�һ�����λ��*/
			{
				pstu_node->cnext = pcharge_node_current->next;
			}
			else
			{
				pcharge_node_prior->next = pcharge_node_current->next;
			}
			free(pcharge_node_current);
		}
	}
	return bRet;
}

/**
* ��������: ModifChargeNode
* ��������: ��ָ���Ľɷ���Ϣ������ݽ����޸�.
* �������: hd ����ͷָ��
*           stu_id �ɷ�ѧ��ѧ��
*           date �ɷ�����
*           pcharge_node ָ�����޸����ݽ���ָ��
* �������: ��
* �� �� ֵ: BOOL����, TRUE��ʾ�޸ĳɹ�, FALSE��ʾ�޸�ʧ��
*
* ����˵��:
*/
BOOL ModifChargeNode(DORM_NODE *hd, char *stu_id, char *date, CHARGE_NODE *pcharge_node)
{
	CHARGE_NODE *pcharge_node_temp;
	CHARGE_NODE *pcharge_node_next;
	int bRet = 0;
	pcharge_node_temp = SeekChargeNode(hd, stu_id, date);/*����ָ���ɷ���Ϣ���*/
	if (pcharge_node_temp != NULL)/*����ҵ�������޸�*/
	{
		pcharge_node_next = pcharge_node_temp->next;/*��ֵǰ����ָ����*/
		*pcharge_node_temp = *pcharge_node;
		pcharge_node_temp->next = pcharge_node_next;/*�ָ�ָ���ϵ*/
		bRet = 1;
	}
	return bRet;
}

/**
* ��������: SeekStuNode
* ��������: ��ѧ�Ų���ѧ��������Ϣ���.
* �������: hd ����ͷָ��
*           stu_id ѧ��ѧ��
* �������: ��
* �� �� ֵ: ����ʱ���ؽ��ĵ�ַ, ���򷵻�NULL
*
* ����˵��:
*/
STU_NODE *SeekStuNode(DORM_NODE *hd, char *stu_id)
{
	DORM_NODE *pdorm_node;
	STU_NODE *pstu_node;
	int find = 0;
	for (pdorm_node = hd; pdorm_node != NULL; pdorm_node = pdorm_node->next)
	{
		/*����ѭ��������������ÿ������ѧ����Ϣ֧��*/
		pstu_node = pdorm_node->snext;
		while (pstu_node != NULL)
		{
			if (strcmp(pstu_node->stu_id, stu_id) == 0)
			{
				find = 1;
				break;
			}
			pstu_node = pstu_node->next;
		}
		if (find)
		{
			break;
		}

	}
	if (find)
	{
		return pstu_node;
	}
	else
	{
		return NULL;
	}
}

/**
* ��������: SeekChargeNode
* ��������: ��ѧ�źͽɷ����ڲ��ҽɷ���Ϣ���.
* �������: hd ����ͷָ��
*           stu_id ѧ��ѧ��
*           date �ɷ�����
* �������: ��
* �� �� ֵ: ����ʱ���ؽ��ĵ�ַ, ���򷵻�NULL
*
* ����˵��:
*/
CHARGE_NODE *SeekChargeNode(DORM_NODE *hd, char *stu_id, char *date)
{
	STU_NODE *pstu_node;
	CHARGE_NODE *pcharge_node;
	int find = 0;
	pstu_node = SeekStuNode(hd, stu_id);/*���Ȳ��Ҷ�Ӧ��ѧ��������Ϣ���*/

										/*����ҵ����ڽɷ���Ϣ֧���ϼ�����ָ���ɷ���Ϣ���*/
	if (pstu_node != NULL)
	{
		pcharge_node = pstu_node->cnext;
		while (pcharge_node != NULL)
		{
			if (strcmp(pcharge_node->date, date) == 0)
			{
				find = 1;
				break;
			}
			pcharge_node = pcharge_node->next;
		}
	}
	if (find)
	{
		return pcharge_node;
	}
	else
	{
		return NULL;
	}
}

/**
* ��������: SeekStuNodeM
* ��������: ������������ϲ�ѯ��������������ѧ����Ϣ���.
* �������: hd ����ͷָ��
*           cond_num ��������ĸ���
*           ... ��ʾ��ѯ�������ַ���
* �������: ��
* �� �� ֵ: ���������������Ľ�㸴�Ƶ�����������ؽ�������ͷ����ַ
*
* ����˵��:
*/
STU_NODE *SeekStuNodeM(DORM_NODE *hd, int cond_num, ...)
{
	DORM_NODE *pdorm_node;
	STU_NODE *pstu_node;
	STU_NODE *pstu_node_ret = NULL;/*��ѯ��������ͷָ��*/
	STU_NODE *pstu_node_temp;
	char *pcTemp;
	char *condition[cond_num];
	int i;
	va_list ap;
	va_start(ap, cond_num);
	for (i = 0; i<cond_num; i++) /*�ӿɱ��������ȡ�������ַ����������ַ�������*/
	{
		pcTemp = va_arg(ap, char*);
		condition[i] = (char*)malloc(strlen(pcTemp) + 1);
		strcpy(condition[i], pcTemp);
	}
	va_end(ap);

	for (pdorm_node = hd; pdorm_node != NULL; pdorm_node = pdorm_node->next)
	{
		/*����ʮ������ÿ��ѧ����Ϣ��㡣���������������Ľ�㸳ֵ���������*/
		pstu_node = pdorm_node->snext;
		while (pstu_node != NULL)
		{
			for (i = 0; i<cond_num; i++)
			{
				if (JudgeStuNodeItem(pstu_node, condition[i]) == FALSE)
				{
					break;
				}
			}
			if (i == cond_num) /*���ʱ��ʾ��������������*/
			{
				/*���ý����Ϣ���Ƶ�һ���½�㣬�����½����뵽�������*/
				pstu_node_temp = (STU_NODE*)malloc(sizeof(STU_NODE));
				*pstu_node_temp = *pstu_node;
				pstu_node_temp->next = pstu_node_ret;
				pstu_node_ret = pstu_node_temp;
			}
			pstu_node = pstu_node->next;
		}
	}
	for (i = 0; i<cond_num; i++)
	{
		free(condition[i]);
	}
	return pstu_node_ret;
}

/**
* ��������: JudgeStuNodeItem
* ��������: �ж�ѧ����Ϣ����Ƿ������������.
* �������: pstu_node ѧ����Ϣ���ָ��
*           pcondition ������ʾ�������ַ���
* �������: ��
* �� �� ֵ: ��������ʱ, ����TRUE; ���򷵻�FALSE
*
* ����˵��:
*/
BOOL JudgeStuNodeItem(STU_NODE *pstu_node, char *pcondition)
{

	return TRUE;
}

/**
* ��������: MatchString
* ��������: �Ը����ַ�������������ƥ��.
* �������: string_item �����ַ���
*           pcond ����ƥ����������ڵ������ַ���
* �������: ��
* �� �� ֵ: ƥ��ɹ�ʱ, ����TRUE; ���򷵻�FALSE
*
* ����˵��:
*/
BOOL MatchString(char *string_item, char *pcond)
{

	return TRUE;
}

/**
* ��������: MatchChar
* ��������: �Ը����ַ�����������ƥ��.
* �������: char_item �����ַ�
*           pcond ����ƥ����������ڵ������ַ���
* �������: ��
* �� �� ֵ: ƥ��ɹ�ʱ, ����TRUE; ���򷵻�FALSE
*
* ����˵��:
*/
BOOL MatchChar(char char_item, char *pcond)
{
	char op;
	int compare_result;
	BOOL bRet = FALSE;
	compare_result = char_item - *(pcond + 1); /*���ַ����бȽ�*/
	op = *pcond;                           /*��ȡƥ�������*/

	switch (op)
	{
	case '=':
		if (compare_result == 0)
		{
			bRet = TRUE;
		}
		else
		{
			bRet = FALSE;
		}
		break;
	case '<':
		if (compare_result<0)
		{
			bRet = TRUE;
		}
		else
		{
			bRet = FALSE;
		}
		break;
	case '>':
		if (compare_result>0)
		{
			bRet = TRUE;
		}
		else
		{
			bRet = FALSE;
		}
		break;
	case '!':
		if (compare_result != 0)
		{
			bRet = TRUE;
		}
		else
		{
			bRet = FALSE;
		}
		break;
	}
	return bRet;
}

/**
* ��������: StatUnchargeInfo
* ��������: ͳ��δ�ɷ���Ϣ.
* �������: hd ����ͷ���ָ��
* �������: ��
* �� �� ֵ: ����ͳ�ƽ����ͷ����ַ
*
* ����˵��:
*/
UNCHARGE_NODE *StatUnchargeInfo(DORM_NODE *hd)
{
	DORM_NODE *pdorm_node = hd;   /*ͷָ��ָ��ס����Ϣ�Ľ��*/
	STU_NODE *pstu_node;
	CHARGE_NODE *pcharge_node;
	UNCHARGE_NODE *puncharge_node_ret = NULL;
	UNCHARGE_NODE *puncharge_node_temp;
	char enroll_date[8];
	int p1[2];
	char *pctemp;
	int today_year, today_month;
	int enroll_year, enroll_month;
	int months;
	int i;
	float due_amount;
	float paid_amount;
	time_t current_time;
	struct tm *current_tm;
	time(&current_time);                             /*ȡ��ϵͳ��ǰʱ��*/
	current_tm = localtime(&current_time);             /*ȡ��������*/
	today_year = current_tm->tm_year + 1900;
	today_month = current_tm->tm_mon + 1;

	for (pdorm_node = hd; pdorm_node != NULL; pdorm_node = pdorm_node->next)   /*������������*/
	{
		pstu_node = pdorm_node->snext; /*pstu_nodeָ���´����Ľ��*/
		while (pstu_node != NULL)  /*ѭ������ÿһ���ڵ�*/
		{
			pctemp = pstu_node->enroll_date;  /*ȡ��ѧ����Ϣ�������ѧ������Ϣ*/
			strncpy(enroll_date, pctemp, 4);   /*��pctemp�е�4���ַ������Ƶ�enroll_date��*/
			enroll_year = atoi(enroll_date);   /*��enroll_date�е��ַ���ת�������Ͳ�����enroll_year*/
			strncpy(p1, pctemp + 4, 2);         /*��petemp+4�е�2���ַ����Ƶ�p1��*/
			enroll_month = atoi(p1);         /*��p1�е��ַ���ת�������Ͳ�����enroll_month*/

			if ((today_year * 12 + today_month)>(enroll_year * 12 + enroll_month))
			{
				/*��ǰ��������ѧ����֮�����ȼ���ס������*/
				months = 0;
				for (i = enroll_year; i<today_year; i++)
				{
					months += 10;       /*ס��ʱ��ÿ�갴10���¼��㣬2��8�����²���ס��*/
				}
				months += today_month - enroll_month;
				if (today_month>7)
				{
					/*��۳�2��8������*/
					months -= 2;
				}
				else if (today_month>1)
				{
					/*��۳�2�·�һ����ʱ��*/
					months -= 1;
				}
				if (enroll_month>7)
				{
					/*����۳���2��8������*/
					months += 2;
				}
				else if (enroll_month>1)
				{
					/*����۳���2�·�һ����*/
					months += 1;
				}
				due_amount = months*pdorm_node->fee / 10;  /*����Ӧ��ס�޷�*/
				paid_amount = 0.0;
				pcharge_node = pstu_node->cnext;
				while (pcharge_node != NULL)               /*�ۼ��ѽ�ס�޷�*/
				{
					paid_amount += pcharge_node->sum;
					pcharge_node = pcharge_node->next;
				}
				if (due_amount>paid_amount)    /*Ӧ�ɶ�ȴ����ѽɶ�ȣ�����Ƿ��*/
				{
					/*��Ƿ����Ϣ�����½�㣬�����½�����ͳ�ƽ����*/
					puncharge_node_temp = (UNCHARGE_NODE *)malloc(sizeof(UNCHARGE_NODE));
					strcpy(puncharge_node_temp->stu_id, pstu_node->stu_id);
					strcpy(puncharge_node_temp->name, pstu_node->name);
					strcpy(puncharge_node_temp->dorm_id, pstu_node->dorm_id);
					strcpy(puncharge_node_temp->room_num, pstu_node->room);
					puncharge_node_temp->amount = due_amount - paid_amount;
					puncharge_node_temp->next = puncharge_node_ret;
					puncharge_node_ret = puncharge_node_temp;
				}
			}
			pstu_node = pstu_node->next;
		}
	}
	SortUnchargeInfo(puncharge_node_ret);   /*��ͳ�ƽ������������*/
	return puncharge_node_ret;
}

/**
* ��������: SortUnchargeInfo
* ��������: ��Ƿ����Ϣ����������.
* �������: uncharge_hd Ƿ����Ϣ��ͷ���ָ��
* �������: uncharge_hd ������ͬʱͨ��ͷ���ָ�뷵��
* �� �� ֵ: ��
*
* ����˵��:
*/
void SortUnchargeInfo(UNCHARGE_NODE *uncharge_hd)
{
	UNCHARGE_NODE *puncharge_node_prior;
	UNCHARGE_NODE *puncharge_node_after;
	UNCHARGE_NODE *puncharge_node_cur;
	UNCHARGE_NODE *puncharge_node_temp;
	puncharge_node_prior = uncharge_hd;
	if (puncharge_node_prior == NULL)          /*����*/
	{
		return;
	}

	/*����ʱ�����ڽ��������Ϣϵ��ʱ���*/
	puncharge_node_temp = (UNCHARGE_NODE *)malloc(sizeof(UNCHARGE_NODE));
	while (puncharge_node_prior->next != NULL)   /*ѡ������*/
	{
		puncharge_node_cur = puncharge_node_prior;
		puncharge_node_after = puncharge_node_prior->next;
		while (puncharge_node_after != NULL)
		{
			if (puncharge_node_cur->amount<puncharge_node_after->amount)
			{
				puncharge_node_cur = puncharge_node_after;
			}
			puncharge_node_after = puncharge_node_after->next;
		}

		if (puncharge_node_cur != puncharge_node_prior)
		{
			/*������������е���Ϣ��ָ���򲻽���*/
			*puncharge_node_temp = *puncharge_node_prior;
			*puncharge_node_prior = *puncharge_node_cur;
			puncharge_node_prior->next = puncharge_node_temp->next;
			puncharge_node_temp->next = puncharge_node_cur->next;
			*puncharge_node_cur = *puncharge_node_temp;
		}
		puncharge_node_prior = puncharge_node_prior->next;
	}
	free(puncharge_node_temp);
	return;
}

/**
* ��������: SaveSysData
* ��������: ����ϵͳ�����������������.
* �������: hd ����ͷ���ָ��
* �������:
* �� �� ֵ:
*
* ����˵��:
*/
void SaveSysData(DORM_NODE *hd, char *fn[3])
{
	DORM_NODE *pdorm_node = hd;
	STU_NODE *pstu_node;
	CHARGE_NODE *pcharge_node;
	FILE *pfout1, *pfout2, *pfout3;
	if ((pfout1 = fopen(fn[0], "wb")) == NULL)
		exit(-1);
	if ((pfout2 = fopen(fn[1], "wb")) == NULL)
		exit(-1);
	if ((pfout3 = fopen(fn[2], "wb")) == NULL)
		exit(-1);
	while (pdorm_node != NULL)
	{
		fwrite(pdorm_node, sizeof(DORM_NODE), 1, pfout1);
		pstu_node = pdorm_node->snext;
		while (pstu_node != NULL)
		{
			fwrite(pstu_node, sizeof(STU_NODE), 1, pfout2);
			pcharge_node = pstu_node->cnext;
			while (pcharge_node != NULL)
			{
				fwrite(pcharge_node, sizeof(CHARGE_NODE), 1, pfout3);
				pcharge_node = pcharge_node->next;
			}
			pstu_node = pstu_node->next;
		}
		pdorm_node = pdorm_node->next;
	}
	fclose(pfout1);
	fclose(pfout2);
	fclose(pfout3);
	printf("��������ѱ��棡\n");
}


/**
* ��������: BackupSysData
* ��������: ��ϵͳ����������������ݱ��ݵ�һ�������ļ�.
* �������: hd ����ͷ���ָ��
*           filename �����ļ���
* �������:
* �� �� ֵ: BOOL����, ����ΪTRUE
*
* ����˵��:
*/
BOOL BackupSysData(DORM_NODE *hd, char *filename)
{

	return TRUE;
}

/**
* ��������: RestoreSysData
* ��������: ��ָ�������ļ��лָ�ϵͳ�����������������.
* �������: phead ����ͷ���ָ��ĵ�ַ
*           filename ��ű������ݵ������ļ���
* �������:
* �� �� ֵ: BOOL����, ����ΪTRUE
*
* ����˵��:
*/
BOOL RestoreSysData(DORM_NODE **phead, char *filename)
{

	return TRUE;
}

/**
* ��������: ShowModule
* ��������: ��������ģ��
* �������: pString �ַ��������׵�ַ
*           num ��ʾ���ַ���������
* �������:
* �� �� ֵ: int����, �������
*
* ����˵��:
*/
BOOL ShowModule(char **pString, int n)
{
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	CONSOLE_CURSOR_INFO lpCur;
	LABEL_BUNDLE labels;
	HOT_AREA areas;
	BOOL bRet = TRUE;
	SMALL_RECT rcPop;
	COORD pos = { 0,0 }, size;
	WORD att;
	int iHot = 1;
	int iRet;
	int i, maxlen, str_len;

	GetConsoleScreenBufferInfo(gh_std_out, &bInfo);
	size.X = bInfo.dwSize.X;
	size.Y = 1;
	SetConsoleCursorPosition(gh_std_out, pos);

	for (i = 0, maxlen = 0; i<n; i++)  /* ѡ������ַ������� */
	{
		str_len = strlen(pString[i]);
		if (maxlen < str_len)
		{
			maxlen = str_len;
		}
	}

	pos.X = maxlen + 6;
	pos.Y = n + 4;
	rcPop.Left = (SCR_COL - pos.X) / 2;
	rcPop.Right = rcPop.Left + pos.X - 1;
	rcPop.Top = (SCR_ROW - pos.Y) / 2;
	rcPop.Bottom = rcPop.Top + pos.Y - 1;

	att = BACKGROUND_GREEN | BACKGROUND_RED;  /*�Ƶ׺���*/
	labels.num = n;
	labels.ppLabel = pString;
	COORD aLoc[n];

	for (i = 0; i<n; i++)
	{
		aLoc[i].X = rcPop.Left + 3;
		aLoc[i].Y = rcPop.Top + 1 + 2 * i;

	}

	labels.pLoc = aLoc;
	SMALL_RECT aArea[] = { {
			aLoc[0].X - 1, aLoc[0].Y,
			aLoc[0].X + maxlen, aLoc[0].Y
		},
		{
			aLoc[0].X - 1, aLoc[0].Y + 2,
			aLoc[0].X + maxlen, aLoc[0].Y + 2
		},
		{
			aLoc[0].X - 1, aLoc[0].Y + 4,
			aLoc[0].X + maxlen, aLoc[0].Y + 4
		}
	};
	char aSort[n];
	char aTag[n];

	for (i = 0; i<n; i++)
	{
		aSort[i] = 0;
		aTag[i] = i + 1;
	}

	areas.num = n;
	areas.pArea = aArea;
	areas.pSort = aSort;
	areas.pTag = aTag;
	PopUp(&rcPop, att, &labels, &areas);

	iRet = DealInput(&areas, &iHot);
	PopOff();

	return iRet;
}

