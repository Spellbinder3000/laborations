#pragma once

template<class E>
class LinkedList 
{
private:
	struct node
	{
		E data;
		node *next;
	};

	node *head, *tail;
	size_t count;
public:

	LinkedList():count(0)
	{
	}

	~LinkedList()
	{
		if (head == 0)
			return;
		node *tmp ;
		node *next = head;
		do {

			tmp = next->next;
			delete next;
			next = tmp;
		} while (next != head);
	}

	void addEnd(E e);

	E get(size_t index);
	bool isEmpty();
	void remove(size_t index);
	size_t size();
	void clear();
	size_t getStart()
	{
		return 0;
	}
	size_t getEnd()
	{
		return count - 1;
	}
	//*/

};

template<class E>
void LinkedList<E>::addEnd(E e)
{
	node *tmp = new node;
	tmp->data = e;
	if (head == 0)
	{
		head = tail = tmp;
	}
	else
	{
		tail->next = tmp;
		tail = tmp;
	}
	tmp->next = head;
	++count;
}

template<class E>
E LinkedList<E>::get(size_t index)
{
	if (index > count)
		throw 1;
	size_t counter = 0;
	for (node *i = head; counter < count; i = i->next, counter++)
	{
		if (counter == index)
		{
			return i->data;
		}
	}
	throw 2;
}


template<class E>
inline bool LinkedList<E>::isEmpty()
{
	return count == 0;
}

template<class E>
void LinkedList<E>::remove(size_t index)
{
	if (index > count)
		throw INDEX_ERROR_EXCEPTION;

	if (count == 1)
	{
		delete head;
		head = tail = 0;
		count = 0;
		return;
	}

	node *prev = head;
	size_t counter = 0;
	for (node *i = head; counter < count; i = i->next, counter++)
	{
		if (counter == index)
		{
			if (i == head)
			{
				head = head->next;
				delete tail->next;
				tail->next = head;
				break;
			}
			if (i == tail)
			{
				tail = prev;
				delete tail->next;
				tail->next = head;
				break;
			}
			if (i != tail && i != head)
			{
				prev->next = i->next;
				delete i;
			}
			break;
		}
		prev = i;
	}
	--count;
}

template<class E>
inline size_t LinkedList<E>::size()
{
	return count;
}

template<class E>
inline void LinkedList<E>::clear()
{
	node *tmp;
	node *next = head;
	do
	{
		tmp = next->next;
		delete next;
		next = tmp;

	} while (next != head);
	head = tail = 0;
	count = 0;
}
