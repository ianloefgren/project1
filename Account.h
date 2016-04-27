#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>

class Account
{
private:
	std::string user_name;
	std::string hashed_password;
	int number;

public:
	Account *next;
   	Account *prev;

	Account();
	Account(std::string in_name, std::string in_password);
	~Account();
	void setUsername(std::string name);
	void setPass(std::string pass);
	//void setPointers(Account* prev,Account* next);
	void printInfo();

};

#endif // ACCOUNT_H