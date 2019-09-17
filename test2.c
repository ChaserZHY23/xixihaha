#define _CRT_SE-CURE_NO-WARNINGS 1
#include<stdio.h>
int main(){
	int a=5;
	int b=10;
	int c=0;
	scanf("%d%d", &a, &b);
	printf("a=%d b=%d\n", a, b);
	c = a;
	a = b;
	b = c;
	printf("a=%d b=%d\n", a, b);
	return 0;
}