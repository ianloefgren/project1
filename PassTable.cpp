/* 
* CSCI 2270 Data Structures
* Final Project
* PassTable class definitions
*
*/

#include <iostream>
#include <string>
#include <random>
#include <time.h>
#include "PassTable.h"

using namespace std;

PassTable::PassTable()
{}

PassTable::~PassTable()
{}

//Code in following function written by Ates Goral with modifications by Ian Loefgren
string PassTable::saltGenerator() //create salt to be appended to password
{
	string s = "00000000000000000000000000000000";

	srand(rand()^time(NULL));

    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < 32; ++i) {
        s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    s[32] = 0;

    return s;
}

string PassTable::passHash(string saltyPassword) //hash function to hash salted passwords
{
	for(int i=0;i<saltyPassword.length();i++)
	{
		if(i%2==0)
			saltyPassword[i] = saltyPassword[i] * 7 / 2 + 10;
		else if(i%5==0)
			saltyPassword[i] = saltyPassword[i]^2/100;
		else
			saltyPassword[i] = saltyPassword[i] + 3;
	}
	cout << saltyPassword << endl;
	return saltyPassword;
}

string PassTable::encrypt(string password,string salt)
{
	//string salt = saltGenerator(); //generate salt to add to password
	string saltyPassword = password.append(salt); //append salt to password
	string hashedPassword = passHash(saltyPassword); //hash salted password

	return hashedPassword; 
}

string PassTable::getSalt()
{
	string salt = saltGenerator();
	return salt;
}