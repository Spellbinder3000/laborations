#include "ListStack.h"
#include "ListQueue.h"
#include <iostream>


void main()
{
	ListStack<int> lt;
	ListQueue<int> lq;

	lq.add(05);
	lq.add(15);
	lq.add(25);
	lq.add(35);
	lq.add(45);
	lq.add(75);
	lq.add(85);
	lq.add(95);

	lt.add(05);
	lt.add(15);
	lt.add(25);
	lt.add(35);
	lt.add(45);
	lt.add(75);
	lt.add(85);
	lt.add(95);

	lt.writeRandom();

	try
	{
		lq.print();

	}catch(int ee)
	{
		std::cout << std::endl << "stack is empty";
	}


	std::cin.get();


}