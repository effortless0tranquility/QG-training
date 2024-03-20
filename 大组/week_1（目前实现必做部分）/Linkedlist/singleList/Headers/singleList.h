#pragma once
#include<iostream>
using namespace std;
void showMenu()
{
	cout << "������ADT" << endl;
	cout << "������ָ��:" << endl;
	cout << "1:��ʼ��������" << endl;
	cout << "2:�������" << endl;
	cout << "3:�鿴��������" << endl;
	cout << "4:��������" << endl;
	cout << "5:ɾ������" << endl;
	cout << "6:������������" << endl;
	cout << "7:��������" << endl;

}
struct singleList {
	string data;
	struct singleList* next;

};
singleList* head = NULL;

singleList* creat() {
	if (head == NULL)
	{
		string data;
		head = new singleList;
		cout << "�������ʼ�������ֵ��" << endl;
		cin >> data;
		head->data = data;
		head->next = NULL;
		cout << "�������ʼ���ɹ���" << endl;
		return (head);
	}
	else {
		cout << "��������ɳ�ʼ���������ظ�������" << endl;
		
	}
}

void addList() {
	string data;
	cout << "������Ҫ��ӵ�����" << endl;
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
		while (p1 != NULL) {
			p2 = p1;
			p1 = p1->next;
		}
		p1 = new singleList;
		p1->data = data;
		p1->next = NULL;
		p2->next = p1;

	}
	cout << "��ӳɹ���" << endl;
	system("pause");
	system("cls");
}
void findData() {
	cout << "��������Ҫ���ҵ����ݣ�" << endl;
	string data;
	cin >> data;
	singleList* p1;
	singleList* p2;
	p1 = p1 = head;
	while (true) {
		if (head == NULL) {
			cout << "��ֵ�����ڡ�" << endl;
			break;
		}
		if (p1->data == data) {
			cout << "��ֵ���ڡ�" << endl;
			break;
		}
		else {
			p2 = p1;
			p1 = p1->next;
		}
		if (p1 == NULL) {                       //����ȫ�������Ҳ���data
			cout << "��ֵ������" << endl;
			break;
		}
	}
	system("pause");
	system("cls");
}
singleList* findData(string data) {
	singleList* p1;
	singleList* p2;
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
		}
		if (p1 == NULL) {                       //����ȫ�������Ҳ���data
			return 0;
		}
	}
}

void insertList() {
	if (head == NULL) {
		cout << "��ǰ����Ϊ�գ������������" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "��������Ҫ���������:";
	string insertData, oriData;
	cin >> insertData;
	cout << "����������Ҫ���뵽�ĸ�����֮��������뵽��ͷ֮ǰ������*head��:";
	cin >> oriData;
	singleList* p1;
	singleList* p2;
	singleList* p3;
	if (oriData=="*head") {				//�����ͷ
		p1 = head;
		p3 = new singleList;
		p3->data = insertData;
		p3->next = p1;
		head = p3;
		cout << "���ݲ���ɹ�!" << endl;
		system("pause");
		system("cls");
	}
	else {
		p2 = p1 = findData(oriData);
		if (p1 == NULL) {
			cout << "����������ֲ����ڣ�" << endl;
			system("pause");
			system("cls");
			return;
		}
		if (p1->next != NULL) {
			p3 = p1->next;
			p1 = new singleList;
			p2->next = p1;
			p1->data = insertData;
			p1->next = p3;
			cout << "���ݲ���ɹ�!" << endl;
			system("pause");
			system("cls");
		}
		else if (p1->next == NULL) {			//�����β
			p3 = new singleList;
			p3->data = insertData;
			p3->next = NULL;
			p1->next = p3;
			cout << "���ݲ���ɹ�!" << endl;
			system("pause");
			system("cls");
		}
	}


}
void destroyList() {
	singleList* p1;
	p1 = head;
	while (p1 != NULL) {
		head = head->next;
		free(p1);
		p1 = head;
	}
	head = NULL;
	free(p1);
	cout << "�������ٳɹ���" << endl;
	system("pause");
	system("cls");
}
void deleteList() {
	string deleteData;
	cout << "��������Ҫɾ�������ݣ�" << endl;
	cin >> deleteData;
	singleList* p1, * p2;
	p1 = p2 = head;
	if (head == NULL) {
		cout << "��ǰ����Ϊ�գ����ȴ�������" << endl;
		system("pause");
		system("cls");
		return;
	}
	if (head->data == deleteData) {
		head = p1->next;
		free(p2);
		cout << "ɾ���ɹ���" << endl;
		system("pause");
		system("cls");
		return;
	}
	while (true) {
		if (p1->data == deleteData) {

			if (p1->next != NULL) {
				p1 = p1->next;
				p2->next = p1;
			}
			else {
				p2->next = NULL;
			}
			cout << "ɾ���ɹ���" << endl;
			system("pause");
			system("cls");
			break;
		}
		else {
			p2 = p1;
			p1 = p1->next;
		}
		if (p1 == NULL) {
			cout << "�����ݲ����ڣ�" << endl;
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
		cout << "��ǰ����Ϊ�ա�" << endl;
		system("pause");
		system("cls");
		return;
	}
	singleList* p1 = head;
	do {
		cout << p1->data << '\t';
		p1 = p1->next;
	} while (p1 != NULL);
	system("pause");
	system("cls");
}