#include"calculator.h"
#include<iomanip>
int main()
{
	char infix[100] ;
	char postfix[100];
	int n = 3;
	while (true) 
	{
		n = 3;
		cout << "��������׺���ʽ:" << endl;
		fgets(infix, 100, stdin);
		cout << "��������Ҫ����С������λ��:(Ĭ��Ϊ3)" << endl;
		cin >> n;
		if (n < 0)
		{
			cout << "������������������!" << endl;
			system("pause");
			system("cls");
			continue;
		}
		transmit(infix, postfix);
		cout << setiosflags(ios::fixed) << setprecision(n) << Calculate(postfix) << endl;
		getchar();
		system("pause");
		system("cls");
	}
	return 0;
}