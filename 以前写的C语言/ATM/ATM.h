#pragma once
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include<Windows.h>
#include<ctime>
#include <conio.h>
#include"class.h"
#include"data.h"
using namespace std;
int ATM::depositcount = 0;
int ATM::creditcount = 0;

void ATM::withdraw_ATM()
{
	int ss;
	cout << "������ȡ���" << endl;
	cin >> ss;
	int s = 0;
	if (ss > sum(s))
	{
		cout << "����" << endl;
	}
	else
	{
		sum(-ss);
	}
	system("pause");
}
void ATM::deposit_ATM()
{
	int m;
	cout << "��������ATM�����" << endl;
	cin >> m;
	sum(m);
}
void ATM::choice()
{
	int s;
	cout << "����ѡ����ݣ�����Ա��0��/�û���1��" << endl;
	cin >> s;
		if (s == 0)
		{
			staffload();
		}
		if (s == 1)
		{
			menu();
		}
		

}
void ATM::modify(int a)
{
	string changepassword0;
	int qte;
	cout << "<<��ѡ����Ҫ���и��ĵ���Ϣ:>>" << endl;
	cout << "1.������Ϣ" << endl;
	cout << "2.����" << endl;
	cout << "3.���붪ʧ" << endl;
	cin >> qte;
	if (a == 0)
	{
		if (qte == 1)
		{
			cout << "����������ԭ������:" << endl;
			cin >> changepassword0;
			for (int i = 0; i < depositcount; i++)
			{
				
				if (changepassword0 == deposit[i]->password )
				{
					cout << "�������µ��������Ա����֤����ַ���ֻ���:" << endl;
					cin >> deposit[i]->name >> deposit[i]->sex >> deposit[i]->shenfen >> deposit[i]->address >> deposit[i]->tele;
				}
			}
			
		}

		if (qte == 2)
		{
			cout << "����������ԭ������:" << endl;
			cin >> changepassword0;
			for (int i = 0; i < depositcount; i++)
			{
				if (deposit[i]->password == changepassword0)
				{
					cout << "�������µ�����" << endl;
					cin >> deposit[i]->password;
				}
			}
			
		}
		if (qte == 3)
			cout << "<<����ϵ���й�����Ա���������޸�";//�������Ա����202001������������
	}
	dsave();
	if (a == 1)
	{
		if (qte == 1)
		{
			cout << "����������ԭ������:" << endl;
			cin >> changepassword0;
			for (int i = 0; i < creditcount; i++)
			{
				if (credit[i]->password == changepassword0)
				{
					cout << "�������µ��������Ա����֤����ַ���ֻ���:" << endl;
					cin >> credit[i]->name >> credit[i]->sex >> credit[i]->shenfen >> credit[i]->address >> credit[i]->tele;
				}
			}
			
		}

		if (qte == 2)
		{
			cout << "����������ԭ������:" << endl;
			cin >> changepassword0;
			int flag = 1;
			for (int i = 0; i < creditcount; i++)
			{
				if (credit[i]->password == changepassword0)
				{
					cout << "�������µ�����" << endl;
					cin >> credit[i]->password;
				}
			}
			
		}
		if (qte == 3)
			cout << "<<����ϵ���й�����Ա���������޸�" << endl;
	}
	dsave();
	cout << "�밴�����������" << endl;
	cin.get();

}
double ATM::sum(double m)
{
	s += m;
	return s;
}
void ATM::delaccount()     //����
{
	int n, i = 0, j, k, flag = 1;
	string id, p;
	cout << "�������(0)/���ÿ�����(1)" << endl;
	cin >> n;
	if (n == 0)
	{
		while (flag)
		{
			cout << "��������Ҫ�����Ŀ��ţ�" << endl;
			cin >> id;
			for (i = 0; i < depositcount; i++)
			{
				if (id == deposit[i]->getid())
				{
					j = i;
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
		while (1)
    	{

			cout << "����������:" << endl;

			p = inputpassword();

			if (p != deposit[j]->getp())

			{

				cout << "�������,���������룡" << endl;

				p = inputpassword();

			}

			else

				break;

		}
		delete deposit[j];
		for (k = j; k < depositcount; k++) //���б�ɾ�ź���������´洢
		{deposit[k] = deposit[k + 1];}
	    deposit[depositcount - 1] = NULL;
		depositcount--; //�˺������Լ�һ��
		cout << "����˻��Ѿ���ע��!" << endl << endl;
		dsave();
		cin.get();
	}
	if (n == 1)
	{

		double a;
		while (flag)
		{

			cout << "��������Ҫ�����Ŀ��ţ�" << endl;
			cin >> id;
			for (i = 0; i < creditcount; i++)
			{
				if (id == credit[i]->getid())
				{
					j = i;
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
		while (1)

		{

			cout << "����������:" << endl;

			p = inputpassword();

			if (p != credit[j]->getp())

			{

				cout << "�������,���������룡" << endl;

				p = inputpassword();

			}

			else

				break;

		}
		while (credit[j]->touzhi < 0)
		{

			cout << "���Ȼ���,���Ѿ�͸֧���Ϊ��" << credit[j]->tmax-credit[j]->touzhi << endl;
			cin >> a;
			if ((credit[j]->tmax - credit[j]->touzhi) == a)
			{
					credit[j]->add(a);
					cout << "����ɹ���" << endl;
			}
			else
			{
				cout << "����������" << endl;
			}
		}
		delete credit[j];
		for (int j = i; j < creditcount; j++) //���б�ɾ�ź���������´洢
		{
			credit[j] = credit[j + 1];
		}

		credit[creditcount - 1] = NULL;

		creditcount--; //�˺������Լ�һ��

		cout << "����˻��Ѿ���ע��!" << endl << endl;

		csave();

		cin.get();

	}
	cout << endl << "�밴�����������" << endl;
	cin.get();
}
void ATM::dsave()            //����ർ������ļ�

{
	ofstream infile("deposit.txt", ios::app);//��׷�ӷ�ʽ���ļ�
	ofstream outfile("deposit.txt", ios::app);//�������ʽ���ļ�,���մ��ڴ����������

	int n = 0;
	outfile << depositcount << "  ";
	for (n = 0; n < depositcount; n++)
	{
		outfile << deposit[n]->id << "  ";//����Ϣд���ļ�
		outfile << deposit[n]->money << "  ";
	    outfile << deposit[n]->name << "  ";
		outfile << deposit[n]->password << "  ";
		outfile << deposit[n]->shenfen << "  ";
		outfile << deposit[n]->tele << "  ";
		outfile << deposit[n]->address << "  ";
		outfile << deposit[n]->sex << "  ";
	}
	outfile.close();
}
void ATM::dread()
{
	int n;
	string id, sex;
	string nam, passw, tele;
	double money;
	string shenfen;
	string address;
	ifstream infile("deposit.txt", ios::in);       //�����뷽ʽ���ļ�
	infile >> depositcount;
	if (!infile)
	{
		cerr << "Error reading, no data!" << endl;
		return;
	}
	for (n = 0; n < depositcount; n++) //ȫ������
	{
		infile >> id;
		infile >> money;
		infile >> nam;
		infile >> passw;
		infile >> shenfen;
		infile >> tele;
		infile >> address;
		infile >> sex;
		depositcard* acc = new depositcard(id, nam, sex, address, tele, shenfen, passw, money); //ÿ����һ��n����һ���ڴ�
		deposit[n] = acc; //��ֵ�׵�ַ
	}
	infile.close();
	cout << "Normal reading !" << endl;
}

void ATM::csave()              //���ÿ��ർ������ļ�

{

	ofstream infile("credit.txt", ios::app);//�������ʽ���ļ�

	ofstream outfile("credit.txt", ios::app);//�������ʽ���ļ� bankdat.dat���մ��ڴ����������

	int n = 0;

	outfile << creditcount << "  ";

	for (n = 0; n < creditcount; n++)

	{

		outfile << credit[n]->id << "  ";//����Ϣд������ļ�

		outfile << credit[n]->money << "  ";

		outfile << credit[n]->name << "  ";

		outfile << credit[n]->password << "  ";

		outfile << credit[n]->shenfen << "  ";

		outfile << credit[n]->tele << "  ";

		outfile << credit[n]->address << "  ";

		outfile << credit[n]->sex << "  ";

		outfile << credit[n]->touzhi << "  ";

		outfile << credit[n]->tmax << "  ";

	}

	outfile.close();

}

void ATM::cread()

{

	int n;

	string id, sex;

	string nam, passw, tele;

	double money, touzhi, tmax;

	string shenfen;

	string address;



	ifstream infile("credit.txt", ios::in);       //�����뷽ʽ���ļ�

	infile >> creditcount;

	if (!infile)

	{

		cerr << "Error reading, no data!" << endl;

		return;

	}



	for (n = 0; n < creditcount; n++) //ȫ������

	{

		infile >> id;

		infile >> money;

		infile >> nam;

		infile >> passw;

		infile >> shenfen;

		infile >> tele;

		infile >> address;

		infile >> sex;

		infile >> touzhi;

		infile >> tmax;

		creditcard* acc = new creditcard(id, nam, sex, address, tele, shenfen, passw, money, touzhi, tmax); //ÿ����һ��n����һ���ڴ�

		credit[n] = acc; //��ֵ�׵�ַ

	}

	infile.close();

	cout << "Normal reading !" << endl;

}
string ATM::inputpassword()
{
	string s;
	char ch;
	while ((ch = _getch()) != '\r')
	{
		s += ch;
		cout << "*";
	}
	return s;
}
bool ATM::check(string str)//������֤���Ƿ�ϸ�
{
	int len = str.length();
	if (len != 18)
	{
		return false;
	}
	else
	{
		int i;
		for (i = 0; i < 18; i++)
		{
			if (str[i] < '0' || str[i] > '9')
			{
				if (i == 17 && str[i] != 'x' && str[i] != 'X')
				{return false;}
			}
		}
	}
	return true;
}
void ATM::exitatm()
{

	cout << "��л��ʹ��ATM��ȡһ�������ӭ������" << endl;

	exit(0);

}

void ATM::menu()        //���ܲ˵�����
{
	int u;
	cout << endl << endl << endl << endl << endl;
	cout << "                                         *******************************" << endl;
	cout << "                                         *                             *" << endl;

	cout << "                                         *    ��ӭʹ��ATM��ȡһ���!      *" << endl;
	cout << "                                         *                             *" << endl;

	cout << "                                         *******************************" << endl << endl;

	cout << "                                                    �����������!          " << endl;
	_getch();
	do
	{

		system("cls");

		cout << endl << endl << endl << endl << "                        ��ѡ�������ţ�(1~6)" << endl;

		cout << "                           **********************************************************" << endl;

		cout << "                           *                                                        *" << endl;

		cout << "                           *                    1.����˻�����                    *" << endl;

		cout << "                           *                    2.����˻���¼                    *" << endl;

		cout << "                           *                    3.���ÿ��˻�����                    *" << endl;

		cout << "                           *                    4.���ÿ��˻���¼                    *" << endl;

		cout << "                           *                    5.�˻�ע��                         *" << endl;
		
		cout << "                           *                    6.�˳�                             *" << endl;

		cout << "                           *                                                      *" << endl;

		cout << "                           **********************************************************" << endl;

		cin >> u;

		while (u < 1 || u>7)
		{
			cout << "��Ϸ�����!" << endl;
			cin >> u;
		}
		system("cls");
		switch (u)
		{
		case 1:
			setdeposit();//��������˻�
			break;
		case 2:
			enterdeposit();
			break;       //�����¼
		case 3:
			setcredit();
			break;       //�������ÿ��˻�
		case 4:
			entercredit();
			break;       //���ÿ���¼
		case 5:
			delaccount();
			break;        //�˻�ע��*/
		case 6:
			exitatm();
			break;           //�˳�
		}
	}
	while (1);
	system("cls");
}
void ATM::setdeposit()     //�����˻�
{
	srand((unsigned)time(NULL));
	string i, n, a, t, s, se, p;
	double m;
	int find = 1;
	cin.get();
	cout << "������������" << endl;
	getline(cin, n);
	cout << "�������Ա�(�л�Ů)" << endl;
	cin >> se;
	cin.get();
	cout << "�������ַ��" << endl;
	getline(cin, a);
	cout << "�������ֻ��ţ�(11λ)" << endl;
	cin >> t;
	while (1)
	{
		cout << "���������֤�ţ�" << endl;
		cin >> s;
		if (!check(s))
		{
			cout << "���Ϸ�����!" << endl;
			continue;
		}
		else
			break;
	}

	while (1)

	{

		int x = 2;

		cout << "������6λ���������룺" << endl;

		p = inputpassword();

		cout << endl;

		string p1;

		cout << "�������������õ�����!" << endl;

		p1 = inputpassword();

		cout << endl;

		while (p != p1 && x != 0)

		{

			cout << "����������������룡(" << x << "�λ���)" << endl;

			p1 = inputpassword();

			x--;

			cout << endl;

		}

		if (p1 == p)

			break;

		if (x == 0)

		{

			find = 0;

			break;

		}

	}

	if (find == 0)

		return;

	cout << "����������" << endl;

	cin >> m;
	sum(m);
	while (m <= 0)

	{

		cout << "��Ϸ������" << endl;

		cin >> m;

	}

	cin.get();

	unsigned long long acc = account0 + random(1, 100) + number;

	number++;

	cout << "�����ɹ���" << endl << endl;

	cout << "�������п���Ϊ:" << acc << "   ���μ�! ���Ž����������˻���½!" << endl;

	stringstream str;

	str << acc;

	str >> i;

	deposit[depositcount] = new depositcard(i, n, se, a, t, s, p, m);                     //���½��˻������ַ����ȥ

	++depositcount;

	dsave();

	cout << "�밴���������!" << endl;

	cin.get();

	return;

}

void ATM::setcredit()     //�������ÿ��˻�

{

	srand((unsigned)time(NULL));

	string i, n, a, t, s, se, p;

	double m;

	double tou, tmax;

	int find = 1;

	cin.get();

	cout << "������������" << endl;

	getline(cin, n);

	cout << "�������Ա�(�л�Ů)" << endl;

	cin >> se;

	cin.get();

	cout << "�������ַ��" << endl;

	getline(cin, a);

	cout << "�������ֻ��ţ�(11λ)" << endl;

	cin >> t;

	while (1)

	{

		cout << "���������֤�ţ�" << endl;

		cin >> s;

		if (!check(s))

		{

			cout << "���Ϸ�����!" << endl;

			continue;

		}

		else

			break;

	}

	while (1)
	{
		int x = 2;
		cout << "������6λ���������룺" << endl;
		p = inputpassword();
		cout << endl;
		string p1;
		cout << "�������������õ�����!" << endl;
		p1 = inputpassword();
		cout << endl;
		while (p != p1)
		{
			cout << "����������������룡(" << x << "�λ���)" << endl;
			p1 = inputpassword();
			x--;
			cout << endl;
		}
		if (p1 == p)
			break;
		if (x == 0)
		{
			find = 0;
			break;
		}
	}
	if (find == 0)
		return;
	cout << "����������" << endl;
	cin >> m;
	while (m <= 0)
	{
		cout << "��Ϸ������" << endl;
		cin >> m;
		sum(m);
	}
	cout << "������͸֧��(����2000��С��10000)" << endl;
	cin >> tou;
	while (tou <= 2000 || tou > 10000)
	{
		cout << "��Ϸ����룡" << endl;
		cin >> tou;
	}
	tmax = tou;//���͸֧��ȣ�������
	cin.get();
	unsigned long long acc = account0 + random(1, 100) + number;

	number++;

	cout << "�����ɹ���" << endl << endl;

	cout << "�������п���Ϊ:" << acc << "   ���μ�! ���Ž����������˻���½!" << endl;

	stringstream str;

	str << acc;

	str >> i;

	creditcard* pt = new creditcard(i, n, se, a, t, s, p, m, tou, tmax);   //��̬����һ���˻�����
    
	credit[creditcount] = pt; 
	creditcount++;                    //���½��˻������ַ����ȥ
	csave();

	cout << "�밴���������!" << endl;

	cin.get();

}

void ATM::enterdeposit()   //�����¼
{
	dread();
	string id, p;
	int f1 = 1;
	int flag = 1, j, i = 0; int x = 2, y = 2;
	cout << "�����뿨�ţ�" << endl;
	cin >> id;
	while (flag && x != 0)
	{
		for (int i = 0; i < depositcount; i++)
		{
			if (id == deposit[i]->getid())
			{
			    flag = 0;
				j = i;
				break;
			}
		}
		if (flag == 1)
		{
			cout << "�˺Ų�����,���������룡(" << x << "�λ���)" << endl;
			cin >> id;
			x--;
		}
		if (x == 0)
			cout << "������һ���棡" << endl;
	}
	if (x == 0)
	{
		return;
	}
	while (1)
	{
		cout << "����������:" << endl;
		p = inputpassword();
		if (p != deposit[j]->getp())
		{
			cout << endl << "�������,���������룡(" << y << "�λ���)" << endl;

			p = inputpassword();
			y--;
		}
		else
			break;
		if (y == 0)
		{
			f1 = 0;
			cout << "������һ���棡" << endl;
			break;
		}
	}
	if (f1 == 0)
		return;
	int n;
	do
	{

		system("cls");

		cout << "��ѡ�������ţ�" << endl;

		cout << "**********************************************************" << endl;

		cout << "*                                                        " << endl;

		cout << "*                    1.�û���Ϣ                          " << endl;

		cout << "*                    2.���                              " << endl;

		cout << "*                    3.ȡ��                              " << endl;

		cout << "*                    4.����ѯ                           " << endl;

		cout << "*                    5.��Ϣ����                           " << endl;

		cout << "*                    6.ת��                              " << endl;
		
		cout << "*                    7.���������                         " << endl;
		
		cout << "*                    8.�޸ĸ�����Ϣ                       " << endl;
		
		cout << "*                    9.�����ϸ�����                       " << endl;

		cout << "*                                                       " << endl;

		cout << "**********************************************************" << endl;

		cin >> n;

		while (n < 1 || n>10)

		{

			cout << "��Ϸ�����!" << endl;

			cin >> n;

		}
		switch (n)
		{
		case 1:
			deposit[j]->display();    //�û���Ϣ����
			break;
		case 2:
			deposit[j]->save();
			dsave();
			break;    //�����Ǯ
		case 3:
			deposit[j]->fetch();
			dsave();
			break;    //���ȡǮ
		case 4:
			deposit[j]->querymoney();
			dsave();
			break;   //�������ѯ
		case 5:
			deposit[j]->lixi();     //��Ϣ����
			dsave();
			break;
		case 6:
			deposit[j]->Transfer(); //ת��
			dsave();
			break;
		case 7:
			deposit[j]->Living();//�����
			dsave();
			break;
		case 8:
			deposit[j]->modify(0);//�޸ĸ�����Ϣ
			dsave();
			break;
		case 9:
			return;
		}
		cin.get();
	}
	while (1);
}

void ATM::entercredit()   //���ÿ���¼

{

	//cread();

	string id, p;

	int f1 = 1;

	int flag = 1, j, i = 0; int x = 2, y = 2;

	cout << "�����뿨�ţ�" << endl;

	cin >> id;

	while (flag&& x != 0)
	{
		for (int i = 0; i < creditcount; i++)
		{
			if (id == credit[i]->getid())
			{
				flag = 0;
			    j = i;
				break;
			}
		}

		if (flag == 1)

		{

			cout << "�˺Ų�����,���������룡" << endl;

			cin >> id;

		}

	}

	while (1)

	{

		cout << "����������:" << endl;

		p = inputpassword();

		if (p != credit[j]->getp())

		{

			cout << endl << "�������,���������룡(" << y - 2 << "�λ��ᣡ" << endl;

			p = inputpassword();

			y--;

		}

		else

			break;

		if (y == 0)

		{

			f1 = 0;

			break;

		}

	}

	if (f1 == 0)

		return;

	int n;

	do

	{

		system("cls");

		cout << "��ѡ�������ţ�" << endl;

		cout << "**********************************************************" << endl;

		cout << "*                                                        *" << endl;

		cout << "*                    1.�û���Ϣ                          *" << endl;

		cout << "*                    2.���򻹿�                        *" << endl;

		cout << "*                    3.ȡ��                              *" << endl;

		cout << "*                    4.����ѯ                          *" << endl;

		cout << "*                    5.ת��                          *" << endl;

		cout << "*                    6.���������                         *" << endl;
		
		cout << "*                    7.�޸ĸ�����Ϣ                        *" << endl;
		
		cout << "*                    8.������һ����                      *" << endl;

		cout << "*                                                        *" << endl;

		cout << "**********************************************************" << endl;

		cin >> n;

		while (n < 1 || n>9)

		{

			cout << "��Ϸ�����!" << endl;

			cin >> n;

		}

		switch (n)
		{
		case 1:
			credit[j]->display();    //�û���Ϣ����
			credit[j]->show();
			break;
		case 2:
			credit[j]->save();
			csave();
			break;    //���ÿ���Ǯ
		case 3:
			credit[j]->fetch();
			csave();
			break;    //���ÿ�ȡǮ

		case 4:
			credit[j]->querymoney();
			credit[j]->show();
			csave();
			break;   //���ÿ�����ѯ
		case 5:
			credit[j]->Transfer();//ת��
			csave();
			break;
		case 6:
			credit[j]->Living();//�����
			csave();
			break;
		case 7:
			credit[j]->modify(1);//�޸ĸ�����Ϣ
			csave();
			break;
		case 8:
			return;
		}
		cin.get();
		
	}

	while (1);

}
