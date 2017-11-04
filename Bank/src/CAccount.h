
#ifndef CACCOUNT_H
#define CACCOUNT_H

#include <string>

class CAccount
{
public:
	CAccount(std::string owner = "No owner", int ID = 555555, float initialBalance = 0);
	void withdraw (float amount);
	void deposit (float amount);
	std::string getOwner();
	int getID();
	float getBalance();
private:
	int m_ID;
	float m_balance;
	std::string m_owner;
};

#endif // CACCOUNT_H
