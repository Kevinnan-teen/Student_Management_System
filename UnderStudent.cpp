/*UnderStudent.cpp 此文件为UnderStudent类的实现*/
#include"UnderStudent.h"
Understudent::Understudent(string na, string id, string passw, float gra, string s):name(na),ID(id),password(passw),grade(gra), sex(s)
{}
void Understudent::display()
{
	cout << "******************"<< endl;
	cout << "* 姓名:" << name   << endl;
	cout << "* 学号:" << ID     <<endl ;
	cout << "* 性别:"  << sex   <<endl ;
	cout << "* 绩点:"  << grade << endl;
	cout << "******************"<< endl;
}

