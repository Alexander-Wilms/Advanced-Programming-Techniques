/*
 * CSort.h
 *
 *  Created on: 05.11.2017
 *      Author: Fabian Alexander Wilms
 */

#ifndef CSORT_H_
#define CSORT_H_

class CSort {
private:
	int m_numberElements;
	int m_maxElements;
	int m_addElements;
	int* m_pList;

	void quicksort(int* pList, int lo, int hi);
	int partition(int* pList, int lo, int hi);
public:
	CSort(int initialMaxElements = 10, int addElements = 5);
	~CSort();
	void addElement(int a);
	void printList();
	void sortList();
};

#endif /* CSORT_H_ */
