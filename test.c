#define _CRT_SECURE_NO_WARNINGS 1
/*int main()
{
	int a[5] = { 0, 1, 2, 3, 4 };
	int b[5] = { 4, 3, 2, 1, 0 };
	int i=0 ; int j=0;
	for (i = 0; i <5; i++)
	{
		j = a[i];
		a[i] = b[i];
		b[i] = j;
	}
	for (i = 0; i <5; i++)
	{
		printf("%d", a[i]);
	}
	printf("\n");
	for (i = 0; i < 5; i++)
	{
		printf("%d", b[i]);
	}
	printf("\n");
		return 0;	
}
int main()
{
	double sum1 = 0;
	double sum2 = 0;
	double sum = 0;
	int i = 0;
	for (i = 1; i <= 100; i = i + 2)
	{
		sum1 = sum1 + (1.0/ i);
	}
	for (i = 2; i <= 100; i = i + 2){

		sum2 = sum2 + (1.0/ i);
	}
	sum = sum1 - sum2;
	printf("%f", sum);
	return 0;
}
int main()
{
	int num = 0; int count = 0; int a, b;
	for (num = 1; num <= 100; num++)
	{	 a = num % 10;
		 b = num / 10;
		if (a == 9)
		{
			count++;
		}
		if (b == 9)
		{
			count++;
		}
	}
	printf("count=%d\n", count);
	return 0;
	}
int main()
{
	int num1 = 0;
	int num2, num3, num4;
	int i;
	int a, b, c, d,f, e;
	for (num1 = 100; num1 <= 999; num1++)
	{
		a = num1 / 100;
		b = (num1 / 10) % 10;
		c = num1 % 10;
		i = a*a*a + b*b*b + c*c*c;
		if (num1 == i)
		{
			printf("%d是水仙花数\n", num1);
		}
	}
	for (num2 = 1000; num2 <= 9999; num2++)
	{
		a = num2 / 1000;
		b = (num2 / 100) % 10;
		c = (num2 / 10) % 10;
		d = num2 % 10;
		i = a*a*a*a + b*b*b*b + c*c*c*c + d*d*d*d;
		if (i == num2)
		{
			printf("%d是水仙花数\n", num2);
		}

	}
	for (num3 = 10000; num3 <= 99999; num3++)
	{
		a = num3 / 10000;
		b = (num3 / 1000) % 10;
		c = (num3 / 100) % 10;
		d = (num3 / 10) % 10;
		e = num3 % 10;
		i = a*a*a*a*a + b*b*b*b*b + c*c*c*c*c + d*d*d*d*d + e*e*e*e*e;
		if (i == num3)
		{
			printf("%d是水仙花数\n", num3);
		}
	}
	for (num4 = 100000; num4 < 999999; num4++)
	{
		a = num4 / 100000;
		b = (num4 / 10000) % 10;
		c = (num4 / 1000) % 10;
		d = (num4 / 100) % 10;
		e = (num4/10) % 10;
		f = num4 % 10;
		i = a*a*a*a*a*a + b*b*b*b*b*b + c*c*c*c*c*c + d*d*d*d*d*d + e*e*e*e*e*e+f*f*f*f*f*f;
		if (i == num4)
		{
			printf("%d是水仙花数\n", num4);
		}

	}


	return 0;
	}
int main()
{
	int n = 5; int a = 2; int sum = 0; int sum1 = 0; int i = 0;
	for (i= 0; i < n; i++)
	{
		sum = sum * 10 + a;
		sum1 = sum1 + sum;
	}
	printf("sum1=%d\n", sum1);
	return 0;
}

int BinarySearch(int arr[], int len, int n)
{
	int left = 0;
	int right = len - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] > n)
		{
			left = left;
			right = mid - 1;
		}
		else if (arr[mid] < n)
		{
			left = mid + 1;
			right= right;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 6, 8, 9, 13, 48 };
	int index=BinarySearch(arr, 9, 13);
	printf("index=%d", index);
	return 0;
	}
#include<string.h>
int main(){
	char passward[10];
	int count = 3;
	while (count > 0)
	{
		printf("请输入密码");
		scanf("%s\n", &passward);
		if (strcmp(passward, 123456) == 0){
			printf("登录成功\n");
			break;
		}
		else
		{
			count--;
			printf("错误，你还有%d\n次机会", count);
		}
	}
	return 0;
}
#include<stdio.h>
#define iM 9
void i(int q);
int main()
{
	int n;
	printf("输入一个数\n");
	scanf("%d", &n);
	if (n >= 3 && n <= iM)
	{
		i(n);
	}
	else
		printf("T D L\n");
}
void i(int q)
{
	int sum = 0;
	int a;
	int b = 0;
	int s = 100;
	int w = 2;
	int i;
	int j;
	int t;
	int v;
	int m = 0;
	for (a = 1; a <= q; a++)
	{
		b = b * 10 + 9;
	}
	for (a = 100; a <= b; a++)
	{
		sum = 0;
		if (a%s == 0)
		{
			s = s * 10;
			w = w + 1;
		}
		v = a;
		for (j = 1; j <= w; j++)
		{
			i = v % 10;
			m = i;
			for (t = 1; t<w; t++)
			{
				i = i*m;
			}
			sum = sum + i;
			v = v / 10;
			i = 0;
		}
		if (a == sum)
		{
			printf("%d是水仙花数\n", a);
		}
	}
}
#include<string.h>
int main(){
	char passward[10];
	int count = 3;
	while (count > 0)
	{
		printf("请输入密码");
		scanf("%s\n",&passward);
		if (strcmp(passward,"123456") == 0){
			printf("登录成功\n");
			break;
		}
		else
		{
			count--;
		}
	}	printf("错误，你还有%d\n次机会", count);
	return 0;
}
*/
#include<stdio.h>
#include<string.h>
int main(){
	char passward[10];
	int count = 3;
	printf("请输入密码");
	while (count > 0)
	{
		scanf("%s\n", &passward);
		if (strcmp(passward,"123456") == 0){
			printf("登录成功\n");
			break;
		}
		else
		{
			count--;
			printf("错误，你还有%d\n次机会", count);
		}
	}
	return 0;
}