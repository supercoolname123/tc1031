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
	list.create(-1, 4);
	list.printList();

	list.update(1, 7);
	list.printList();

	list.del(2);
	list.printList();
}

