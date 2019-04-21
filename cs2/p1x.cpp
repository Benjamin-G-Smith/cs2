// Ben Smith 
// p1x.cpp
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
	Hangman player1;
	Hangman player2;
	bool game1End = false;
	bool game1Win = false;
	bool game2Win = false;
	bool game2Win = false;
	bool play = true;
	char letterP1;
	char letterP2;
	string player1Start;
	string player2Start;
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
	cout << "[PLAYER_1]" << endl;
	cout << "Type enter any key to START or 'quit' to exit "; 
	cin >> player1Start;
	//The player can quit on start
	if(player1Start == QUIT){
		cout << "Thanks for playing Goodbye..." << endl;
		return 0;
	}
	welcomeMessage();
	cout  <<"[PLAYER_2]" << endl;
	cout << "Type enter any key to START or 'quit' to exit "; 
	cin >> player1Start;
	//The player can quit on start
	if(player1Start == QUIT){
		cout << "Thanks for playing Goodbye..." << endl;
		return 0; 
	}

	while(play){

		player1.displayStatistics();
		player1.newWord();
		player1.displayGame();
		game1End = false;
		game1Win = false;
		game2Win = false;
		game2End = false;

		while(!game1End && !game2End){

			cout << "[PLAYER_1] Guess Letter: ";
			cin >> letterP1;
			//Input validation 
			while(!isalpha(letterP1)){
				cout << "Invalid input"<< endl;
				cout << "Guess Letter: "<< endl;
				cin >> letterP1;
			}
			player1.guess(toupper(letterP1),game1End,game1Win);
			player1.displayGame();
			
			cout <<"[PLAYER_2] Guess Letter: "
			cin >> letterP2;
			while(!isalpha(letterP2)){
				cout << "Invalid input"<< endl;
				cout << "Guess Letter: "<< endl;
				cin >> letterP2;
			}
			player1.guess(toupper(letterP1),game1End,game1Win);
			player1.displayGame();
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
