// Ben Smith
// tictactoex.h
// 4/21/2017

// Purpose: The class file for tictactoe. This class allows the game of 
//  tic tac toe to be played. This class creates any size board up to 9x9 
//  that will be used in the game tic tac toe. Also allowing for players
//  to give input on where they want to put their piece. 

#include <iostream>
#include <cctype>
#include <cassert>

using namespace std;

#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToe
{
 public:
  TicTacToe(int size);
  TicTacToe& operator=(const TicTacToe&rhs);
  TicTacToe(const TicTacToe&h);
  ~TicTacToe();
  bool setPlayerInput(int row, int col, int numPlayer, bool& tie);
  // Pre: The row,col space must not be occupied. There must be a current
  //  player, and a condition for the tie.
  // Post: The row,col position is set with the current player's piece. If
  //  the current player has won then the game over condition is returned. 
  //  If no player has won then the tie condition is meet. 
  bool spaceFilled(int row, int col);
  // Pre: There must be valid row,col ie they must be in the bounds of the
  //  board size.
  // Post: If the space row,col is occupied then the space desired is filled
  //  this result is sent to main.
  void displayBoard();
  // Pre: There must be a valid board already created.
  // Post: N/A   
  static const char BLANK = ' ';
  const string TAB = "      ";
  const string HEADER ="         ";
  const string HEADERBAR =" | ";
  const string SPACE_SEPORATOR = "| ";
  static const char X = 'X';
  static const char O = 'O';
  static const char DASH = '-';
  static const char END = '|';
  
 private:
  char** board;
  int boardSize;
};
#endif