#define _CRT_SECURE_NO_WARNINGS 1
#include "BTree.h"
#include "queue.h" //参考之前的代码
#include "stack.h"
BTNode *BinaryTreeCreate(BTDataType * src, int n, int* pi) {
	if (src[*pi] == '#' || *pi >= n)
	{
		(*pi)++;
		return NULL;
	}
	BTNode * cur = (BTNode *)malloc(sizeof(BTNode));
	cur->_data = src[s_n];
	(*pi)++;
	cur->_left = BinaryTreeCreateExe(src);
	cur->_right = BinaryTreeCreateExe(src);
	return cur;
}
void BinaryTreePrevOrder(BTNode* root) {
	if (root)
	{
		putchar(root->_data);
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
	}
}
void BinaryTreeInOrder(BTNode* root) {
	if (root)
	{
		BinaryTreeInOrder(root->_left);
		putchar(root->_data);
		BinaryTreeInOrder(root->_right);
	}
}
void BinaryTreePostOrder(BTNode* root) {
	比特科技
		if (root)
		{
			BinaryTreePostOrder(root->_left);
			BinaryTreePostOrder(root->_right);
			putchar(root->_data);
		}
}
void BinaryTreeDestory(BTNode** root) {
	if (*root)
	{
		BinaryTreeDestory((*root)->_left);
		BinaryTreeDestory((*root)->_right);
		free(*root);
		*root = NULL;
	}
}
void BinaryTreeLevelOrder(BTNode* root) {
	Queue qu;
	BTNode * cur;
	QueueInit(&qu);
	QueuePush(&qu, root);
	while (!QueueIsEmpty(&qu))
	{
		cur = QueueTop(&qu);
		putchar(cur->_data);
		if (cur->_left)
		{
			QueuePush(&qu, cur->_left);
		}
		if (cur->_right)
		{
			QueuePush(&qu, cur->_right);
		}
		QueuePop(&qu);
	}
	QueueDestory(&qu);
}
int BinaryTreeComplete(BTNode* root) {
	Queue qu;
