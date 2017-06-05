#include "Queue.h"
#include <iostream>

using namespace std;

int main()
{
	try
	{


		Queue <int> temp(10);

		temp.push(5);
		temp.push(7);
		temp.push(25);
		temp.push(40);
		temp.resize(9);
		cout << temp.pop(); 
		cout << " " << temp.pop(); 
		cout << " " << temp.next() << endl;
	}
	catch (int & e)
	{
		cout << "error number: " << e << endl;
	}
	cin.get();
	return 0;
}


