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

	cout << "\nType 'quit' to quit the program" << endl;

	string input = "";
	while (input!="quit")
	{
		cout << "\n====== Main Menu ======" << endl;
		cout << "1. Log in" << endl;
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
				cout << "\nLogged in successfully!" << endl;
				//userLogin->printInfo();

 				while(input!="4")
 				{	
 					cout << "\nAccount Options" << endl;
 					cout << "---------------" << endl;
 					cout << "1. Change password" << endl;
 					cout << "2. Edit message" << endl;
 					cout << "3. Print user info" << endl;
 					cout << "4. Logout" << endl;
					getline(cin,input);

					if(input=="1")
					{
						string password = "0";
						string passwordConfirm = "-1";

						cout << "\nEnter new password: ";
						getline(cin,password);

						while(password!=passwordConfirm)
						{
							cout << "Please confirm new password: ";
							getline(cin,passwordConfirm);	
						}

						string salt = pass.getSalt();
						string hashedPass = pass.encrypt(passwordConfirm,salt);

						userLogin->setSalt(salt);
						userLogin->setPass(hashedPass);

					}
					else if(input=="2")
					{
						cout << "Enter new message: ";
						getline(cin,input);
						userLogin->setMessage(input);
					}
					else if(input=="3")
					{
						userLogin->printInfo();
					}
					else if(input=="4")
					{
						userLogin->logout();
						cout << "Logged out successfully!" << endl;
					}
				}	
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