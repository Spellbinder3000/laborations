#include "stack.h"
#include <iostream>

using namespace std;

int main()
{
	try
	{

	
	Tstack <int> temp(10);
	
	temp.push(5);
	temp.push(7);
	temp.push(25);
	temp.push(40);
	cout << temp.pop() << " ";
	cout << temp.pop() << " ";
	cout << temp.pop() << " ";
	cout << temp.pop();
	temp.resize(2);
	}
	catch (int& e)
	{
		cout << "error number:" << e << endl;
	}
	cin.get();
	return 0;
}