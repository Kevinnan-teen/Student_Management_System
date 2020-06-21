/*System.cpp 此文件为System类的实现*/
#include"System.h"

int System::underst_count = 0;
int System::ad_count = 0;

//登陆界面
void System::load_interface()
{
	int i;
	do
	{
		system("cls");
		load_ad();
		load_undst();
		cout << "********************" << endl;
		cout << "1)开通管理员账户!" << endl;
		cout << "2)管理员身份登陆!" << endl;
		cout << "3)本科生身份登陆!" << endl;
		cout << "4)退出系统!" << endl;
		cout << "********************" << endl;
		cout << "请输入操作:";
		cin >> i;
		while (i < 1 || i>4)
		{
			cout << "请输入正确的序号!" << endl;
			cout << "请重新输入:";
			cin >> i;
		}
		switch (i)
		{
		case 1:
			set_ad_account();
			break;
		case 2:
			enter_ad_account();
			break;
		case 3:
			enter_underst_account();
			break;
		case 4:
			exit_system();
			break;
		default:
			break;
		}
		//cin.get();
	} while (true);
}

//退出系统
void System::exit_system()
{
	cout << "****************感谢使用!******************" << endl;
	exit(0);
}


//本科生功能界面
void System::understudent_functionshow()
{
	cout << "***************************" << endl;
	cout << "1)查看个人信息" << endl;
	cout << "2)修改密码" << endl;
	cout << "3)返回上一级菜单!" << endl;
	cout << "*****************************" << endl;
	cout << "请选择你要进行的操作:";
}


//管理员功能界面
void System::administer_functionshow()
{
	cout << "***************************" << endl;	
	cout << "1)查看所有学生信息!" << endl;
	cout << "2)按姓名查找学生信息!" << endl;
	cout << "3)按学号查找学生信息!" << endl;
	cout << "4)录入学生信息" << endl;
	cout << "5)按学号删除学生信息" << endl;
	cout << "6)返回上一级菜单!" << endl;
	cout << "*****************************" << endl;
	cout << "请选择你要进行的操作:";
}


//设置管理员账户
void System::set_ad_account()
{
	string name;
	string id;
	string password;
	string password2;
	cout << endl<<"请输入姓名:";
	cin >> name;
	cout << endl << "请输入ID:";
	cin >> id;
	cout << endl << "请输入密码:";
	cin >> password;
	cout << endl << "请再次输入密码:";
	cin >> password2;
	while (password != password2)
	{
		cout << "两次密码不一致，请再次确认:";
		cin >> password2;
	}
	Administer adm(name, id, password);
	ad.push_back(adm);
	cout << "开户成功!" << endl;
	cin.get();
	ad_count++;
	save_ad();
}


//管理员身份登陆
void System::enter_ad_account()
{
	string udst_name;	//要查询的学生的名字
	string udst_id;		//要查询学生的ID
	string id;
	string passw;
	list<Administer>::iterator iter;
	cout << "请输入账户:";
	cin >> id;
	int flag = 1;
	for (iter = ad.begin(); iter != ad.end(); iter++)
	{
		if (id == iter->get_id())
		{
			flag = 0;
			break;
		}	
	}
	if (flag)
	{
		cout << endl<<"账户不存在!" << endl;
		return;
	}
	cout << endl << "请输入密码:";
	cin >> passw;
	while (passw != iter->get_password())
	{
		cout << endl<<"密码错误，请重新输入:";
		cin >> passw;
	}
	cin.get();
	int n;
	do 
	{
		system("cls");
		administer_functionshow();
		cin >> n;
		while (n < 1 || n>6)
		{
			cout << "请输入正确的选项:";
			cin >> n;
		}
		switch (n)
		{
		case 1:
			look_all_underst();
			break;
		case 2:
			cout << "请输入要查询学生的名字:";
			cin >> udst_name;
			look_underst_by_name(udst_name);
			break;
		case 3:
			cout << "请输入要查询学生的ID:";
			cin >> udst_id;
			look_underst_by_id(udst_id);
			break;
		case 4:
			input_underst_info();
			break;
		case 5:
			cout << "请输入要删除学生的ID:";
			cin >> udst_id;
			delete_underst_by_id(udst_id);
			break;
		case 6:
			return;
			break;
		default:
			break;
		}
	} while (1);
}

//本科生身份登陆
void System::enter_underst_account()
{
	list<Understudent>::iterator iter;
	string id;
	string passw;
	cout << "请输入账户:";
	cin >> id;
	int flag = 1;
	for (iter = underst.begin(); iter != underst.end(); iter++)
	{
		if (id == iter->get_id())
		{
			flag = 0;
			break;
		}
	}
	if (flag)
	{
		cout << endl << "账户不存在!" << endl;
		return;
	}
	cout << endl << "请输入密码:";
	cin >> passw;
	while (passw != iter->get_password())
	{
		cout << endl << "密码错误，请重新输入:";
		cin >> passw;
	}
	int n;
	do
	{
		system("cls");
		understudent_functionshow();
		cin >> n;
		while (n < 1 || n>3)
		{
			cout << endl << "请输入正确的操作:";
			cin >> n;
		}
		system("cls");
		switch (n)
		{
		case 1:
			iter->display();
			break;
		case 2:

			change_password(id);
			break;
		case 3:
			return;
			break;
		default:
			break;
		}
		system("pause");

	} while (true);
}

//保存管理员数据
void System::save_ad()
{
	ofstream outfile("administer.dat",ios::out);
	list<Administer>::iterator iter;
	outfile << ad_count << endl;
	for (iter = ad.begin(); iter != ad.end(); iter++)
	{
		outfile << iter->get_name() << "\t" << iter->get_id() << "\t" << iter->get_password() << endl;
	}
	outfile.close();
}

//保存本科生数据
void System::save_undst()
{
	ofstream outfile("understudent.dat",ios::out);
	list<Understudent>::iterator iter;
	outfile << underst_count << endl;
	for (iter = underst.begin(); iter != underst.end(); iter++)
	{
		outfile << iter->get_name() << "\t" << iter->get_id() << "\t" << iter->get_password() << "\t" << iter->get_grade() << "\t"
			<< iter->get_sex() << endl;
	}
	outfile.close();
}

//读取本科生数据
void System::load_undst()
{
	ifstream infile("understudent.dat");
	if (!infile)
	{
		cout << "无本科生资料！" << endl;
		return;
	}
	string name;
	string ID;
	string password;
	float grade;
	string sex;
	infile >> underst_count;//读取本科生总人数
	infile.get();
	if (!underst.empty())
		underst.clear();
	while (!infile.eof() && infile.peek() != EOF)
	{
		infile >> name >> ID >> password >> grade >> sex;
		Understudent undst(name, ID, password, grade, sex);
		underst.push_back(undst);
		infile.get();
	}
	infile.close();
	cout << "读取本科生资料正常。" << endl;
	
}

//读取管理员数据
void System::load_ad()
{
	ifstream infile("administer.dat");
	if (!infile)
	{
		cout << "无管理员资料!" << endl;
		return;
	}
	string name;
	string ID;
	string password;
	infile >> ad_count;//读取管理员总人数
	infile.get();
	if (!ad.empty())
		ad.clear();
	while (!infile.eof()||infile.peek()!=EOF)
	{
		infile >> name >> ID >> password;
		Administer adm(name, ID, password);
		ad.push_back(adm);
		infile.get();
	}
	infile.close();
	cout << "读取管理员资料正常。" << endl;
}

/*
管理员权限：
*/

//1)查看所有本科生信息
void System::look_all_underst()
{
	system("cls");
	if (underst.empty())
	{
		cout << "无本科生数据!" << endl;
		system("pause");
		return;
	}
	list<Understudent>::iterator iter;
	cout << "姓名" << "\t" << "ID" << "\t" << "\t" <<"性别"  << "\t" << "绩点" << endl;
	for (iter = underst.begin(); iter != underst.end(); iter++)
		cout << iter->get_name() << "\t" << iter->get_id() << "\t" << iter->get_sex() << "\t" << iter->get_grade() << endl;
	cout << endl << "学生总人数:" << underst_count << endl;
	system("pause");
}

//2)按姓名查看本科生数据
void System::look_underst_by_name(string udst_name)
{
	system("cls");
	if (underst.empty())
	{
		cout << "无本科生数据!" << endl;
		system("pause");
		return;
	}
	list<Understudent>::iterator iter;
	for (iter = underst.begin(); iter != underst.end(); iter++)
	{
		if (iter->get_name() == udst_name)
		{
			cout << "姓名" << "\t" << "ID" << "\t" << "\t" << "性别" << "\t" << "绩点" << endl;
			cout << iter->get_name() << "\t" << iter->get_id() << "\t" << iter->get_sex() << "\t" << iter->get_grade() << endl;
			//姓名可以重复，因此遍历所有
		}
		if (iter == --underst.end())
		{
			system("pause");
			return;
		}
	}	
	cout << "无该生数据!" << endl;
	system("pause");
	return;
}

//3）按ID查看本科生数据
void System::look_underst_by_id(string udst_id)
{
	system("cls");
	if (underst.empty())
	{
		cout << "无本科生数据!" << endl;
		system("pause");
		return;
	}
	list<Understudent>::iterator iter;
	for (iter = underst.begin(); iter != underst.end(); iter++)
	{
		if (iter->get_id()==udst_id)
		{
			cout << "姓名" << "\t" << "ID" << "\t" << "\t" << "性别" << "\t" << "绩点" << endl;
			cout << iter->get_name() << "\t" << iter->get_id() << "\t" << iter->get_sex() << "\t" << iter->get_grade() << endl;
			system("pause");
			return;	//ID不能有重复
		}
	}
	cout << "无该生数据!" << endl;
	system("pause");
	return;
}

//4)录入本科生信息
void System::input_underst_info()
{

	string name;
	string ID;
	string password;
	float grade;
	string sex;
	char s;	//是否继续录入flag
	do
	{
		system("cls");
		cout << endl << "请输入学生姓名:";
		cin >> name;
		cout << endl << "请输入学生ID:";
		cin >> ID;
		cout << endl << "请输入学生初始密码:";
		cin >> password;
		cout << endl << "请输入学生绩点:";
		cin >> grade;
		cout <<endl<< "请输入学生性别:";
		cin >> sex;
		Understudent undst(name, ID, password, grade, sex);
		underst.push_back(undst);
		underst_count++;
		cout << endl << "是否继续录入?(Y/N)";
		cin >> s;
		while (s != 'Y'&&s != 'N'&&s != 'y'&&s != 'n')
		{
			cout << endl << "请输入正确操作(Y/N):";
			cin >> s;
		}
	} while (s == 'Y'||s=='y');
	save_undst();
}

//5)按ID删除学生信息
void System::delete_underst_by_id(string udst_id)
{
	system("cls");
	if (underst.empty())
	{
		cout << "无本科生数据!" << endl;
		system("pause");
		return;
	}
	list<Understudent>::iterator iter;
	string name;
	string ID;
	string password;
	float grade;
	string sex;
	for (iter = underst.begin(); iter != underst.end(); iter++)
	{
		if (iter->get_id() == udst_id)
		{
			name = iter->get_name(); 
			ID = iter->get_id(); 
			password = iter->get_password();
			grade = iter->get_grade(); 
			sex = iter->get_sex();
			Understudent undst(name, ID, password, grade, sex);
			underst.remove(undst);
			underst_count--;
			cout << "删除成功!" << endl;
			system("pause");
			save_undst();
			return;	//ID不能有重复
		}
	}
	cout << "无该生数据!" << endl;
	system("pause");
	return;
}


/*
本科生权限
*/
//2)修改密码
void System::change_password(string id)
{
	string password, passw;
	cout << "请输入新密码:";
	cin >> password;
	cout <<endl<<"请再次输入:";
	cin >> passw;
	while (password != passw)
	{
		cout << endl<<"两次密码不一致，请重新输入:";
		cin >> passw;
	}
	list<Understudent>::iterator iter;
	for (iter = underst.begin(); iter != underst.end(); iter++)
	{
		if (iter->get_id() == id)
			break;
	}
	iter->set_password(password);
	cout << "修改密码成功!" << endl;
	save_undst();
}

