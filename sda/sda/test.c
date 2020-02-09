#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
typedef struct  BtreeNode
{
	struct BtreeNode* left;
struct BtreeNode* right;
int val;
}BtreeNode;
BtreeNode*creatTree(char* a, int*pindex)
{
	if (a[*pindex] == '#')
		return NULL;
	BtreeNode* root = (BtreeNode*)malloc(sizeof(BtreeNode));
	root->val = a[*pindex];
	++(*pindex);
	root->left = creatTree(a, pindex);
	++(*pindex);
	root->right = creatTree(a, pindex);
	return root;
}
void Inorder(BtreeNode*root)
{
	if (root == NULL)
		return;
	Inorder(root->left);
	printf("%c ", root->val);
	Inorder(root->right);
}
int main()
{
	char a[100] = { 0 };
	scanf("%s", a);
	int index = 0;
	BtreeNode*root = creatTree(a, &index);
	Inorder(root);
	return 0;
}