// GIT-Labor
// main.h

////////////////////////////////////////////////////////////////////////////////
// Header-Dateien
#include <iostream>
#include <list>

using namespace std;


// Hauptprogramm
// Dient als Testrahmen, von hier aus werden die Klassen aufgerufen
int main (void)
{

	list<int> myList;

	list<int>::iterator it = myList.end();
	myList.insert(it,1);
	myList.insert(it,2);

	list<int>::reverse_iterator rit = myList.rbegin();
	myList.insert(rit.base(),3);

	int count = 0;

	for (it = myList.begin(); it != myList.end(); ++it)
	{
		cout << "Pos: " << count++ << " Value: " << *it << endl;
	}

	return 0;
}
