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
			system("cls");						        //��������
			break;
		case 2:addList();							//���
			break;
		case 3:printList();							//��ӡ
			break;
		case 4:findData();							//����
			break;
		case 5:deleteList();						//ɾ��
			break;
		case 6:destroyList();				        //����
			break;
		case 7:	insertList();						//����
			cout << "test3" << endl;
			break;
		default:cout << "�������������������룡" << endl;;
			break;
		}
	}

	system("pause");
	return 0;
}