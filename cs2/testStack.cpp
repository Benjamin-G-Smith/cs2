#include "stack.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
  srand(time(0));

  cout << "Testing stack..." << endl;
  Stack cards(52);

  for(int i = 0; i < 51; i++){
    int num = rand() % 13 + 1;
    cout<< num;
    cards.push(num);
  }
  while(!cards.isEmpty()){
    int num;
    if(!cards.pop(num)){
      cout << "could not pop" << endl;
    }
    else
    cout << "poped "<< num  << endl;
  }


  return 0;
}
