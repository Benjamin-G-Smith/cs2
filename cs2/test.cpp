//
//
//
//
#include <iostream>

using namespace std;


int main()
{
  int a;
  int* p;

  a = 2;
  p = &a;
  a = a + 1;
  cout << *p <<endl;
  return 0;
  
}
