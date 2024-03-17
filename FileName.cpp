#include<iostream>
using namespace std;
void showMenu()
{
	cout << "请输入指令:" << endl;
	cout << "1:生成空链表" << endl;
	cout << "2:添加链表" << endl;
	cout << "3:查看所有数据" << endl;
	cout << "4:查找数据" << endl;
	cout << "5:删除数据" << endl;
	cout << "6:销毁所有数据" << endl;
	cout << "7:插入数据" << endl;

}
struct singleList {
	string data;
	struct singleList* next;

};
singleList* creat() {
	singleList* head;
	//singleList* p1;
	//singleList* p2;
	//p1 = p2 = new singleList;
	//head = p1;
	head = new singleList;
	head->next = NULL;
	cout << "空链表创建成功！" << endl;
	return (head);
}

void addList(singleList* head) {
	string data;
	cout << "请输入要添加的数据" << endl;
	cin >> data;
	if (head == NULL) {
		head = new singleList;
		head->data = data;
		head->next = NULL;
	}
	else {
		singleList* p1;
		singleList* p2;
		p1 = p2 = head;
		while (p1->next != NULL) {
			p2 = p1;
			p1 = p1->next;
		}
		p1->data = data;
	}
	system("pause");
	system("cls");
}
void findData(singleList* head) {
	cout << "请输入您要查找的数据：" << endl;
	string data;
	cin >> data;
	singleList* p1;
	singleList* p2;
	p1 = p1 = head;
	while (true) {
		if (head == NULL) {
			cout << "该值不存在。" << endl;
			break;
		}
		if (p1->data == data) {
			cout << "该值存在。" << endl;
			break;
		}
		else {
			p2 = p1;
			p1 = p1->next;
		}
		if (p1 == NULL) {                       //遍历全部链表找不到data
			cout << "该值不存在" << endl;
			break;
		}
	}
}
singleList* findData(singleList* head, string data) {
	singleList* p1;
	singleList* p2;
	p1 = p1 = head;
	while (true) {
		if (head == NULL) {
			cout << "该值不存在。" << endl;
			return 0;
		}
		if (p1->data == data) {
			cout << "该值存在。" << endl;
			return p1;
		}
		else {
			p2 = p1;
			p1 = p1->next;
		}
		if (p1 == NULL) {                       //遍历全部链表找不到data
			cout << "该值不存在" << endl;
			return 0;
		}
	}
}

void insertList(singleList* head) {
	if (head == NULL) {
		cout << "当前链表为空，请先添加链表！";
		return;
	}
	cout << "请输入您要插入的数据";
	string insertData, oriData;
	cin >> insertData;
	cout << "请您输入您要插入到哪个数据之后:";
	cin >> oriData;
	singleList* p1;
	singleList* p2;
	singleList* p3;
	p2 = p1 = findData(head, oriData);
	p3 = p1->next;
	p1 = new singleList;
	p2->next = p1;
	p1->data = insertData;
	p1->next = p3;
	cout << "数据插入成功!" << endl;
	system("pause");
	system("cls");

}
void destroyList(singleList* head) {
	singleList* p1 = NULL;
	p1 = head;
	while (p1->next != NULL) {
		head = p1->next;
		free(p1);
	}
	cout << "链表销毁成功！" << endl;
	system("pause");
	system("cls");
}
void deleteList(singleList* head) {
	string deleteData;
	cout << "请输入您要删除的数据：" << endl;
	cin >> deleteData;
	singleList* p1, * p2;
	p1 = p2 = head;
	if (head == NULL) {
		cout << "当前链表为空，请先创建链表" << endl;
		return;
	}
	while (true) {
		if (p1->data == deleteData) {
			p2 = p1;
			p1 = p1->next;
			p1 = NULL;
			p2->next = NULL;
			break;
		}
		else {
			p2 = p1;
			p1 = p1->next;
		}
		if (p1 == NULL) {
			cout << "该数据存在！" << endl;
			break;
		}
	}
	system("pause");
	system("cls");
}
void printList(singleList* head) {
	if (head == NULL) {
		cout << "当前链表为空。" << endl;
		return;
	}
	singleList* p1 = head;
	do {
		cout << p1->data << endl;
		p1 = p1->next;
	} while (p1 != NULL);
	system("pause");
	system("cls");
}
int main() {
	int command = 0;
	singleList* head;
	head = NULL;
	while (true)
	{
		showMenu();
		cin >> command;
		switch (command)
		{
		case 1:head = creat();
			system("pause");
			system("cls");						        //链表生成
			break;
		case 2:addList(head);							//添加
			break;
		case 3:printList(head);							//打印
			break;
		case 4:findData(head);							//查找
			break;
		case 5:deleteList(head);						//删除
			break;
		case 6:destroyList(head);				        //销毁
			break;
		case 7:	insertList(head);						//插入
			cout << "test3" << endl;
			break;
		default:cout << "输入有误，请您重新输入！" << endl;;
			break;
		}
	}

	system("pause");
	return 0;
}