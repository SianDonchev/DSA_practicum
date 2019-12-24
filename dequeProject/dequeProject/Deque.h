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
	void pushFront(const T& el);
	void pushBack(const T& el);
	void popFront();
	void popBack();
	bool isEmpty()const;

	const T& front()const
	{
		if (isEmpty())
			throw std::logic_error("Deque is empty!");

		return deque[frontIndex];
	}

	const T& back()const
	{
		if (isEmpty())
			throw std::logic_error("Deque is empty!");

		return deque[backIndex];
	}

public:
	const T& operator[](size_t index)const;
	T& operator[](size_t index)const;

private:
	void copyFrom(const Deque<T>& other);
	void clear();

	void increaseBackIndex()
	{
		if (backIndex == (capacity - 1))
			backIndex = 0;
		else
			++backIndex;
	}

	void decreaseBackIndex()
	{
		if (backIndex == 0)
			backIndex == capacity - 1;
		else
			--backIndex;
	}

	void decreaseFrontIndex()
	{
		if (frontIndex == 0)
			frontIndex = capacity - 1;
		else
			--frontIndex;
	}

	void increaseFrontIndex()
	{
		if (frontIndex == capacity - 1)
			frontIndex = 0;
		else
			++frontIndex;
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
		delete deque[i];
	}
	delete[] deque;

	return;
}

template <typename T>
Deque<T>::copyFrom(const Deque<T>& other)
{
	deque = new T*[other.capacity];
	
	this->capacity = other.capacity;
	this->size = other.size;

	for (size_t i = 0; i < size; ++i)
	{
		deque[i] = new T(other[i]);
	}

	return;
}

template <typename T>
const T& Deque<T>::operator[](size_t index)const
{
	if (index >= size)
	{
		throw std::out_of_range("Invalid index");
	}
	whichElement = (frontIndex + index) % size;

	return *(deque[whichElement]);
}

template <typenema T>
T& Deque<T>::operator[](size_t index)const
{
	if (index >= size)
	{
		throw std::out_of_range("Invalid index");
	}

	whichElement = (frontIndex + index) % size;

	return *(deque[whichElement]);
}

template <typename T>
void Deque<T>::resize()
{
	newCapacity = capacity == 0 ? 1 : (capacity * 2);

	T** tempDeque = new T*[newCapacity];

	for (int i = 0; i < size; ++i)
	{
		tempDeque[i] = (*this)[i];
	}

	frontIndex = 0;
	backIndex = size - 1;
	
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
	
	increaseBackIndex();
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

	decreaseFrontIndex();
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
	increaseFrontIndex();

	--size;

	return;
}

template <typename T>
void Deque<T>::popBack()
{
	if (isEmpty())
		return;

	delete deque[backIndex];
	decreaseBackIndex();

	--size;

	return;
}