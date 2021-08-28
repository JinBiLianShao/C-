#pragma once
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include<ctime>
#include<windows.h>
#include <conio.h>
#include"class.h"
#include"data.h"
using namespace std;
void depositcard::current()
{
	double a;
	a = 0.00009 * (input()/365);
	money += a;
}
void depositcard::Transfer()//转账
{
	system("cls");
	double a;
	int b;
	do
	{
		cout << "请输入转账金额！" << endl;
		cin >> a;
		while (a < 0)
		{
			cout << "请合法输入！" << endl;
			cin >> a;
		}
		if (money < a)
		{
			cout << "对不起，您的余额不足！" << endl;
		}
		else
		{
			money = money - a;
			string ss;
			cout << "请输入要转账的银行卡号：" << endl;
			cin >> ss;
			for (int f=1; f < depositcount; f++)
			{
				if (deposit[f]->id == ss)
				{
					deposit[f]->money += a;
				}
			}
			for (int s=1; s < creditcount; s++)
			{
				if (credit[s]->getid() == ss)
				{
					if (credit[s]->money >= 0)
					{
						credit[s]->money += a;
					}
					if((credit[s]->money==0)&&(a < (credit[s]->tmax-credit[s]->touzhi  )))
					{ 
						credit[s]->touzhi += a;
					}
					if ((credit[s]->money == 0) && (a > (credit[s]->tmax - credit[s]->touzhi)))
					{
						credit[s]->touzhi = credit[s]->tmax;
						money = (a - credit[s]->tmax + credit[s]->touzhi);
					}
				}
			}
			cout << endl << "转账成功！" << endl;
			cout << "现在余额：" << money << endl;
		}
		cout << "是否继续转账？是(0)/否(1) " << endl;
		cin >> b;
		while (b != 0 && b != 1)//选择错误时判定
		{
			cout << "请合法输入！" << endl;
			cin >> b;
		}
	}
	while (b == 0);
	cout << "请按任意键继续！" << endl;

	cin.get();
}
void depositcard::Living()
{
	system("cls");
	double a;
	int b;
	do
	{
		cout << "请输入缴纳金额！" << endl;

		cin >> a;

		while (a < 0)
		{
			cout << "请合法输入！" << endl;
			cin >> a;
		}
		if (money < a)
		{
			cout << "对不起，您的余额不足！" << endl;

		}
		else
		{
			money = money - a;
			cout << endl << "缴纳成功！" << endl;
		}

		cout << "是否继续缴纳？是(0)/否(1) " << endl;
		cin >> b;

		while (b != 0 && b != 1)//选择错误时判定
		{
			cout << "请合法输入！" << endl;
			cin >> b;
		}
	}
	while (b == 0);

	cout << "请按任意键继续！" << endl;

	cin.get();
}
void depositcard::save()     //储蓄卡存钱
{
	cin.get();
	system("cls");
	double a;
	cout << "请输入存款金额！" << endl;
	cin >> a;
	while (a <= 0)
	{
		cout << "请合法输入！" << endl;

		cin >> a;

	}
	cout << "存款成功！" << endl;
	money += a;
	sum(a);
	cout << "请按任意键继续！" << endl;
	cin.get();
}



void depositcard::fetch()    //储蓄卡取钱

{
	int f;
	cout << "你存的类型：活期（1）/死期（0）" << endl;
	cin >> f;
	if (f == 1)
	{
		current();
	}
	if (f == 0)
	{
		death();
	}
	system("cls");

	double a;

	int b;

	do

	{

		cout << "请输入取款金额！" << endl;

		cin >> a;

		while (a < 0)

		{

			cout << "请合法输入！" << endl;

			cin >> a;

		}

		if (money < a)

		{

			cout << "对不起，您的余额不足！" << endl;

		}

		else

		{

			money = money - a;
			sum(-a);
			cout << endl << "取款成功！" << endl;



		}

		cout << "是否继续取款？是(0)/否(1) " << endl;

		cin >> b;

		while (b != 0 && b != 1)//选择错误时判定
		{
			cout << "请合法输入！" << endl;
			cin >> b;
		}

	}

	while (b == 0);

	cout << "请按任意键继续！" << endl;

	cin.get();

}
void depositcard::lixi()//显示利率
{
	cout << "    死期利率表" << endl;

	cout << "(1~4月)，利率：0.001" << endl;

	cout << "(5~8月)，利率：0.0014" << endl;

	cout << "(9~12月)，利率：0.0018" << endl;

	cout << "(大于12月)，利率：0.002" << endl;

	cout << "活期利率：0.0009" << endl;

	system("pause");
}
void depositcard::death()     //储蓄卡查利息

{

	system("cls");

	double month, lixi;

	cout << "" << endl;

	cout << "              利率表" << endl;

	cout << "(1~4月)，利率：0.001" << endl;

	cout << "(5~8月)，利率：0.0014" << endl;

	cout << "(9~12月)，利率：0.0018" << endl;

	cout << "(大于12月)，利率：0.002" << endl;

	cin >> month;

	while (month <= 0)
	{
		cout << "请合法输入！" << endl;
		cin >> month;
	}

	if (month <= 4)

	{

		lixi = money * 0.001 * month;
		

	}

	else if (month <= 8)

	{

		lixi = money * 0.0014 * month;
		

	}

	else if (month <= 12)

	{

		lixi = money * 0.0018 * month;
		
	}

	else if (month > 12)
	{
		lixi = money * 0.002 * month;	
	}
	money += lixi;
	cout << "请按任意键继续！" << endl;
	cin.get();

}
