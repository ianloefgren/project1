#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>

class Account
{
private:
	std::string user_name;
	std::string hashed_password;
	std::string salt;
	std::string message;
	bool logged_in;

public:
	Account *next;
   	Account *prev;

	Account();
	Account(std::string in_name, std::string in_password,std::string in_salt);
	~Account();
	void setUsername(std::string name);
	void setPass(std::string pass);
	//void setPointers(Account* prev,Account* next);
	void printInfo();
	std::string getPassword();
	std::string getUsername();
	std::string getSalt();
	void login(bool loginPermission);
	void logout();
	bool loginStatus();

};

#endif // ACCOUNT_H