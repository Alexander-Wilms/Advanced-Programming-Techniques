#include <string>
#include <iostream>
#include <set>
#include <random>
#include "CBank.h"
#include "CTransaction.h"

/**
 * creates a new customer object and stores it in a map
 * using the name as key and the object as value
 */
void CBank::addCustomer(std::string name) {
	CCustomer customer(name);
	m_CustomersMap.insert(std::pair<std::string,CCustomer>(name, customer));
}

void CBank::addAccount(std::string name, float amount) {
	if(m_CustomersMap.find(name) != m_CustomersMap.end()) {
	// generate a random ID
	int ID = m_distribution(m_generator);

	// create account
	CAccount account(name, ID, amount);

	// store account
	m_AccountsMap.insert(std::pair<int,CAccount>(ID, account));
	m_CustomersMap[name].openAccount(ID);
	} else {
		std::cout << "ERROR: Generating Account - Customer <" << name << "> not found!" << std::endl;
	}
}

void CBank::deleteAccount(int ID) {
	// find the account's owner
	std::string owner = m_AccountsMap[ID].getOwner();
	// delete the customer's link to the account
	m_CustomersMap[owner].deleteAccount(ID);
	// delete the account
	m_AccountsMap.erase(ID);
}

void CBank::deleteCustomer(std::string name) {
	// find associated accounts
	std::set<int> associatedAccountIDs= m_CustomersMap[name].getAssociatedAccountIDs();
	// delete associated accounts
	for(std::set<int>::iterator it1 = associatedAccountIDs.begin(); it1 != associatedAccountIDs.end(); it1++) {
		std::map<int,CAccount>::iterator it2 = m_AccountsMap.find(*it1);
		m_AccountsMap.erase(it2);
	}
	// delete customer
	std::map<std::string, CCustomer>::iterator it3 = m_CustomersMap.find(name);
	m_CustomersMap.erase(it3);
}

void CBank::performTransaction(int fromAccountID, int toAccountID,
		float amount, std::string date) {
	// perform transaction
	m_AccountsMap[fromAccountID].withdraw(amount);
	m_AccountsMap[toAccountID].deposit(amount);
	// log transaction
	CTransaction transaction(&m_AccountsMap[fromAccountID], &m_AccountsMap[toAccountID], amount, date);
	m_TransactionsVector.push_back(transaction);
}

void CBank::generateReport() {
	std::cout << "Bank Customers..." << std::endl;
	for(std::map<std::string,CCustomer>::iterator it = m_CustomersMap.begin(); it != m_CustomersMap.end(); it++) {
		std::cout << "\t" << it->second.getName() << std::endl;
	}
	std::cout << "Bank Accounts..." << std::endl;
	for(std::map<int,CAccount>::iterator it = m_AccountsMap.begin(); it != m_AccountsMap.end(); it++) {
		std::cout << "\t" << it->second.getID() << " " << it->second.getOwner() << " " << it->second.getBalance() << std::endl;
	}
	std::cout << "Bank Transactions..." << std::endl;
	// iterate over all customers
	for(std::map<std::string,CCustomer>::iterator it = m_CustomersMap.begin(); it != m_CustomersMap.end(); it++) {
		std::cout << "...for customer: " << it->second.getName() << std::endl;
		// iterate over all the customer's accounts
		for(std::set<int>::iterator it2 = it->second.getAssociatedAccountIDs().begin(); it2 != it->second.getAssociatedAccountIDs().end(); it2++) {
			std::cout << "\t...Account " << *it2 << std::endl;
			// iterate over all the transactions
			for(std::vector<CTransaction>::iterator it3 = m_TransactionsVector.begin(); it3 != m_TransactionsVector.end(); it3++) {
				if(it3.base()->getFromAccount().getID() == *it2) {
					std::cout << it3.base()->getDate() << " " << it3.base()->getAmount() << "EURO to " << it3.base()->getToAccount().getID() << std::endl;
				}
			}
		}
	}
	std::cout << "=====================" << std::endl;
}

CBank::CBank() {
}
