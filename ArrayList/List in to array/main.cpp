#include "ListMass.h"
#include <iostream>

int main()
{
   Spisok<int> K(7);
   K.addStart(53);
   K.addStart(62);
   K.addEnd(74);
   K.addEnd(135);
   K.addEnd(422);
   K.addEnd(551);
   K.addStart(123);
   

   for(int i=K.getStart();!K.isEnd(i);i=K.getNext(i))
   {
	   std:: cout<<K.get(i)<<" ";
   }
   std::cout << std::endl;
   K.print();

   std:: cin.get();
};