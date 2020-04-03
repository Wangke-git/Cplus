#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//描述一个联系人信息
typedef struct PersonInfo {
	char name[1024];
	char phone[1024];
}PersonInfo;
//使用数组组织若干个联系人信息
#define MAX_SIZE 200
typedef struct AddressBook {
	PersonInfo persons[MAX_SIZE];
	int size;//区分当前数组中，多少个元素是有效元素
	//【0，size】这个范围中为元素是有效元素
	//【size ,200]范围中是无效元素
} AddressBook;
//此处参数设为指针，原因有二
//1.结构体作为函数参数时，需要进行拷贝，而结构体占据内存可能较大，参数写成指针，能够降低内存拷贝
//2.初始化函数内部，需要修改结构体变量的内容，我们需要在函数内部修改，同时能影响到函数外部，此时指针相当于一个输出

void Init(AddressBook* addr){
	//初始化通讯录结构体
	addr->size = 0;
	for (int i = 0; i < MAX_SIZE;i++)
	{
		strcpy(addr->persons[i].name, "");
		strcpy(addr->persons[i].phone, "");
	}
}
int Menu() {
	printf("=============================\n");
	printf("1.新增联系人\n");
	printf("2.删除联系人\n");
	printf("3.查找联系热\n");
	printf("4.修改联系人\n");
	printf("5.打印全部联系人\n");
	printf("6.清空全部联系人\n");
	printf("0.退出\n");
	printf("=============================\n");
	printf("请你输入您的选择：");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
void AddPersonInfo(AddressBook* addr_book) {
	printf("新增联系人！\n");
	if (addr_book->size >= MAX_SIZE) {
		printf("通讯录已满，新增联系人失败！\n");
		return;
	}
	//需要让用户输入联系人的基本信息
	PersonInfo* info = &addr_book->persons[addr_book->size];
	printf("请输入联系人姓名：");
	scanf("%s", info->name);
	printf("请输入联系人电话：");
	scanf("%s", info->phone);
	//千万不要忘记，每次新增一个联系人，size就要+1
	addr_book->size++;
	printf("新增联系人成功\n");
}
void DelPersonInfo(AddressBook* addr_book) {
	//删除策略，可以指定用户名删除，可能会有重名
	//指定序号删除
	printf("执行删除操作\n");
	if (addr_book->size <= 0) {
		printf("通讯录为空！删除失败\n");
		return;
	}
	printf("请输入要删除联系人的序号：");
	int id = 0;//此处的序号是联系人数组的下标
	if (id < 0 || id >= addr_book->size) {
		printf("输入序号非法，删除失败\n");
		return;
	}
	scanf("%d", &id);
	//删除中间元素：把最后一个元素填充到要删除元素位置，然后在size--
	//获取到最后一个元素
	PersonInfo* last_info = &addr_book->persons[addr_book->size - 1];
	//获取到待删除元素
	PersonInfo* to_del = &addr_book->persons[id];
	//把最后一个元素赋值给待删除元素
	*to_del = *last_info;
	//更新size
	addr_book->size--;
	printf("删除成功");
}
void FindPersonInfo(AddressBook* addr_book) {
	//此处我们按照联系人姓名查找，如果存在重名，把所有记录都获取-
	printf("查找指定联系人！\n");
	printf("请输入要查找的联系人姓名：");
	char name[1024] = { 0 };
	scanf("%s", name);
	for (int i = 0; i < addr_book->size; i++) {
		PersonInfo* info = &addr_book->persons[i];
		if (strcmp(name, info->name) == 0) {
			printf("[%d] %s:%s\n", i, info->name, info->phone);
		}
	}
	printf("查找指定联系人完毕！\n");
}
void ModifyPersonInfo(AddressBook* addr_book) {
	if (addr_book->size <= 0) {
		printf("通讯录为空！修改失败！\n");
		return;
	}
	//y用户要修改的id
	int id = 0;
	printf("请输入要修改的联系人序号：");
	scanf("%d", &id);
	if (id < 0 || id >= addr_book->size) {
		printf("输入的序号非法，修改失败");
		return;
	}
	//修改
	PersonInfo* info = &addr_book->persons[id];
	printf("请输入修改后的名字(* 表示不变)");
	char name[1024] = { 0 };
	scanf("%s", name);
	if (strcmp(name, "*") != 0) {
		strcpy(info->name, name);
	}

	printf("请输入要修改的电话（* 表示不变）");
	char phone[1024] = { 0 };
	scanf("%s", phone);
	if (strcmp(phone, "*") != 0) {
		strcpy(info->phone, phone);
	}
	printf("修改成功!\n");
}
void PrintPersonInfo(AddressBook* addr_book) {
	printf("打印所有联系人：\n");
	for (int i = 0; i < addr_book->size; i++) {
		PersonInfo* info = &addr_book->persons[i];
		printf("[%d] %s %s\n", i, info->name, info->phone);
	}
	printf("当前共打印%d条记录！\n",addr_book->size);

}
void ClearPersonInfo(AddressBook* addr_book) {
	//很危险
	printf("删除全部记录！\n");
	printf("您确定？Y/N\n");
	char choice[1024] = { 0 };
	scanf("%s", &choice);
	if (strcmp(choice, "Y") == 0) {
		addr_book->size = 0;
		printf("删除成功！\n");
		return;
	}
	else {
		printf("删除已经取消！\n");
		return;
	}
}
int main()
{
	//此处可能存在风险，一旦AddressBook太大了，可能会超出栈的范围
	AddressBook address_book;
	Init(&address_book);
	//创建一个类型Func ，对应一个函数指针类型，void(*)(AddressBook);
	typedef void(*Func)(AddressBook*);
	Func func_table[] = {
		NULL,//null纯属用来占位置，为了让后续函数的下表和用户输入的命令一一对应
		AddPersonInfo,
		DelPersonInfo,
		FindPersonInfo,
		ModifyPersonInfo,
		PrintPersonInfo,
		ClearPersonInfo,
	};
	while (1) {
		//转移表
		int choice = Menu();
		//数组元素个数是7，命令范围0-6；
		if (choice < 0 || choice >= sizeof(func_table) / sizeof(func_table[0])) {
			printf("您的输入有误！\n");
			continue;
		}
		if (choice == 0) {
			printf("goodbye\n");
			break;
		}
		func_table[choice](&address_book);
		/*if (choice == 0) {
			printf("goodbye\n");
			break;
		}else if (choice == 1) {
			AddPersonIofo(&address_book);
		}
		else if (choice == 2) {
			DelPersonInfo(&address_book);
		}
		else if (choice == 3) {
			FindPersonInfo(&address_book);
		}
		else if (choice == 4) {
			ModifyPersonInfo(&address_book);
		}
		else if (choice == 5) {
			PrintPersonInfo(&address_book);
		}
		else if (choice == 6) {
			ClearPersonInfo(&address_book);
		}
		else {
			printf("您的输入有误!\n");
		}*/
	}
	system("pause");
	return 0;
}