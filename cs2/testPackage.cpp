//

#include "stack.h"
//#include "queue.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

void shuffle(Stack& cards,Stack& disCard);

const int SIZE = 14;
const int STACK_SIZE = 52;
const int SETS = 13;
const int MAX_CARDS = 4;

int main()
{
  srand(time(0));
  Stack cards(52);
  Stack disCard(52);
  cout << cards.stackSize << endl;
  shuffle(cards,disCard);
  cin.get();
  cout << cards.stackSize << endl;
  cin.get();
  int num;
  int c = 1;
  while(!cards.isEmpty()){
    cards.pop(num);
    cout << c << " cards " << num << endl;
    //cout << cards.stackSize << endl;
    c++;
  }
  cout << disCard.stackSize << endl;

  return 0;
}
void shuffle(Stack& cards,Stack& disCard)
{
  int randomArr[SIZE] = {0};
  int counter[SIZE] = {0};
  int setsComplete = 0;
  int num;
  bool done = false;
  while(!done){

    for(int i = 1; i < SIZE; i++){
      randomArr[i] = rand() % SETS + 1;
    }
    // Error pushing the correct number onto the stack
    for(int i = 1; i < SIZE; i++){
      int index = i;
      for(int j = 1; j < SIZE; j++){
        if(randomArr[j] == index && counter[index] < MAX_CARDS){
          cards.push(randomArr[j]);
          counter[index]++;
        }
      }
    }
    setsComplete = 0;
    for(int i = 1; i < SIZE; i++){
      if(counter[i] == MAX_CARDS){
        setsComplete++;
      }
    }
    if(setsComplete == SETS){
      done = true;
    }
  }
  cards.pop(num);
  disCard.push(num);
}
