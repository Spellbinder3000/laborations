#include "Hastable.h"
#include <iostream>

void main()
{
	Table<int,double> t(50);
	t.printFromFile();

	std::cin.get();

}