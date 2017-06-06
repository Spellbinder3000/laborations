#include <iostream>
#include "NStack.h"



void main()
{

	NStack<int> t(50,10);

	t.readOfFile();
	std::cout <<  t << std::endl;
	
	std::cin.get();
}