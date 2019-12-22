#pragma once
#include <stdexcept>

template <typename T>
class Deque
{

public:
	Deque();
	Deque(const Deque<T>& other);
	Deque<T>& operator=(const Deque<T>& other);
	~Deque();

public:
	void pushFront(const T& newElem);
	void pushBack(const T& newElem);
	void popFront();
	void popBack();
	bool isEmpty()const;
	const T& front()const;
	const T& back()const;

public:
	const T& operator[](size_t index)const;
	T& operator[](size_t index)const;

private:
	void copyFrom(const Deque<T>& other);
	void clear();
	void resize();
	size_t getSize()const
	{
		return size;
	}

	size_t getCapacity()const
	{
		return capacity;
	}
private:
	T** deque;
	
	size_t size;
	size_t capacity;

	size_t front;
	size_t back;

};

template <typename T>
Deque<T>::Deque() : deque(nullptr) , size(0) , capacity(0){

}

template <typename T>
Deque<T>& Deque<T>::operator=(const Deque<T>& other)
{
	if (this != &other)
	{
		clear();
		copyFrom(other);
	}

	return *this;
}

template<typename T>
Deque<T>::~Deque()
{
	clear();
}

template<typename T>
Deque<T>::Deque(const Deque<T>& other)
{
	copyFrom(other);
}

template<typename T>
void Deque<T>::clear()
{
	for (size_t i = 0; i < size; ++i)
	{
		delete deque[i];
	}
	return;
}

template<typename T>
Deque<T>::copyFrom(const Deque<T>& other)
{
	deque = new T[other.getCapacity];
	
	size_t size = other.size;

	for (size_t i = 0; i < size; ++i)
	{
		deque[i] = new T(other[i]);
	}

	this->size = other.size;
	return;
}

template<typename T>
const T& Deque<T>::operator[](size_t index)const
{
	if (index >= size)
	{
		throw std::out_of_range("Invalid index");
	}
	whichElement = (front + index) % size;

	return deque[whichElement];
}

template<typnema T>
T& Deque<T>::operator[](size_t index)const
{
	if (index >= size)
	{
		throw std::out_of_range("Invalid index");
	}

	whichElement = (front_index) % size;

	return deque[whichElement];
}