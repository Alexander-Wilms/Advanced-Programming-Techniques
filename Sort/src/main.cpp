/*
 * main.cpp
 *
 *  Created on: 05.11.2017
 *      Author: awilms
 */

#include "CSort.h"
#include "CSort_t.h"
#include "CCoordinate.h"
#include <ctime>
#include <iostream>
#include <stdlib.h>
#include <list>
#include <stdio.h>
#include <chrono>

int main(void) {
	srand(std::time_t(NULL));

	std::cout << "CSort" << std::endl;
	CSort sort;
	for (int i = 0; i < 15; i++) {
		sort.addElement(rand() % 100);
	}
	sort.printList();
	sort.sortList();
	sort.printList();

	std::cout << "CSort_t" << std::endl;
	CSort_t<CCoordinate> sort_coord;
	for (int i = 0; i < 15; i++) {
		CCoordinate coordinate;
		sort_coord.addElement(coordinate);
	}
	sort.printList();
	sort.sortList();
	sort.printList();

	int value;
	CSort_t<int> sortTest;
	std::list<int> listTest;
	std::cout.precision(17);
	std::chrono::duration<double>  elapsed;

	for (int i = 0; i < 100; i++) {
		value = rand() % 100;
		sortTest.addElement(value);
		listTest.push_back(value);
	}

	auto start = std::chrono::high_resolution_clock::now();
	sortTest.sortList();
	auto finish = std::chrono::high_resolution_clock::now();
	elapsed = finish - start;
	std::cout << "Sorting 100 elements with CSort: " << elapsed.count()
			<< std::endl;

	start = std::chrono::high_resolution_clock::now();
	listTest.sort();
	finish = std::chrono::high_resolution_clock::now();
	elapsed = finish - start;
	std::cout << "Sorting 100 elements with std::list: " << elapsed.count()
			<< std::endl;

	for (int i = 0; i < 100000; i++) {
		value = rand() % 100;
		sortTest.addElement(value);
		listTest.push_back(value);
	}

	start = std::chrono::high_resolution_clock::now();
	sortTest.sortList();
	finish = std::chrono::high_resolution_clock::now();
	elapsed = finish - start;
	std::cout << "Sorting 100000 elements with CSort: " << elapsed.count()
			<< std::endl;

	start = std::chrono::high_resolution_clock::now();
	listTest.sort();
	finish = std::chrono::high_resolution_clock::now();
	elapsed = finish - start;
	std::cout << "Sorting 100000 elements with std::list: " << elapsed.count()
			<< std::endl;

	return 0;
}
