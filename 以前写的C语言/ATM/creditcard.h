#pragma once
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include<ctime>
#include <conio.h>
#include"class.h"
using namespace std;
void creditcard::Transfer()
{
	double a, b;
	b = money + touzhi;
	system("cls");
	cout << "当前余额：" << money << endl;
	cout << "透支余额：" << touzhi << endl;
	cout << "输入转账金额！" << endl;
	cin >> a;
	while (a<0 || a>b)
	{
		if (a < 0)
		{
			cout << "请合法输入！" << endl;
			cin >> a;
		}
		else
		{
			cout << "转账金额不足,请重新输入！" << endl;
			cin >> a;
		}
	}
	
	if (a <= money)
	{
		money -= a;
		string ss;
		cout << "请输入要转账的银行卡号：" << endl;
		cin >> ss;
		for (int f = 1; f < depositcount; f++)
		{
			if (deposit[f]->getid() == ss)
			{
				deposit[f]->money += a;
			}
		}
		for (int s = 1; s < creditcount; s++)
		{
			if (credit[s]->getid() == ss)
			{
				if (credit[s]->money >= 0)
				{
					credit[s]->money += a;
				}
				if ((credit[s]->money == 0) && (a < (credit[s]->tmax - credit[s]->touzhi)))
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
		cout << "转账成功，请按任意键继续！" << endl;
	}
	else
	{
		touzhi -= (a - money);
		money = 0;
		string ss;
		cout << "请输入要转账的银行卡号：" << endl;
		cin >> ss;
		for (int f = 1; f < depositcount; f++)
		{
			if (deposit[f]->getid() == ss)
			{
				deposit[f]->money += a;
			}
		}
		for (int s = 1; s < creditcount; s++)
		{
			if (credit[s]->getid() == ss)
			{
				if (credit[s]->money >= 0)
				{
					credit[s]->money += a;
				}
				if ((credit[s]->money == 0) && (a < (credit[s]->tmax - credit[s]->touzhi)))
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
		cout << "转账成功，请按任意键继续！" << endl;

	}
	cin.get();
}
void creditcard::Living()
{
	double a, b;
	b = money + touzhi;
	system("cls");
	cout << "当前余额：" << money << endl;
	cout << "透支余额：" << touzhi << endl;
	cout << "输入缴纳金额！" << endl;
	cin >> a;
	while (a<0 || a>b)
	{
		if (a < 0)
		{
			cout << "请合法输入！" << endl;
			cin >> a;
		}
		else
		{
			cout << "金额不足,请重新输入！" << endl;
			cin >> a;
		}
	}
	if (a <= money)
	{
		money -= a;
		cout << "缴纳成功，请按任意键继续！" << endl;
	}
	else
	{
		touzhi -= (a - money);
		money = 0;
		cout << "缴纳成功，请按任意键继续！" << endl;

	}
	cout << "请按任意键继续！" << endl;

	cin.get();
}
void creditcard::show()
{
	cout << "透支余额：" << touzhi << endl;
	cout << "请按任意键继续！" << endl;
}



void creditcard::save()    //信用卡存钱或还钱
{
	double a;

	int find = 1;

	if (touzhi < tmax)//透支的小于最大透支额度
	{
		find = 0;
		cout << "输入存放金钱，但请先还款透支金额！" << endl;//
		cin >> a;
		while (a < 0)
		{
			cout << "请合法输入！" << endl;
			cin >> a;
		}
		if (a < tmax - touzhi)
		{
			touzhi += a;
			cout << "您当前只还款一部分！" << endl;
		}

		else if (a >= tmax - touzhi)
		{

			a -= (tmax - touzhi);

			cout << "您已经完成还款！" << endl;

			money += a;

			cout << "当前余额为：" << money << endl;

			cout << "可透支余额为：" << tmax << endl;

		}

	}

	if (touzhi == tmax && find == 1)

	{

		cout << "输入存放金钱！" << endl;

		cin >> a;

		while (a < 0)

		{

			cout << "请合法输入！" << endl;

			cin >> a;

		}

		money += a;
		sum(a);
		cout << "当前余额为：" << money << endl;

	}

	cout << "请按任意键继续！" << endl;

	cin.get();

}

void creditcard::fetch()   //信用卡取钱
{
	double a, b;
	b = money + touzhi;
	system("cls");
	cout << "当前余额：" << money << endl;
	cout << "透支余额：" << touzhi << endl;
	cout << "输入取款金额！" << endl;
	cin >> a;
	while (a<0 || a>b)
	{
		if (a < 0)
		{
			cout << "请合法输入！" << endl;
			cin >> a;
		}
		else
		{
		cout << "取款金额不足,请重新输入！" << endl;
			cin >> a;
		}
	}
	if (a <= money)
	{
		money -= a;
		sum(-a);
		cout << "取款成功，请按任意键继续！" << endl;
	}
	else
	{
		touzhi -= (a - money);
		sum(-a);
		money = 0;
		cout << "取款成功，请按任意键继续！" << endl;

	}
	cin.get();
}
void creditcard::add(double x)//销户里面使用
{
	touzhi += x;
}
