#include "stack.h"
#include <iostream>

using namespace std;

int main()
{
	try
	{

	
	Tstack <int> temp(20);
	
	temp.fillFile();
	cout << temp.pop() << endl;
	cout << temp.pop() << endl;
	cout << temp.pop() << endl;
	cout << temp.pop() << endl;
	}
	catch (int& e)
	{
		cout << "error number:" << e << endl;
	}
	cin.get();
	return 0;
}