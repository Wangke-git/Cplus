#include <stdlib.h>
#include <stdio.h>

#include "SingleList.h"

void singleListInit(SingleList* sl)
{
	//空链表
	sl->_head = NULL;
}

Node* creatNode(Type data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->_data = data;
	node->_next = NULL;
	return node;
}

void singleListPrint(SingleList* sl)
{
	Node* cur = sl->_head;
	while (cur)
	{
		printf("%d ", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}

void singleListPushFront(SingleList* sl, Type data)
{
	Node* node = creatNode(data);
	//是否为空表
	if (sl->_head == NULL)
	{
		sl->_head = node;
	}
	else
	{
		node->_next = sl->_head;
		sl->_head = node;
	}
}

void singleListPopFront(SingleList* sl)
{
	if (sl->_head)
	{
		Node* cur = sl->_head;
		sl->_head = cur->_next;
		free(cur);
	}
}
//正确接口
void singleListPop(Node** head)
{
	if (*head)
	{
		Node* newH = (*head)->_next;
		free(*head);
		*head = newH;
	}
}
// 错误接口
void singleListPop1(Node* head)
{
	if (head)
	{
		Node* newH = head->_next;
		free(head);
		head = newH;
	}
}

void singleListPushBack(SingleList* sl, Type data)
{
	Node* node = creatNode(data);
	if (sl->_head == NULL)
		sl->_head = node;
	else
	{
		//找到最后一个数据
		// last   newNode
		Node* last = sl->_head;
		while (last->_next)
			last = last->_next;

		//尾插
		last->_next = node;
	}	
}

void singleListPopBack(SingleList* sl)
{
	//找到最后一个节点，并且，修改被删除节点的前驱节点的执行
	if (sl->_head)
	{
		//找到最后一个节点，遍历的过程中，更新prev
		Node* prev = NULL;
		Node* tail = sl->_head;
		while (tail->_next)
		{
			prev = tail;
			tail = tail->_next;
		}
		//如果删除的为头结点， 或者链表中只要一个节点
		//和下面判断等价if (prev == NULL)
		if (tail == sl->_head)
			sl->_head = NULL;
		else
			prev->_next = NULL;

		free(tail);
	}
}


void singleListInsertAfter(Node* pos, Type data)
{
	if (pos == NULL)
		return;
	// pos  newNode next
	Node* newNode = creatNode(data);
	//注意先后顺序
	newNode->_next = pos->_next;
	pos->_next = newNode;
}

void singleListEraseAfter(Node* pos)
{
	Node* next;
	if (pos == NULL)
		return;
	//pos  next
	next = pos->_next;
	//确保next非空指针, pos->_next->_next
	if (next)
	{
		pos->_next = next->_next;
		free(next);
	}
}

Node* find(SingleList* sl, Type data)
{
	Node* cur = sl->_head;
	while (cur)
	{
		if (cur->_data == data)
			return cur;
		cur = cur->_next;
	}
	return NULL;
}

void singleListDestroy(SingleList* sl)
{
	Node* cur = sl->_head;
	while (cur)
	{
		Node* next = cur->_next;
		free(cur);
		cur = next;
	}
}

