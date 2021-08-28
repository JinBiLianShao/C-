#pragma once
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include<ctime>
#include <conio.h>
#define account0  7116620100000254000    //��һ�������Ŀ���
#define random(a,b) (rand()%(b-a+1)+a)
using namespace std;
int number = 0;
class ATM;
class depositcard;
class creditcard;
class account//�û���
{
public:
	account()
	{
		id = "0", name = "0", sex = "0", address = "0", tele = "0", shenfen = "0", password = "0", money = 0;   //Ĭ�Ϲ��캯��
	}
	account(string i, string n, string se, string a, string t, string s, string p, double m)        //���������캯��
	{
		id = i, name = n, sex = se, address = a, tele = t, shenfen = s, password = p, money = m;
	}
	string getid(){return id;}
	double money;
	void display();      //�û���Ϣ����
	void querymoney();      //����ѯ
protected:
	string id, name, address, tele, shenfen, password, sex;
	
};
class Staff//����Ա��
{
public:
	Staff() {};
	string staffpassword="123456";
};
class ATM
{
public:
	friend class account;
	void staffload();//��ʾ����Ա������ͨ�û��Ľ���
	void choice();//ѡ��ģʽ
	void setdeposit();      //���濨����
	void setcredit();      //���ÿ�����
	void enterdeposit();   //���濨��¼
	void entercredit();   //���ÿ���¼
	void delaccount();      //����
	void exitatm();           //�˳�
	void dsave();          //����ർ������ļ�
	void csave();           //���ÿ��ർ������ļ�
	void dread();      //�����Ϣ�Ӵ����ļ�����
	void cread();    //���ÿ���Ϣ�Ӵ����ļ�����
	string inputpassword();        //�����˻�������
	bool check(string str);    //������֤�Ƿ�ϸ�
	double sum(double m);//ATM��Ǯ���ܺ�
	void modify(int s);//�޸ĸ�����Ϣ
	void menu();           //���ܲ˵�
	void deposit_ATM();//atm���
	void withdraw_ATM();//ATMȡ��
protected:
	depositcard* deposit[50];    //���������濨����
	creditcard* credit[50];     //���������ÿ�����
	static int depositcount, creditcount;
	double s = 50000;//ATMԭ��Ǯ��
	Staff staff;
};
class depositcard :public account, public ATM             //�˻������ࣺ���
{
public:
	friend class account;
	friend class ATM;
	depositcard(string i, string n, string se, string a, string t, string s, string p, double m) :account(i, n, se, a, t, s, p, m) {}
	void save();          //��Ǯ����
	void fetch();        //ȡǮ����
	void death();       //����
	void lixi();   //��ѯ��Ϣ
	void current();  //����
	string getp()
	{return password;}
	void Transfer(); //ת��
	void Living();  //�����
};
class creditcard :public account, public ATM            //�˻������ࣺ���ÿ�
{
public:
	friend class ATM;
	friend class account;
	creditcard(string i, string n, string se, string a, string t, string s, string p, double m, double tou, double tm) :
		account(i, n, se, a, t, s, p, m), touzhi(tou), tmax(tm) {}
	void save();          //��Ǯ����
	void fetch();        //ȡǮ����
	void show();
	string getp(){return password;}
	void add(double x);//
	void Transfer(); //ת��
	void Living();  //�����
	double touzhi;   //����͸֧��Ǯ��
	double tmax;//���͸֧������
};
