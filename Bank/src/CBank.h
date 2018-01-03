#ifndef CBANK_H
#define CBANK_H

#include <string>
#include <vector>
#include <map>
#include <random>
#include "CAccount.h"
#include "CCustomer.h"
#include "CTransaction.h"

class CBank {
public:
	CBank();
	void addCustomer(std::string name);
	void addAccount(std::string name, float amount);
	void deleteAccount(int ID);
	void deleteCustomer(std::string name);
	void performTransaction(int fromAccountID, int toAccountID,
			float amount, std::string date);
	void generateReport();
private:
	std::map<std::string, CCustomer> m_CustomersMap;
	std::vector<CTransaction> m_TransactionsVector;
	std::map<int,CAccount> m_AccountsMap;
	std::default_random_engine m_generator;
	std::uniform_int_distribution<int> m_distribution = std::uniform_int_distribution<int>(111111,999999);

	static int m_ID;
};

#endif // CBANK_H
