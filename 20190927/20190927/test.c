#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//void Shuzu(int arr[], int len)
{
	int left = 0;
	int right = len - 1;
	int tmp = 0;
	while (left < right)
	{
		while (arr[left] % 2 == 1)
		{
			left++;
		}
		while (arr[right] % 2 == 0)
		{
			right--;
		}
		if (left < right)
		{
			tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
			left++;
			right--;

		}
	}
}
int main()
{
	int i = 0;
	int arr[] = { 1, 2, 3, 4, 5, 2, 1, 5, 6, 9 };
	int len = sizeof(arr) / sizeof(arr[0]);
	Shuzu(arr, len);
	for (i = 0; i <len; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
int find(int arr[3][3], int *px, int * py, int key)
{
	int i = 0;
	int j = 2;
	while (i < 3 && j >= 0)
	{
		if (arr[i][j]>key)
		{
			j--;
		}
		else if (arr[i][j] < key)
		{
			i++;
		}

		else
		{
			return 1;
		}
		return 0;
	}
}
int main()
{
	int arr[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int x = 3;
	int y = 3;
	int ret = 0;
	ret=find(arr, &x, &y, 4);
	if(ret = 1)
	{ 
		printf("该值存在\n");
	}
	else
	{
		printf("该值不存在\n");
	}

}
int Zhaoshuzi(char arr[], int len)
{
	int i = 0;
	for (int i = 1; i < len; i++)
	{
		arr[0] = arr[0] ^ arr[i];
	}
	printf("%d\n", arr[0]);
	return 0;
}
int main()
{
	char arr[10] = { 1, 5, 4, 9, 5, 2, 1, 6, 4, 7 };
	 int len = sizeof(arr) / sizeof(arr[0]);
	int ret= Zhaoshuzi(arr[10], len);
	printf("%d\n", ret);
	 return 0;
}
博客链接：https://blog.csdn.net/ChaserZHY/article/details/101635570