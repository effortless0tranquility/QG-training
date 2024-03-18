#include"singleList.h"
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
		case 2:addList();							//添加
			break;
		case 3:printList();							//打印
			break;
		case 4:findData();							//查找
			break;
		case 5:deleteList();						//删除
			break;
		case 6:destroyList();				        //销毁
			break;
		case 7:	insertList();						//插入
			break;
		default:cout << "输入有误，请您重新输入！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}