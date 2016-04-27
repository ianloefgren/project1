/*
* CSCI 2270 Data Stuctures
* Final Project
* Author: Ian Loefgren
* Date Created: 4/20/2016
* Date Modified: 4/25/2016
*
*/

#include <iostream>
//#include "HashTable.h"
//#include "PassTable.h"
//#include "Account.h"

using namespace std;

int main()
{
	//PassTable pass;
	//HashTable hash;

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
			cout << "Not yet operational." << endl;
		}
		else if(input == "2")
		{
			string username = "0";
			string usernameConfirm = "-1";

			cout << "Enter desired username: "; //consider exception handling
			getline(cin,username);
			//CHECK IF USERNAME ALREADY EXISTS IN DATABASE <- ADD FEATURE
			while(username!=usernameConfirm)
			{
				cout << "\nPlease confirm username: ";
				getline(cin,usernameConfirm);
			}
			
			string password = "0";
			string passwordConfirm = "-1";

			cout << "Enter password:";
			getline(cin,password);

			while(password!=passwordConfirm)
			{
				cout << "Please confirm password" << endl;
				getline(cin,passwordConfirm);	
			}

			//string hashedPass = pass.encrypt(passwordConfirm);



		}
	}

	return 0;
}