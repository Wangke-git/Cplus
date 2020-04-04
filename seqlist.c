#include <stdlib.h>
#include "seqList.h"

void seqListInit(seqList* sl)
{
	//��ʼ������
	sl->_array = (int*)malloc(sizeof(DataType)* 4);
	sl->_capacity = 4;
	sl->_size = 0;
}
// pushBack: β��
void seqListPushBack(seqList* sl, DataType value)
{
	/*
	checkCapacity(sl);
	sl->_array[sl->_size++] = value;
	*/
	seqListInsert(sl, sl->_size, value);
}


//popBack: βɾ
void seqListPopBack(seqList* sl)
{
	/*
	//����Ҫ�ͷſռ�
	if (sl->_size)
		--sl->_size;
	*/
	seqListErase(sl, sl->_size - 1);
}

// pushFront: ͷ��
void seqListPushFront(seqList* sl, DataType value)
{
	/*
	checkCapacity(sl);
	//Ԫ���ƶ���Ҫ�Ӻ���ǰ�ƶ�, ��ֹԪ�ظ���
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
	//����
	if (sl->_size == sl->_capacity)
	{
		sl->_capacity *= 2;
		/*
		//���ռ�
		DataType* newArray = (DataType*)malloc(sizeof(DataType)* sl->_capacity);
		//����
		memcpy(newArray, sl->_array, sl->_size * sizeof(DataType));
		//�ͷſռ�
		free(sl->_array);
		sl->_array = newArray;
		*/
		sl->_array = (DataType*)realloc(sl->_array, sizeof(DataType)* sl->_capacity);
	}
}

// popFront: ͷɾ
void seqListPopFront(seqList* sl)
{
	/*
	//ע��Ԫ�ظ������⣺
	//�ƶ��� ��ǰ����ƶ�
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

// ��posλ��ǰ�����һ������value
void  seqListInsert(seqList* sl, size_t pos, DataType value)
{
	//�ж�λ���Ƿ�Ϸ�
	if (pos <= sl->_size)
	{
		//�������
		checkCapacity(sl);

		//�ƶ�Ԫ�أ� pos ~  size-1
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

//ɾ��posλ�õ�����
void seqListErase(seqList* sl, size_t pos)
{
	if (pos < sl->_size)
	{
		// �ƶ�Ԫ�أ� ��ǰ����ƶ�
		// �ƶ���λ�ã� pos + 1 ~ size - 1 --->   pos ~  size - 2
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