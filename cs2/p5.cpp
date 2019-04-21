// Ben Smith
// p5.cpp
// 6/01/2017

// PURPOSE: Allows a game of stack 13 to be played between two players.
//  Stack and Queues are used to accomplish this game. The players play
//  until the objective has been meet at which point the game can either
//  be played again or exited.

// INPUTS: If the users want to play the game along with their turn input.
//  Also if the players would like to run the game again.

// PROCESSING: The game will shuffle a series of cards into a stack(deck)
//  Then deal 7 cards to each player. Then each player will play a card
//  until they have run out of cards.

// OUTPUTS: Messages to the user including welcome messages, and prompts
//  for inputs when required.


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cctype>

#include "queue.h"
#include "stack.h"

using namespace std;

struct Player{
  Queue hand;
  int pNum;
};

const int SIZE = 14;
const int STACK_SIZE = 52;
const int SETS = 13;
const int MAX_CARDS = 4;

void shuffle(Stack& cards,Stack& disCard);
// Pre: There must be a valid card stack and queue stack
// Post: Creates cards and places them into the deck and disCard
void drawCard(Queue& player, Stack& cards, int &deckCount);
// Pre: There must be a valid queue and stack before using.
// Post: One card from the deck pile is placed into the players queue.
//  Deck count is also moddified to keep track.
void playCard(Queue& player, Stack& deck,Stack& disCard, int &deckCount);
// Pre: There must be a valud stack and queue.
// Post: A card from the players hand it taken and compared to the top
//  card of the discard pile. The player will take cards according to
//  conditions of the game.
void flipDeck(Stack& deck, Stack& disCard, int &deckCount);
// Pre: Valid stack and queue.
// Post: The contents of the discard pile and the remainder of the deck pile
//  are added to a new deck pile thus resetting the deck for reuse.
void deleteCards(Stack& deck);
// Pre: A valid stack is needed.
// Post: The contents of the deck are removed
void deleteHands(Player *players, int numPlayers);
// Pre: There must be a correct number of plaers and there must be a valid
//  player array.

int main()
{
  // Creates a shuffled deck of cards
  int deckCount = STACK_SIZE-1;
  int PLAYER_NUM = 2;
  Player *players = new Player[PLAYER_NUM];

  srand(time(0));
  Stack cards(STACK_SIZE);
  Stack disCard(STACK_SIZE);
  int playerNum = 0;
  int winner = 0;
  bool end = false;
  char playGame;

  cout << "\n--------Welcome to Stack 13---------\n" << endl;
  cout << "[OBJECTIVE]:" << endl;
  cout << " Run out of cards before your opponent" << endl;
  cout << "\nDo you want to play ? [y/n]";
  cin >> playGame;
  cin.get();

  while(toupper(playGame) == 'Y'){

    cout << "\nShuffling cards.........\n" << endl;

    shuffle(cards,disCard);

    for(int i = 0; i < 7; i++){ // deals 7 cards to each player
      drawCard(players[0].hand,cards,deckCount);
      drawCard(players[1].hand,cards,deckCount);
    }
    playerNum = 0;
    while(!end){
      if(playerNum > 1){
        playerNum = 0;
      } // Each players turn
      cout << "player "<<playerNum+1<< " press enter to play a card: ";
      cin.get();
      playCard(players[playerNum].hand,cards,disCard,deckCount);
      if(deckCount < 3){ // Flip condiion
        cout << "Flipping\n" << endl;
        flipDeck(cards,disCard,deckCount);
      }
      if(players[playerNum].hand.isEmpty()){ // winner check
        winner = playerNum;
        end = true;
      }
      playerNum++;
    }
    cout << "Player_"<<winner+1<< " has Won !"<< endl;
    cout << "Would you like to play again ? [y/n]";
    cin >> playGame;
    cin.get();
    if(toupper(playGame) == 'Y'){ // Game reset calls
      end = false;
      deleteCards(cards);
      deleteCards(disCard);
      deleteHands(players,PLAYER_NUM);
      deckCount = STACK_SIZE-1;
    }
  }
  delete [] players;
  cout << "\nGoodbye..." << endl;
  return 0;
}
void deleteHands(Player *players, int numPlayers)
{
  int num;
  int count = 0;
  while(count < numPlayers){
    while(!players[count].hand.isEmpty()){
      players[count].hand.dequeue(num);
    }
    count++;
  }
}
void deleteCards(Stack& deck)
{
  int num;
  while(!deck.isEmpty()){
    deck.pop(num);
  }
}
void playCard(Queue& player, Stack& deck, Stack& disCard, int &deckCount)
{
  int card;
  int topCard;

  disCard.pop(topCard);
  player.dequeue(card);

  cout << "\nThe top card is [ " << topCard<<" ]"<< endl;
  cout << "You played a [ " << card <<" ]" << endl;

  if(card > topCard){
    cout << "{ Don't draw }\n" << endl;
    disCard.push(topCard);
    disCard.push(card);
  }
  else if(card == topCard){
    cout << "{ Equal }\n" << endl;
    drawCard(player,deck,deckCount);
    disCard.push(topCard);
    disCard.push(card);
  }
  else{
    cout << "{ Draw 2 }\n" << endl;
    disCard.push(topCard);
    disCard.push(card);
    drawCard(player,deck,deckCount);
    drawCard(player,deck,deckCount);
  }
}
void flipDeck(Stack& deck, Stack& disCard, int &deckCount)
{
  int disCardTop;
  int discardNum;
  int deckNum;
  disCard.pop(disCardTop); // stores the top of the discard
  Queue temp;
  while(!disCard.isEmpty()){ // puts all of the cards from the disCard to the
    disCard.pop(discardNum); //  temp Queue
    temp.enqueue(discardNum);
  }
  while(!deck.isEmpty()){ // Puts the remaining cards into the temp
    deck.pop(deckNum);
    temp.enqueue(deckNum);
  }
  while(!temp.isEmpty()){ // Pushes everything back onto the deck flipped
    temp.dequeue(discardNum);
    deck.push(discardNum);
    deckCount++;
  }
  disCard.push(disCardTop); // Puts the previous topcard back onto the discard
}
void drawCard(Queue& player, Stack& cards, int &deckCount)
{
  int num;
  cards.pop(num);
  player.enqueue(num);
  deckCount--;
}
void shuffle(Stack& cards,Stack& disCard)
{
  int randomArr[SIZE] = {0}; // 13 random numbers
  int counter[SIZE] = {0}; // 13 counters for each number
  int setsComplete = 0; // sets of 4s
  int num = 0;
  bool done = false;
  while(!done){
    for(int i = 1; i < SIZE; i++){ // Generates cards
      randomArr[i] = rand() % SETS + 1;
    }
    for(int i = 1; i < SIZE; i++){ // counts the occurences of each num
      int index = i;
      for(int j = 1; j < SIZE; j++){
        if(randomArr[j] == index && counter[index] < MAX_CARDS){
          cards.push(randomArr[j]); // pushes the number onto the deck
          counter[index]++;
        }
      }
    }
    setsComplete = 0;
    for(int i = 1; i < SIZE; i++){ // count the number of 'sets' completed
      if(counter[i] == MAX_CARDS){
        setsComplete++;
      }
    }
    if(setsComplete == SETS){ // ends the shuffle loop when there are 13
      done = true;
    }
  }
  cards.pop(num); // Places on card onto the discard pile to start the game
  disCard.push(num);
}
