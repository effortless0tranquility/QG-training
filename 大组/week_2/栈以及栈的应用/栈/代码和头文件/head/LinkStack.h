#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include<iostream>
using namespace std;
typedef enum Status
{
	ERROR = 0,
	SUCCESS = 1
} Status;

typedef string ElemType;

typedef  struct StackNode
{
	ElemType data;
	struct StackNode* next;
}StackNode, * LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top;
	int	count;
}LinkStack;

void showMenu() {
	cout << "��ջ" << endl;
	cout << "1:��ʼ����ջ" << endl;
	cout << "2:�����ջ�Ƿ�Ϊ��" << endl;
	cout << "3:�õ�ջ��Ԫ��" << endl;
	cout << "4:�����ջ" << endl;
	cout << "5:������ջ" << endl;
	cout << "6:�õ���ջ����" << endl;
	cout << "7:������ѹ��ջ" << endl;
	cout << "8:������ѹ��ջ" << endl;


}
//��ջ
//��ʼ��ջ
Status initLStack(LinkStack* s)
{
	Status Statu  ;
	ElemType data;
	if (s ->top!= NULL) {
		cout << "��ʼ��ʧ�ܣ������ظ���ʼ��ջ��";
		 Statu = ERROR;
		
	}
	else {
		cout << "������Ҫѹ��ջ�ĳ�ʼԪ��:" << endl;
		cin >> data;
		s->count = 1;
		s->top = new StackNode;
		s->top->data = data;
		s->top->next = NULL;
		cout << "��ʼ���ɹ���" << endl;
		 Statu = SUCCESS;
		
	}
	
	return Statu;
}
Status isEmptyLStack(LinkStack* s)//�ж�ջ�Ƿ�Ϊ��
{
	if (s->top == NULL) {
		cout << "��ǰջΪ�գ�"<<endl;
	}
	else {
		cout << "��ǰջ����ֵ" << endl;
	}
	Status Statu = SUCCESS;
	return Statu;

}
Status getTopLStack(LinkStack* s, ElemType* e)//�õ�ջ��Ԫ��
{
	 Status Statu;
	if (s->top == NULL) {
		cout << "��ǰջΪ�գ��������Ԫ�أ�" << endl;
		 Statu = ERROR;
	}
	else
	{
		*e=s->top->data;
		Statu = SUCCESS;
	}
	return Statu;
}
Status clearLStack(LinkStack* s)//���ջ
{
	StackNode* p1, * p2;
	Status Statu;
	if (s->top != NULL) {
		p1 = p2 = s->top;
		while (s->top != NULL) {
			p1 = p2 = s->top;
			s->top = s->top->next;
			s->count--;
			free(p1);
		}
		cout << "�����ջ" << endl;
		Statu = SUCCESS;
		 
	}
	else {
		cout << "��ǰջΪ�գ�" << endl;
		Statu = SUCCESS;
	}
	return Statu;

}
Status destroyLStack(LinkStack* s)//����ջ
{
	StackNode* p1, * p2;
	Status Statu;
	if (s->top != NULL) {
		p1 = p2 = s->top;
		while (s->top != NULL) {
			p1 = p2 = s->top;
			s->top = s->top->next;
			free(p1);
		}

		free(s->top);
		s->count = 0;
		cout << "ջ������" << endl;
		Statu = SUCCESS;

	}
	else {
		cout << "��ǰջΪ�գ�" << endl;
		Statu = SUCCESS;
	}
	return Statu;
}
Status LStackLength(LinkStack* s, int* length)//���ջ����
{
	*length = s->count;
	Status Statu = SUCCESS;
	return Statu;
}
Status pushLStack(LinkStack* s, ElemType data)//��ջ
{
	Status Statu;
	if (s->top == NULL) {
		cout << "������ɶ�ջ�ĳ�ʼ��������" << endl;
		Statu = ERROR;
	}
	else
	{
		StackNode* p1, * p2;
		p2 = s->top;
		p1 = new StackNode;
		p1->data = data;
		p1->next = p2;
		s->top = p1;
		s->count++;
		Statu = SUCCESS;
		cout << "������ջ�ɹ�" << endl;
	}
	return Statu;
}
Status popLStack(LinkStack* s, ElemType* data)//��ջ
{
	Status Statu;
	if (s->top == NULL) 
	{
		cout << "��ǰջΪ�գ����Ƚ�������ջ��" << endl;
		Statu = ERROR;
	}
	else
	{
		StackNode* p1;
		p1   = s->top;
		*data = p1->data;
		s->top = p1->next;
		p1->next = NULL;
		free(p1);
		cout << "���ݳ�ջ�ɹ�����" << endl;
		Statu = SUCCESS;
	}
	return Statu;
}

#endif 
