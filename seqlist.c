#include<stdlib.h>
#include"seqList.h"
void seqListInit(seqList* sl)
{
	//��ʼ������

	sl->_array = (int*)malloc(sizeof(DataType) * 4);
	sl->_capacity = 4;
	sl->_size = 0;
}
// pushBack: β��
void seqListPushBack(seqList* sl, DataType value)
{
	sl->_array[sl->_size++] = value;
}

//βɾ
void seqListPopBack(seqList* sl)
{
	//����Ҫ�ͷſռ�
	if (sl->_size)
		--sl-> _size;
}
/*

//ͷ��
void seqListPushFront(seqList* sl, DateType value)
{
	
}
//ͷɾ
void seqListPopFront(seqList* sl);
//����
void seqListInsert(seqList* sl, size_t pos, DateType value);
//ɾ��
void sqeListErase(seqList* sl, size_t pos);
//Ѱ��
int seqListFind(seqList* sl, DateType value);
//��ӡ
*/
void seqListPrint(seqList* sl)
{
	for (size_t i = 0; i < sl->_size; i++)
	{
		printf("%d ", sl->_array[i]);
	}
	printf("\n");
}