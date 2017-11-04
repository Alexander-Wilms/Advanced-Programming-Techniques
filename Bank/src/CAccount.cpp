#include "CAccount.h"

CAccount::CAccount(std::string name, int ID, float initialBalance) {
	m_owner = name;
	m_ID = ID;
	m_balance = initialBalance;
}

void CAccount::withdraw(float amount) {
	m_balance -= amount;
}

void CAccount::deposit(float amount) {
	m_balance += amount;
}

std::string CAccount::getOwner() {
	return m_owner;
}

int CAccount::getID() {
	return m_ID;
}

float CAccount::getBalance() {
	return m_balance;
}
