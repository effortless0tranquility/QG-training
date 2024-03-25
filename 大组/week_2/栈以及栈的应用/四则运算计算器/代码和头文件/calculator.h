#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include<iostream>
using namespace std;
typedef enum Status
{
	ERROR = 0,
	SUCCESS = 1
} Status;

typedef double ElemType;

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


//��ջ
//��ʼ��ջ
Status initLStack(LinkStack* s)
{
		Status Statu;
		s->count = 0;
		s->top = new StackNode;
		Statu = SUCCESS;
	return Statu;
}
Status isEmptyLStack(LinkStack* s)//�ж�ջ�Ƿ�Ϊ��
{
	Status Statu ;
	if (s->count==0) {
		Statu = SUCCESS;
	}
	else {
		Statu = ERROR;
	}
	
	return Statu;

}
Status getTopLStack(LinkStack* s, ElemType* e)//�õ�ջ��Ԫ��
{
	Status Statu;
	if (s->top == NULL) {
		cout << "���ʽ����" << endl;
		exit(1);
		Statu = ERROR;
	}
	else
	{
		*e = s->top->data;
		Statu = SUCCESS;
	}
	return Statu;
}

Status pushLStack(LinkStack* s, ElemType data)//��ջ
{
	Status Statu;
	LinkStack* p1 = s;
	StackNode* p2;
	p2 = new StackNode;
	p2->data = data;
	p2->next = p1->top;
	s->top = p2;
	s->count++;
	Statu = SUCCESS;
	return Statu;
}
Status popLStack(LinkStack* s, ElemType* data)//��ջ
{
	Status Statu;
	if (isEmptyLStack(s) == SUCCESS)
	{
		cout << "���ʽ����" << endl;
		exit(1);
		Statu = ERROR;
	}
	else
	{
		StackNode* p1;
		p1 = s->top;
		*data = p1->data;
		s->top = p1->next;
		s->count--;
		p1->next = NULL;
		free(p1);
		//cout << "���ݳ�ջ�ɹ�����" << endl;
		Statu = SUCCESS;
	}
	return Statu;
}
bool isdigital(char num)			//�ж�������ַ��Ƿ�Ϊ����
{
	if (num == '0' || num == '1' || num == '2' || num == '3' 
	    ||num == '4' || num == '5' || num == '6' ||
		num == '7' || num == '8' || num == '9'  )
	{
		return  true;
	}
	return false;
}
int priority(char cha1)					  //�ж����ȼ�
{
	switch (cha1)
	{
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	default:
		return 0;
	}
}
bool isCharacter(char cha1)
{
	if (cha1 == '+' || cha1 == '-' || cha1 == '*' || cha1 == '/')
	{
		return true;
	}
	return false;
}
bool isNChara(char* p, char *infix)
{
	if (*p != '-')
	{
		return 0;
	}
	else if (p == infix)
	{
		return 1;
	}
	else if (*(p - 1) == '(' || isCharacter(*(p - 1)))
		return 1;

}
void transmit(char* infix, char* postfix)
{
	LinkStack* s=new LinkStack;
	initLStack(s);
	char* p1 = infix;
	char* p2 = postfix;
	while (*p1 != '\0')
	{
		if (isdigital(*p1)) 
		{
			while (isdigital(*p1) || *p1 == '.')  //����ֱ�����
			{
				*p2 = *p1;
				p1++;
				p2++;
			}
			*p2 = ' ';
			p2++;
		}
		else if (*p1 == '(')		//'('��ջ
		{
			pushLStack(s, *p1);
			p1++;
		}
		else if (*p1 == '+' || *p1 == '-' || *p1 == '*' || *p1 == '/') 
		{
			if (isNChara(p1, infix))		//0������
			{
				*p2 = '0';
				p2++;
				*p2 = ' ';
				p2++;
			}
			while(priority(*p1) <= priority(s->top->data)&&isEmptyLStack(s)==ERROR&&isCharacter(*p1))  //�������ջ  //ջ�����ȼ�������ջ�����
			{
				double data;
				double* d = &data;
				popLStack(s, d);
				*p2 = data;
				p2++;
				*p2 = ' ';
				p2++;
			}
			pushLStack(s, *p1);
			p1++;
		}
		else if (*p1 == ')')			//����������
		{
			while (s->top->data != '(' && isEmptyLStack(s) == ERROR)
			{
			
					double data;
					double* d = &data;
					popLStack(s, d);
					*p2 = data;
					p2++;
					*p2 = ' ';
					p2++;
			}
			if (isEmptyLStack(s) == ERROR && s->top->data == '(')		//����������
			{
				double data;
				double* d = &data;
				popLStack(s, d);

			}
			p1++;
		}
		else
		{
			p1++;
		}
	}
	while (isEmptyLStack(s) == ERROR)        // ��ʣ�������ȫ������
	{
		double data;
		double* d;
		d = &data;
		popLStack(s, d);
		* p2 = data;
		p2++;
		*p2 = ' ';
		p2++;
	}
	*(p2 - 1) = '\0';
}
double rule(double num1, char cha,double num2)     //�ƶ��������
{
	switch (cha)
	{
	case'+':
		return num1+num2;
	case'-':
		return num1 - num2;
	case '*':
		return num1 * num2;
	case'/':
		return num1 / num2;
	default:cout << "��������" << endl;
		exit(1);
		break;
	}
}
double Calculate(char* postfix)   //�����׺���ʽ��ֵ
{
	LinkStack* s = new LinkStack;
	initLStack(s);
	char* p;
	p = postfix;
	while (*p != '\0')
	{
		if (isdigital(*p))		//��ǰλ��Ϊ����
		{
			double num = *p - '0';      //�õ�������������
			p++;
			while (isdigital(*p) || *p == '.')  //��������Ǹ�����
			{
				if (*p == '.')
				{
					p++;
					double factor = 0.1;
					while (isdigital(*p))
					{
						num += *p * factor;
						p++;
						factor *= 0.1;
					}
					break;
				}
				else
				{
					num = num * 10 + *p - '0';
					p++;
				}
			}
			pushLStack(s, num);
		}
		else if (isCharacter(*p))		//��ǰλ��Ϊ�����
		{
			double data1, data2;
			double* d1, * d2;
			d1 = &data1;
			d2 = &data2;
			popLStack(s, d2);
			popLStack(s, d1);
			double result = rule(data1, *p, data2);
			pushLStack(s, result);
			p++;
		}
		else
		{
			p++;
		}
	}
	double getNum;
	double* g;
	g = &getNum;
	popLStack(s, g);
	return getNum;
}
#endif 