#include "ListStack.h"
#include "ListQueue.h"
#include <iostream>


void main()
{
	ListStack<int> lt;
	//ListQueue<int> lt;

	lt.add(15);
	lt.add(25);
	lt.add(35);
	lt.add(45);
	lt.add(75);

	for (size_t i = 0; i < lt.size(); i++)
		std::cout << lt[i] << "|";
	std::cout << std::endl;
	try
	{
		for (;;)
		std::cout<<	lt.get()<<"|";
	}catch(int ee)
	{
		std::cout << std::endl << "stack is empty";
	}


	std::cin.get();


}