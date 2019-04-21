// Ben Smith 
// p1.cpp
// 4/9/2017

// PURPOSE: Allows a user to play a game of hangman. On each turn
//  the player tries to guess the hidden word displayed in underscores.
//  If the player guesses one letter that letter is revealed. If the 
//  player is wrong then a body part for the hangman is displayed.
//  The player continues to play until they have run out of guesses or
//  they sucessfuly guess the word. At the end of each game wins and losses
//  are kept track of. 

// INPUT: A file containing data for the wordlist in the game. If the player
//  wants to play the game or quit. Each letter guessed is taken into the 
//  program and processed. 

// PROCESS: The program establishes a wordlist array with the data from the
//  input file. Initalizes all the elements of a hangman game (guesses,
//  display, wordChoice, and the alphabet). 

// OUTPUT: Display game statistics(wins, losses, numberofGuesses, and 
//  numberOfWords in the word lsit). If the player wants to play/play again.
//  The game display ie the hangman body and body parts. Welcome and goodbye 
//  messages.

// EXAMPLES:
//File loaded OK...
//******************************************************
//* Welcome to..........................               *
//*  _                                                 *
//* | |                                                *
//* | |__   __ _ _ __   __ _ _ __ ___   __ _ _ __      *
//* | '_ \ / _` | '_ \ / _` | '_ ` _ \ / _` | '_ \     *
//* | | | | (_| | | | | (_| | | | | | | (_| | | | |    *
//* |_| |_|\__,_|_| |_|\__, |_| |_| |_|\__,_|_| |_|    *
//*                     __/ |                          *
//*                    |___/                           *
//*The purpose of the is game is to try and guess the  *
//*hidden word before the man is hung                  *
//******************************************************
//Type enter any key to START or 'quit' to exit a
//Number of Wins: 0 Number of Losses: 0
//Words: 48
//Words Remaining: 48
//    ----
//    |  |
//       |
//       |
//       |
//       |
//       |
//       |
//_______|___
//_ _ _ _ _ _ _ _
//
//A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
//Guess Letter: a
//    ----
//    |  |
//       |
//       |
//       |
//       |
//       |
//       |
//_______|___
//_ _ _ _ _ A _ _
//
// B C D E F G H I J K L M N O P Q R S T U V W X Y Z
//    ----
//    |  |
//    O  |
//    |  |
//   -|- |
//    |  |
//   / \ |
//       |
//_______|___
//The word was: CONTRAST
//You WON!
//Number of Wins: 1 Number of Losses: 0
//Words: 48
//Words Remaining: 47
//Type ANY character to PLAY AGAIN or 'quit' to exit quit
//Thanks for playing goodbye...

//File loaded OK...
//******************************************************
//* Welcome to..........................               *
//*  _                                                 *
//* | |                                                *
//* | |__   __ _ _ __   __ _ _ __ ___   __ _ _ __      *
//* | '_ \ / _` | '_ \ / _` | '_ ` _ \ / _` | '_ \     *
//* | | | | (_| | | | | (_| | | | | | | (_| | | | |    *
//* |_| |_|\__,_|_| |_|\__, |_| |_| |_|\__,_|_| |_|    *
//*                     __/ |                          *
//*                    |___/                           *
//*The purpose of the is game is to try and guess the  *
//*hidden word before the man is hung                  *
//******************************************************
//Type enter any key to START or 'quit' to exit a
//Number of Wins: 0 Number of Losses: 0
//Words: 48
//Words Remaining: 48
//
// B C D  F G H I J K L M N O P Q R S T U V W X Y Z
//Guess Letter: a
//    ----
//    |  |
//       |
//       |
//       |
//       |
//       |
//       |
//_______|___
//_ _ _ _ E _
//
// B C D  F G H I J K L M N O P Q R S T U V W X Y Z
//Guess Letter: z
//    ----
//    |  |
//    O  |
//       |
//       |
//       |
//       |
//       |
//_______|___
//_ _ _ _ E _
//
//    ----
//    |  |
//    O  |
//    |  |
//   -|- |
//    |  |
//   / \ |
//       |
//_______|___
//The word was: HUNTER
//Number of Wins: 1 Number of Losses: 1
//Words: 48
//Words Remaining: 46
//Type ANY character to PLAY AGAIN or 'quit' to exit quit
//Thanks for playing Goodbye...

#include "hangman.h"
#include <iostream>
#include <cctype>

using namespace std;

void welcomeMessage();
// OUT: Prints a welcome message for hangman
int main()
{
	Hangman game;
	bool gameEnd = false;
	bool gameWin = false;
	bool play = true;
	char letter;
	string playGame;
	const string QUIT = "quit";	
	const string inputFile = "/home/fac/sreeder/class/cs1430/p1input.dat";
	//checks for a valid file
	if(!game.initializeFile(inputFile)){
		cout << "Error opening file..." << endl;
		return 0;
	}
	else
		cout << "File loaded OK..." << endl;

	welcomeMessage();

	cout << "Type enter any key to START or 'quit' to exit "; 
	cin >> playGame;
	//The player can quit on start
	if(playGame == QUIT){
		cout << "Thanks for playing Goodbye..." << endl;
		return 0;
	}

	game.displayStatistics();

	while(play){

		game.newWord();
		game.displayGame();
		gameEnd = false;
		gameWin = false;

		while(!gameEnd){
			cout << "Guess Letter: ";
			cin >> letter;
			//Input validation 
			while(!isalpha(letter)){
				cout << "Invalid input"<< endl;
				cout << "Guess Letter: "<< endl;
				cin >> letter;
			}
			game.guess(toupper(letter),gameEnd,gameWin);
			game.displayGame();
		}
		game.revealWord();
		if(gameWin){
			cout << "You WON!"<< endl;
		}
		game.displayStatistics();
		cout << "Type ANY character to PLAY AGAIN or 'quit' to exit ";
		cin >> playGame;
		if(playGame == QUIT){
			play = false;
		}
	}
	cout << "Thanks for playing Goodbye..." << endl;
	return 0;
}
void welcomeMessage()
{
	cout <<"******************************************************"<<endl;
	cout <<"* Welcome to..........................               *"<<endl;
	cout <<"*  _                                                 *"<<endl; 
	cout <<"* | |                                                *"<<endl;
	cout <<"* | |__   __ _ _ __   __ _ _ __ ___   __ _ _ __      *"<<endl;
	cout <<"* | '_ \\ / _` | '_ \\ / _` | '_ ` _ \\ / _` | '_ \\     *"<<endl;
	cout <<"* | | | | (_| | | | | (_| | | | | | | (_| | | | |    *"<<endl;
	cout <<"* |_| |_|\\__,_|_| |_|\\__, |_| |_| |_|\\__,_|_| |_|    *"<<endl;
	cout <<"*                     __/ |                          *"<<endl;
	cout <<"*                    |___/                           *"<<endl;
	cout <<"*The purpose of the is game is to try and guess the  *"<<endl;
	cout <<"*hidden word before the man is hung                  *" << endl;
	cout <<"******************************************************"<<endl;
}
