#include <iostream>
#include <string>
#include "TableSee.h"

using namespace std;

void main()
{
	table<int,double> vvv(15);

		vvv.add(123, 432.23);
		vvv.add(121, 33.41);
		vvv.add(1212, 12.123);

		cout << vvv.findMinKey();
		vvv.resize(3);
	
	
	cin.get();
}