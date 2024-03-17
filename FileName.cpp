#include<iostream>
using namespace std;
void showMenu()
{
	cout << "������ָ��:" << endl;
	cout << "1:���ɿ�����" << endl;
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
singleList* creat() {
	singleList* head;
	//singleList* p1;
	//singleList* p2;
	//p1 = p2 = new singleList;
	//head = p1;
	head = new singleList;
	head->next = NULL;
	cout << "���������ɹ���" << endl;
	return (head);
}

void addList(singleList* head) {
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
}
singleList* findData(singleList* head, string data) {
	singleList* p1;
	singleList* p2;
	p1 = p1 = head;
	while (true) {
		if (head == NULL) {
			cout << "��ֵ�����ڡ�" << endl;
			return 0;
		}
		if (p1->data == data) {
			cout << "��ֵ���ڡ�" << endl;
			return p1;
		}
		else {
			p2 = p1;
			p1 = p1->next;
		}
		if (p1 == NULL) {                       //����ȫ�������Ҳ���data
			cout << "��ֵ������" << endl;
			return 0;
		}
	}
}

void insertList(singleList* head) {
	if (head == NULL) {
		cout << "��ǰ����Ϊ�գ������������";
		return;
	}
	cout << "��������Ҫ���������";
	string insertData, oriData;
	cin >> insertData;
	cout << "����������Ҫ���뵽�ĸ�����֮��:";
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
	cout << "���ݲ���ɹ�!" << endl;
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
	cout << "�������ٳɹ���" << endl;
	system("pause");
	system("cls");
}
void deleteList(singleList* head) {
	string deleteData;
	cout << "��������Ҫɾ�������ݣ�" << endl;
	cin >> deleteData;
	singleList* p1, * p2;
	p1 = p2 = head;
	if (head == NULL) {
		cout << "��ǰ����Ϊ�գ����ȴ�������" << endl;
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
			cout << "�����ݴ��ڣ�" << endl;
			break;
		}
	}
	system("pause");
	system("cls");
}
void printList(singleList* head) {
	if (head == NULL) {
		cout << "��ǰ����Ϊ�ա�" << endl;
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
			system("cls");						        //��������
			break;
		case 2:addList(head);							//���
			break;
		case 3:printList(head);							//��ӡ
			break;
		case 4:findData(head);							//����
			break;
		case 5:deleteList(head);						//ɾ��
			break;
		case 6:destroyList(head);				        //����
			break;
		case 7:	insertList(head);						//����
			cout << "test3" << endl;
			break;
		default:cout << "�������������������룡" << endl;;
			break;
		}
	}

	system("pause");
	return 0;
}