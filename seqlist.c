#include <stdlib.h>
#include "seqList.h"

void seqListInit(seqList* sl)
{
	//初始化数组
	sl->_array = (int*)malloc(sizeof(DataType)* 4);
	sl->_capacity = 4;
	sl->_size = 0;
}
// pushBack: 尾插
void seqListPushBack(seqList* sl, DataType value)
{
	/*
	checkCapacity(sl);
	sl->_array[sl->_size++] = value;
	*/
	seqListInsert(sl, sl->_size, value);
}


//popBack: 尾删
void seqListPopBack(seqList* sl)
{
	/*
	//不需要释放空间
	if (sl->_size)
		--sl->_size;
	*/
	seqListErase(sl, sl->_size - 1);
}

// pushFront: 头插
void seqListPushFront(seqList* sl, DataType value)
{
	/*
	checkCapacity(sl);
	//元素移动需要从后向前移动, 防止元素覆盖
	size_t end = sl->_size;
	while (end > 0)
	{
		sl->_array[end] = sl->_array[end - 1];
		--end;
	}
	sl->_array[0] = value;
	++sl->_size;
	*/
	seqListInsert(sl, 0, value);
}

void checkCapacity(seqList* sl)
{
	//增容
	if (sl->_size == sl->_capacity)
	{
		sl->_capacity *= 2;
		/*
		//开空间
		DataType* newArray = (DataType*)malloc(sizeof(DataType)* sl->_capacity);
		//拷贝
		memcpy(newArray, sl->_array, sl->_size * sizeof(DataType));
		//释放空间
		free(sl->_array);
		sl->_array = newArray;
		*/
		sl->_array = (DataType*)realloc(sl->_array, sizeof(DataType)* sl->_capacity);
	}
}

// popFront: 头删
void seqListPopFront(seqList* sl)
{
	/*
	//注意元素覆盖问题：
	//移动： 从前向后移动
	if (sl->_size)
	{
		size_t start = 1;
		// 1 ~ size - 1   ---->  0  ~  size - 2
		while (start < sl->_size)
		{
			sl->_array[start - 1] = sl->_array[start];
			++start;
		}
		--sl->_size;
	}
	*/
	seqListErase(sl, 0);

}

// 在pos位置前面插入一个数据value
void  seqListInsert(seqList* sl, size_t pos, DataType value)
{
	//判断位置是否合法
	if (pos <= sl->_size)
	{
		//检查容量
		checkCapacity(sl);

		//移动元素： pos ~  size-1
		size_t end = sl->_size;
		while (end > pos)
		{
			sl->_array[end] = sl->_array[end - 1];
			--end;
		}
		sl->_array[pos] = value;
		++sl->_size;
	}
}

//删除pos位置的数据
void seqListErase(seqList* sl, size_t pos)
{
	if (pos < sl->_size)
	{
		// 移动元素： 从前向后移动
		// 移动的位置： pos + 1 ~ size - 1 --->   pos ~  size - 2
		size_t start = pos + 1;
		while (start < sl->_size)
		{
			sl->_array[start - 1] = sl->_array[start];
			++start;
		}
		--sl->_size;
	}
}

int seqListFind(seqList* sl, DataType value)
{
	for (int i = 0; i < sl->_size; ++i)
	{
		if (sl->_array[i] == value)
			return i;
	}
	return -1;
}

void seqListPrint(seqList* sl)
{
	for (size_t i = 0; i < sl->_size; ++i)
	{
		printf("%d ", sl->_array[i]);
	}
	printf("\n");
}