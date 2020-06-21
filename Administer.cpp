/*Administer.cpp 此文件为Administer类的实现*/
#include"Administer.h"
Administer::Administer(string na, string id, string passw) :name(na), ID(id), password(passw)
{}
void Administer::display()
{
	cout << endl << "******************" << endl;
	cout << endl << "* 姓名:" << name;
	cout << endl << "* 账号:" << ID;
	cout << endl << "******************" << endl;
}

