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
	cout << "链栈" << endl;
	cout << "1:初始化链栈" << endl;
	cout << "2:检查链栈是否为空" << endl;
	cout << "3:得到栈顶元素" << endl;
	cout << "4:清空链栈" << endl;
	cout << "5:销毁链栈" << endl;
	cout << "6:得到链栈长度" << endl;
	cout << "7:将数据压入栈" << endl;
	cout << "8:将数据压出栈" << endl;


}
//链栈
//初始化栈
Status initLStack(LinkStack* s)
{
	Status Statu  ;
	ElemType data;
	if (s ->top!= NULL) {
		cout << "初始化失败，请勿重复初始化栈！";
		 Statu = ERROR;
		
	}
	else {
		cout << "请输入要压入栈的初始元素:" << endl;
		cin >> data;
		s->count = 1;
		s->top = new StackNode;
		s->top->data = data;
		s->top->next = NULL;
		cout << "初始化成功！" << endl;
		 Statu = SUCCESS;
		
	}
	
	return Statu;
}
Status isEmptyLStack(LinkStack* s)//判断栈是否为空
{
	if (s->top == NULL) {
		cout << "当前栈为空！"<<endl;
	}
	else {
		cout << "当前栈存在值" << endl;
	}
	Status Statu = SUCCESS;
	return Statu;

}
Status getTopLStack(LinkStack* s, ElemType* e)//得到栈顶元素
{
	 Status Statu;
	if (s->top == NULL) {
		cout << "当前栈为空，请先添加元素！" << endl;
		 Statu = ERROR;
	}
	else
	{
		*e=s->top->data;
		Statu = SUCCESS;
	}
	return Statu;
}
Status clearLStack(LinkStack* s)//清空栈
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
		cout << "已清空栈" << endl;
		Statu = SUCCESS;
		 
	}
	else {
		cout << "当前栈为空！" << endl;
		Statu = SUCCESS;
	}
	return Statu;

}
Status destroyLStack(LinkStack* s)//销毁栈
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
		cout << "栈已销毁" << endl;
		Statu = SUCCESS;

	}
	else {
		cout << "当前栈为空！" << endl;
		Statu = SUCCESS;
	}
	return Statu;
}
Status LStackLength(LinkStack* s, int* length)//检测栈长度
{
	*length = s->count;
	Status Statu = SUCCESS;
	return Statu;
}
Status pushLStack(LinkStack* s, ElemType data)//入栈
{
	Status Statu;
	if (s->top == NULL) {
		cout << "请先完成对栈的初始化！！！" << endl;
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
		cout << "数据入栈成功" << endl;
	}
	return Statu;
}
Status popLStack(LinkStack* s, ElemType* data)//出栈
{
	Status Statu;
	if (s->top == NULL) 
	{
		cout << "当前栈为空！请先将数据入栈！" << endl;
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
		cout << "数据出栈成功！！" << endl;
		Statu = SUCCESS;
	}
	return Statu;
}

#endif 
