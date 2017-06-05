#ifndef LIST_H
#define LIST_H
#include <iostream>

template <class TYPE>
class Spisok
{  
   private:
	   int* ukozateli; //Массив указателей
	   TYPE* inform; //Массив данных
	   int maxCount; //Рамер массива
	   int usagecolvo; //Количество элементов
	   int start; //Начало массива
	   int end; //Конец массива
   public:
	Spisok(int =1);
	Spisok(Spisok&);
	TYPE get(int);
	~Spisok();
	void enddelite();
	int getNext(int);
	void startdelete();
	int getStart();
	void addStart(TYPE);
	void addEnd(TYPE);
	bool isEnd(int);
};
 
template <class TYPE>
 Spisok<TYPE>::Spisok<TYPE>(int a)
{ 
	maxCount=a;
	usagecolvo= start= end =0;
	ukozateli= new int[maxCount];
	inform= new TYPE[maxCount];
	for(int i=0; i<maxCount; i++)
	{ 
		ukozateli[i]=-1;
		inform[i]=0;
	}
}

template <class TYPE>
Spisok<TYPE>::Spisok<TYPE>(Spisok<TYPE>&a)
{
	maxCount=a.maxCount;
	usagecolvo=a.usagecolvo;
	start=a.start;
	end=a.end;
	ukozateli = new int[maxCount];
	inform = new TYPE[maxCount];
	for (int i = 0; i<maxCount; i++)
	{
		ukozateli[i] = a.ukozateli[i];
		inform[i] = a.inform[i];
	}
}

template <class TYPE>
Spisok<TYPE>::~Spisok<TYPE>()
{
	delete[] ukozateli;
	delete[] inform;
}

template <class TYPE>
void Spisok<TYPE>:: addStart(TYPE a)
{
	if(usagecolvo==0)
	{ 
	   ukozateli[0]=-2;
	   start=0;
	   end=0;
	   inform[start]=a;

	}
	else
	{ 
		for(int i=0;i<maxCount;i++)
		{ 
			if(ukozateli[i]==-1)
			{
			  ukozateli[i]=start;
			  start=i;
			  inform[i]=a; 
			  break; 
			}
		}
	}
	usagecolvo++;
}

template <class TYPE>
void Spisok<TYPE>:: addEnd(TYPE a)
{
	if(usagecolvo==0)
	{ 
	   ukozateli[0]=-2;
	   start=0;
	   end=0;
	   inform[end]=a;
	}
	else
	{ 
		for(int i=0;i<maxCount;i++)
		{ 
			if(ukozateli[i]==-1)
			{
			  ukozateli[end]=i;
			  end=i;
			  inform[i]=a; 
			  ukozateli[i]=-2;
			  break; 
			}
		}
	}usagecolvo++;
}

template <class TYPE>
void Spisok<TYPE>:: startdelete()
{
	int S=start;
	start=ukozateli[start];
	ukozateli[S]=-1;
	usagecolvo--;
}

template <class TYPE>
void Spisok<TYPE>:: enddelite()
{
	for(int i=0; i<maxCount; i++)
	{
	  if(ukozateli[i]==end)
	  {
	    ukozateli[end]=-1;
		ukozateli[i]=-2;
		end=i;
		usagecolvo--;
		return;
	  }
	}
}

template <class TYPE>
int Spisok<TYPE>:: getStart()
{
	return start;
}

template <class TYPE>
int Spisok<TYPE>:: getNext(int a)
{
    return ukozateli[a];
}

template <class TYPE>
bool Spisok<TYPE>:: isEnd(int a)
{
	if(a==-2)
	{ return true; }
	return false;
}

template <class TYPE>
TYPE Spisok<TYPE>:: get(int end)
{
	return inform[end];
}

#endif 
