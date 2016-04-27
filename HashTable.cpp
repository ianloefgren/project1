/* 
* CSCI 2270 Data Structures
* Final Project
* HashTable class definitions
*
*/

#include <iostream>
#include <string>
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

void HashTable::addUser(string name, string hashed_password)
{
	int tableIndex = hashSum(name,tableSize); //compute value of index to store new user 

	Account *newAccount = new Account(name,hashed_password); //create new instance of Account
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

void HashTable::findUser(string name)
{
	int index = hashSum(name,tableSize); //find index
	bool notFound = true; //flag for if hash table is empty
	Account *tmp = hashTable[index];

	while(tmp!=NULL && notFound) //find element
	{
		if (tmp->title == name)
			notFound = false;
		else
			tmp = tmp->next;
	}

	if (notFound)
		cout << "not found" << endl;
	else
	{
		
	}
}





