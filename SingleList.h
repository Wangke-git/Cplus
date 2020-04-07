#pragma  once;

typedef int Type;

typedef struct Node
{
	struct Node* _next;
	Type _data;
}Node;

//ʵ�ֲ���ͷ�����ѭ������
typedef struct SingleList
{
	Node* _head; // head: ��ʾ����������ͷ��㣬����һ����Ч�����ݵ�λ��
}SingleList;

void singleListInit(SingleList* sl);

Node* creatNode(Type data);

void singleListPushBack(SingleList* sl, Type data);

void singleListPopBack(SingleList* sl);

void singleListPushFront(SingleList* sl, Type data);

void singleListPopFront(SingleList* sl);

void singleListInsertAfter(Node* pos, Type data);

void singleListEraseAfter(Node* pos);

Node* find(SingleList* sl, Type data);
void singleListPop(Node** head);
void singleListPop1(Node* head);

void singleListPrint(SingleList* sl);

void singleListDestroy(SingleList* sl);