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
void account::display()     //�û���Ϣ����
{
	cin.get();
	system("cls");
	cout << "**************************************************************" << endl;

	cout << "*                                                            " << endl;
	cout << "*                    ������" << name << "                        " << endl;

	cout << "*                    �Ա�" << sex << "                        " << endl;

	cout << "*                    ��ַ��" << address << "                        " << endl;

	cout << "*                    �ֻ���" << tele << "                        " << endl;

	cout << "*                    ���ţ�" << id << "                          " << endl;

	cout << "*                    ���: " << money << "                       " << endl;

	cout << "*                    ��������ص���һ�˵�                    " << endl;

	cout << "*                                                            " << endl;

	cout << "**************************************************************" << endl;

}
void account::querymoney()
{
	system("cls");
	cout << "���˻���ǰ���Ϊ��" << money << endl;
	cin.get();
}

