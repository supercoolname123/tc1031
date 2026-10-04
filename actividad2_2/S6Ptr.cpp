#include <iostream>
#include "FLinked.h"

int main()
{     
	/*FLinked<int> testCreateAtZero;
	testCreateAtZero.create(0, 1);
	testCreateAtZero.printList();
	testCreateAtZero.create(0, 2);
	testCreateAtZero.printList();*/

	FLinked<int> list;

	list.create(0, 1);
	list.create(1, 2);
	list.create(2, 3);
	list.create(100, 5);
	list.create(100, 4);
	list.printList();

	list.update(1, 7);
	list.printList();

std::cout << list.read(4) << std::endl;
std::cout << list.read(3) << std::endl;
std::cout << list.read(2) << std::endl;
std::cout << list.read(1) << std::endl;
std::cout << list.read(0) << std::endl;

	list.create(0, 1);
}

