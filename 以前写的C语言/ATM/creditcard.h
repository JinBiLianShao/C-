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
	cout << "��ǰ��" << money << endl;
	cout << "͸֧��" << touzhi << endl;
	cout << "����ת�˽�" << endl;
	cin >> a;
	while (a<0 || a>b)
	{
		if (a < 0)
		{
			cout << "��Ϸ����룡" << endl;
			cin >> a;
		}
		else
		{
			cout << "ת�˽���,���������룡" << endl;
			cin >> a;
		}
	}
	
	if (a <= money)
	{
		money -= a;
		string ss;
		cout << "������Ҫת�˵����п��ţ�" << endl;
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
		cout << "ת�˳ɹ����밴�����������" << endl;
	}
	else
	{
		touzhi -= (a - money);
		money = 0;
		string ss;
		cout << "������Ҫת�˵����п��ţ�" << endl;
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
		cout << "ת�˳ɹ����밴�����������" << endl;

	}
	cin.get();
}
void creditcard::Living()
{
	double a, b;
	b = money + touzhi;
	system("cls");
	cout << "��ǰ��" << money << endl;
	cout << "͸֧��" << touzhi << endl;
	cout << "������ɽ�" << endl;
	cin >> a;
	while (a<0 || a>b)
	{
		if (a < 0)
		{
			cout << "��Ϸ����룡" << endl;
			cin >> a;
		}
		else
		{
			cout << "����,���������룡" << endl;
			cin >> a;
		}
	}
	if (a <= money)
	{
		money -= a;
		cout << "���ɳɹ����밴�����������" << endl;
	}
	else
	{
		touzhi -= (a - money);
		money = 0;
		cout << "���ɳɹ����밴�����������" << endl;

	}
	cout << "�밴�����������" << endl;

	cin.get();
}
void creditcard::show()
{
	cout << "͸֧��" << touzhi << endl;
	cout << "�밴�����������" << endl;
}



void creditcard::save()    //���ÿ���Ǯ��Ǯ
{
	double a;

	int find = 1;

	if (touzhi < tmax)//͸֧��С�����͸֧���
	{
		find = 0;
		cout << "�����Ž�Ǯ�������Ȼ���͸֧��" << endl;//
		cin >> a;
		while (a < 0)
		{
			cout << "��Ϸ����룡" << endl;
			cin >> a;
		}
		if (a < tmax - touzhi)
		{
			touzhi += a;
			cout << "����ǰֻ����һ���֣�" << endl;
		}

		else if (a >= tmax - touzhi)
		{

			a -= (tmax - touzhi);

			cout << "���Ѿ���ɻ��" << endl;

			money += a;

			cout << "��ǰ���Ϊ��" << money << endl;

			cout << "��͸֧���Ϊ��" << tmax << endl;

		}

	}

	if (touzhi == tmax && find == 1)

	{

		cout << "�����Ž�Ǯ��" << endl;

		cin >> a;

		while (a < 0)

		{

			cout << "��Ϸ����룡" << endl;

			cin >> a;

		}

		money += a;
		sum(a);
		cout << "��ǰ���Ϊ��" << money << endl;

	}

	cout << "�밴�����������" << endl;

	cin.get();

}

void creditcard::fetch()   //���ÿ�ȡǮ
{
	double a, b;
	b = money + touzhi;
	system("cls");
	cout << "��ǰ��" << money << endl;
	cout << "͸֧��" << touzhi << endl;
	cout << "����ȡ���" << endl;
	cin >> a;
	while (a<0 || a>b)
	{
		if (a < 0)
		{
			cout << "��Ϸ����룡" << endl;
			cin >> a;
		}
		else
		{
		cout << "ȡ�����,���������룡" << endl;
			cin >> a;
		}
	}
	if (a <= money)
	{
		money -= a;
		sum(-a);
		cout << "ȡ��ɹ����밴�����������" << endl;
	}
	else
	{
		touzhi -= (a - money);
		sum(-a);
		money = 0;
		cout << "ȡ��ɹ����밴�����������" << endl;

	}
	cin.get();
}
void creditcard::add(double x)//��������ʹ��
{
	touzhi += x;
}
