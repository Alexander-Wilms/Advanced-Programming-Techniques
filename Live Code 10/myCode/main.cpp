// Copyright HDA
#include <iostream>				
#include <stdlib.h>
#include <algorithm>

using namespace std;			


#include "BasicTest.h"
using namespace Test;

void findSmallest (int& value, int& index, int values[], int valueCount) {
	int refValue = values[0];
	int refIndex = 0;

	for (int i = 1; i < valueCount; i++) {
		if (values[i] < refValue) {
			refValue = values[i];
			refIndex = i;
		}
	}
	index = refIndex;
	value = refValue;
}

void removeFromArray (int toBeRemoved, int values[], int& valueCount) {
	for (int i = toBeRemoved; i + 1 < valueCount; i++) {
		values[i] = values[i + 1];
	}
	valueCount -= 1;
}

void naiveSort (int sorted[], int values[], int valueCount) {

	int sortedIndex = 0;
	while (valueCount > 0) {
		int smallest;
		int smallestIndex;

		findSmallest(smallest, smallestIndex, values, valueCount);
		sorted[sortedIndex++] = smallest;
		removeFromArray(smallestIndex, values, valueCount);
	}
}

void quicksort1(int values[], int valueCount) {
	int pivot = values[0];

	int* smaller = new int[valueCount - 1]; // worst case
	int* greater = new int[valueCount - 1]; // worst case
	int* pSmaller = smaller;
	int* pGreater = greater;

	for (int i = 1; i < valueCount; i++) {
		if (values[i] < pivot) {
			*pSmaller++ = values[i];
		} else {
			*pGreater++ = values[i];
		}
	}

	int* pRes = values;
	for (int* p = smaller; p < pSmaller;) {
		*pRes++ = *p++;
	}
	*pRes++ = pivot;
	for (int* p = greater; p < pGreater;) {
		*pRes++ = *p++;
	}
	delete [] smaller;
	delete [] greater;

	if (pSmaller - smaller >= 2) {
		quicksort1(values, pSmaller - smaller);
	}
	if (pGreater - greater >= 2) {
		quicksort1(values + (pSmaller - smaller) + 1, pGreater - greater);
	}
}

void quicksort2(int values[], int valueCount) {
	int* pivot = values;
	int* right = values + valueCount - 1;
	int* left = values;

	while (true) {
		// search not yet looked at from end
		while (right > pivot && *right >= *pivot) {
			right -= 1;
		}
		if (right == pivot) {
			// nothing left to search
			break;
		}
		// if we get here *right < *pivot
		swap (*right, *pivot);
		left = pivot + 1; // leftmost element not yet looked at
		pivot = right; // pivot is here now
		// search not yet looked at from left
		while (left < pivot && *left <= *pivot) {
			left += 1;
		}
		if (left == pivot) {
			// nothing left to search
			break;
		}
		// if we get here *left > *pivot
		swap (*left, *pivot);
		right = pivot - 1; // rightmost element not yet looked at
		pivot = left; // pivot is here now
	}

	if (pivot - values >= 2) {
		quicksort2(values, pivot - values);
	}
	if (values - pivot + valueCount - 1 >= 2) {
		quicksort2(pivot + 1, values - pivot + valueCount - 1);
	}
}

int main (void)
{
//	int values [] = { 6, 2, 5, 9, 8, 3 };

//	int smallest;
//	int smallestIndex;
//
//	findSmallest(smallest, smallestIndex, values, 6);
//
//	cout << "Smallest value is " << smallest
//			<< " found at index " << smallestIndex << endl;
//
//	int valueCount = 6;
//	removeFromArray(smallestIndex, values, valueCount);
//
//	cout << "Left after removal:" << endl;
//	for (int i = 0; i < valueCount; i++) {
//		cout << values[i] << " ";
//	}
//	cout << endl;

//////////////////////////////////////////

//	int sorted[6];
//	naiveSort(sorted, values, 6);
//
//	cout << "Sorted:" << endl;
//	for (int i = 0; i < 6; i++) {
//		cout << sorted[i] << " ";
//	}
//	cout << endl;
//
//	int moreValues[100000];
//	int moreSorted[100000];
//	cout << "Sorting starts" << endl;
//	naiveSort(moreSorted, moreValues, 100000);
//	cout << "Sorting ends" << endl;

//	quicksort1(values, 6);
//	cout << "Sorted:" << endl;
//	for (int i = 0; i < 6; i++) {
//		cout << values[i] << " ";
//	}
//	cout << endl;
//
//	int moreValues[100000];
//	cout << "Sorting starts" << endl;
//	quicksort1(moreValues, 100000);
//	cout << "Sorting ends" << endl;

////////////////////////////////////////

//	quicksort2(values, 6);
//	cout << "Sorted:" << endl;
//	for (int i = 0; i < 6; i++) {
//		cout << values[i] << " ";
//	}
//	cout << endl;
//
//	int moreValues[100000];
//	for (int i = 0; i < 100000; i++) {
//		moreValues[i] = (i + 50000) % 100000;
//	}
//	cout << "Sorting starts" << endl;
//	quicksort2(moreValues, 100000);
//	cout << "Sorting ends" << endl;
//
//	for (int i = 0; i < 100000 - 1; i++) {
//		if (moreValues[i] > moreValues[i + 1]) {
//			cerr << "Found error" << endl;
//		}
//	}

	BasicTest test;
	test.run();

	return EXIT_SUCCESS;		
}
