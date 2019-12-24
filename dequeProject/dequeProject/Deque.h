#pragma once
#include <stdexcept>
#include <fstream>

template <typename T>
class Deque
{

public:
	Deque();
	Deque(const Deque<T>& other);
	Deque<T>& operator=(const Deque<T>& other);
	~Deque();

public:
	void pushFront(const T& el);
	void pushBack(const T& el);
	void popFront();
	void popBack();
	bool isEmpty()const;
	void print(std::ostream& ofs)const;

	const T& front()const
	{
		if (isEmpty())
			throw std::logic_error("Deque is empty!");

		return *deque[frontIndex];
	}

	const T& back()const
	{
		if (isEmpty())
			throw std::logic_error("Deque is empty!");

		return *deque[backIndex];
	}

public:
	const T& operator[](size_t index)const;
	T& operator[](size_t index);

private:
	void copyFrom(const Deque<T>& other);
	void clear();

	void decreaseIndex(size_t& index)
	{
		if (index == 0)
			index = capacity - 1;
		else
			--index;
	}

	void increaseIndex(size_t& index)
	{
		if (index == capacity - 1)
			index = 0;
		else
			++index;
	}



	void resize();

private:
	T** deque;
	
	size_t size;
	size_t capacity;

	size_t frontIndex;
	size_t backIndex;

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

template <typename T>
Deque<T>::~Deque()
{
	clear();
}

template <typename T>
Deque<T>::Deque(const Deque<T>& other)
{
	copyFrom(other);
}

template <typename T>
void Deque<T>::clear()
{
	for (size_t i = 0; i < size; ++i)
	{
		delete &(*this)[i];
	}
	delete[] deque;

	return;
}

template <typename T>
void Deque<T>::print(std::ostream& ofs)const
{
	for (size_t i = 0; i < size; ++i)
	{
		ofs << (*this)[i];
	}

	return;
}

template <typename T>
void Deque<T>::copyFrom(const Deque<T>& other)
{
	deque = new T*[other.capacity];
	
	this->capacity = other.capacity;
	this->size = other.size;

	for (size_t i = 0; i < size; ++i)
	{
		deque[i] = new T(other[i]);
	}

	this->frontIndex = 0;
	this->backIndex = size - 1;

	return;
}

template <typename T>
const T& Deque<T>::operator[](size_t index)const
{
	if (index >= size)
	{
		throw std::out_of_range("Invalid index");
	}
	size_t whichElement = (frontIndex + index) % capacity;

	return *(deque[whichElement]);
}

template <typename T>
T& Deque<T>::operator[](size_t index)
{
	if (index >= size)
	{
		throw std::out_of_range("Invalid index");
	}

	size_t whichElement = (frontIndex + index) % capacity;

	return *(deque[whichElement]);
}

template <typename T>
void Deque<T>::resize()
{
	size_t newCapacity = capacity == 0 ? 1 : (capacity * 2);

	T** tempDeque = new T*[newCapacity];

	for (size_t i = 0; i < size; ++i)
	{
		tempDeque[i] = &(*this)[i];
	}

	frontIndex = 0;
	backIndex = size == 0 ? 0 : (size - 1);
	
	delete[] deque;
	capacity = newCapacity;
	deque = tempDeque;
}

template <typename T>
void Deque<T>::pushBack(const T& el)
{
	if (size == capacity)
	{
		resize();
	}
	
	increaseIndex(backIndex);
	deque[backIndex] = new T(el);
	++size;
	
}

template <typename T>
void Deque<T>::pushFront(const T& el)
{
	if (size == capacity)
	{
		resize();
	}

	decreaseIndex(frontIndex);
	deque[frontIndex] = new T(el);
	++size;
}

template <typename T>
bool Deque<T>::isEmpty()const
{
	return size == 0;
}

template <typename T>
void Deque<T>::popFront()
{
	if (isEmpty())
		return;

	delete deque[frontIndex];
	increaseIndex(frontIndex);

	--size;

	return;
}

template <typename T>
void Deque<T>::popBack()
{
	if (isEmpty())
		return;

	delete deque[backIndex];
	decreaseIndex(backIndex);

	--size;

	return;
}