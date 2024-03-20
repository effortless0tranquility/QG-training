#pragma once
#include<iostream>
using namespace std;
void showMenu()
{
	cout << "˫����ADT" << endl;
	cout << "������ָ��:" << endl;
	cout << "1:��ʼ��������" << endl;
	cout << "2:��巨�������" << endl;
	cout << "3:ǰ�巨�������" << endl;
	cout << "4:�鿴��������" << endl;
	cout << "5:��������" << endl;
	cout << "6:ɾ������" << endl;
	cout << "7:������������" << endl;
	cout << "8:��������" << endl;

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
		cout << "�������ʼ�������ֵ��" << endl;
		cin >> data;
		head->data = data;
		head->next = NULL;
		head->front = NULL;
		cout << "�������ʼ���ɹ���" << endl;
		return (head);
	}
	else {
		cout << "��������ɳ�ʼ���������ظ�������" << endl;

	}
}

void BaAddList() {
	string data;
	cout << "������Ҫ��ӵ�����" << endl;
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
	cout << "��ӳɹ���" << endl;
	system("pause");
	system("cls");
}

void FrAddList() {
	string data;
	cout << "������Ҫ��ӵ�����" << endl;
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
	cout << "��ӳɹ���" << endl;
	system("pause");
	system("cls");
}
void findData() {
	cout << "��������Ҫ���ҵ����ݣ�" << endl;
	string data;
	cin >> data;
	duList* p1;
	duList* p2;
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
	cout << "����������Ҫ���뵽�ĸ�����֮��:";
	cin >> oriData;
	duList* p1;
	duList* p2;
	duList* p3;
		p2 = p1 = findData(oriData);
		if (p1 == NULL) {
			cout << "����������ֲ����ڣ�" << endl;
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
			cout << "���ݲ���ɹ�!" << endl;
			system("pause");
			system("cls");
		}
		else if (p1->next == NULL) {			//�����β
			p3 = new duList;
			p3->front = p1;
			p3->data = insertData;
			p3->next = NULL;
			p1->next = p3;
			cout << "���ݲ���ɹ�!" << endl;
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
	cout << "�������ٳɹ���" << endl;
	system("pause");
	system("cls");
}
void deleteList() {
	string deleteData;
	cout << "��������Ҫɾ�������ݣ�" << endl;
	cin >> deleteData;
	duList* p1, * p2;
	p1 = p2 = head;
	if (head == NULL) {
		cout << "��ǰ����Ϊ�գ����ȴ�������" << endl;
		system("pause");
		system("cls");
		return;
	}
	if (head->data == deleteData) {
		head = p1->next;
		head->front = NULL;
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
				p1->front = p2;
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
			p1->front = p2;
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