#include <stdlib.h>
#include <stdio.h>

#include "SingleList.h"

void singleListInit(SingleList* sl)
{
	//������
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
	//�Ƿ�Ϊ�ձ�
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
//��ȷ�ӿ�
void singleListPop(Node** head)
{
	if (*head)
	{
		Node* newH = (*head)->_next;
		free(*head);
		*head = newH;
	}
}
// ����ӿ�
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
		//�ҵ����һ������
		// last   newNode
		Node* last = sl->_head;
		while (last->_next)
			last = last->_next;

		//β��
		last->_next = node;
	}	
}

void singleListPopBack(SingleList* sl)
{
	//�ҵ����һ���ڵ㣬���ң��޸ı�ɾ���ڵ��ǰ���ڵ��ִ��
	if (sl->_head)
	{
		//�ҵ����һ���ڵ㣬�����Ĺ����У�����prev
		Node* prev = NULL;
		Node* tail = sl->_head;
		while (tail->_next)
		{
			prev = tail;
			tail = tail->_next;
		}
		//���ɾ����Ϊͷ��㣬 ����������ֻҪһ���ڵ�
		//�������жϵȼ�if (prev == NULL)
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
	//ע���Ⱥ�˳��
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
	//ȷ��next�ǿ�ָ��, pos->_next->_next
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

