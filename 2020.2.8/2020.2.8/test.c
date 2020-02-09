#define _CRT_SECURE_NO_WARNINGS 1
ListNode* BuyListNode(LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = x;
	node->next = NULL;
	node->prev = NULL;
	return node;
}//这个是先申请创建一个节点
ListNode* ListCreate()
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	head->next = head;
	head->prev = head;
	return head;
}
void ListPrint(ListNode* pHead)
{
	assert(pHead);
	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
void ListDestroy(ListNode* pHead)
{
	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}

	free(pHead);
}
void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* newnode = BuyListNode(x);
	// phead tail newnode
	ListNode* tail = pHead->prev;
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = pHead;
	pHead->prev = newnode;
	ListInsert(pHead, x);
}
void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* newnode = BuyListNode(x);
	ListNode* first = pHead->next;
	pHead->next = newnode;
	newnode->prev = pHead;
	newnode->next = first;
	first->prev = newnode;
	ListNode* newNode = BuyListNode(x);
	newNode->next = pHead->next;
	pHead->next->prev = newNode;
	pHead->next = newNode;
	newNode->prev = pHead;
	ListInsert(pHead->next, x);
}
void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	ListNode* tail = pHead->prev;
	ListNode* tailPrev = tail->prev;
	// pHead tailPrev tail
	tailPrev->next = pHead;
	pHead->prev = tailPrev;
	free(tail);
	ListNode* tail = pHead->prev;
	pHead->prev = tail->prev;
	tail->prev->next = pHead;
	free(tail);
	ListErase(pHead->prev);
}
void ListPopFront(ListNode* pHead)
{
	//...
	ListErase(pHead->next);
}
// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* newnode = BuyListNode(x);
	// prev newnode pos
	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;
}
// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* next = pos->next;
	prev->next = next;
	next->prev = prev;
	free(pos);
}