/*
 * main.cpp
 *
 *  Created on: 03.11.2017
 *      Author: awilms
 */

#include "CBank.h"
#include <iostream>

int main(void) {
	CBank bank;

	// Generate the customers "Paul Panther" and "Whoopie Goldberg"
	bank.addCustomer("Paul Panther");
	bank.addCustomer("Whoopie Goldberg");

	// Open new accounts for the customers
	bank.addAccount("Paul Panther", 100);
	bank.addAccount("Paul Panther", 200);
	bank.addAccount("Paul Panther", 200);
	bank.addAccount("Whoopie Goldberg", 200);
	bank.addAccount("Johnny Depp", 200);

	bank.generateReport();

	bank.performTransaction(111117, 228077, 20, "15.11.08");

	bank.generateReport();

	bank.deleteAccount(111117);

	bank.generateReport();

	bank.deleteCustomer("Paul Panther");

	bank.generateReport();

	return 0;
}
