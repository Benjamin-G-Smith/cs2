// Ben Smith
// hangman.h
// 4/5/2017

// Class file for the hangman game
// PURPOSE: This class is meant to be used to implement a game of hangman. 
//  The methods declared in this main give the programer the tools to create
//  a fully functioning game. 

#include <iostream> 
#include <cstdlib>
#include <fstream>
#include <cctype>
#include <string.h>

using namespace std;

#ifndef HANGMAN_H
#define HANGMAN_H

class Hangman
{
	public:
	Hangman();
	void displayGame();
	// PRE: Hidden word has been set along with the alphabet array
	// POST: Changes the displayed spaced for the hidden word with the actual
	//  characters.
	void displayStatistics();
	// PRE: wins, losses, number of words in the file, and number of 
	//  words left to be selected.
	void revealWord(); 
	// PRE: Must have a hidden word
	bool initializeFile(string filename);
	// PRE: Having a good file to use
	// POST: Sets the hidden word
	bool newWord();	
	// PRE: Must have a wordlist
	// POST: Changes the word
	bool guess(char letter,bool& done,bool& won);
	// PRE: Must have a letter, done condition, and win bool condition
	// POST: Ends the game declaring a winner or if the player lost
	private:
		void gameReset();
		static const int NUMBER_OF_GUESSES = 7;
		static const char UNDERSCORE = '_';
		static const int BODY_SIZE = 9;
		static const int LIST_SIZE = 100;
		static const int ALPHABET = 26;
		static const char START = 'A';
		static const int HEAD = 1;
		static const int BODY = 2;
		static const int L_ARM = 3;		
		static const int R_ARM = 4;
		static const int TORSO = 5;
		static const int L_LEG = 6;
		static const int R_LEG = 7;
		const string SPACE = " ";
		string randomWord;
		int wins;
		int losses;
		int numberOfWords;
		int totalWords = 0;
		int wordsRemaining; 
		int badGuess;
		unsigned int wordsCorrect;
		char hiddenWordArray[1042];	

		struct BodyPart
		{
			string firstLine;
			string secondLine;
			string thirdLine;
			bool displaySecond;
			bool displayThird;
		};
		struct Letter
		{
			char letter;
			bool counted;
			bool used;
			int index;
		};
		struct Word
		{
			string word;
			bool used;
		};

		Word fileWords[LIST_SIZE];
		BodyPart body[BODY_SIZE];
		Letter alphabet[ALPHABET];		
};
#endif 