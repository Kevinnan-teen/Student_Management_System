/*System.h 此文件为System的头文件*/
#pragma once
#include<list>
#include<fstream>
#include"UnderStudent.h"
#include"Administer.h"
class System
{
private:
	list<Understudent> underst;
	list<Administer> ad;
	static int underst_count;
	static int ad_count;
public:
	virtual void load_interface();			//登陆界面
	void exit_system();					    //退出系统
	void understudent_functionshow();		//学生用户功能界面
	void administer_functionshow();			//管理员功能界面
	void set_ad_account();					//设置管理员账户
	void enter_ad_account();				//管理员身份登陆
	void enter_underst_account();			//本科生身份登陆
	void save_undst();						//保存本科生数据
	void save_ad();							//保存管理员数据
	void load_undst();						//读取本科生数据
	void load_ad();							//读取管理员数据
	/*管理员功能*/
	void input_underst_info();				//录入本科生信息
	void look_all_underst();				//查看所有本科生信息
	void look_underst_by_name(string name);			//根据姓名查看本科生信息
	void look_underst_by_id(string id);				//根据ID查看本科生信息
	void delete_underst_by_id(string id);			//根据ID删除本科生信息
	/*本科生功能*/
	void change_password(string id);			//修改密码 
};

