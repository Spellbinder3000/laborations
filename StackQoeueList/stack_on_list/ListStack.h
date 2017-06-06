#pragma once
#include "ListMass.h"
#include <fstream>
#include <iostream>

template<class E>
class ListStack
{
private:
	Spisok<E> *list;

public:
	ListStack()
	{
		list = new Spisok<E>(20);
	}
	~ListStack()
	{
		delete list;
	}

	void add(E elem)
	{
		list->addEnd(elem);
	}

	E get()
	{
		if (list->getSize() == 0)
			throw 2;
		E tmp = list->get(list->getEnd());
		list->removeEnd();
		return tmp;
	}

	size_t size()
	{
		return list->getSize();
	}

	E operator[](size_t index)
	{
		int counter = 0;
		for (int i = list->getStart(); !list->isEnd(i); i = list->getNext(i), counter++)
		{
			if (counter == index)
				return list->get(index);
		}
	}
	void writeRandom()
	{
		int *aa = new int[list->getSize()];
		int iter = 0;
		std::ofstream file("stack");
		while (iter < list->getSize())
		{
			int tmp = rand() % list->getSize();
			bool dobl = false;
			for (int i = 0; i < iter; i++)
			{
				if (aa[i] == tmp)
				{
					dobl = true;
					break;
				}
			}
			if (!dobl)
			{
				aa[iter++] = tmp;
				file << list->get(tmp) << std::endl;
			}

		}
		file.close();
	}
};