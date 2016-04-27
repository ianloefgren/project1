/* 
* CSCI 2270 Data Structures
* Final Project
* PassTable class definitions
*
*/

#include <iostream>
#include <string>

#include "PassTable.h"

using namespace std;

PassTable::PassTable()
{}

PassTable::~PassTable()
{}

string PassTable::saltGenerator()
{

}

string PassTable::passHash(string saltyPassword)
{

}

string PassTable::encrypt(string password)
{
	string salt = saltGenerator(); //generate salt to add to password
	string saltyPassword = password.append(salt); //append salt to password
	string hashedPassword = passHash(saltyPassword); //hash salted password

	return hashedPassword; 
}