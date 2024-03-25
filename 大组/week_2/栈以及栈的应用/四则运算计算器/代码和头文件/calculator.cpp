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
		cout << "请输入中缀表达式:" << endl;
		fgets(infix, 100, stdin);
		cout << "请输入您要保留小数点后的位数:(默认为3)" << endl;
		cin >> n;
		if (n < 0)
		{
			cout << "输入有误请重新输入!" << endl;
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