#ifndef PASSTABLE_H
#define PASSTABLE_H
#include <string>

class PassTable
{
	public:
		PassTable();
		~PassTable();
		std::string encrypt(std::string password);
	private:
		std::string saltGenerator();
		std::string passHash(std::string);
};

#endif // PASHTABLE_H