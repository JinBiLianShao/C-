#pragma once
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include<ctime>
#include <conio.h>
#define account0  7116620100000254000    //第一个开户的卡号
#define random(a,b) (rand()%(b-a+1)+a)
using namespace std;
int number = 0;
class ATM;
class depositcard;
class creditcard;
class account//用户类
{
public:
	account()
	{
		id = "0", name = "0", sex = "0", address = "0", tele = "0", shenfen = "0", password = "0", money = 0;   //默认构造函数
	}
	account(string i, string n, string se, string a, string t, string s, string p, double m)        //带参数构造函数
	{
		id = i, name = n, sex = se, address = a, tele = t, shenfen = s, password = p, money = m;
	}
	string getid(){return id;}
	double money;
	void display();      //用户信息界面
	void querymoney();      //余额查询
protected:
	string id, name, address, tele, shenfen, password, sex;
	
};
class Staff//操作员类
{
public:
	Staff() {};
	string staffpassword="123456";
};
class ATM
{
public:
	friend class account;
	void staffload();//显示操作员管理普通用户的界面
	void choice();//选择模式
	void setdeposit();      //储存卡开户
	void setcredit();      //信用卡开户
	void enterdeposit();   //储存卡登录
	void entercredit();   //信用卡登录
	void delaccount();      //销户
	void exitatm();           //退出
	void dsave();          //储蓄卡类导入磁盘文件
	void csave();           //信用卡类导入磁盘文件
	void dread();      //储蓄卡信息从磁盘文件导出
	void cread();    //信用卡信息从磁盘文件导出
	string inputpassword();        //设置账户的密码
	bool check(string str);    //检查身份证是否合格
	double sum(double m);//ATM机钱数总和
	void modify(int s);//修改个人信息
	void menu();           //功能菜单
	void deposit_ATM();//atm存款
	void withdraw_ATM();//ATM取款
protected:
	depositcard* deposit[50];    //定义多个储存卡对象
	creditcard* credit[50];     //定义多个信用卡对象
	static int depositcount, creditcount;
	double s = 50000;//ATM原有钱数
	Staff staff;
};
class depositcard :public account, public ATM             //账户派生类：储蓄卡
{
public:
	friend class account;
	friend class ATM;
	depositcard(string i, string n, string se, string a, string t, string s, string p, double m) :account(i, n, se, a, t, s, p, m) {}
	void save();          //存钱功能
	void fetch();        //取钱功能
	void death();       //死期
	void lixi();   //查询利息
	void current();  //活期
	string getp()
	{return password;}
	void Transfer(); //转账
	void Living();  //生活费
};
class creditcard :public account, public ATM            //账户派生类：信用卡
{
public:
	friend class ATM;
	friend class account;
	creditcard(string i, string n, string se, string a, string t, string s, string p, double m, double tou, double tm) :
		account(i, n, se, a, t, s, p, m), touzhi(tou), tmax(tm) {}
	void save();          //存钱功能
	void fetch();        //取钱功能
	void show();
	string getp(){return password;}
	void add(double x);//
	void Transfer(); //转账
	void Living();  //生活费
	double touzhi;   //还能透支的钱数
	double tmax;//最大透支金额（正数
};
