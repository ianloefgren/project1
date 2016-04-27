/*
* CSCI 2270 Data Stuctures
* Final Project
* Author: Ian Loefgren
* Date Created: 4/20/2016
* Date Modified: 4/25/2016
*
*/

#include <iostream>
#include "Account.h"
#include "PassTable.h"
#include "HashTable.h"


using namespace std;

int main()
{
	PassTable pass;
	HashTable hash;

	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~ Welcome ~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	string input = "";
	while (input!="quit")
	{
		cout << "\n1. Log in" << endl;
		cout << "2. Create a new account" << endl;

		getline(cin,input);

		if (input=="1")
		{
			cout << "Please enter username and password:" << endl;
			string input_username = "";
			string input_password = "";
			getline(cin,input_username);
			getline(cin,input_password);

			Account* userLogin = hash.login(input_username,input_password);

			if(userLogin!=NULL)
			{
				cout << "logged in" << endl;
				userLogin->printInfo();
			}

		}
		else if(input == "2")
		{
			string username = "0";
			string usernameConfirm = "-1";

			cout << "\nEnter desired username: "; //consider exception handling
			getline(cin,username);
			//CHECK IF USERNAME ALREADY EXISTS IN DATABASE <- ADD FEATURE
			while(username!=usernameConfirm)
			{
				cout << "Please confirm username: ";
				getline(cin,usernameConfirm);
			}
			
			string password = "0";
			string passwordConfirm = "-1";

			cout << "\nEnter password: ";
			getline(cin,password);

			while(password!=passwordConfirm)
			{
				cout << "Please confirm password: ";
				getline(cin,passwordConfirm);	
			}

			string salt = pass.getSalt();
			string hashedPass = pass.encrypt(passwordConfirm,salt);

			hash.addUser(usernameConfirm,hashedPass,salt); //DONT FORGET TO CHANGE THIS TO HASHED WHEN FUNCITONING



		}
	}

	return 0;
}