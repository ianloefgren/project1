#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
#include "Account.h"

//this should be a class for proper encapsulation

class HashTable
{
	public:
		HashTable();
		~HashTable();
		void printUserInfo();
		void printDatabase();
		bool login(std::string user, std::string password);
		void addUser(std::string name,std::string password);
		void deleteUser(std::string name);
		void findUser(std::string name);
	private:
		int hashSum(std::string x, int s);
		int tableSize;
		Account* hashTable[10];

};


#endif // HASHTABLE_H