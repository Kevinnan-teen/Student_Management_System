/*Administer.h 此文件为Administer类的头文件*/
#pragma once
#include<iostream>
#include<string>
using namespace std;
class Administer
{
private:
	string name;
	string ID;
	string password;
public:
	Administer() {}
	Administer(string na, string id, string passw);
	string get_id(){return ID;}
	string get_name(){return name;}
	string get_password(){	return password;	}
	void display();
};

