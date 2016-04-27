/* 
* CSCI 2270 Data Structures
* Final Project
* Account class definitions
*
*/

#include <iostream>
#include <string>
#include "PassTable.h"
#include "Account.h"

using namespace std;

Account::Account()
{
	user_name = "Undefined";
	hashed_password = "None";
	next = NULL;
	prev = NULL;
}

Account::Account(string in_name,string in_password,string in_salt)
{
	user_name = in_name;
	hashed_password = in_password;
	salt = in_salt;
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
{
	cout << "User: " << user_name << endl;
	cout << "Hashed password: " << hashed_password << endl;
	cout << "Stored message: " << message << endl;
}

string Account::getUsername()
{
	return user_name;
}

string Account::getPassword()
{
	return hashed_password;
}

string Account::getSalt()
{
	return salt;
}

void Account::login(bool loginPermission)
{
	if(loginPermission)
		logged_in = true;
}

void Account::logout()
{
	logged_in = false;
}

bool Account::loginStatus()
{
	return logged_in;
}

void Account::setMessage(string input)
{
	message = input;
}

void Account::setSalt(string saltInput)
{
	salt = saltInput;
}