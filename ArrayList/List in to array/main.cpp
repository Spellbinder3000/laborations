#include "ListMass.h"
#include <iostream>

int main()
{
   Spisok<int> K(7);
   K.addStart(53);
   K.addStart(62);
   K.addEnd(74);
   K.enddelite();
   K.addEnd(135);
   K.addEnd(422);
   K.enddelite();
   K.addEnd(551);
   K.addStart(123);
   K.enddelite();

   for(int i=K.getStart();!K.isEnd(i);i=K.getNext(i))
   {
	   std:: cout<<K.get(i)<<" ";
   }

   std:: cin.get();
};