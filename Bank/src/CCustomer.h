
#ifndef CCUSTOMER_H
#define CCUSTOMER_H

#include <string>
#include <vector>
#include <set>

class CCustomer
{
public:
	CCustomer(std::string name = "No name");
	void openAccount(int ID);
	void deleteAccount(int ID);
	std::set<int> getAssociatedAccountIDs();
	std::string getName();
private:
	std::string m_name;
	std::set<int> m_associatedAccountIDs;
};

#endif // CCUSTOMER_H
