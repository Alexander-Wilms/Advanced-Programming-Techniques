/*
 * CJsonToken.h
 *
 *  Created on: 10.12.2015
 *      Author: mnl
 */

#ifndef MYCODE_CJSONTOKEN_H_
#define MYCODE_CJSONTOKEN_H_

#include <string>
#include <sstream>

namespace APT {

/**
 * This is the base class for all tokens. It provides the
 * token type.
 */
class CJsonToken {
public:
	/**
	 * The different token types. See RFC7159
	 * (https://tools.ietf.org/html/rfc7159).
	 */
	enum TokenType { BEGIN_OBJECT, END_OBJECT, BEGIN_ARRAY, END_ARRAY,
		NAME_SEPARATOR, VALUE_SEPARATOR, STRING, NUMBER, BOOL, JSON_NULL };

	CJsonToken(TokenType type);
	virtual ~CJsonToken();

	/**
	 * Return the type of the token.
	 */
	TokenType getType();

	/**
	 * Allow convertion to string.
	 */
	virtual std::string str();

private:
	TokenType type;

};

/**
 * This template is used to define special tokens that have an associated
 * value of the given type. This is not intended to be used by programmers.
 * Use the derived types CJsonStringToken, CJsonNumberToken and
 * CJsonBoolToken instead.
 */
template <CJsonToken::TokenType tokenType, class T>
class CJsonValueToken : public CJsonToken {
private:
	T value;

public:
	/**
	 * Create a token with the given value.
	 */
	CJsonValueToken(T value) : CJsonToken(tokenType) {
		this->value = value;
	}

	/**
	 * Return the value associated with the token.
	 */
	T getValue() const {
		return value;
	}

	std::string str() {
		std::ostringstream res;
		res << CJsonToken::str() << ": " << value;
		return res.str();
	}
};

/**
 * A string token associated with a string value.
 */
typedef CJsonValueToken<CJsonToken::STRING, std::string> CJsonStringToken;

/**
 * A number token associated with a double value.
 */
typedef CJsonValueToken<CJsonToken::NUMBER, double> CJsonNumberToken;

/**
 * A bool(ean) token associated with a bool(ean).
 */
typedef CJsonValueToken<CJsonToken::BOOL, bool> CJsonBoolToken;

} /* namespace APT */

#endif /* MYCODE_CJSONTOKEN_H_ */
