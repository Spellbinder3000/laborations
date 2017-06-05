#pragma once
#include "ListMass.h"


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
};