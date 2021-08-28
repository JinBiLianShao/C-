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
void account::display()     //用户信息界面
{
	cin.get();
	system("cls");
	cout << "**************************************************************" << endl;

	cout << "*                                                            " << endl;
	cout << "*                    姓名：" << name << "                        " << endl;

	cout << "*                    性别：" << sex << "                        " << endl;

	cout << "*                    地址：" << address << "                        " << endl;

	cout << "*                    手机：" << tele << "                        " << endl;

	cout << "*                    卡号：" << id << "                          " << endl;

	cout << "*                    余额: " << money << "                       " << endl;

	cout << "*                    按输入键回到上一菜单                    " << endl;

	cout << "*                                                            " << endl;

	cout << "**************************************************************" << endl;

}
void account::querymoney()
{
	system("cls");
	cout << "您账户当前余额为：" << money << endl;
	cin.get();
}

