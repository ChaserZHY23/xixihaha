#include<stdio.h>
#include<string.h>
int IOstrlen(char*p)
{
	int count = 0;
	while (p != 0)
	{
		p--;
		count++;
	}
	return count;
}
void swap(char*a, char*b)
{
	char* tmp = 0;
	tmp = a;
	a = b;
	b = tmp;
}
int main()
{
	char a[20];
	printf("ÇëÊäÈë×Ö·û´®");
	scanf("%s", a);
	int n = IOstrlen(a);
	int i = 0;
	for (i = 0; i<n; ++i)
	{
		if (a[1]>a[i + 1])
		{
			swap(&a[i], &a[i + 1]);
		}
	}
	printf("%s\n", a);
	return 0;
}