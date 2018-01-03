/*
 * A.h
 *
 *  Created on: 28.12.2017
 *      Author: Fabian Alexander Wilms
 */

#ifndef MYCODE_A_H_
#define MYCODE_A_H_

#include <list>
#include <string>

class A {
private:
	std::list<std::string*> myList;
public:
	A(std::string* element) {
		myList.push_back(element);
	}

	A& operator=(const A& a) {
		myList = a.myList;
		return *this;
	}

	~A();
};

#endif /* MYCODE_A_H_ */
