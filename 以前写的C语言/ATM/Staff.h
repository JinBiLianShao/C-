#pragma once
#include<iostream>
#include<Windows.h>
#include"class.h"
using namespace std;
void ATM::staffload()
{
	int k;
	string str;
	cout << "���ѽ������Աģʽ" << endl << "���������Ա���룺";
	cin >> str;
	if (staff.staffpassword != str)
	{
		char judge;//������¼ѡ��
		while (staff.staffpassword != str)//�жϲ���Ա�����Ƿ���ȷ
		{
			cout << "����Ա������������Ƿ���������   (1)��   (2)��" << endl;//�˴����ǵ������ǿͻ���С�Ľ������ѡ���˳�����Աģʽ
			cin >> judge;
			while (judge != '1' && judge != '2')//����û���������,��ʾ
			{
				cout << "������ѡ���Ƿ�������������  (1)��   (2)��" << endl;
			}
			if (judge == '1')//������������
			{
				cout << "�������������Ա����:";
				cin >> str;//�����������Ա����
			}
			else
			{
				break;//��������������ѭ��
			}
		}
	}
	if (staff.staffpassword == str)//�ɹ���½����Ա
	{
		cout << endl << "==================================����Ա��½�ɹ�===============================" << endl;
		system("pause");

		do {
			system("cls");

			cout << endl << endl << endl << endl << "                        ��ѡ�������ţ�(1~5)" << endl;

			cout << "                           ***********************************************************" << endl;

			cout << "                           *                                                         *" << endl;

			cout << "                           *                    1.��ATM�����                         *" << endl;

			cout << "                           *                    2.��ATM��ȡ��                         *" << endl;

			cout << "                           *                    3.�鿴����û���Ϣ                    *" << endl;

			cout << "                           *                    4.�鿴���ÿ��û���Ϣ                    *" << endl;

			cout << "                           *                    5.�˳�                                *" << endl;
			cout << "                           *                                                         *" << endl;

			cout << "                           **********************************************************" << endl;

			cin >> k;

			while (k < 1 || k>5)
			{
				cout << "��Ϸ�����!" << endl;
				cin >> k;
			}
			string id;
			int flag = 1,  i = 0;
			switch (k)
			{
			case 1:
				deposit_ATM();
				break; //��ATM����� 
			case 2:
				withdraw_ATM();
				break; // ��ATM��ȡ��
			case 3:
				dread();

				cout << "�����봢����ţ�" << endl;
				cin >> id;
				while (flag != 0)
				{
					for (int i = 0; i < depositcount; i++)//������������Ϣ
					{
						if (id == deposit[i]->getid())
						{
							deposit[i]->display();
							flag = 0;
							break;
						}
					}
					if (flag == 1)
					{
						cout << "�˺Ų�����,���������룡" << endl;
						cin >> id;
					}
				}
				system("pause");
				break;       //�˳�
			case 4:
				cread();
				cout << "�����뿨�ţ�" << endl;
				cin >> id;
				while (flag != 0)
				{
					for (int i = 0; i < creditcount; i++)
					{
						if (id == credit[i]->getid())
						{
							credit[i]->display();    //�û���Ϣ����
							credit[i]->show();
							flag = 0;
							break;
						}
					}
					if (flag == 1)

					{

						cout << "�˺Ų�����,���������룡" << endl;

						cin >> id;

					}

				}
				system("pause");
				break;
			case 5:
				return;
				break;

			}
		} 
		while (1);
	}
	system("cls");
}

