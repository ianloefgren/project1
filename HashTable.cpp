/* 
* CSCI 2270 Data Structures
* Final Project
* HashTable class definitions
*
*/

#include <iostream>
#include <string>
#include "Account.h"
#include "PassTable.h"
#include "HashTable.h"

using namespace std;

HashTable::HashTable()
{
	tableSize = 10;
	for (int i=0;i<tableSize;i++) //initialize each element of hash table to null
	{
		hashTable[i] = NULL;
	}
}

HashTable::~HashTable()
{}

int HashTable::hashSum(string username, int tableSize)
{
	int sum = 0;
	for(int i=0;i<username.length();i++) //add ascii values of all letters
	{
		sum = sum + username[i];
	}
	sum = sum % tableSize; //find the remainder when divided by size of hash table
	return sum; //return value as index of hash table
}

void HashTable::addUser(string name, string hashed_password,string salt)
{
	int tableIndex = hashSum(name,tableSize); //compute value of index to store new user 

	Account *newAccount = new Account(name,hashed_password,salt); //create new instance of Account
	if (hashTable[tableIndex]==NULL) //if no elements at index
		hashTable[tableIndex] = newAccount;
	else
	{
		Account *tmp = hashTable[tableIndex];
		while(tmp->next!=NULL)
		{
			tmp = tmp->next;
		}
		newAccount->prev = tmp;
		newAccount->next = NULL;
	}
}

Account* HashTable::findUser(string name)
{
	int index = hashSum(name,tableSize); //find index
	//cout << index << endl;
	bool notFound = true; //flag for if hash table is empty
	Account *tmp = hashTable[index];

	while(tmp!=NULL && notFound) //find element
	{
		//cout << tmp->getUsername() << endl;
		if (tmp->getUsername() == name)
			notFound = false;
		else
			tmp = tmp->next;
	}

	if (notFound)
	{
		cout << "Username not found." << endl;
		return NULL;
	}	
	else
	{
		return tmp;
	}
}

Account* HashTable::login(string user, string password)
{
	Account* foundUser = findUser(user); //find user
	string hashed = passHash(password.append(foundUser->getSalt())); //hash inputted password with salt
	if(foundUser!=NULL)
	{
		if(hashed == foundUser->getPassword()) //if passwords match
		{
			return foundUser; //return user account to log in
		}
		else
		{
			cout << "Incorrect username or password." << endl;	
			return NULL;
		}	
	}
	else
		return NULL;
}

void HashTable::deleteUser(string name)
{
	bool deleted = false;
	int index = hashSum(name, tableSize); // index of user to delete
	Account *current = hashTable[index];
	while(deleted == false && current != NULL)
    {
		if(current -> getUsername() == name)
		{
			if(current -> prev != NULL)
			{
				current -> prev -> next = current -> next;
			}
			if(current -> next != NULL)
			{
				current -> next -> prev = current -> prev;
			}
			if(current -> next == NULL && current -> prev == NULL)
			{
				hashTable[index] = NULL;
			}
			deleted = true;
		}
		if(deleted)
		{
			delete current;
		}
		else
		{
			current = current -> next;
		}
		
	}
}





