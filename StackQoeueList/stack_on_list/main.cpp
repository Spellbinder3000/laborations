#include "ListStack.h"
#include "ListQueue.h"
#include <iostream>


void main()
{
	//ListStack<int> lt;
	ListQueue<int> lq;

	lq.add(05);
	lq.add(15);
	lq.add(25);
	lq.add(35);
	lq.add(45);
	lq.add(75);
	lq.add(85);
	lq.add(95);



	try
	{
		lq.print();

	}catch(int ee)
	{
		std::cout << std::endl << "stack is empty";
	}


	std::cin.get();


}