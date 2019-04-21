// Ben Smith
// tictactoex.cpp
// 4/27/2017

// Purpose: Implementation of the tictactoe in tictactoex.h

#include "tictactoex.h"

// Default constructor 
TicTacToe::TicTacToe(int size = 3)
{
  boardSize = size;
  board = new char* [boardSize];
  assert(board != nullptr);
  for(int i = 0; i < boardSize; i++){
    board[i] = new char[boardSize];
    assert(board[i] != nullptr);
  }
  for(int r = 0; r < boardSize; r++){
    for(int c = 0; c < boardSize; c++){
      board[r][c] = BLANK;
    }
  }
}
// Overloaded assignment opperator
TicTacToe& TicTacToe::operator=(const TicTacToe&rhs)
{
  if(this != &rhs){
    for(int r = 0; r < this->boardSize; r++){
      delete [] this->board[r];
    }
    delete [] this->board;
    
    board = new char* [boardSize];
    assert(board != nullptr);
    for(int i = 0; i < boardSize; i++){
      board[i] = new char[boardSize];
      assert(board[i] != nullptr);
    }
  }
  return *this;
}
// Copy constructor 
TicTacToe::TicTacToe(const TicTacToe&h)
{
  board = new char* [boardSize];
  assert(board != nullptr);
  for(int i = 0; i < boardSize; i++){
    board[i] = new char[boardSize];
    assert(board[i] != nullptr);
  }
}
// Prints the board
void TicTacToe::displayBoard()
{
  cout <<HEADER;
  for(int i = 0; i < boardSize; i++){
    cout <<i<<HEADERBAR; 
  }
  cout << endl;
  for(int r = 0; r < boardSize; r++){
    cout <<TAB<< r;
    for(int c = 0; c < boardSize; c++){
      cout <<SPACE_SEPORATOR<< board[r][c]<<BLANK;
    }
    cout<<END<<endl;
  }
}
// Checks each space to place a new piece
bool TicTacToe::spaceFilled(int row, int col){
  if(board[row][col] != BLANK){
    return true;
  }
  else{
    return false;
  }
}
// Sets the players input
bool TicTacToe::setPlayerInput(int row,int col,int numPlayer,bool& tie)
{
  int rowMatches = 0; 
  int colMatches = 0;
  int diagMatches1 = 0;
  int diagMatches2 = 0;
  char player;	
  
  if(numPlayer == 1){
    player = 'X';
  }
  else if(numPlayer == 2){
    player = 'O';
  }
  
  board[row][col] = player;
  // Row matches
  for(int r = 0; r < boardSize; r++){
    for(int c = 0; c < boardSize; c++){
      if(board[r][c] == player){
        rowMatches ++;
      }
    }
    if(rowMatches == boardSize){
      return true;
    }
    else{
      rowMatches = 0;
    }		
  }	
  // Col matches
  for(int c = 0; c < boardSize; c++){
    for(int r = 0; r < boardSize; r++){
      if(board[r][c] == player){
        colMatches ++;
      }
    }
    if(colMatches == boardSize){
      return true;
    }
    else{
      colMatches = 0;
    }
  }	
  // Diag 1 match
  for(int d = 0; d < boardSize; d++){
    if(board[d][d] == player){
      diagMatches1 ++;
    }
    if(diagMatches1 == boardSize){
      return true;
    }	
  }
  // Diag 2 match
  int r = boardSize-1;
  for(int c = 0; c < boardSize; c++){
    if(board[c][r] == player){
      diagMatches2++;
    }
    if(diagMatches2 == boardSize){
      return true;
    }
    r--;
  }
  // Checks for empty
  int spacesEmpty = boardSize * boardSize;
  for(int r = 0; r < boardSize; r++){
    for(int c = 0; c < boardSize; c++){
      if(board[r][c] != BLANK){
        spacesEmpty--;
      }
    }
  }
  if(spacesEmpty == 0){
    tie = true;
    return true;
  }
  return false;
}
// Destructor
TicTacToe::~TicTacToe()
{
  for(int r = 0; r < boardSize; r++){
    delete [] board[r];
  }
  delete [] board;
}