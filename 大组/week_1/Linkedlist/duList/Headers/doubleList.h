#pragma once
#include<iostream>
using namespace std;
void showMenu()
{
	cout << "双链表ADT" << endl;
	cout << "请输入指令:" << endl;
	cout << "1:初始化空链表" << endl;
	cout << "2:后插法添加链表" << endl;
	cout << "3:前插法添加链表" << endl;
	cout << "4:查看所有数据" << endl;
	cout << "5:查找数据" << endl;
	cout << "6:删除数据" << endl;
	cout << "7:销毁所有数据" << endl;
	cout << "8:插入数据" << endl;

}
struct duList {
	struct duList* front;
	string data;
	struct duList* next;

};
duList* head = NULL;

duList* creat() {
	if (head == NULL)
	{
		string data;
		head = new duList;
		cout << "请输入初始化链表的值：" << endl;
		cin >> data;
		head->data = data;
		head->next = NULL;
		head->front = NULL;
		cout << "空链表初始化成功！" << endl;
		return (head);
	}
	else {
		cout << "链表已完成初始化，请勿重复操作！" << endl;

	}
}

void BaAddList() {
	string data;
	cout << "请输入要添加的数据" << endl;
	cin >> data;
	if (head == NULL) {
		head = new duList;
		head->data = data;
		head->front = NULL;
		head->next = NULL;
	}
	else {
		duList* p1;
		duList* p2;
		p1 = p2 = head;
		while (p1 != NULL) {
			p2 = p1;
			p1 = p1->next;
		}
		p1 = new duList;
		p1->data = data;
		p1->front = p2;
		p1->next = NULL;
		p2->next = p1;

	}
	cout << "添加成功！" << endl;
	system("pause");
	system("cls");
}

void FrAddList() {
	string data;
	cout << "请输入要添加的数据" << endl;
	cin >> data;
	if (head == NULL) {
		head = new duList;
		head->data = data;
		head->front = NULL;
		head->next = NULL;
	}
	else {
		duList* p1;
		duList* p2;
		p1 = p2 = head;
		p1 = new duList;
		p1->front = NULL;
		p1->data = data;
		p1->next = p2;
		head->front = p1;
		head = p1;

	}
	cout << "添加成功！" << endl;
	system("pause");
	system("cls");
}
void findData() {
	cout << "请输入您要查找的数据：" << endl;
	string data;
	cin >> data;
	duList* p1;
	duList* p2;
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
	system("pause");
	system("cls");
}
duList* findData(string data) {
	duList* p1;
	duList* p2;
	p1 = p1 = head;
	while (true) {
		if (head == NULL) {
			return 0;
		}
		if (p1->data == data) {

			return p1;
		}
		else {
			p2 = p1;
			p1 = p1->next;
			p1->front = p2;
		}
		if (p1 == NULL) {                       //遍历全部链表找不到data
			return 0;
		}
	}
}

void insertList() {
	if (head == NULL) {
		cout << "当前链表为空，请先添加链表！" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "请输入您要插入的数据:";
	string insertData, oriData;
	cin >> insertData;
	cout << "请您输入您要插入到哪个数据之后:";
	cin >> oriData;
	duList* p1;
	duList* p2;
	duList* p3;
		p2 = p1 = findData(oriData);
		if (p1 == NULL) {
			cout << "您输入的数字不存在！" << endl;
			system("pause");
			system("cls");
			return;
		}
		if (p1->next != NULL) {
			p3 = p1->next;
			p1 = new duList;
			p2->next = p1;
			p1->front = p2;
			p1->data = insertData;
			p1->next = p3;
			p3->front = p1;
			cout << "数据插入成功!" << endl;
			system("pause");
			system("cls");
		}
		else if (p1->next == NULL) {			//插入表尾
			p3 = new duList;
			p3->front = p1;
			p3->data = insertData;
			p3->next = NULL;
			p1->next = p3;
			cout << "数据插入成功!" << endl;
			system("pause");
			system("cls");
		}
	
}
void destroyList() {
	duList* p1;
	p1 = head;
	while (p1 != NULL) {
		head = head->next;
		free(p1);
		p1 = head;
	}
	head = NULL;
	free(p1);
	cout << "链表销毁成功！" << endl;
	system("pause");
	system("cls");
}
void deleteList() {
	string deleteData;
	cout << "请输入您要删除的数据：" << endl;
	cin >> deleteData;
	duList* p1, * p2;
	p1 = p2 = head;
	if (head == NULL) {
		cout << "当前链表为空，请先创建链表" << endl;
		system("pause");
		system("cls");
		return;
	}
	if (head->data == deleteData) {
		head = p1->next;
		head->front = NULL;
		free(p2);
		cout << "删除成功！" << endl;
		system("pause");
		system("cls");
		return;
	}
	while (true) {
		if (p1->data == deleteData) {

			if (p1->next != NULL) {
				p1 = p1->next;
				p1->front = p2;
				p2->next = p1;
			}
			else {
				p2->next = NULL;
			}
			cout << "删除成功！" << endl;
			system("pause");
			system("cls");
			break;
		}
		else {
			p2 = p1;
			p1 = p1->next;
			p1->front = p2;
		}
		if (p1 == NULL) {
			cout << "该数据不存在！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	system("cls");
}
void printList() {
	if (head == NULL) {
		cout << "当前链表为空。" << endl;
		system("pause");
		system("cls");
		return;
	}
	duList* p1 = head;
	duList* p2 = p1;
	do {
		cout << p1->data << '\t';
		p2 = p1;
		p1 = p1->next;
		
	} while (p1 != NULL);
	system("pause");
	system("cls");
}