#pragma once
#include "Stack.h"

template<class T>
class VStack :
	public Stack<T>
{
	size_t start;
public:
	VStack() :Stack() {
		start = 0;
	};
	VStack(T* point, size_t Size) :Stack()
	{
		mass = point;
		this->maxSize = Size;
		start = 0;
	};
	VStack(VStack& vs)
	{
		mass = vs.mass;
		maxSize = vs.Size;
		start = vs.start;
		currentElem = vs.currentElem;
	};
	VStack& operator=(VStack& vs)
	{
		mass = vs.mass;
		maxSize = vs.maxSize;
		start = vs.start;
		currentElem = vs.currentElem;
		return *this;
	};
	virtual ~VStack() { mass = 0; }
	void setPointer(T* p)
	{
		mass = p;
	}
	void setStart(size_t start_index)
	{
		start = start_index;
	}
	void pointerShift(int shift)
	{
		mass += shift;
	}
	size_t getStart()
	{
		return start;
	}
	void resize(size_t newSize, bool autoSlice = true)
	{
		if (newSize == maxSize)
			return;
		if (newSize < 0)
			throw STACK_ERROR_SIZE;

		if (currentElem > newSize && autoSlice)
			currentElem = newSize;
		else if(currentElem > newSize && !autoSlice)
			throw STACK_SAFE_RESIZE;

		this->maxSize = newSize;
	}
};
