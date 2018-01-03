/*
 * main.cpp
 *
 *  Created on: 05.11.2017
 *      Author: Fabian Alexander Wilms
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

	// fill CSort instance with 15 random values
	for (int i = 0; i < 15; i++) {
		sort.addElement(rand() % 100);
	}
	std::cout << "non-sorted list: " << std::endl;
	sort.printList();
	sort.sortList();
	std::cout << "sorted list: " << std::endl;
	sort.printList();

	std::cout << "CSort_t with CCoordinates" << std::endl;
	CSort_t<CCoordinate> sort_coord;
	for (int i = 0; i < 15; i++) {
		CCoordinate coordinate(rand() % 100, rand() % 100);
		sort_coord.addElement(coordinate);
	}
	sort_coord.printList();
	sort_coord.sortList();
	sort_coord.printList();

	std::cout << "compare runtime of CSort and std::list & std::sort() for integers" << std::endl;
	int value;
	CSort_t<int> sortTestInt;
	std::list<int> listTestInt;
	CSort_t<CCoordinate> sortTestCoordinate;
	std::list<CCoordinate> listTestCoordinate;
	std::cout.precision(17);
	std::chrono::duration<double>  elapsed;

	for (int i = 0; i < 100; i++) {
		value = rand() % 100;
		sortTestInt.addElement(value);
		listTestInt.push_back(value);
	}

	auto start = std::chrono::high_resolution_clock::now();
	sortTestInt.sortList();
	auto finish = std::chrono::high_resolution_clock::now();
	elapsed = finish - start;
	std::cout << "Sorting 100 integers with CSort: \t\t\t" << elapsed.count() << " s"
			<< std::endl;

	start = std::chrono::high_resolution_clock::now();
	listTestInt.sort();
	finish = std::chrono::high_resolution_clock::now();
	elapsed = finish - start;
	std::cout << "Sorting 100 integers with std::list & std::sort(): \t" << elapsed.count() << " s"
			<< std::endl;

	for (int i = 0; i < 100000; i++) {
		value = rand() % 100;
		sortTestInt.addElement(value);
		listTestInt.push_back(value);
	}

	start = std::chrono::high_resolution_clock::now();
	sortTestInt.sortList();
	finish = std::chrono::high_resolution_clock::now();
	elapsed = finish - start;
	std::cout << "Sorting 100000 random integers with CSort: \t\t\t" << elapsed.count() << " s"
			<< std::endl;

	start = std::chrono::high_resolution_clock::now();
	listTestInt.sort();
	finish = std::chrono::high_resolution_clock::now();
	elapsed = finish - start;
	std::cout << "Sorting 100000 random integers with std::list & std::sort(): \t" << elapsed.count() << " s"
			<< std::endl;

	for (int i = 0; i < 100; i++) {
		CCoordinate coordinate(rand() % 100, rand() % 100);
		sortTestCoordinate.addElement(coordinate);
		listTestCoordinate.push_back(coordinate);
	}

	start = std::chrono::high_resolution_clock::now();
	sortTestCoordinate.sortList();
	finish = std::chrono::high_resolution_clock::now();
	elapsed = finish - start;
	std::cout << "Sorting 100 random random coordinates with CSort: \t\t\t" << elapsed.count() << " s"
			<< std::endl;

	start = std::chrono::high_resolution_clock::now();
	listTestCoordinate.sort();
	finish = std::chrono::high_resolution_clock::now();
	elapsed = finish - start;
	std::cout << "Sorting 100 random random coordinates with std::list & std::sort(): \t" << elapsed.count() << " s"
			<< std::endl;

	for (int i = 0; i < 100000; i++) {
		CCoordinate coordinate(rand() % 100, rand() % 100);
		sortTestCoordinate.addElement(coordinate);
		listTestCoordinate.push_back(coordinate);
	}

	start = std::chrono::high_resolution_clock::now();
	sortTestCoordinate.sortList();
	finish = std::chrono::high_resolution_clock::now();
	elapsed = finish - start;
	std::cout << "Sorting 100000 random coordinates with CSort: \t\t\t" << elapsed.count() << " s"
			<< std::endl;

	start = std::chrono::high_resolution_clock::now();
	listTestCoordinate.sort();
	finish = std::chrono::high_resolution_clock::now();
	elapsed = finish - start;
	std::cout << "Sorting 100000 random coordinates with std::list & std::sort(): \t" << elapsed.count() << " s"
			<< std::endl;

	return 0;
}
