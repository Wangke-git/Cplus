#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
int Strcmp(const char* str1, const char* str2)
{
	assert(str1 != NULL && str2 != NULL);//断言
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 < *str2)
		{
			return -1;
		}
		else if (*str1 > * str2)
		{
			return 1;
		}
		else
		{
			*str1++;
			*str2++;
		}
	}
	//判断一个字符先达到‘\0'的状况
	if (*str1 < *str2)
	{
		return -1;
	}
	else if (*str1 > * str2)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}
const char* Strstr(const char* str1, const char* str2)
{
	assert(str1 != NULL && str2 != NULL);//断言
	if (*str2 == '\0')
	{
		return NULL;
	}
	const char* black = str1;
	while (*black != '\0')
	{
		const char* red = black;
		const char* sub = str2;
		while (*red != '\0' && *sub != '\0' && (*red == *sub))
		{
			red++;
			sub++;
		}
		//当上边循环体结束，可能会有三种情况
		//1.*red遇到'\0'
		//2.*sub遇到'\0'
		//3.*red !=*sub
		if (*red == '\0')
		{
			return black;
		}
		if (*sub == '\0')
		{
			return NULL;
		}
		black++;
	}
	return NULL;
}
void* Memcpy(void* dest, const void* src, size_t num)
{
	assert(dest != NULL && src != NULL);//断言
	void* ret = dest;
	for (size_t i = 0; i < num; i++)
	{
		*(char*)dest = *(char*)src;
		dest = (char*)dest + 1;
		src = (char*)src + 1;
	}
	return ret;
}
void* Memmove(void* dest, const void* src, size_t num)
{
	assert(dest != '\0' && src != '\0');
	char* cdest = (char*)dest;
	char* csrc = (char*)src;
	if (csrc < cdest && cdest < csrc + num)
	{
		char* pdest = cdest + num - 1;
		char* psrc = csrc + num - 1;
		for (size_t i = 0; i < num; i++)
		{
			*pdest = *psrc;
			pdest--;
			psrc--;
		}
	}
	else
	{
		Memcpy(dest, src, num);
	}
	return dest;
}
int main()
{
	int arr[] = { 1,2,3,4 };
	int arr2[4] = { 0 };
	Memmove(arr2, arr, 4);
	for (int i = 0; i < 4; i++)
	{
		printf("%d\n", arr2[i]);
	}
	return 0;
}