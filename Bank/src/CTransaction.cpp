#include "CTransaction.h"
#include <string>

CTransaction::CTransaction(CAccount* fromAccount, CAccount* toAccount,
		float amount, std::string date) {
	m_fromAccount = fromAccount;
	m_toAccount = toAccount;
	m_amount = amount;
	m_date = date;
}

CAccount CTransaction::getFromAccount() const {
	return *m_fromAccount;
}

CAccount CTransaction::getToAccount() const {
	return *m_toAccount;
}

float CTransaction::getAmount() const {
	return m_amount;
}

std::string CTransaction::getDate() const {
	return m_date;
}

bool operator<(CTransaction& l, CTransaction& r) {
	return l.getFromAccount().getID() < r.getFromAccount().getID();
}
