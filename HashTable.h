#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
#include "PassTable.h"
#include "Account.h"

//this should be a class for proper encapsulation

class HashTable : public PassTable
{
	public:
		HashTable();
		~HashTable();
		void printUserInfo();
		void printDatabase();
		Account* login(std::string user, std::string password);
		void addUser(std::string name,std::string password,std::string salt);
		void deleteUser(std::string name);
		Account* findUser(std::string name);
	private:
		int hashSum(std::string x, int s);
		int tableSize;
		Account* hashTable[10];

};


#endif // HASHTABLE_H