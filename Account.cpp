/* 
* CSCI 2270 Data Structures
* Final Project
* Account class definitions
*
*/

#include <iostream>
#include <string>
#include "Account.h"

using namespace std;

Account::Account()
{
	user_name = "Undefined";
	hashed_password = "None";
	next = NULL;
	prev = NULL;
}

Account::Account(string in_name,string in_password)
{
	user_name = in_name;
	hashed_password = in_password;
	next = NULL;
	prev = NULL;
}

Account::~Account()
{}

/*void Account::setUsername(string name)
{
	string input = "";
	cout << "Are"
}*/

void Account::setPass(string pass)
{
	hashed_password = pass;
}

void Account::printInfo()
{}	