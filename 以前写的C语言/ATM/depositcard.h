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
void depositcard::Transfer()//ת��
{
	system("cls");
	double a;
	int b;
	do
	{
		cout << "������ת�˽�" << endl;
		cin >> a;
		while (a < 0)
		{
			cout << "��Ϸ����룡" << endl;
			cin >> a;
		}
		if (money < a)
		{
			cout << "�Բ����������㣡" << endl;
		}
		else
		{
			money = money - a;
			string ss;
			cout << "������Ҫת�˵����п��ţ�" << endl;
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
			cout << endl << "ת�˳ɹ���" << endl;
			cout << "������" << money << endl;
		}
		cout << "�Ƿ����ת�ˣ���(0)/��(1) " << endl;
		cin >> b;
		while (b != 0 && b != 1)//ѡ�����ʱ�ж�
		{
			cout << "��Ϸ����룡" << endl;
			cin >> b;
		}
	}
	while (b == 0);
	cout << "�밴�����������" << endl;

	cin.get();
}
void depositcard::Living()
{
	system("cls");
	double a;
	int b;
	do
	{
		cout << "��������ɽ�" << endl;

		cin >> a;

		while (a < 0)
		{
			cout << "��Ϸ����룡" << endl;
			cin >> a;
		}
		if (money < a)
		{
			cout << "�Բ����������㣡" << endl;

		}
		else
		{
			money = money - a;
			cout << endl << "���ɳɹ���" << endl;
		}

		cout << "�Ƿ�������ɣ���(0)/��(1) " << endl;
		cin >> b;

		while (b != 0 && b != 1)//ѡ�����ʱ�ж�
		{
			cout << "��Ϸ����룡" << endl;
			cin >> b;
		}
	}
	while (b == 0);

	cout << "�밴�����������" << endl;

	cin.get();
}
void depositcard::save()     //�����Ǯ
{
	cin.get();
	system("cls");
	double a;
	cout << "���������" << endl;
	cin >> a;
	while (a <= 0)
	{
		cout << "��Ϸ����룡" << endl;

		cin >> a;

	}
	cout << "���ɹ���" << endl;
	money += a;
	sum(a);
	cout << "�밴�����������" << endl;
	cin.get();
}



void depositcard::fetch()    //���ȡǮ

{
	int f;
	cout << "�������ͣ����ڣ�1��/���ڣ�0��" << endl;
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

		cout << "������ȡ���" << endl;

		cin >> a;

		while (a < 0)

		{

			cout << "��Ϸ����룡" << endl;

			cin >> a;

		}

		if (money < a)

		{

			cout << "�Բ����������㣡" << endl;

		}

		else

		{

			money = money - a;
			sum(-a);
			cout << endl << "ȡ��ɹ���" << endl;



		}

		cout << "�Ƿ����ȡ���(0)/��(1) " << endl;

		cin >> b;

		while (b != 0 && b != 1)//ѡ�����ʱ�ж�
		{
			cout << "��Ϸ����룡" << endl;
			cin >> b;
		}

	}

	while (b == 0);

	cout << "�밴�����������" << endl;

	cin.get();

}
void depositcard::lixi()//��ʾ����
{
	cout << "    �������ʱ�" << endl;

	cout << "(1~4��)�����ʣ�0.001" << endl;

	cout << "(5~8��)�����ʣ�0.0014" << endl;

	cout << "(9~12��)�����ʣ�0.0018" << endl;

	cout << "(����12��)�����ʣ�0.002" << endl;

	cout << "�������ʣ�0.0009" << endl;

	system("pause");
}
void depositcard::death()     //�������Ϣ

{

	system("cls");

	double month, lixi;

	cout << "" << endl;

	cout << "              ���ʱ�" << endl;

	cout << "(1~4��)�����ʣ�0.001" << endl;

	cout << "(5~8��)�����ʣ�0.0014" << endl;

	cout << "(9~12��)�����ʣ�0.0018" << endl;

	cout << "(����12��)�����ʣ�0.002" << endl;

	cin >> month;

	while (month <= 0)
	{
		cout << "��Ϸ����룡" << endl;
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
	cout << "�밴�����������" << endl;
	cin.get();

}
