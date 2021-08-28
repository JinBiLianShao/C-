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
	cout << "请输入取款金额：" << endl;
	cin >> ss;
	int s = 0;
	if (ss > sum(s))
	{
		cout << "超额" << endl;
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
	cout << "请输入向ATM存款数" << endl;
	cin >> m;
	sum(m);
}
void ATM::choice()
{
	int s;
	cout << "请你选择身份：操作员（0）/用户（1）" << endl;
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
	cout << "<<请选择您要进行更改的信息:>>" << endl;
	cout << "1.基本信息" << endl;
	cout << "2.密码" << endl;
	cout << "3.密码丢失" << endl;
	cin >> qte;
	if (a == 0)
	{
		if (qte == 1)
		{
			cout << "请输入您的原有密码:" << endl;
			cin >> changepassword0;
			for (int i = 0; i < depositcount; i++)
			{
				
				if (changepassword0 == deposit[i]->password )
				{
					cout << "请输入新的姓名，性别，身份证，地址，手机号:" << endl;
					cin >> deposit[i]->name >> deposit[i]->sex >> deposit[i]->shenfen >> deposit[i]->address >> deposit[i]->tele;
				}
			}
			
		}

		if (qte == 2)
		{
			cout << "请输入您的原有密码:" << endl;
			cin >> changepassword0;
			for (int i = 0; i < depositcount; i++)
			{
				if (deposit[i]->password == changepassword0)
				{
					cout << "请输入新的密码" << endl;
					cin >> deposit[i]->password;
				}
			}
			
		}
		if (qte == 3)
			cout << "<<请联系银行工作人员进行密码修改";//输入管理员密码202001进行密码重设
	}
	dsave();
	if (a == 1)
	{
		if (qte == 1)
		{
			cout << "请输入您的原有密码:" << endl;
			cin >> changepassword0;
			for (int i = 0; i < creditcount; i++)
			{
				if (credit[i]->password == changepassword0)
				{
					cout << "请输入新的姓名，性别，身份证，地址，手机号:" << endl;
					cin >> credit[i]->name >> credit[i]->sex >> credit[i]->shenfen >> credit[i]->address >> credit[i]->tele;
				}
			}
			
		}

		if (qte == 2)
		{
			cout << "请输入您的原有密码:" << endl;
			cin >> changepassword0;
			int flag = 1;
			for (int i = 0; i < creditcount; i++)
			{
				if (credit[i]->password == changepassword0)
				{
					cout << "请输入新的密码" << endl;
					cin >> credit[i]->password;
				}
			}
			
		}
		if (qte == 3)
			cout << "<<请联系银行工作人员进行密码修改" << endl;
	}
	dsave();
	cout << "请按任意键继续！" << endl;
	cin.get();

}
double ATM::sum(double m)
{
	s += m;
	return s;
}
void ATM::delaccount()     //销户
{
	int n, i = 0, j, k, flag = 1;
	string id, p;
	cout << "储蓄卡销户(0)/信用卡销户(1)" << endl;
	cin >> n;
	if (n == 0)
	{
		while (flag)
		{
			cout << "请输入你要销户的卡号：" << endl;
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
				cout << "账号不存在,请重新输入！" << endl;
				cin >> id;
			}
		}
		while (1)
    	{

			cout << "请输入密码:" << endl;

			p = inputpassword();

			if (p != deposit[j]->getp())

			{

				cout << "密码错误,请重新输入！" << endl;

				p = inputpassword();

			}

			else

				break;

		}
		delete deposit[j];
		for (k = j; k < depositcount; k++) //所有被删号后的数据重新存储
		{deposit[k] = deposit[k + 1];}
	    deposit[depositcount - 1] = NULL;
		depositcount--; //账号总数自减一次
		cout << "你的账户已经被注销!" << endl << endl;
		dsave();
		cin.get();
	}
	if (n == 1)
	{

		double a;
		while (flag)
		{

			cout << "请输入你要销户的卡号：" << endl;
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
				cout << "账号不存在,请重新输入！" << endl;
				cin >> id;
			}
		}
		while (1)

		{

			cout << "请输入密码:" << endl;

			p = inputpassword();

			if (p != credit[j]->getp())

			{

				cout << "密码错误,请重新输入！" << endl;

				p = inputpassword();

			}

			else

				break;

		}
		while (credit[j]->touzhi < 0)
		{

			cout << "请先还款,您已经透支金额为：" << credit[j]->tmax-credit[j]->touzhi << endl;
			cin >> a;
			if ((credit[j]->tmax - credit[j]->touzhi) == a)
			{
					credit[j]->add(a);
					cout << "还款成功！" << endl;
			}
			else
			{
				cout << "请重新输入" << endl;
			}
		}
		delete credit[j];
		for (int j = i; j < creditcount; j++) //所有被删号后的数据重新存储
		{
			credit[j] = credit[j + 1];
		}

		credit[creditcount - 1] = NULL;

		creditcount--; //账号总数自减一次

		cout << "你的账户已经被注销!" << endl << endl;

		csave();

		cin.get();

	}
	cout << endl << "请按任意键继续！" << endl;
	cin.get();
}
void ATM::dsave()            //储蓄卡类导入磁盘文件

{
	ofstream infile("deposit.txt", ios::app);//以追加方式打开文件
	ofstream outfile("deposit.txt", ios::app);//以输出方式打开文件,接收从内存输出的数据

	int n = 0;
	outfile << depositcount << "  ";
	for (n = 0; n < depositcount; n++)
	{
		outfile << deposit[n]->id << "  ";//把信息写入文件
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
	ifstream infile("deposit.txt", ios::in);       //以输入方式打开文件
	infile >> depositcount;
	if (!infile)
	{
		cerr << "Error reading, no data!" << endl;
		return;
	}
	for (n = 0; n < depositcount; n++) //全部读入
	{
		infile >> id;
		infile >> money;
		infile >> nam;
		infile >> passw;
		infile >> shenfen;
		infile >> tele;
		infile >> address;
		infile >> sex;
		depositcard* acc = new depositcard(id, nam, sex, address, tele, shenfen, passw, money); //每读入一个n开辟一段内存
		deposit[n] = acc; //赋值首地址
	}
	infile.close();
	cout << "Normal reading !" << endl;
}

void ATM::csave()              //信用卡类导入磁盘文件

{

	ofstream infile("credit.txt", ios::app);//以输出方式打开文件

	ofstream outfile("credit.txt", ios::app);//以输出方式打开文件 bankdat.dat接收从内存输出的数据

	int n = 0;

	outfile << creditcount << "  ";

	for (n = 0; n < creditcount; n++)

	{

		outfile << credit[n]->id << "  ";//把信息写入磁盘文件

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



	ifstream infile("credit.txt", ios::in);       //以输入方式打开文件

	infile >> creditcount;

	if (!infile)

	{

		cerr << "Error reading, no data!" << endl;

		return;

	}



	for (n = 0; n < creditcount; n++) //全部读入

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

		creditcard* acc = new creditcard(id, nam, sex, address, tele, shenfen, passw, money, touzhi, tmax); //每读入一个n开辟一段内存

		credit[n] = acc; //赋值首地址

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
bool ATM::check(string str)//检查身份证号是否合格
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

	cout << "感谢您使用ATM存取一体机，欢迎再来！" << endl;

	exit(0);

}

void ATM::menu()        //功能菜单函数
{
	int u;
	cout << endl << endl << endl << endl << endl;
	cout << "                                         *******************************" << endl;
	cout << "                                         *                             *" << endl;

	cout << "                                         *    欢迎使用ATM存取一体机!      *" << endl;
	cout << "                                         *                             *" << endl;

	cout << "                                         *******************************" << endl << endl;

	cout << "                                                    按任意键继续!          " << endl;
	_getch();
	do
	{

		system("cls");

		cout << endl << endl << endl << endl << "                        请选择操作序号！(1~6)" << endl;

		cout << "                           **********************************************************" << endl;

		cout << "                           *                                                        *" << endl;

		cout << "                           *                    1.储蓄卡账户创建                    *" << endl;

		cout << "                           *                    2.储蓄卡账户登录                    *" << endl;

		cout << "                           *                    3.信用卡账户创建                    *" << endl;

		cout << "                           *                    4.信用卡账户登录                    *" << endl;

		cout << "                           *                    5.账户注销                         *" << endl;
		
		cout << "                           *                    6.退出                             *" << endl;

		cout << "                           *                                                      *" << endl;

		cout << "                           **********************************************************" << endl;

		cin >> u;

		while (u < 1 || u>7)
		{
			cout << "请合法输入!" << endl;
			cin >> u;
		}
		system("cls");
		switch (u)
		{
		case 1:
			setdeposit();//创建储蓄卡账户
			break;
		case 2:
			enterdeposit();
			break;       //储蓄卡登录
		case 3:
			setcredit();
			break;       //创建信用卡账户
		case 4:
			entercredit();
			break;       //信用卡登录
		case 5:
			delaccount();
			break;        //账户注销*/
		case 6:
			exitatm();
			break;           //退出
		}
	}
	while (1);
	system("cls");
}
void ATM::setdeposit()     //创建账户
{
	srand((unsigned)time(NULL));
	string i, n, a, t, s, se, p;
	double m;
	int find = 1;
	cin.get();
	cout << "请输入姓名：" << endl;
	getline(cin, n);
	cout << "请输入性别：(男或女)" << endl;
	cin >> se;
	cin.get();
	cout << "请输入地址：" << endl;
	getline(cin, a);
	cout << "请输入手机号：(11位)" << endl;
	cin >> t;
	while (1)
	{
		cout << "请输入身份证号：" << endl;
		cin >> s;
		if (!check(s))
		{
			cout << "不合法输入!" << endl;
			continue;
		}
		else
			break;
	}

	while (1)

	{

		int x = 2;

		cout << "请输入6位纯数字密码：" << endl;

		p = inputpassword();

		cout << endl;

		string p1;

		cout << "请在输入您设置的密码!" << endl;

		p1 = inputpassword();

		cout << endl;

		while (p != p1 && x != 0)

		{

			cout << "输入错误，请重新输入！(" << x << "次机会)" << endl;

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

	cout << "请输入存入金额：" << endl;

	cin >> m;
	sum(m);
	while (m <= 0)

	{

		cout << "请合法输入金额：" << endl;

		cin >> m;

	}

	cin.get();

	unsigned long long acc = account0 + random(1, 100) + number;

	number++;

	cout << "开户成功！" << endl << endl;

	cout << "您的银行卡号为:" << acc << "   请牢记! 卡号将用于您的账户登陆!" << endl;

	stringstream str;

	str << acc;

	str >> i;

	deposit[depositcount] = new depositcard(i, n, se, a, t, s, p, m);                     //把新建账户对象地址传过去

	++depositcount;

	dsave();

	cout << "请按任意键继续!" << endl;

	cin.get();

	return;

}

void ATM::setcredit()     //创建信用卡账户

{

	srand((unsigned)time(NULL));

	string i, n, a, t, s, se, p;

	double m;

	double tou, tmax;

	int find = 1;

	cin.get();

	cout << "请输入姓名：" << endl;

	getline(cin, n);

	cout << "请输入性别：(男或女)" << endl;

	cin >> se;

	cin.get();

	cout << "请输入地址：" << endl;

	getline(cin, a);

	cout << "请输入手机号：(11位)" << endl;

	cin >> t;

	while (1)

	{

		cout << "请输入身份证号：" << endl;

		cin >> s;

		if (!check(s))

		{

			cout << "不合法输入!" << endl;

			continue;

		}

		else

			break;

	}

	while (1)
	{
		int x = 2;
		cout << "请输入6位纯数字密码：" << endl;
		p = inputpassword();
		cout << endl;
		string p1;
		cout << "请在输入您设置的密码!" << endl;
		p1 = inputpassword();
		cout << endl;
		while (p != p1)
		{
			cout << "输入错误，请重新输入！(" << x << "次机会)" << endl;
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
	cout << "请输入存入金额：" << endl;
	cin >> m;
	while (m <= 0)
	{
		cout << "请合法输入金额：" << endl;
		cin >> m;
		sum(m);
	}
	cout << "请输入透支金额！(大于2000，小于10000)" << endl;
	cin >> tou;
	while (tou <= 2000 || tou > 10000)
	{
		cout << "请合法输入！" << endl;
		cin >> tou;
	}
	tmax = tou;//最大透支额度（正数）
	cin.get();
	unsigned long long acc = account0 + random(1, 100) + number;

	number++;

	cout << "开户成功！" << endl << endl;

	cout << "您的银行卡号为:" << acc << "   请牢记! 卡号将用于您的账户登陆!" << endl;

	stringstream str;

	str << acc;

	str >> i;

	creditcard* pt = new creditcard(i, n, se, a, t, s, p, m, tou, tmax);   //动态建立一个账户对象
    
	credit[creditcount] = pt; 
	creditcount++;                    //把新建账户对象地址传过去
	csave();

	cout << "请按任意键继续!" << endl;

	cin.get();

}

void ATM::enterdeposit()   //储蓄卡登录
{
	dread();
	string id, p;
	int f1 = 1;
	int flag = 1, j, i = 0; int x = 2, y = 2;
	cout << "请输入卡号：" << endl;
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
			cout << "账号不存在,请重新输入！(" << x << "次机会)" << endl;
			cin >> id;
			x--;
		}
		if (x == 0)
			cout << "返回上一界面！" << endl;
	}
	if (x == 0)
	{
		return;
	}
	while (1)
	{
		cout << "请输入密码:" << endl;
		p = inputpassword();
		if (p != deposit[j]->getp())
		{
			cout << endl << "密码错误,请重新输入！(" << y << "次机会)" << endl;

			p = inputpassword();
			y--;
		}
		else
			break;
		if (y == 0)
		{
			f1 = 0;
			cout << "返回上一界面！" << endl;
			break;
		}
	}
	if (f1 == 0)
		return;
	int n;
	do
	{

		system("cls");

		cout << "请选择操作序号！" << endl;

		cout << "**********************************************************" << endl;

		cout << "*                                                        " << endl;

		cout << "*                    1.用户信息                          " << endl;

		cout << "*                    2.存款                              " << endl;

		cout << "*                    3.取款                              " << endl;

		cout << "*                    4.余额查询                           " << endl;

		cout << "*                    5.利息计算                           " << endl;

		cout << "*                    6.转账                              " << endl;
		
		cout << "*                    7.缴纳生活费                         " << endl;
		
		cout << "*                    8.修改个人信息                       " << endl;
		
		cout << "*                    9.返回上个界面                       " << endl;

		cout << "*                                                       " << endl;

		cout << "**********************************************************" << endl;

		cin >> n;

		while (n < 1 || n>10)

		{

			cout << "请合法输入!" << endl;

			cin >> n;

		}
		switch (n)
		{
		case 1:
			deposit[j]->display();    //用户信息界面
			break;
		case 2:
			deposit[j]->save();
			dsave();
			break;    //储蓄卡存钱
		case 3:
			deposit[j]->fetch();
			dsave();
			break;    //储蓄卡取钱
		case 4:
			deposit[j]->querymoney();
			dsave();
			break;   //储蓄卡余额查询
		case 5:
			deposit[j]->lixi();     //利息计算
			dsave();
			break;
		case 6:
			deposit[j]->Transfer(); //转账
			dsave();
			break;
		case 7:
			deposit[j]->Living();//生活费
			dsave();
			break;
		case 8:
			deposit[j]->modify(0);//修改个人信息
			dsave();
			break;
		case 9:
			return;
		}
		cin.get();
	}
	while (1);
}

void ATM::entercredit()   //信用卡登录

{

	//cread();

	string id, p;

	int f1 = 1;

	int flag = 1, j, i = 0; int x = 2, y = 2;

	cout << "请输入卡号：" << endl;

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

			cout << "账号不存在,请重新输入！" << endl;

			cin >> id;

		}

	}

	while (1)

	{

		cout << "请输入密码:" << endl;

		p = inputpassword();

		if (p != credit[j]->getp())

		{

			cout << endl << "密码错误,请重新输入！(" << y - 2 << "次机会！" << endl;

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

		cout << "请选择操作序号！" << endl;

		cout << "**********************************************************" << endl;

		cout << "*                                                        *" << endl;

		cout << "*                    1.用户信息                          *" << endl;

		cout << "*                    2.存款或还款                        *" << endl;

		cout << "*                    3.取款                              *" << endl;

		cout << "*                    4.余额查询                          *" << endl;

		cout << "*                    5.转账                          *" << endl;

		cout << "*                    6.缴纳生活费                         *" << endl;
		
		cout << "*                    7.修改个人信息                        *" << endl;
		
		cout << "*                    8.返回上一界面                      *" << endl;

		cout << "*                                                        *" << endl;

		cout << "**********************************************************" << endl;

		cin >> n;

		while (n < 1 || n>9)

		{

			cout << "请合法输入!" << endl;

			cin >> n;

		}

		switch (n)
		{
		case 1:
			credit[j]->display();    //用户信息界面
			credit[j]->show();
			break;
		case 2:
			credit[j]->save();
			csave();
			break;    //信用卡存钱
		case 3:
			credit[j]->fetch();
			csave();
			break;    //信用卡取钱

		case 4:
			credit[j]->querymoney();
			credit[j]->show();
			csave();
			break;   //信用卡余额查询
		case 5:
			credit[j]->Transfer();//转账
			csave();
			break;
		case 6:
			credit[j]->Living();//生活费
			csave();
			break;
		case 7:
			credit[j]->modify(1);//修改个人信息
			csave();
			break;
		case 8:
			return;
		}
		cin.get();
		
	}

	while (1);

}
