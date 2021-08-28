#pragma once
#include<iostream>
#include<Windows.h>
#include"class.h"
using namespace std;
void ATM::staffload()
{
	int k;
	string str;
	cout << "您已进入操作员模式" << endl << "请输入操作员密码：";
	cin >> str;
	if (staff.staffpassword != str)
	{
		char judge;//用来记录选择
		while (staff.staffpassword != str)//判断操作员密码是否正确
		{
			cout << "操作员密码输入错误，是否重新输入   (1)是   (2)否" << endl;//此处考虑到可能是客户不小心进入可以选择退出操作员模式
			cin >> judge;
			while (judge != '1' && judge != '2')//如果用户输入有误,提示
			{
				cout << "请重新选择是否重新输入密码  (1)是   (2)否" << endl;
			}
			if (judge == '1')//继续输入密码
			{
				cout << "请重新输入操作员密码:";
				cin >> str;//重新输入操作员密码
			}
			else
			{
				break;//结束本输入密码循环
			}
		}
	}
	if (staff.staffpassword == str)//成功登陆操作员
	{
		cout << endl << "==================================操作员登陆成功===============================" << endl;
		system("pause");

		do {
			system("cls");

			cout << endl << endl << endl << endl << "                        请选择操作序号！(1~5)" << endl;

			cout << "                           ***********************************************************" << endl;

			cout << "                           *                                                         *" << endl;

			cout << "                           *                    1.向ATM机存款                         *" << endl;

			cout << "                           *                    2.向ATM机取款                         *" << endl;

			cout << "                           *                    3.查看储蓄卡用户信息                    *" << endl;

			cout << "                           *                    4.查看信用卡用户信息                    *" << endl;

			cout << "                           *                    5.退出                                *" << endl;
			cout << "                           *                                                         *" << endl;

			cout << "                           **********************************************************" << endl;

			cin >> k;

			while (k < 1 || k>5)
			{
				cout << "请合法输入!" << endl;
				cin >> k;
			}
			string id;
			int flag = 1,  i = 0;
			switch (k)
			{
			case 1:
				deposit_ATM();
				break; //向ATM机存款 
			case 2:
				withdraw_ATM();
				break; // 向ATM机取款
			case 3:
				dread();

				cout << "请输入储蓄卡卡号：" << endl;
				cin >> id;
				while (flag != 0)
				{
					for (int i = 0; i < depositcount; i++)//遍历，查找信息
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
						cout << "账号不存在,请重新输入！" << endl;
						cin >> id;
					}
				}
				system("pause");
				break;       //退出
			case 4:
				cread();
				cout << "请输入卡号：" << endl;
				cin >> id;
				while (flag != 0)
				{
					for (int i = 0; i < creditcount; i++)
					{
						if (id == credit[i]->getid())
						{
							credit[i]->display();    //用户信息界面
							credit[i]->show();
							flag = 0;
							break;
						}
					}
					if (flag == 1)

					{

						cout << "账号不存在,请重新输入！" << endl;

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

