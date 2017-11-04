#include "CCustomer.h"

CCustomer::CCustomer(std::string name) {
	m_name = name;
}

void CCustomer::openAccount(int ID) {
	m_associatedAccountIDs.insert(ID);
}

void CCustomer::deleteAccount(int ID) {
	m_associatedAccountIDs.erase(ID);
}

std::set<int> CCustomer::getAssociatedAccountIDs() {
	return m_associatedAccountIDs;
}

std::string CCustomer::getName() {
	return m_name;
}
