#include"LinkStack.h"
int main() {
	LinkStack* s = new LinkStack;
	s->top = NULL;
	s->count = 0;
	int count = 0;
	int* length = &count;
	char command ;
	ElemType ele ;
	ElemType* e ;
	e = &ele;
	ElemType data1,data2;
	ElemType* data = &data2;
	Status Statu1,Statu2;
	while (true)
	{
		showMenu();
		cin >> command;
		switch (command)
		{
		case '1':initLStack(s);
			system("pause");
			system("cls");
			break;
		case '2':isEmptyLStack(s);
			system("pause");
			system("cls");
			break;
		case '3': Statu1=getTopLStack(s, e);
			if(Statu1 == SUCCESS)
			cout << "ջ��Ԫ��Ϊ��" << ele << endl;
			system("pause");
			system("cls");
			break;
		case '4':clearLStack(s);
			system("pause");
			system("cls");
			break;
		case '5':destroyLStack(s);
			system("pause");
			system("cls");
			break;
		case '6':LStackLength(s, length);
			cout << "ջ�ĳ���Ϊ��" << *length << endl;
			system("pause");
			system("cls");
			break;
		case '7':
			cout << "������Ҫѹ��ջ������:";
			cin >> data1;
			pushLStack(s, data1);
			system("pause");
			system("cls");
			break;
		case '8':popLStack(s, data);
			cout << "��ջ������Ϊ:" << data2 << endl;
			system("pause");
			system("cls");
			break;
		default:cout << "���������������������룡" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

}