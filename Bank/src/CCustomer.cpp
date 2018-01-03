#include "CCustomer.h"
#include <algorithm>
#include <iostream>

CCustomer::CCustomer(std::string name) {
	m_name = name;
}

void CCustomer::openAccount(int ID) {
	m_associatedAccountIDs.push_back(ID);
	std::cout << m_name << ": ";
	for (std::vector<int>::iterator it=m_associatedAccountIDs.begin(); it!=m_associatedAccountIDs.end(); ++it)
	    std::cout << ' ' << *it;
	std::cout << std::endl;
}

void CCustomer::deleteAccount(int ID) {
	std::vector<int>::iterator it = std::find(m_associatedAccountIDs.begin(), m_associatedAccountIDs.end(), ID);
	if(it != m_associatedAccountIDs.end()) {
		m_associatedAccountIDs.erase(it);
	}
}

std::vector<int> CCustomer::getAssociatedAccountIDs() {
	//std::sort(m_associatedAccountIDs.begin(), m_associatedAccountIDs.end());

	return m_associatedAccountIDs;
}

std::string CCustomer::getName() {
	return m_name;
}
