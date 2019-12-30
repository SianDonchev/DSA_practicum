#include <iostream>
#include "Deque.h"

const int FOR_EXAMPLE = 10000;
const int TO_REMOVE = 100;

int main()
{
	Deque<int> example;

	//add 10000 elements
	for (int i = 0; i < FOR_EXAMPLE; ++i)
	{
		if (example.isEmpty())
		{
			example.pushBack(i);
		}
		//if i is a prime number add to the front
		if (i % 2 == 0)
		{
			example.pushFront(i);
		}
		//else add to the back
		else
		{
			example.pushBack(i);
		}
	}

	//if the "front" and the "back" are different from 0
	if (example.front() != 0 && example.back() != 0)
	{
		//remove the first and last 50 elements
		for (int i = 0; i < TO_REMOVE; ++i)
		{
			if (i % 2 == 0)
				example.popBack();
			else
				example.popFront();
		}
	}

	example.print(std::cout);

	return 0;
}