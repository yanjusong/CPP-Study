#include <iostream>
using namespace std;

#include "List.h"

int main()
{
	List<int> li;
	
	// test push_back
	li.push_back(1);
	li.push_back(2);
	li.printList();

	// test push_front
	li.push_front(-1);
	li.printList();

	// test pop_front
	li.pop_front();
	li.printList();

	// test remove
	li.push_back(3);
	li.push_back(4);
	li.push_back(5);
	cout << li.size() << endl;
	li.printList();
	

	li.remove(5);
	li.printList();
	li.remove(1);
	li.printList();
	li.remove(2);
	li.printList();

	// test clear
	li.clear();
	li.printList();

	// test insert
	li.insert(1, 1);
	li.insert(2, 3);
	li.insert(2, 2);
	li.printList();

	// test reverse
	li.reverse();
	li.printList();

	// test sort
	li.sort();
	li.printList();

	// test friend operator<<
	cout << li;

	// test find
	cout << li.find(2) << endl;
	cout << li.find(4) << endl;

	// test count
	cout << li.count(1) << endl;
	li.push_back(1);
	cout << li.count(1) << endl;

	system("pause");
	return 0;
}