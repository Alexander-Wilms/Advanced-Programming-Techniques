/*
 * CSort.h
 *
 *  Created on: 05.11.2017
 *      Author: awilms
 */

#ifndef CSORT_H_
#define CSORT_H_

class CSort {
public:
	CSort(int initialMaxElements = 10, int addElements = 5);
	~CSort();
	void addElement(int a);
	void printList();
	void sortList();
private:
	void quicksort(int* pList, int lo, int hi);
	int partition(int* pList, int lo, int hi);
	int m_numberElements;
	int m_maxElements;
	int m_addElements;
	int* m_pList;
};

#endif /* CSORT_H_ */
