#include "BinaryTree.h"
#include <string>
#include <iostream>

void main()
{
	BinaryTree<int,int> binary;

	binary.add(5, 15675);
	binary.add(1, 11100);
	binary.add(3, 0);
	binary.add(16,1235);
	binary.add(6, 3);
	binary.add(9, 12345);
	binary.add(24,1222);
	binary.add(5, 1);
	binary.add(4, 15);
	binary.add(2, 1);
	binary.add(10,0);

	binary.remove(100);
	binary.remove(5);
	binary.remove(9);
	binary.remove(300);

	std::cout << binary.getMaxValue();

	std::cin.get();

	return;

}