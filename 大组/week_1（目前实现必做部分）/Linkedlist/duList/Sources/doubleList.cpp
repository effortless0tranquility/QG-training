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
			system("cls");						        //��������
			break;
		case 2:BaAddList();							//���
			break;
		case 3:FrAddList();							//���
			break;
		case 4:printList();							//��ӡ
			break;
		case 5:findData();							//����
			break;
		case 6:deleteList();						//ɾ��
			break;
		case 7:destroyList();				        //����
			break;
		case 8:	insertList();						//����
			break;
		default:
			cout << "�������������������룡" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");

	return 0;
}