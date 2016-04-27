#ifndef PASSTABLE_H
#define PASSTABLE_H

class PassTable
{
	public:
		PassTable();
		~PassTable();
		std::string encrypt(std::string password,std::string salt);
		std::string getSalt();
		std::string passHash(std::string);
	private:
		std::string saltGenerator();
};

#endif // PASSTABLE_H