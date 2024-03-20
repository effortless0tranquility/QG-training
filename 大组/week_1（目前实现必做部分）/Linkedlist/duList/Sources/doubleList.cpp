#include"doubleList.h"
int main() {
	int command = 0;

	while (true)
	{
		showMenu();
		cin >> command;
		switch (command)
		{
		case 1:head = creat();
			system("pause");
			system("cls");						        //链表生成
			break;
		case 2:BaAddList();							//添加
			break;
		case 3:FrAddList();							//添加
			break;
		case 4:printList();							//打印
			break;
		case 5:findData();							//查找
			break;
		case 6:deleteList();						//删除
			break;
		case 7:destroyList();				        //销毁
			break;
		case 8:	insertList();						//插入
			break;
		default:
			cout << "输入有误，请您重新输入！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");

	return 0;
}