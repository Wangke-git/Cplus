#include<stdlib.h>
#include"seqList.h"
void seqListInit(seqList* sl)
{
	//初始化数组

	sl->_array = (int*)malloc(sizeof(DataType) * 4);
	sl->_capacity = 4;
	sl->_size = 0;
}
// pushBack: 尾插
void seqListPushBack(seqList* sl, DataType value)
{
	sl->_array[sl->_size++] = value;
}

//尾删
void seqListPopBack(seqList* sl)
{
	//不需要释放空间
	if (sl->_size)
		--sl-> _size;
}
/*

//头插
void seqListPushFront(seqList* sl, DateType value)
{
	
}
//头删
void seqListPopFront(seqList* sl);
//插入
void seqListInsert(seqList* sl, size_t pos, DateType value);
//删除
void sqeListErase(seqList* sl, size_t pos);
//寻找
int seqListFind(seqList* sl, DateType value);
//打印
*/
void seqListPrint(seqList* sl)
{
	for (size_t i = 0; i < sl->_size; i++)
	{
		printf("%d ", sl->_array[i]);
	}
	printf("\n");
}