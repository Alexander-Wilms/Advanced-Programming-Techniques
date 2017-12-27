/*
 * CJsonToken.cpp
 *
 *  Created on: 10.12.2015
 *      Author: mnl
 */

#include "CJsonToken.h"

using namespace std;

namespace APT {

CJsonToken::CJsonToken(TokenType type) {
	this->type = type;
}

CJsonToken::~CJsonToken() {
}

CJsonToken::TokenType CJsonToken::getType() {
	return type;
}

string CJsonToken::str() {
	switch (type) {
	case BEGIN_OBJECT:
		return "begin_object";
	case END_OBJECT:
		return "end_object";
	case BEGIN_ARRAY:
		return "begin_array";
	case END_ARRAY:
		return "end_array";
	case NAME_SEPARATOR:
		return "name_separator";
	case VALUE_SEPARATOR:
		return "value_separator";
	case STRING:
		return "string";
	case NUMBER:
		return "number";
	case BOOL:
		return "bool";
	case JSON_NULL:
		return "null";
	}
	return "";
}

}

/* namespace APT */

