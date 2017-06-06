// ����, ���, ���� "������ ����������������-2", �++, ���
//
// sample_matrix.cpp - Copyright (c) ������� �.�. 07.05.2001
//   ������������ ��� Microsoft Visual Studio 2008 �������� �.�. (20.04.2015)
//
// ������������ ����������������� �������

#include <iostream>
#include "utmatrix.h"
//---------------------------------------------------------------------------

void main()
{
  TMatrix<int> a(5), b(5), c(5), d(5);
  int i, j;

  setlocale(LC_ALL, "Russian");
  cout << "������������ �������� ��������� ������������� ����������� ������"
    << endl;
  for (i = 0; i < 5; i++)
    for (j = i; j < 5; j++ )
    {
      a[i][j] =  i + j+i;
      b[i][j] = (i + j) * 10+1;
    }
  TVector<int> aa(2);
  TVector<int> bb(2);
  
  c = a + b;
  d = a / b;
  cout << "Matrix a = " <<a.sumNotEven()<< endl << a << endl;
  cout << "Matrix b = " << b.sumNotEven()<<endl << b << endl;
  cout << "Matrix c = a + b"<<c.sumNotEven() << endl << c << endl;
  cout << "Matrix d = a / b"<<d.sumNotEven() << endl << d << endl;
  cin.get();
}
//---------------------------------------------------------------------------
