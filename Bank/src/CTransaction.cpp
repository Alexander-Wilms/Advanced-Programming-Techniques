#include "CTransaction.h"
#include <string>

CTransaction::CTransaction(CAccount* fromAccount, CAccount* toAccount,
		float amount, std::string date) {
	m_fromAccount = fromAccount;
	m_toAccount = toAccount;
	m_amount = amount;
	m_date = date;
}

CAccount CTransaction::getFromAccount() {
	return *m_fromAccount;
}

CAccount CTransaction::getToAccount() {
	return *m_toAccount;
}

float CTransaction::getAmount() {
	return m_amount;
}

std::string CTransaction::getDate() {
	return m_date;
}
