#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef unsigned char Byte;
typedef unsigned long int Word;

typedef struct
{
	Word data[16];
} Group;

//
#define FF0(x,y,z) ( (x) ^ (y) ^ (z)) 
#define FF1(x,y,z) (((x) & (y)) | ( (x) & (z)) | ( (y) & (z)))
#define GG0(x,y,z) ( (x) ^ (y) ^ (z)) 
#define GG1(x,y,z) (((x) & (y)) | ( (~(x)) & (z)) )
//#define P0(X) ((X)^((X)<<9)^((X)<<17))
//#define P1(X) ((X)^((X)<<15)^((X)<<23))
#define  SHL(x,n) (((x) & 0xFFFFFFFF) << n)
#define ROTL(x,n) (SHL((x),n) | ((x) >> (32 - n)))
#define P0(x) ((x) ^  ROTL((x),9) ^ ROTL((x),17)) 
#define P1(x) ((x) ^  ROTL((x),15) ^ ROTL((x),23)) 
#define Byte2Word(a,b,i)  (a) = (b[(i)]<<24)|(b[(i)+1]<<16)|(b[(i)+2]<<8)|(b[(i)+3]);
#define Word2Byte(a,b,i)  b[(i)]=(Byte)((a)>>24);b[(i)+1]=(Byte)((a)>>16);b[(i)+2]=(Byte)((a)>>8);b[(i)+3]=(Byte)((a));
#define MAX 127
#define Debug 



//SM3ģ�� 
static const Byte sm3_padding[64] =
{
	0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};
int SM3(Byte *Message, Word *V, int end, long long int sum)
{
	long long int k, l;
	int i;
	Group Bn;
	//Byte Message[64] ="abc\0";
	if (end == 2) {
#ifdef Debug
		printf("strlen(Message)=%d\n", strlen(Message));
#endif 

		//l = 8*strlen(Message); 
		//long int n=l/512+1;
		//long int d=l%512;
		//k =d>447?((512-1-d)+448),n++:(448-1-d);
		memcpy((void*)(Message + strlen(Message)), sm3_padding, 64 - strlen(Message));

#ifdef Debug
		//printf("n = %d\n",n);
		// printf("k = %d\n",k);
		//printf("d = %d\n",d);
#endif
		for (i = 0; i<14; i++)
			Byte2Word(Bn.data[i], Message, 4 * i);


		Bn.data[14] = (Word)(sum >> 32);
		Bn.data[15] = (Word)(sum);
	}
	else if (end == 1) {
		memcpy((void*)(Message + strlen(Message)), sm3_padding, 64 - strlen(Message));
	}
	else {
		for (i = 0; i<16; i++)
			Byte2Word(Bn.data[i], Message, 4 * i);
	}
#ifdef Debug
	printf("�������Ϣ\n");
	for (i = 0; i<16; i++) {
		printf("%08X ", Bn.data[i]);
		if (i % 8 == 7)
			printf("\n");
	}
#endif   
	Word W1[68];
	Word W2[64];
	for (i = 0; i<16; i++)
		W1[i] = Bn.data[i];
	for (i = 16; i<68; i++)
		W1[i] = P1(W1[i - 16] ^ W1[i - 9] ^ (ROTL(W1[i - 3], 15))) ^ (ROTL(W1[i - 13], 7)) ^ W1[i - 6];
	for (i = 0; i<64; i++)
		W2[i] = W1[i] ^ W1[i + 4];

#ifdef Debug
	printf("��չ�����Ϣ\n");
	printf("W1\n");
	for (i = 0; i<68; i++) {
		printf("%08X ", W1[i]);
		if (i % 8 == 7)
			printf("\n");
	}
	printf("\n");
	printf("W2\n");
	for (i = 0; i<64; i++) {
		printf("%08X ", W2[i]);
		if (i % 8 == 7)
			printf("\n");
	}
#endif    

	Word A, B, C, D, E, F, G, H, SS1, SS2, TT1, TT2;
	//Word V[8];
	A = V[0];
	B = V[1];
	C = V[2];
	D = V[3];
	E = V[4];
	F = V[5];
	G = V[6];
	H = V[7];
#ifdef Debug 
	printf("j     A       B        C         D         E        F        G       H\n");
#endif  
	Word T1 = 0x79cc4519;
	Word T2 = 0x7a879d8a;
	for (i = 0; i < 16; i++) {
		SS1 = ROTL((Word)(ROTL(A, 12) + E + ROTL(T1, i)), 7);
		SS2 = SS1 ^ (ROTL(A, 12));
		TT1 = (Word)(FF0(A, B, C) + D + SS2 + W2[i]);
		TT2 = (Word)(GG0(E, F, G) + H + SS1 + W1[i]);
		D = C;
		C = ROTL(B, 9);
		B = A;
		A = TT1;
		H = G;
		G = ROTL(F, 19);
		F = E;
		E = P0(TT2);
#ifdef Debug       
		printf("   %08x %08x %08x %08x %08x %08x %08x %08x\n", A, B, C, D, E, F, G, H);
#endif

	}


	for (i = 16; i < 64; i++) {
		SS1 = ROTL((Word)(ROTL(A, 12) + E + ROTL(T2, i)), 7);
		SS2 = SS1 ^ (ROTL(A, 12));
		TT1 = FF1(A, B, C) + D + SS2 + W2[i];
		TT2 = GG1(E, F, G) + H + SS1 + W1[i];
		D = C;
		C = ROTL(B, 9);
		B = A;
		A = TT1;
		H = G;
		G = ROTL(F, 19);
		F = E;
		E = P0(TT2);
#ifdef Debug       
		printf("   %08x %08x %08x %08x %08x %08x %08x %08x\n", A, B, C, D, E, F, G, H);
#endif
	}

	V[0] ^= A, V[1] ^= B, V[2] ^= C, V[3] ^= D, V[4] ^= E, V[5] ^= F, V[6] ^= G, V[7] ^= H;
#ifdef Debug
	printf("256λ�Ӵ�ֵ\n");
	printf("   %08x %08x %08x %08x %08x %08x %08x %08x\n", V[0], V[1], V[2], V[3], V[4], V[5], V[6], V[7]);
#endif

	return V;
}

//SM3ģ�� 




//DESģ��

int IP[64] = {         //��ʼ��λ��
	58, 50, 42, 34, 26, 18, 10, 2,
	60, 52, 44, 36, 28, 20, 12, 4,
	62, 54, 46, 38, 30, 22, 14, 6,
	64, 56, 48, 40, 32, 24, 16, 8,
	57, 49, 41, 33, 25, 17, 9, 1,
	59, 51, 43, 35, 27, 19, 11, 3,
	61, 53, 45, 37, 29, 21, 13, 5,
	63, 55, 47, 39, 31, 23, 15, 7
};

int E[48] = {            //��չ��λ��
	32, 1, 2, 3, 4, 5,
	4, 5, 6, 7, 8, 9,
	8, 9, 10, 11, 12, 13,
	12, 13, 14, 15, 16, 17,
	16, 17, 18, 19, 20, 21,
	20, 21, 22, 23, 24, 25,
	24, 25, 26, 27, 28, 29,
	28, 29, 30, 31, 32, 1 };

int PC1[56] = {          //PC1��λ��64��>56��
	57, 49, 41, 33, 25, 17, 9,
	1, 58, 50, 42, 34, 26, 18,
	10, 2, 59, 51, 43, 35, 27,
	19, 11, 3, 60, 52, 44, 36,
	63, 55, 47, 39, 31, 23, 15,
	7, 62, 54, 46, 38, 30, 22,
	14, 6, 61, 53, 45, 37, 29,
	21, 13, 5, 28, 20, 12, 4 };

int move[16] = {			//ѭ����λ��
	1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1 };

int PC2[48] = {  		   //PC2��λ��56��>48��
	14, 17, 11, 24, 1, 5,
	3, 28, 15, 6, 21, 10,
	23, 19, 12, 4, 26, 8,
	16, 7, 27, 20, 13, 2,
	41, 52, 31, 37, 47, 55,
	30, 40, 51, 45, 33, 48,
	44, 49, 39, 56, 34, 53,
	46, 42, 50, 36, 29, 32 };

int S1[4][16] = {      //S��λ��
	14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7,
	0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
	4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0,
	15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13
};
int S2[4][16] = {
	15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10,
	3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
	0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15,
	13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9
};
int S3[4][16] = {
	10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8,
	13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
	13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7,
	1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12
};
int S4[4][16] = {
	7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
	13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
	10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4,
	3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14
};
int S5[4][16] = {
	2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,
	14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6,
	4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,
	11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3
};
int S6[4][16] = {
	12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11,
	10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8,
	9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6,
	4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13
};
int S7[4][16] = {
	4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,
	13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,
	1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2,
	6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12
};
int S8[4][16] = {
	13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7,
	1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2,
	7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8,
	2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11
};
int P[32] = {                    //P��λ��
	16,7,20,21,29,12,28,17,1,15,23,26,5,18,31,10,
	2,8,24,14,32,27,3,9,19,13,30,6,22,11,4,25
};

int DES_encrypto(Byte *Message, Byte *InputKey, Byte*Secret)
{


	int key[64];
	int text[64];
	int text_ip[64];
	int text_out[64];
	int text_end[64];
	int K[16][48];              //���16��ѭ�����Ʋ���������Կ
	int RK[48];                 //���RE��K��������Ľ��
	int RKS[8];                 //��ž�������8��S���õ���8��ʮ���ƽ��
	int keyPC1[64];
	int keyCD[56];
	int i;
	int j;
	int m, n;
	int t;
	int C0[28];
	int D0[28];
	int L0[32];
	int R0[32];
	int Hide[16];
	int RE0[48];
	int r[8], c[8];
	int SP[32];
	int RKSP[32];
	int Ri[32], Li[32];
	int result[64];
	for (i = 0; i<8; i++) {          //����Կת����64λ���������ŵ�һά����key��
		int a[8] = { 0,0,0,0,0,0,0,0 };
		m = InputKey[i];
		for (j = 0; m != 0; j++) {
			a[j] = m % 2;
			m = m / 2;
		}

		for (j = 0; j<8; j++)
			key[(i * 8) + j] = a[7 - j];
	}

	for (i = 0; i<56; i++)      //ͨ��PC1��λ����56λ��Կ����keyPC1��
		keyPC1[i] = key[PC1[i] - 1];

	for (i = 0; i<28; i++) {      //�ֳ�C0��D0�����֣���28λ
		C0[i] = keyPC1[i];
		D0[i] = keyPC1[i + 28];
	}

	for (t = 0; t<16; t++) {
		if (move[t] == 1)       //����ѭ����λ��Ai��Bi�ֱ�����move[t]λ
		{
			n = C0[0];
			for (i = 0; i<27; i++)
				C0[i] = C0[i + 1];
			C0[27] = n;
			n = D0[0];
			for (i = 0; i<28; i++)
				D0[i] = D0[i + 1];
			D0[27] = n;
		}
		else
		{
			n = C0[0];
			m = C0[1];
			for (i = 0; i<26; i++)
				C0[i] = C0[i + 2];
			C0[26] = n;
			C0[27] = m;
			n = D0[0];
			m = D0[1];
			for (i = 0; i<26; i++)
				D0[i] = D0[i + 2];
			D0[26] = n;
			D0[27] = m;
		}

		for (i = 0; i<28; i++)    //��A��B�ϲ���56λ
		{
			keyCD[i] = C0[i];
			keyCD[i + 28] = D0[i];
		}

		for (i = 0; i<48; i++)    //ͨ��PC2��λ����48λ��Կ
			K[t][i] = keyCD[PC2[i] - 1];
	}
#ifdef debug
	printf("*                       ���ɵ�16������Կ�ֱ�Ϊ��                       *\n*");
	for (t = 0; t<16; t++)
	{
		printf("\t");
		for (i = 0; i<48; i++)
		{
			printf("%d", K[t][i]);
		}
		printf("\n*");
	}
#endif


	for (i = 0; i<8; i++) {           //���õ�������ת���ɶ����������浽����text��
		int a[8] = { 0,0,0,0,0,0,0,0 };
		m = Message[i];
		for (j = 0; m != 0; j++) {
			a[j] = m % 2;
			m = m / 2;
		}
		for (j = 0; j<8; j++)
			text[(i * 8) + j] = a[7 - j];
	}


	for (i = 0; i<64; i++)          //���г�ʼ��λ
		text_ip[i] = text[IP[i] - 1];

	for (i = 0; i<32; i++) {         //�ֳ����������֣���32λ
		L0[i] = text_ip[i];
		R0[i] = text_ip[i + 32];
	}

	for (t = 0; t<16; t++) {
		for (i = 0; i<48; i++)        //���Ұ벿��ͨ����չ��λ��E��32λ��չ��48λ
			RE0[i] = R0[E[i] - 1];


		for (i = 0; i<48; i++)      //RE��K�������
			RK[i] = RE0[i] ^ K[t][i];


		for (i = 0; i<8; i++) {        //��R��K�������Ľ��ͨ��Sλ�Ʊ�									
			r[i] = RK[(i * 6) + 0] * 2 + RK[(i * 6) + 5];
			c[i] = RK[(i * 6) + 1] * 8 + RK[(i * 6) + 2] * 4 + RK[(i * 6) + 3] * 2 + RK[(i * 6) + 4];
		}

		RKS[0] = S1[r[0]][c[0]];
		RKS[1] = S2[r[1]][c[1]];
		RKS[2] = S3[r[2]][c[2]];
		RKS[3] = S4[r[3]][c[3]];
		RKS[4] = S5[r[4]][c[4]];
		RKS[5] = S6[r[5]][c[5]];
		RKS[6] = S7[r[6]][c[6]];
		RKS[7] = S8[r[7]][c[7]];

		for (i = 0; i<8; i++)        //�ѽ��ת��32λ�����ƴ���������SP��
		{
			int b[4] = { 0,0,0,0 };
			m = RKS[i];
			for (j = 3; m != 0; j--)
			{
				b[j] = m % 2;
				m = m / 2;
			}
			for (j = 0; j<4; j++)
				SP[j + (i * 4)] = b[j];
		}

		for (i = 0; i<32; i++)        //�������ƽ���پ���һ��P�л�λ
			RKSP[i] = SP[P[i] - 1];

		for (i = 0; i<32; i++)        //��ǰһ�ε���������㣬�õ����ε������Ҳ�
			Ri[i] = L0[i] ^ RKSP[i];

		for (i = 0; i<32; i++)
		{
			L0[i] = R0[i];
			R0[i] = Ri[i];
		}
	}

	//����32λ����								
	for (i = 0; i<32; i++)
		Li[i] = R0[i];
	for (i = 0; i<32; i++)
		R0[i] = L0[i];
	for (i = 0; i<32; i++)
		L0[i] = Li[i];

	//��ʼ��λ�������								
	for (i = 0; i<32; i++)         //�����������ֺ������浽text_end��
		text_end[i] = L0[i];
	for (i = 32; i<64; i++)
		text_end[i] = R0[i - 32];

	for (i = 0; i<64; i++)          //���г�ʼ��λ�������
		result[IP[i] - 1] = text_end[i];

	for (i = 0; i<8; i++)
		Secret[i] = (Byte)(result[(i * 8) + 0] * 128 + result[(i * 8) + 1] * 64 + result[(i * 8) + 2] * 32 + result[(i * 8) + 3] * 16 + result[(i * 8) + 4] * 8 + result[(i * 8) + 5] * 4 + result[(i * 8) + 6] * 2 + result[(i * 8) + 7]);


	//Secret[17]='\0';
#ifdef debug
	printf("*\t�����ļ�����DES���ܺ�������ǣ�");
	printf("%s\n", Secret);
	printf("\n\n");
#endif



	return 0;
}
// DESģ�� 




//DES���� 
int DES_decrypto(Byte *Message, Byte *InputKey, Byte*Secret)
{


	int key[64];
	int text[64];
	int text_ip[64];
	int text_out[64];
	int text_end[64];
	int K[16][48];              //���16��ѭ�����Ʋ���������Կ
	int RK[48];                 //���RE��K��������Ľ��
	int RKS[8];                 //��ž�������8��S���õ���8��ʮ���ƽ��
	int keyPC1[64];
	int keyCD[56];
	int i;
	int j;
	int m, n;
	int t;
	int C0[28];
	int D0[28];
	int L0[32];
	int R0[32];
	int Hide[16];
	int RE0[48];
	int r[8], c[8];
	int SP[32];
	int RKSP[32];
	int Ri[32], Li[32];
	int result[64];

	for (i = 0; i<8; i++) {          //����Կת����64λ���������ŵ�һά����key��
		int a[8] = { 0,0,0,0,0,0,0,0 };
		m = InputKey[i];
		for (j = 0; m != 0; j++) {
			a[j] = m % 2;
			m = m / 2;
		}

		for (j = 0; j<8; j++)
			key[(i * 8) + j] = a[7 - j];
	}

	for (i = 0; i<56; i++)      //ͨ��PC1��λ����56λ��Կ����keyPC1��
		keyPC1[i] = key[PC1[i] - 1];

	for (i = 0; i<28; i++) {      //�ֳ�C0��D0�����֣���28λ
		C0[i] = keyPC1[i];
		D0[i] = keyPC1[i + 28];
	}

	for (t = 0; t<16; t++) {
		if (move[t] == 1)       //����ѭ����λ��Ai��Bi�ֱ�����move[t]λ
		{
			n = C0[0];
			for (i = 0; i<27; i++)
				C0[i] = C0[i + 1];
			C0[27] = n;
			n = D0[0];
			for (i = 0; i<28; i++)
				D0[i] = D0[i + 1];
			D0[27] = n;
		}
		else
		{
			n = C0[0];
			m = C0[1];
			for (i = 0; i<26; i++)
				C0[i] = C0[i + 2];
			C0[26] = n;
			C0[27] = m;
			n = D0[0];
			m = D0[1];
			for (i = 0; i<26; i++)
				D0[i] = D0[i + 2];
			D0[26] = n;
			D0[27] = m;
		}

		for (i = 0; i<28; i++)    //��A��B�ϲ���56λ
		{
			keyCD[i] = C0[i];
			keyCD[i + 28] = D0[i];
		}

		for (i = 0; i<48; i++)    //ͨ��PC2��λ����48λ��Կ
			K[t][i] = keyCD[PC2[i] - 1];
	}
#ifdef debug
	printf("*                       ���ɵ�16������Կ�ֱ�Ϊ��                       *\n*");
	for (t = 0; t<16; t++)
	{
		printf("\t");
		for (i = 0; i<48; i++)
		{
			printf("%d", K[t][i]);
		}
		printf("\n*");
	}
#endif


	for (i = 0; i<8; i++) {           //���õ�������ת���ɶ����������浽����text��
		int a[8] = { 0,0,0,0,0,0,0,0 };
		m = Secret[i];
		for (j = 0; m != 0; j++) {
			a[j] = m % 2;
			m = m / 2;
		}
		for (j = 0; j<8; j++)
			text[(i * 8) + j] = a[7 - j];
	}


	for (i = 0; i<64; i++)          //���г�ʼ��λ
		text_ip[i] = text[IP[i] - 1];

	for (i = 0; i<32; i++) {         //�ֳ����������֣���32λ
		L0[i] = text_ip[i];
		R0[i] = text_ip[i + 32];
	}
	for (t = 0; t<16; t++) {
		for (i = 0; i<48; i++)        //���Ұ벿��ͨ����չ��λ��E��32λ��չ��48λ
			RE0[i] = R0[E[i] - 1];


		for (i = 0; i<48; i++)      //RE��K�������
			RK[i] = RE0[i] ^ K[15 - t][i];


		for (i = 0; i<8; i++) {        //��R��K�������Ľ��ͨ��Sλ�Ʊ�									
			r[i] = RK[(i * 6) + 0] * 2 + RK[(i * 6) + 5];
			c[i] = RK[(i * 6) + 1] * 8 + RK[(i * 6) + 2] * 4 + RK[(i * 6) + 3] * 2 + RK[(i * 6) + 4];
		}

		RKS[0] = S1[r[0]][c[0]];
		RKS[1] = S2[r[1]][c[1]];
		RKS[2] = S3[r[2]][c[2]];
		RKS[3] = S4[r[3]][c[3]];
		RKS[4] = S5[r[4]][c[4]];
		RKS[5] = S6[r[5]][c[5]];
		RKS[6] = S7[r[6]][c[6]];
		RKS[7] = S8[r[7]][c[7]];

		for (i = 0; i<8; i++)        //�ѽ��ת��32λ�����ƴ���������SP��
		{
			int b[4] = { 0,0,0,0 };
			m = RKS[i];
			for (j = 3; m != 0; j--)
			{
				b[j] = m % 2;
				m = m / 2;
			}
			for (j = 0; j<4; j++)
				SP[j + (i * 4)] = b[j];
		}

		for (i = 0; i<32; i++)        //�������ƽ���پ���һ��P�л�λ
			RKSP[i] = SP[P[i] - 1];

		for (i = 0; i<32; i++)        //��ǰһ�ε���������㣬�õ����ε������Ҳ�
			Ri[i] = L0[i] ^ RKSP[i];

		for (i = 0; i<32; i++)
		{
			L0[i] = R0[i];
			R0[i] = Ri[i];
		}
	}

	//����32λ����								
	for (i = 0; i<32; i++)
		Li[i] = R0[i];
	for (i = 0; i<32; i++)
		R0[i] = L0[i];
	for (i = 0; i<32; i++)
		L0[i] = Li[i];

	//��ʼ��λ�������								
	for (i = 0; i<32; i++)         //�����������ֺ������浽text_end��
		text_end[i] = L0[i];
	for (i = 32; i<64; i++)
		text_end[i] = R0[i - 32];

	for (i = 0; i<64; i++)          //���г�ʼ��λ�������
		result[IP[i] - 1] = text_end[i];

	for (i = 0; i<8; i++)
		Message[i] = (Byte)(result[(i * 8) + 0] * 128 + result[(i * 8) + 1] * 64 + result[(i * 8) + 2] * 32 + result[(i * 8) + 3] * 16 + result[(i * 8) + 4] * 8 + result[(i * 8) + 5] * 4 + result[(i * 8) + 6] * 2 + result[(i * 8) + 7]);

	//Secret[17]='\0';
#ifdef debug
	//Secret[17]='\0';
	printf("*\t�����ļ�����DES���ܺ�������ǣ�");
	printf("%s\n", Secret);
	printf("\n\n");
#endif				




	return 0;
}


int controlFunction() {//����ѡ��
	int k = 0, j = 0;
	printf("********************************************************************************\n");
	printf("*                           �๦�����빤��                                     *\n");
	printf("********************************************************************************\n");
	printf("\n\n");
	printf("ѡ����Ҫʹ�õĹ��ܣ�\n");
	printf("\t1 .DES����\t\t2 .DES����\n");
	printf("\t3 .SM3����\t\t4 .�ļ�������У��\n");
	printf("\t5 .�˳�ϵͳ\n");
SELECT:

	printf("������ѡ��");
	fflush(stdin);
	j = scanf("%d", &k);
	if (j == 0 || k<1 || k>11) {
		printf("\n��������,���������룡");
		goto SELECT;
	}

	return k;

}

int reselect() {//��������ѡ��
	printf("\n��ѡ��������ܣ�1.��������2.�˳�ϵͳ\n");
	int as;
Y:
	fflush(stdin);
	scanf("%d", &as);
	if (as == 1) {
		system("CLS");
		return 1;
	}
	else
		if (as == 2)	exit(1);
		else {
			printf("\n����������������룺");
			goto Y;
		}
		return 0;
}

int main()
{
	system("color 3f");
	do {
		int x = controlFunction();
		if (x == 1) {
			fflush(stdin);
			Byte *Message;
			Byte *InputKey;
			Byte *Secret;
			Message = (Byte*)malloc(sizeof(Byte) * 8);
			Secret = (Byte*)malloc(sizeof(Byte) * 8);
			InputKey = (Byte*)malloc(sizeof(Byte) * 8);
			memset(Message, 0, sizeof(Byte) * 8);

			printf("������8�ֽ���Կ");
			gets(InputKey);
			while (InputKey[7] == '\0' || InputKey[8] != '\0') {
				printf("���������Կλ����������������8�ֽ���Կ��\n");
				gets(InputKey);
			}
			printf("������Կ�ɹ�\n");
			FILE *fp1;
			FILE *fp2;
			char path[MAX + 1], ch;
			printf("��������ܵ��ļ���: ");
			gets(path);
			if ((fp1 = fopen(path, "rt")) == NULL) {
				printf("�޷�Ŀ���ļ���Ŀ���ļ�������\n");
				goto END;
			}

			printf("����洢���ĵ��ļ���: ");
			fflush(stdin);
			gets(path);
			if ((fp2 = fopen(path, "a+")) == NULL) {
				printf("�޷�Ŀ���ļ���Ŀ���ļ�������\n");
				goto END;
			}
			while (fread(Message, 1, 8, fp1) != 0) {
				DES_encrypto(Message, InputKey, Secret);
				fwrite(Secret, 1, 8, fp2);
			}
			printf("�������ܳɹ�����");
			fclose(fp1);
			fclose(fp2);
		}
		else if (x == 2) {
			fflush(stdin);
			Byte *Message;
			Byte *InputKey;
			Byte *Secret;
			Message = (Byte*)malloc(sizeof(Byte) * 8);
			Secret = (Byte*)malloc(sizeof(Byte) * 8);
			InputKey = (Byte*)malloc(sizeof(Byte) * 8);
			memset(Message, 0, sizeof(Byte) * 8);

			printf("������8�ֽ���Կ");
			gets(InputKey);
			while (InputKey[7] == '\0' || InputKey[8] != '\0') {
				printf("���������Կλ����������������8�ֽ���Կ��\n");
				gets(InputKey);
			}
			printf("������Կ�ɹ�\n");
			FILE *fp1;
			FILE *fp2;
			char path[MAX + 1], ch;
			printf("��������ܵ��ļ���: ");
			gets(path);
			if ((fp1 = fopen(path, "rt")) == NULL) {
				printf("�޷�Ŀ���ļ���Ŀ���ļ�������\n");
				goto END;
			}

			printf("����洢���ĵ��ļ���: ");
			fflush(stdin);
			gets(path);
			if ((fp2 = fopen(path, "a+")) == NULL) {
				printf("�޷���Ŀ���ļ���Ŀ���ļ�������\n");
				goto END;
			}
			while (fread(Secret, 1, 8, fp1) != 0) {
				DES_decrypto(Message, InputKey, Secret);
				fwrite(Message, 1, 8, fp2);
			}
			printf("�������ܡ���");
			fclose(fp1);
			fclose(fp2);
		}
		else if (x == 3) {
			fflush(stdin);
			Word V[8];
			V[0] = 0x7380166f;
			V[1] = 0x4914b2b9;
			V[2] = 0x172442d7;
			V[3] = 0xda8a0600;
			V[4] = 0xa96f30bc;
			V[5] = 0x163138aa;
			V[6] = 0xe38dee4d;
			V[7] = 0xb0fb0e4e;
			int end;
			int count;
			long long int sum = 0;

			Byte *Message;
			Message = (Byte*)malloc(sizeof(Byte) * 64);
			memset(Message, 0, 8 * sizeof(Byte));
			FILE *fp;
			char path[MAX + 1], ch;
			printf("��������ܵ��ļ���: ");
			gets(path);
			if ((fp = fopen(path, "rt")) == NULL) {
				printf("�޷�Ŀ���ļ���Ŀ���ļ�������\n");
				goto END;
			}
			printf("����洢���ĵ��ļ���: ");
			fflush(stdin);
			if ((fp = fopen(path, "rt")) == NULL) {
				printf("�޷�Ŀ���ļ���Ŀ���ļ�������\n");
				goto END;
			}

			while ((count = fread(Message, 1, 64, fp)) == 64) {
#ifdef debug
				printf("\n%c%c%c", Message[0], Message[1], Message[2]);
#endif
				end = 0;
				sum += 8 * sizeof(Byte)*count;
				SM3(Message, V, end, sum);
				memset(Message, 0, 8 * sizeof(Byte));
			}
			fclose(fp);
			if (count >= 0 && count<56) {
				end = 2;
				sum += 8 * sizeof(Byte)*count;
#ifdef debug
				printf("\n%c%c%c", Message[0], Message[1], Message[2]);
#endif
				SM3(Message, V, end, sum);
			}
			else if (count>56) {
#ifdef debug
				printf("\n%c%c%c%c", Message[0], Message[1], Message[2], Message[3]);
#endif
				sum += 8 * sizeof(Byte)*count;
				end = 1;
				SM3(Message, V, end, sum);
				end = 2;
				Message[0] = '\0';
				SM3(Message, V, end, sum);
			}
			else;
#ifdef debug	
			printf("\n%08x %08x %08x %08x %08x", Message[0], Message[1], Message[2], Message[3], Message[4]);
			printf("\n%d\n", strlen(Message));
			printf("\n%d\n", count);
#endif 
			printf("\n�������ܳɹ�������\n\n");
			printf("256λSM3�Ӵ�ֵ\n");
			printf("   %08x %08x %08x %08x %08x %08x %08x %08x\n", V[0], V[1], V[2], V[3], V[4], V[5], V[6], V[7]);
			printf("\n�Ƿ�Ҫ���ر����ϣֵ��Ϊ������У����\n\t1 .��\t\t2 .��\n");
			int t;
			scanf("%d", &t);
			if (t == 1) {
				printf("����洢HASHֵ���ļ���: ");
				char path3[MAX + 1];
				fflush(stdin);
				gets(path3);

				if ((fp = fopen(path3, "w+")) == NULL) {
					printf("�޷�д���ļ�\n");
					goto END;
				}
				if ((count = fwrite(V, 4, 8, fp)) == 8)
					printf("SM3��ϣֵ��д��Ŀ���ļ�\n");
				fclose(fp);
			}
		}
		else if (x == 4) {
			fflush(stdin);
			Word V[8];
			V[0] = 0x7380166f;
			V[1] = 0x4914b2b9;
			V[2] = 0x172442d7;
			V[3] = 0xda8a0600;
			V[4] = 0xa96f30bc;
			V[5] = 0x163138aa;
			V[6] = 0xe38dee4d;
			V[7] = 0xb0fb0e4e;
			int end;
			int count;
			long long int sum = 0;

			Byte *Message;
			Message = (Byte*)malloc(sizeof(Byte) * 64);
			memset(Message, 0, sizeof(Message));
			FILE *fp;
			char path[MAX + 1], ch;
			printf("�������֤���ļ���: ");
			gets(path);
			if ((fp = fopen(path, "rt")) == NULL) {
				printf("�޷�Ŀ���ļ���Ŀ���ļ�������\n");
				goto END;
			}

			while (((count = fread(Message, 1, sizeof(Message), fp))) == 64) {
#ifdef debug
				printf("\n%c%c%c", Message[0], Message[1], Message[2]);
#endif
				end = 0;
				sum += sizeof(Byte)*count;
				SM3(Message, V, end, sum);
			}
			if (count>0 && count<56) {
				end = 2;
				sum += 8 * sizeof(Byte)*count;
#ifdef debug
				printf("\n%c%c%c", Message[0], Message[1], Message[2]);
#endif
				SM3(Message, V, end, sum);
			}
			else if (count>56) {
#ifdef debug
				printf("\n%c%c%c%c", Message[0], Message[1], Message[2], Message[3]);
#endif
				sum += 8 * sizeof(Byte)*count;
				end = 1;
				SM3(Message, V, end, sum);
				end = 2;
				Message[0] = '\0';
				SM3(Message, V, end, sum);
			}
			else;
#ifdef debug	
			printf("\n%08x %08x %08x %08x %08x", Message[0], Message[1], Message[2], Message[3], Message[4]);
			printf("\n%d\n", strlen(Message));
			printf("\n%d\n", count);
#endif 
			printf("\��ô���֤�ļ���HASHֵ\n\n");
			printf("256λSM3�Ӵ�ֵ\n");
			printf("   %08x %08x %08x %08x %08x %08x %08x %08x\n", V[0], V[1], V[2], V[3], V[4], V[5], V[6], V[7]);

			printf("���뱣���ļ���ȷУ������ļ���: ");
			char path2[MAX + 1];
			gets(path2);
			if ((fp = fopen(path2, "rt")) == NULL) {
				printf("�޷�Ŀ���ļ���Ŀ���ļ�������\n");
				goto END;
			}
			Word R[8];
			if ((count = fread(R, 4, 8, fp)) == 8);
			printf("�ɹ���ȡ����У����\n");

			int i;
			printf("   %08x %08x %08x %08x %08x %08x %08x %08x\n", R[0], R[1], R[2], R[3], R[4], R[5], R[6], R[7]);

			for (i = 0; i<8; i++) {
				if (V[i] != R[i]) {
					printf("�ļ�������У��������ƥ�䣡�ļ���������");
					goto END;
				}
			}
			printf("�ļ�������У������ƥ�䣡�ļ�������");
			goto END;
		}
		else if (x = 5) return 0;

	END:
		;

	} while (reselect());

}
