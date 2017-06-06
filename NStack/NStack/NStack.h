#pragma once
#include "VStack.h"
#include "Exception.h"
#include <iostream>
#include <fstream>

template<class ELEM>
class NStack
{
	ELEM * generalMem;
	VStack<ELEM> * allStack;

	size_t elemCount;
	size_t elemUsed;
	size_t stackCount;

public:
	
	void readOfFile()
	{
		delete[] generalMem;
		delete[] allStack;

		std::ifstream read("stack");
		read >> elemCount;
		read >> stackCount;
		if (elemCount < 0)
			throw 10;
		if (stackCount < 0)
			throw 11;

		generalMem = new ELEM[elemCount];
		allStack = new VStack<ELEM>[stackCount];
		int *countUsed = new int[stackCount];
		for (int i = 0; i < stackCount; i++)
		{
			read >> countUsed[i];
			int sum = 0;
			for (int z = 0; z < i; z++)
				sum += countUsed[z];
			allStack[i].resize(countUsed[i]);
			allStack[i].setPointer(generalMem+sum);
			allStack[i].setStart(sum);
		}
		for (int i = 0; i < stackCount; i++)
		{
			for (int z = 0; z < countUsed[i]; z++)
			{
				ELEM tmp;
				read >> tmp;
				allStack[i].push(tmp);
			}
		}
		elemUsed = 0;
		for (int z = 0; z < stackCount; z++)
			elemUsed += countUsed[z];
		allStack[stackCount-1].resize(elemCount -elemUsed);
	}

	NStack(size_t elements, size_t stacks = 1) :elemCount(elements), stackCount(stacks), elemUsed(0)
	{
		if (elements <= 0 || stacks <= 0)
			throw 1;

		generalMem = new ELEM[elements];
		allStack = new VStack<ELEM>[stacks];

		size_t pack = elements / stacks;
		for (size_t i = 0; i < stacks; i++)
		{
			size_t sizeToStack = pack;
			allStack[i].setStart(i*sizeToStack);
			allStack[i].setPointer(generalMem + i*sizeToStack);
			if (i == stacks - 1)
				sizeToStack += elements%stacks;
			allStack[i].resize(sizeToStack);
		}
	}
	~NStack()
	{
		delete[] allStack;
		delete[] generalMem;
	}

	bool checkStackExists(size_t indexStack)//Существует ли стэк с таким индексом
	{
		return indexStack <= stackCount;
	}

	void push(size_t indexStack, ELEM val)
	{
		if (!checkStackExists(indexStack))
			throw STACK_ERROR_INDEX;
		if (elemCount == elemUsed)
			throw MULTISTACK_OVERFLOW;

		try {
			allStack[indexStack].push(val);
		}
		catch (stackException e)//Стэк переполнен
		{
			if (e == STACK_OVERFLOW)
				relocate(indexStack);//перераспределяет данные
			else
				throw e;
			allStack[indexStack].push(val);
		}
		++elemUsed;
	}

	void relocate(size_t indexStack)
	{
		bool free = false;

		for (int i = indexStack - 1; i >= 0; i--)
		{
			if (allStack[i].getCountFreeElements() == 0)
				continue;

			allStack[i].resize(allStack[i].getMaxSize() - 1);

			for (size_t x = i + 1; x < indexStack; x++)
				relocateDataLeft(x);

			free = true;
			relocateDataLeft(indexStack);
			break;
		}

		for (size_t i = indexStack + 1; !free && i < stackCount; i++)
		{
			if (allStack[i].getCountFreeElements() == 0)
				continue;
			allStack[i].resize(allStack[i].getMaxSize() - 1);

			for (size_t x = i; x > indexStack; x--)
				relocateDateRight(x);

			free = true;
			break;
		}
		if (!free)
			throw MULTISTACK_UNKNOW_EXCEPTION;


		allStack[indexStack].resize(allStack[indexStack].getMaxSize() + 1);
	}

	void relocateDataLeft(size_t indexStack)
	{
		for (size_t i = allStack[indexStack].getStart(); i < allStack[indexStack].getStart() + allStack[indexStack].getSize(); i++)
			generalMem[i - 1] = generalMem[i];
		allStack[indexStack].setStart(allStack[indexStack].getStart() - 1);
		allStack[indexStack].pointerShift(-1);
	}
	void relocateDateRight(size_t indexStack)
	{
		for (int i = allStack[indexStack].getStart() + allStack[indexStack].getSize(); i >= allStack[indexStack].getStart(); i--)
			generalMem[i + 1] = generalMem[i];
		allStack[indexStack].setStart(allStack[indexStack].getStart() + 1);
		allStack[indexStack].pointerShift(1);
	}


	ELEM pop(size_t indexStack)
	{
		if (!checkStackExists(indexStack))
			throw STACK_ERROR_INDEX;

		ELEM ret = allStack[indexStack].pop();
		--elemUsed;

		return ret;
	}

	void addStack()
	{
		VStack<ELEM> *tmpStacks = new VStack<ELEM>[stackCount + 1];
		for (int i = 0; i < stackCount; i++)
		{
			tmpStacks[i] = allStack[i];
		}
		tmpStacks[stackCount].setStart(elemCount);
		tmpStacks[stackCount].setPointer(generalMem + elemCount);
		++stackCount;
		delete[] allStack;
		allStack = tmpStacks;
	}

	void resize(size_t newSize)
	{
		if (newSize == elemCount)
			return;
		size_t delta, deltaSize = 0;
		ELEM *tmpMem = new ELEM[newSize];
		if (newSize > elemCount)
		{
			deltaSize = newSize - elemCount;
			for (int i = 0; i < elemCount; i++)
				tmpMem[i] = generalMem[i];
			allStack[stackCount - 1].resize(allStack[stackCount - 1].getMaxSize() + deltaSize);
			
		}
		else {
			deltaSize =delta= elemCount - newSize;
			size_t freeElem = elemCount - elemUsed;
			if (freeElem < deltaSize)
				throw MULTISTACK_SAFE_RESIZE;

			while (delta--)
				relocate(stackCount - 1);
			allStack[stackCount -1].resize(allStack[stackCount-1].getMaxSize()- deltaSize);

			for (int i = 0; i < elemCount && i<newSize; i++)
				tmpMem[i] = generalMem[i];
		}
		for (size_t i = 0; i < stackCount; i++)
		{
			allStack[i].setPointer(tmpMem + allStack[i].getStart());
		}
		delete[] generalMem;
		generalMem = tmpMem;
		elemCount = newSize;
	}

	friend std::ostream& operator<<(std::ostream& os, NStack& ns)
	{
		os << "NStack {elements:" << ns.elemCount << ", Stacks:" << ns.stackCount << "}:" << std::endl;
		for (size_t i = 0; i < ns.stackCount; i++)
			os << i << ":" << ns.allStack[i] << std::endl;
		return os;
	}

};