#include<iostream>
#include<fstream>
#include <iomanip>
#include"List.h"

using namespace std;

int main() {
	List list1, list2;

	//list1: 2 3 4 5 1 2 3 4 5 1 
	for (int i = 1; i < 11; i++) list1.push_back(i%5+1);
	cout << "The first list: " << list1 << endl;
	cout << "Size of the first list: " << list1.get_size() << endl << endl;

	//list2: 1 2 3 4
	for (int i = 2; i < 5; i++) list2.push_back(i);
	list2.push_front(1);

	cout << "The second list: " << list2 << endl;
	cout << "Size of the second list: " << list2.get_size() << endl << endl;

	cout << "The second element of the first list is: " << list1.at(1) << endl;
	cout << "The last element of the second list is: " << list2.at(list2.get_size() - 1) << endl << endl;

	//Find the first occurrence of list2 in the list1
	cout << "\nThe first occurrence of another list in the list: " << list1.find_first(list2) << endl;

	list1.pop_back();
	cout << "\nThe first list after removing the last element: " << list1 << endl;

	list1.pop_front();
	cout << "\nThe first list after removing the first element: " << list1 << endl;

	list1.insert(7, 5);
	cout << "\nThe first list after adding element with value 7 by index 5: " << list1 << endl;

	list1.remove(4);
	cout << "\nThe first list after removing the fourth element: " << list1 << endl;

	list1.set(2, 1);
	cout << "\nThe first list after replacing the second element by 1: " << list1 << endl;

	//Removing all elements of the first list
	list1.clear();

	//Checking if the lists is empty
	if (list1.isEmpty())
		cout << "\nThe first list is empty.\n";
	else
		cout << "\nThe first list is not empty.\n";

	if (list2.isEmpty())
		cout << "\nThe second list is empty.\n";
	else
		cout << "\nThe second list is not empty.\n";
	return 0;
}