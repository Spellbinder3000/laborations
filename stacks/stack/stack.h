#pragma once
#include <iostream>
#include <fstream>
template <typename ELEM>
class Tstack
{
private:
	ELEM *x;
	size_t a;
	size_t b;
public:
	Tstack() :a(0), b(0){
		x = 0;
		x = 0;
	};
	Tstack(size_t size) :b(0),a(size)
	{
		this->x = new ELEM[size];
	}
	void push(const ELEM& elem)
	{
		if (this->b == this->a) // Не переполнен ли стек?
			throw 1;
		
		this->x[this->b++] = elem;
	}
	ELEM pop()//Возвращает и вырезает последний
	{
		if (this->b == 0) // Не переполнен ли стек?
			throw 2;

		return this->x[--this->b];
	}
	ELEM back()
	{
		if (this->b == 0) // Не переполнен ли стек?
			throw 2;

		return this->x[this->b-1];
	}

	void fillFile()
	{
		std::ifstream file("stack");
		ELEM tmp;
		while (file >> tmp)
			push(tmp);

		file.close();
	}

	void resize(size_t newSize)
	{
		ELEM *tmp;
		size_t tmpMS = a;
		if (b > newSize)
			throw 10;
		a = newSize;
		tmp = new ELEM[a];
		for (size_t i = 0; i < a && i < tmpMS; i++)
			tmp[i] = x[i];
		

		delete x;
		x = tmp;
	}

};