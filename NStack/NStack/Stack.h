#pragma once
#include <iostream>
#include "Exception.h"

template <typename ELEM>
class Stack
{
protected:
	ELEM *mass;
	size_t maxSize;
	size_t currentElem;
public:

	Stack() :maxSize(0), currentElem(0),mass(0) {};

	Stack(size_t size) :Stack()
	{
		maxSize = size;
		this->mass = new ELEM[size];
	}

	virtual ~Stack()
	{
		if(mass != 0)
		delete[] mass;
	}

	void push(const ELEM& elem)
	{
		if (this->currentElem == this->maxSize) // Не переполнен ли стек?
			throw STACK_OVERFLOW;

		this->mass[this->currentElem++] = elem;
	}

	ELEM pop()
	{
		if (this->currentElem == 0) // Не пусты ли стек?
			throw STACH_UNDERFLOW;

		return this->mass[--this->currentElem];
	}

	void operator+(const ELEM& elem)
	{
		push(elem);
	}

	ELEM operator-()
	{
		return pop();
	}

	virtual void resize(size_t newSize,bool autoSlice = true)
	{
		if (newSize < 0)
			throw STACK_ERROR_SIZE;
		ELEM *tmp;
		size_t tmpMS = maxSize;
		maxSize = newSize;
		
		if (currentElem > maxSize && autoSlice)
			currentElem = maxSize;
		else
			throw STACK_SAFE_RESIZE;
		
		tmp = new ELEM[maxSize];

		for (size_t i = 0; i < maxSize && i < tmpMS; i++)
		{
			tmp[i] = mass[i];
		}

		delete[] mass;
		mass = tmp;
	}

	ELEM operator[](size_t index) const
	{
		if (index >= maxSize)
			throw STACK_ERROR_INDEX;
		return mass[index];
	}

	size_t getCountFreeElements()
	{
		return maxSize - currentElem;
	}

	size_t getMaxSize()
	{
		return maxSize;
	}

	size_t getSize()
	{
		return currentElem;
	}

	friend std::ostream& operator<<(std::ostream& os, Stack<ELEM>& st)
	{
		os << "Stack {size:" << st.maxSize << ", elements:{ ";
		for (size_t i = 0; i< st.currentElem; i++)
			os << st[i] << (i!= st.currentElem-1?",":"");
		os << " }";
		return os;
	}//
};
