#pragma once
#include "LinkedList.h"

template<class E>
class ListQueue
{
private:
	LinkedList<E> *list;

public:
	ListQueue()
	{
		list = new LinkedList<E>;
	}
	~ListQueue()
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
		E tmp = list->get(list->getStart());
		list->removeStart();
		return tmp;
	}

	size_t size()
	{
		return list->getSize();
	}

	E operator[](size_t index)
	{
		int counter = 0;
		for (int i = list->getStart(); !list->isEnd(i); i = list->getNext(i),counter++)
		{
			if (counter == index)
				return list->get(index);
		}
	}
};