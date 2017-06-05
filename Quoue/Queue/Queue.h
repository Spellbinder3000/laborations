#pragma once

template <typename T>
class Queue
{
private:
	size_t left,right;
	T *mass;
	size_t sizeMax;
	size_t count;
public:
	Queue(size_t size) :sizeMax(size), left(0), right(0),count(0)
	{
		if (size == 0)
			throw 1;
		mass = new T[size];
	}

	void push(const T& el)
	{
		if (count == sizeMax)
			throw 2;
		right = right%sizeMax;
		this->mass[right] = el;
		right++;
		count++;
	}

	T next()
	{
		if (count == 0)
			throw 3;

		left = left%sizeMax;
		T tmp = this->mass[left];
		return tmp;
		
	}

	T pop()
	{
		if (count == 0)
			throw 3;

		left = left%sizeMax;
		T tmp = this->mass[left];
		left++;
		count--;
		return tmp;
	}

	void resize(size_t newSize)
	{
		T *tmp;
		if (count > newSize)
			throw 5;
		size_t tmpMS = sizeMax;
		sizeMax = newSize;
		tmp = new T[sizeMax];
		size_t input = 0;
		for (size_t i = left; input < count; i=(i+1)%tmpMS)
		{
			tmp[input++] = mass[i];
		}
	}
};	