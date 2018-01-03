#include <algorithm>
#include <exception>
#include <string>
#include <iostream>
#include <set>
#include <random>
#include "CBank.h"
#include "CTransaction.h"

// https://stackoverflow.com/questions/185844/initializing-private-static-members/185848
int CBank::m_ID = 123456;

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
		//int ID = m_distribution(m_generator);
		// use predefined IDs, so the output is the same as in the example
		int ID = m_ID;
		m_ID++;

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
	std::cout << "Deleting Account: " << ID << std::endl;
	// find the account's owner
	std::string owner = m_AccountsMap[ID].getOwner();
	// delete the customer's link to the account
	m_CustomersMap[owner].deleteAccount(ID);
	// delete the account
	m_AccountsMap.erase(ID);
}

void CBank::deleteCustomer(std::string name) {
	std::cout << "Deleting Customer: " << name << std::endl;

	// find associated accounts
	std::vector<int> associatedAccountIDs= m_CustomersMap[name].getAssociatedAccountIDs();
	// delete associated accounts
	int noOfAccounts = associatedAccountIDs.size();
	for(std::vector<int>::iterator itAccountID = associatedAccountIDs.begin(); itAccountID != associatedAccountIDs.end(); itAccountID++) {
		std::map<int,CAccount>::iterator itAccount = m_AccountsMap.find(*itAccountID);
		std::cout << "Deleting Account: " << itAccount->second.getID() << std::endl;
		m_AccountsMap.erase(itAccount);
	}

	// delete customer
	std::map<std::string, CCustomer>::iterator itCustomer = m_CustomersMap.find(name);
	if(itCustomer != m_CustomersMap.end()) {
		m_CustomersMap.erase(itCustomer);
		std::cout << "Deleted Customer: " << name << " who owned " << noOfAccounts << " accounts" << std::endl;
	}
}

void CBank::performTransaction(int fromAccountID, int toAccountID,
		float amount, std::string date) {
	// perform transaction
	try {
		m_AccountsMap.at(fromAccountID).withdraw(amount);
	} catch (std::exception& e) {
		std::cerr << "Exception thrown by " << e.what() << std::endl;
		return;
	}
	try {
		m_AccountsMap.at(toAccountID).deposit(amount);
	} catch (std::exception& e) {
		std::cerr << "Exception thrown by " << e.what() << std::endl;
		return;
	}
	// log transaction
	CTransaction transaction(&m_AccountsMap.at(fromAccountID), &m_AccountsMap.at(toAccountID), amount, date);
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
	//std::sort (m_TransactionsVector.begin(), m_TransactionsVector.end());
	// iterate over all customers
	for(std::map<std::string,CCustomer>::iterator it = m_CustomersMap.begin(); it != m_CustomersMap.end(); it++) {
		// std::cout << "...to customer: " << it->first << std::endl;
		// this is the same as
		std::cout << "...for customer: " << it->second.getName() << std::endl;

			// iterate over all the customer's accounts
			std::vector<int> associatedAccountIDs = it->second.getAssociatedAccountIDs();
			for(std::vector<int>::iterator itAssociatedAccountID = associatedAccountIDs.begin(); itAssociatedAccountID != associatedAccountIDs.end(); itAssociatedAccountID++) {
			// print from which account the transaction originated
			std::cout << "\t...from account " << *itAssociatedAccountID << std::endl;

			// iterate over all the transactions
			for(std::vector<CTransaction>::const_iterator itTransaction = m_TransactionsVector.begin(); itTransaction != m_TransactionsVector.end(); itTransaction++) {
				// print transaction
				if(itTransaction->getFromAccount().getID() == *itAssociatedAccountID) {
					std::cout << itTransaction->getDate() << " " << itTransaction->getAmount() << "EURO to " << itTransaction->getToAccount().getID() << std::endl;
				}
			}
		}
	}
	std::cout << "=====================" << std::endl;
}

CBank::CBank() {
}
