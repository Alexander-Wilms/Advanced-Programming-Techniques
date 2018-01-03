#ifndef CTRANSACTION_H
#define CTRANSACTION_H

#include "CAccount.h"
#include <string>

class CTransaction
{
public:
	CTransaction (CAccount* fromAccount, CAccount* toAccount, float amount, std::string date);
	CAccount getFromAccount() const;
	CAccount getToAccount() const;
	float getAmount() const;
	std::string getDate() const;
	friend bool operator<(CTransaction& l, CTransaction& r);
private:
	CAccount* m_fromAccount;
	CAccount* m_toAccount;
	float m_amount;
	std::string m_date;
};

#endif // CTRANSACTION_H
