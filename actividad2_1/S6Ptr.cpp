#include <iostream>
#include "FLinked.h"

int main()
{     
	FLinked<int> list;

	list.create(1, 0);
	list.create(2, 1);
	list.create(3, 1);
	list.update(1, 7);

	std::cout << list[0];
	std::cout << list[1];
	std::cout << list[2];
	std::cout << std::endl;

	list.del(2);
	std::cout << list.read(0);
	std::cout << list.read(1);
}

