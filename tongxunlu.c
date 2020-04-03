#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//����һ����ϵ����Ϣ
typedef struct PersonInfo {
	char name[1024];
	char phone[1024];
}PersonInfo;
//ʹ��������֯���ɸ���ϵ����Ϣ
#define MAX_SIZE 200
typedef struct AddressBook {
	PersonInfo persons[MAX_SIZE];
	int size;//���ֵ�ǰ�����У����ٸ�Ԫ������ЧԪ��
	//��0��size�������Χ��ΪԪ������ЧԪ��
	//��size ,200]��Χ������ЧԪ��
} AddressBook;
//�˴�������Ϊָ�룬ԭ���ж�
//1.�ṹ����Ϊ��������ʱ����Ҫ���п��������ṹ��ռ���ڴ���ܽϴ󣬲���д��ָ�룬�ܹ������ڴ濽��
//2.��ʼ�������ڲ�����Ҫ�޸Ľṹ����������ݣ�������Ҫ�ں����ڲ��޸ģ�ͬʱ��Ӱ�쵽�����ⲿ����ʱָ���൱��һ�����

void Init(AddressBook* addr){
	//��ʼ��ͨѶ¼�ṹ��
	addr->size = 0;
	for (int i = 0; i < MAX_SIZE;i++)
	{
		strcpy(addr->persons[i].name, "");
		strcpy(addr->persons[i].phone, "");
	}
}
int Menu() {
	printf("=============================\n");
	printf("1.������ϵ��\n");
	printf("2.ɾ����ϵ��\n");
	printf("3.������ϵ��\n");
	printf("4.�޸���ϵ��\n");
	printf("5.��ӡȫ����ϵ��\n");
	printf("6.���ȫ����ϵ��\n");
	printf("0.�˳�\n");
	printf("=============================\n");
	printf("������������ѡ��");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
void AddPersonInfo(AddressBook* addr_book) {
	printf("������ϵ�ˣ�\n");
	if (addr_book->size >= MAX_SIZE) {
		printf("ͨѶ¼������������ϵ��ʧ�ܣ�\n");
		return;
	}
	//��Ҫ���û�������ϵ�˵Ļ�����Ϣ
	PersonInfo* info = &addr_book->persons[addr_book->size];
	printf("��������ϵ��������");
	scanf("%s", info->name);
	printf("��������ϵ�˵绰��");
	scanf("%s", info->phone);
	//ǧ��Ҫ���ǣ�ÿ������һ����ϵ�ˣ�size��Ҫ+1
	addr_book->size++;
	printf("������ϵ�˳ɹ�\n");
}
void DelPersonInfo(AddressBook* addr_book) {
	//ɾ�����ԣ�����ָ���û���ɾ�������ܻ�������
	//ָ�����ɾ��
	printf("ִ��ɾ������\n");
	if (addr_book->size <= 0) {
		printf("ͨѶ¼Ϊ�գ�ɾ��ʧ��\n");
		return;
	}
	printf("������Ҫɾ����ϵ�˵���ţ�");
	int id = 0;//�˴����������ϵ��������±�
	if (id < 0 || id >= addr_book->size) {
		printf("������ŷǷ���ɾ��ʧ��\n");
		return;
	}
	scanf("%d", &id);
	//ɾ���м�Ԫ�أ������һ��Ԫ����䵽Ҫɾ��Ԫ��λ�ã�Ȼ����size--
	//��ȡ�����һ��Ԫ��
	PersonInfo* last_info = &addr_book->persons[addr_book->size - 1];
	//��ȡ����ɾ��Ԫ��
	PersonInfo* to_del = &addr_book->persons[id];
	//�����һ��Ԫ�ظ�ֵ����ɾ��Ԫ��
	*to_del = *last_info;
	//����size
	addr_book->size--;
	printf("ɾ���ɹ�");
}
void FindPersonInfo(AddressBook* addr_book) {
	//�˴����ǰ�����ϵ���������ң�������������������м�¼����ȡ-
	printf("����ָ����ϵ�ˣ�\n");
	printf("������Ҫ���ҵ���ϵ��������");
	char name[1024] = { 0 };
	scanf("%s", name);
	for (int i = 0; i < addr_book->size; i++) {
		PersonInfo* info = &addr_book->persons[i];
		if (strcmp(name, info->name) == 0) {
			printf("[%d] %s:%s\n", i, info->name, info->phone);
		}
	}
	printf("����ָ����ϵ����ϣ�\n");
}
void ModifyPersonInfo(AddressBook* addr_book) {
	if (addr_book->size <= 0) {
		printf("ͨѶ¼Ϊ�գ��޸�ʧ�ܣ�\n");
		return;
	}
	//y�û�Ҫ�޸ĵ�id
	int id = 0;
	printf("������Ҫ�޸ĵ���ϵ����ţ�");
	scanf("%d", &id);
	if (id < 0 || id >= addr_book->size) {
		printf("�������ŷǷ����޸�ʧ��");
		return;
	}
	//�޸�
	PersonInfo* info = &addr_book->persons[id];
	printf("�������޸ĺ������(* ��ʾ����)");
	char name[1024] = { 0 };
	scanf("%s", name);
	if (strcmp(name, "*") != 0) {
		strcpy(info->name, name);
	}

	printf("������Ҫ�޸ĵĵ绰��* ��ʾ���䣩");
	char phone[1024] = { 0 };
	scanf("%s", phone);
	if (strcmp(phone, "*") != 0) {
		strcpy(info->phone, phone);
	}
	printf("�޸ĳɹ�!\n");
}
void PrintPersonInfo(AddressBook* addr_book) {
	printf("��ӡ������ϵ�ˣ�\n");
	for (int i = 0; i < addr_book->size; i++) {
		PersonInfo* info = &addr_book->persons[i];
		printf("[%d] %s %s\n", i, info->name, info->phone);
	}
	printf("��ǰ����ӡ%d����¼��\n",addr_book->size);

}
void ClearPersonInfo(AddressBook* addr_book) {
	//��Σ��
	printf("ɾ��ȫ����¼��\n");
	printf("��ȷ����Y/N\n");
	char choice[1024] = { 0 };
	scanf("%s", &choice);
	if (strcmp(choice, "Y") == 0) {
		addr_book->size = 0;
		printf("ɾ���ɹ���\n");
		return;
	}
	else {
		printf("ɾ���Ѿ�ȡ����\n");
		return;
	}
}
int main()
{
	//�˴����ܴ��ڷ��գ�һ��AddressBook̫���ˣ����ܻᳬ��ջ�ķ�Χ
	AddressBook address_book;
	Init(&address_book);
	//����һ������Func ����Ӧһ������ָ�����ͣ�void(*)(AddressBook);
	typedef void(*Func)(AddressBook*);
	Func func_table[] = {
		NULL,//null��������ռλ�ã�Ϊ���ú����������±���û����������һһ��Ӧ
		AddPersonInfo,
		DelPersonInfo,
		FindPersonInfo,
		ModifyPersonInfo,
		PrintPersonInfo,
		ClearPersonInfo,
	};
	while (1) {
		//ת�Ʊ�
		int choice = Menu();
		//����Ԫ�ظ�����7�����Χ0-6��
		if (choice < 0 || choice >= sizeof(func_table) / sizeof(func_table[0])) {
			printf("������������\n");
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
			printf("������������!\n");
		}*/
	}
	system("pause");
	return 0;
}