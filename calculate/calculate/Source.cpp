#include "calculate.h"
#include <iostream>

using namespace std;

void main()
{
	Calculate cl;
	setlocale(NULL,"RUSSIAN");
	cout << "������:";

	string str = "1+2*6^3+5";
	string npl;

	cout<< str<<endl;

	npl = cl.getNPL(str);
	cout <<"���:"<< npl<<endl;
	double res = cl.Counting(npl);
	cout << "���������:" << res;
	cin.get();

	cin.get();


}