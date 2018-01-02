/*
 * BasicTest.cpp
 *
 *  Created on: 05.09.2012
 *      Author: mnl
 */

#include <iostream>
using namespace std;

#include "BasicTest.h"
using namespace APT;

namespace Test {

#define FILENAME "AddressDB.txt"

int BasicTest::menu()
{
	int key;

	cout << "1 - Load records from file" << endl;
	cout << "2 - Save records to file" << endl;
	cout << "3 - Enter record by keyboard" << endl;
	cout << "4 - Print all records" << endl;
	cout << "5 - Print filtered records" << endl;
	cout << "6 - Print sorted records" << endl;
	cout << "7 - Print records sorted by address" << endl;
	cout << "8 - Lookup by number" << endl;
	cout << endl << "0 - End" << endl;

	cout << "Your choice:";
	cin >> key;
	cout << endl;

	//HACK Clear return key
	string s;
	getline(cin,s);

	return key;

}

void BasicTest::appendFromKeyboard()
{
	string name, Address;
	int phone;

	//Get the data
	cout << "Enter your data: ";
	//cin only reads until whitespace, therefore getline is used
	cout << endl << "Name: ";
	getline(cin,name);
	cout << endl << "Address: ";
	getline(cin,Address);
	cout << endl << "Phone: ";
	cin >> phone;

	//Store it as record
	m_db->addRecord(CRecord(name,Address,phone));
}


void BasicTest::run()
{
	m_db = new CAddressDB(FILENAME);

	bool end = false;
	while (!end)
	{
		int key = menu();
		switch (key)
		{
		case 1 :
			m_db->loadFromFile();
			break;
		case 2 :
			m_db->saveToFile();
			break;
		case 3 :
			appendFromKeyboard();
			break;
		case 4 :
			m_db->print(ALL);
			break;
		case 5 :
			m_db->print(FILTER);
			break;
		case 6 :
			m_db->print(SORTED);
			break;
		case 7 :
			m_db->print(SORTED_BY_ADDR);
			break;
		case 8: {
			cout << "Enter number: ";
			int phone;
			cin >> phone;
			const CRecord* result = m_db->findByNumber(phone);
			cout << "================" << endl;
			if (result == 0) {
				cout << "Not found" << endl;
			} else {
				cout << *result << endl;
			}
			cout << "================" << endl;
			break;
		}
		case 0 : end = true;
			break;
		default :
			cout << "Wrong selection [1..5]" << endl;
			break;

		}
	}

	delete m_db;
}

} /* namespace APT */
