// Ben Smith
// Ben Smith
// 4/23/2017
// p2x.cpp

// Purpose: Allows two players to play a game of tic tac toe until a winner
//  or a draw is accomplished. At the end of each game the statistics of
//  each game are displayed along with the option for the game to be played 
//  again. 
// Input: The size of the board. If the players want to play the game. 
//  The row and col that each player wants to put their piece in. Once
//  the game is over the option to play again is given. 
// Process: The row,col input is taken in and the position on the board is
//  updated with the current players piece. After each game is completed the
//  number of wins, losses, ties, and games completed is updated. 
// Output: The board with each piece in it. If the players want to play/play
//  again. Along with the game statistics.

#include "tictactoex.h"
#include <iostream>
#include <cctype>

using namespace std;

int main()
{
	int size;
	bool end = false;
	int row = 0;
	int col = 0;
	const int PLAYER1 = 1;
	const int PLAYER2 = 2;
  const string SPACE = " ";
  const int NUM_SPACES = 25;
	int currentPlayer = 1;
	int p1Wins = 0;
	int p1Losses = 0;
	int p2Wins = 0;
	int p2Losses = 0;
	int ties = 0;
	int gamesPlayed = 0;

	bool tie = false;
	char playGame = 'y';

  for(int i = 0; i < NUM_SPACES; i++){
    cout << SPACE << endl;
  }

	cout <<"Welcome to tic tac toe!"<< endl;
	cout <<"         __|_|__"<<endl;
	cout <<"         __|_|__"<<endl;
	cout <<"           | |  "<<endl;
	cout << endl;
	// ASK if the players want to play 
	cout << "Would you like to play(y/n)?";
  cin >> playGame;
  
  while(toupper(playGame) == 'Y'){
	gamesPlayed++;
	cout <<"Enter the SIZE of your board odd only(3-9):";
	cin >> size;
	while(size % 2 == 0 || size > 9 || size < 3){
		cout << "Please Enter a prime number(3-9):";
		cin >> size;
	}
	TicTacToe game(size);

	cout << "\nPlayer 1 you are 'X' "<< endl;
	cout << "Player 2 you are 'O' "<< endl;
	
	while(!end){
      
      if(currentPlayer > PLAYER2){
        currentPlayer = PLAYER1;
      }
      cout << endl;
      
      game.displayBoard();
      cout << "\nPlayer " <<currentPlayer<< " turn: " << endl;
      cout << "Enter row: ";
      cin >> row;
      while(row < 0 || row > size-1){
        cout << "Error Invalid Input"<< endl;
        cout << "Enter row: ";
        cin >> row;
      }
      cout << "Enter column: ";
      cin >> col;
      while(col < 0 || row > size-1){
        cout << "Error Invalid Input"<< endl;
        cout << "Enter col: ";
        cin >> col;
      }
      while(game.spaceFilled(row,col)){
        cout << "Space filled" << endl;
        cout << "Enter row: ";
        cin >> row;
        while(row < 0 || row > size-1){
          cout << "Error Invalid Input"<< endl;
          cout << "Enter row: ";
          cin >> row;
        }
        cout << "Enter column: ";
        cin >> col;
        while(col < 0 || row > size-1){
          cout << "Error Invalid Input"<< endl;
          cout << "Enter col: ";
          cin >> col;
        }
      }
      end = game.setPlayerInput(row,col,currentPlayer,tie);	
      if(!end){
        currentPlayer++;
      }
    }
    if(tie){
      game.displayBoard();
      cout << "\nTie game ends in draw" << endl;
      ties++;
    }
    else if(currentPlayer == PLAYER1){
      game.displayBoard();
      cout << "\nPlayer 1 has won!" << endl;
      p1Wins++;
      p2Losses++; 
    }
    else if(currentPlayer == PLAYER2){
      game.displayBoard();
      cout << "\nplayer 2 has won!" << endl;
      p2Wins++;
      p1Losses++;
    }
    // game statistics
    cout << "\nGames played: "<<gamesPlayed<<endl;
    cout << "[Player 1] "<<"Wins: "<<p1Wins<<" Losses: "<<p1Losses<< endl;
    cout << "[Player 2] "<<"Wins: "<<p2Wins<<" Losses: "<<p2Losses<< endl;
    cout << "Number of ties: " << ties << endl;
    
    cout << "Do you want to play again(y/n)? ";
    cin >> playGame;		
    if(toupper(playGame) == 'Y'){
      currentPlayer = 1;
      end = false; 
    }
  }
  cout << "Goodbye..." << endl;
  return 0;
}