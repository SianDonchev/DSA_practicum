#include <iostream>
#include "Deque.h"

int main()
{
	Deque<int> d1;
	d1.pushFront(3);
	d1.pushFront(5);
	d1.pushFront(8);
	d1.pushBack(11);
	d1.pushBack(132);
	d1.pushFront(545);
	d1.popBack();
	d1.popBack();
	d1.popBack();

	Deque<int> d2 = d1;

	{
		Deque<int> d3;
		d3.pushBack(1);
		d3 = d2;

		d3.print(std::cout);
	}
	std::cout << std::endl;
	d1.print(std::cout);
	std::cout << std::endl;
	d2.print(std::cout);
	std::cout << std::endl;


	std::cout << d2.front();
	std::cout << std::endl;
	std::cout << d2.back();

	d1 = d1;

	return 0;
}