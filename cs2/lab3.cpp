// Ben Smith
// lab3.cpp
// 4/12/2017

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
  int num;
  int* pointNum;
  srand(time(0));
    
  // 1 & 2.
  cout << "Enter a number: ";
  cin >> num;
  pointNum = &num;

  // 3.
  cout << "The Address of num is: "<< &num <<" The Value is: " << num << endl;
  cout << "The Address stored in pointNum is: "<< pointNum<<" The Value is: "
       << *pointNum << endl;

  // 4 & 5.
  pointNum = new int;
  *pointNum = 5;

  // 6 & 7.
  cout << "The Address of num is: "<< &num <<" The Value is: " << num << endl;
  cout << "The Address stored in pointNum is: "<< pointNum<<" The Value is: "
       << *pointNum << endl;
  cout << "Deleting allocated memory..."<<endl;
  delete pointNum;

  // 8 & 9.
  cout <<"Small number plz: ";
  cin >> num;

  pointNum = new int[num];

  for(int i = 0; i < num; i++){
    pointNum[i] = rand() % 100 + 1;
  }
  // 10 & 11
  for(int i = 0; i < num; i++){
    cout << pointNum[i] << endl;
  }
  cout <<"Deleating allocated memory..."<<endl;
  delete []pointNum;
   
  return 0;
}
