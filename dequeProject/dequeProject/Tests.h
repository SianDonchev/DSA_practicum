#pragma once
#include <iostream>
#include "Deque.h"

const int FOR_EXAMPLE = 10000;
const int TO_REMOVE = 100;

void frontAndBackMethods(const Deque<int>& example)
{
	try
	{
		example.front();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	try
	{
		example.back();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

}

void tests()
{
	Deque<int> example;

	//pop from empty deque
	example.popFront();
	example.popBack();

	frontAndBackMethods(example);

	if (example.isEmpty())
	{
		//pop from deque with 1 element in it
		example.pushBack(1);
		example.popFront();
		if (example.isEmpty())
		{
			std::cout << "The queue is empty";
			frontAndBackMethods(example);
		}
	}

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

	frontAndBackMethods(example);

	example.print(std::cout);

	return;
}