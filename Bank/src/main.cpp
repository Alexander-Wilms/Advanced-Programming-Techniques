/*
 * main.cpp
 *
 *  Created on: 03.11.2017
 *      Author: Fabian Alexander Wilms
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
	bank.addAccount("Whoopie Goldberg", 100);
	bank.addAccount("Johnny Depp", 200);

	bank.generateReport();

	bank.performTransaction(123456, 123457, 20, "15.11.08");

	bank.generateReport();

	std::cout <<  "delete Paul Panther's 3rd account" << std::endl;
	bank.deleteAccount(123458);

	bank.generateReport();

	std::cout <<  "delete customer Paul Panther and all of his accounts" << std::endl;
	bank.deleteCustomer("Paul Panther");

	bank.generateReport();

	return 0;
}
