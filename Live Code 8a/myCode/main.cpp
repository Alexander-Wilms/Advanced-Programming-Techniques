#include <iostream>
#include <string>

#include <vector>
#include <list>
#include <map>
#include <exception>

#include <algorithm>

using namespace std;

void demoException()
{
	vector<int> myVector;
	map<int, string> myMap;

	try
	{
		//myVector.at(2000) = 3;
		//myVector[2000] = 3;
		//myMap[2] = "Hi";
		myMap.at(2) = "hi";
		cout << "Everything fine" << endl;
	}
	catch (exception &e)
	{
		cout << "Error: " << e.what() << endl;
	}
}

void demoVector()
{
	vector<string>  myVector;

	//Adding some data
	myVector.push_back("one");
	myVector.push_back("two");

	//This works with vectors and deques, but not the rest. Therefore not recommended
	for (unsigned int i = 0; i < myVector.size(); i++)
	{
		cout << "ELement at " << i << " has the value " << myVector[i] << endl;
	}

	vector<string>::iterator myIt;

	for (myIt = myVector.begin(); myIt != myVector.end(); ++myIt)
	{
		//Attention: *myIt is using an overloaded operator
		cout << "Element : " << *myIt << endl;
	}

	vector<unsigned int> myVector2;


	cout << "Playing with a growing list" << endl;
	for (unsigned int i = 0; i < 10; ++i)
	{
		myVector2.push_back(i);

		cout << "The list currently has the size " << myVector2.size() << "and the capacity " << myVector2.capacity() << endl;

#if 1
		for (vector<unsigned int>::iterator myIt2 = myVector2.begin(); myIt2 != myVector2.end(); ++myIt2)
		{
			//Attention: *myIt is using an overloaded operator
			cout << "Element : " << *myIt2 << " stored at adress " << &(*myIt2) << endl;
		}
#endif

	}

	//Reverse iterator
	cout << "Traversing the vector in reverse order" << endl;
	for (vector<unsigned int>::reverse_iterator myIt2 = myVector2.rbegin(); myIt2 != myVector2.rend(); ++myIt2)
	{
		//Attention: *myIt is using an overloaded operator
		cout << "Element : " << *myIt2 << " stored at adress " << &(*myIt2) << endl;
	}


}


void demoList()
{
	list<string> myList;

	myList.push_back("one");
	myList.push_back("three");

	list<string>::iterator i;

	//Search for the Element "one"
	for (i = myList.begin(); i != myList.end(); ++i)
	{
		if ((*i) == "one")
		{
			break;
			//Let's leave the loop once we have found the element
		}
	}

	//Insert another element after "one"
	myList.insert(++i,"two");

	//Print the list
	for (i = myList.begin(); i != myList.end(); ++i)
	{
		cout << "Element: " << *i << endl;
	}

	//Simpler way to search for an element
	i = find(myList.begin(), myList.end(), "three");
	cout << "Element found using find() : " << *i << endl;

}

void demoMap()
{
	map<int, string> myMap;

	myMap.insert(pair<int, string>(1,"One"));

	//Easier style
	myMap[4] = "Four";
	myMap[2] = "Two";

	map<int, string>::iterator i;



	cout << "Element at 3" << myMap[3] << endl;

	cout << "Element at 3 (at)" << myMap.at(3) << endl;

	myMap.at(3) = "Three";

	for (i = myMap.begin(); i != myMap.end(); ++i)
	{
		cout << "Element: " << i->first << " content " << i->second << endl;
	}
}

int main (void)
{

	demoVector();
	//demoList();
	//demoMap();

	//demoException();


#if 0
	//Maps
	map<int, string> myMap;

	myMap[1] = "one";
	myMap[3] = "three";

	cout << "Test: " << myMap[2] << "|"<< endl;

	string result;

	demoException();
#endif

	return 0;
}
