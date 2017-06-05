#ifndef LIST_H
#define LIST_H
#include <iostream>

template <class TYPE>
class Spisok
{  
   private:
	   int* List; //Массив указателей
	   TYPE* Data; //Массив данных
	   int size; //Рамер массива
	   int count; //Количество элементов
	   int start; //Начало массива
	   int end; //Конец массива
   public:
	Spisok(int =1);
	Spisok(Spisok&);
	TYPE get(int);
	~Spisok();
	void removeEnd();
	int getNext(int);
	void removeStart();
	int getStart();
	int getEnd();
	void addStart(TYPE);
	void addEnd(TYPE);
	bool isEnd(int);
	int getSize()
	{
		return count;
	}
};
 
template <class TYPE>
 Spisok<TYPE>::Spisok<TYPE>(int a)
{ 
	size=a;
	count= start= end =0;
	List= new int[size];
	Data= new TYPE[size];
	for(int i=0; i<size; i++)
	{ 
		List[i]=-1;
		Data[i]=0;
	}
}

template <class TYPE>
Spisok<TYPE>::Spisok<TYPE>(Spisok<TYPE>&a)
{
	size=a.size;
	count=a.count;
	start=a.start;
	end=a.end;
	List = new int[size];
	Data = new TYPE[size];
	for (int i = 0; i<size; i++)
	{
		List[i] = a.List[i];
		Data[i] = a.Data[i];
	}
}

template <class TYPE>
Spisok<TYPE>::~Spisok<TYPE>()
{
}

template <class TYPE>
void Spisok<TYPE>:: addStart(TYPE a)
{
	if(count==0)
	{ 
	   List[0]=-2;
	   start=0;
	   end=0;
	   Data[start]=a;

	}
	else
	{ 
		for(int i=0;i<size;i++)
		{ 
			if(List[i]==-1)
			{
			  List[i]=start;
			  start=i;
			  Data[i]=a; 
			  break; 
			}
		}
	}count++;
}

template <class TYPE>
void Spisok<TYPE>:: addEnd(TYPE a)
{
	if(count==0)
	{ 
	   List[0]=-2;
	   start=0;
	   end=0;
	   Data[end]=a;
	}
	else
	{ 
		for(int i=0;i<size;i++)
		{ 
			if(List[i]==-1)
			{
			  List[end]=i;
			  end=i;
			  Data[i]=a; 
			  List[i]=-2;
			  break; 
			}
		}
	}count++;
}

template <class TYPE>
void Spisok<TYPE>:: removeStart()
{
	int S=start;
	start=List[start];
	List[S]=-1;
	count--;
}

template <class TYPE>
void Spisok<TYPE>:: removeEnd()
{
	if (count == 1)
	{
		List[end] = -1;
		count--;
		end = start = 0;
		return;
	}
	for(int i=0; i<size; i++)
	{
	  if(List[i]==end)
	  {
	    List[end]=-1;
		List[i]=-2;
		end=i;
		count--;
		return;
	  }
	}
}
template <class TYPE>
int Spisok<TYPE>::getStart()
{
	return start;
}

template <class TYPE>
int Spisok<TYPE>::getEnd()
{
	return end;
}

template <class TYPE>
int Spisok<TYPE>:: getNext(int a)
{
    return List[a];
}

template <class TYPE>
bool Spisok<TYPE>:: isEnd(int a)
{
	if(a==-1)
	{ return true; }
	if(a==-2)
	{ return true; }
	return false;
}

template <class TYPE>
TYPE Spisok<TYPE>:: get(int end)
{
	return Data[end];
}

#endif 
