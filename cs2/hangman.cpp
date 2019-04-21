// Ben Smith
// hangman.cpp
// 4/5/2017

// Purpose: Implementation for hangman described in hangman.h

#include "hangman.h"
// Hangman Constructor: Initalizes class variables along with the body
//  for the hangman display.
Hangman::Hangman()
{

	body[0].firstLine = "    ----\n";
    body[1].firstLine = "    |  |\n";
    body[2].firstLine = "       |\n";
    body[2].secondLine = "    O  |\n";
    body[3].firstLine = "       |\n";
    body[3].secondLine = "    |  |\n";
    body[4].firstLine = "       |\n";
	  body[4].secondLine = "   -|  |\n";
    body[4].thirdLine = "   -|- |\n";
    body[5].firstLine = "       |\n";
    body[5].secondLine = "    |  |\n";
    body[6].firstLine = "       |\n";
    body[6].secondLine = "   /   |\n";
    body[6].thirdLine = "   / \\ |\n";
    body[7].firstLine = "       |\n";
    body[8].firstLine = "_______|___\n";

    for(int i = 0; i < BODY_SIZE; i++){
    	body[i].displaySecond = false;
    	body[i].displayThird = false;
    }

	char letter = 'A';
	for(int index = 0; index < ALPHABET; index++){
		alphabet[index].letter = letter;
		alphabet[index].index = index;
		alphabet[index].used = false;
		alphabet[index].counted = false;
		letter++;
	}

	wins = 0;
	losses = 0;
	numberOfWords = totalWords;
	badGuess = 0;
	wordsCorrect = 0;
}
// OUT: Displays the game information to the player. This includes the hangman
//  picture along with the hidden word represented in "_".
void Hangman::displayGame()
{
	//Display Hangman
	// To be implemented in a different way latter.
	for(int i = 0; i < BODY_SIZE;  i++){
		if(body[i].displaySecond){
			cout << body[i].secondLine;
		}
		else if(body[i].displayThird){
			cout << body[i].thirdLine;
		}
		else
			cout << body[i].firstLine;
	}
	// Displays the hidden wotd with "_" changing them as the user guesses
	//  correctly.
	for(unsigned int i = 0; i < randomWord.length(); i++){
		if(alphabet[hiddenWordArray[i]-START].used){
			cout << hiddenWordArray[i] << SPACE;
		}
		else{
			cout << UNDERSCORE <<SPACE;
		}
	}
	cout <<"\n"<< endl;
	// Displays the alphabet and if each letter has been guessed.
	for(int i = 0; i < ALPHABET; i++){
		if(alphabet[i].used){
			cout << SPACE;
		}
		else if(!alphabet[i].used){
			cout << alphabet[i].letter <<SPACE;
		}
	}
	cout << endl;

}
void Hangman::displayStatistics()
{
	cout <<"Number of Wins: " << wins <<SPACE
	<<"Number of Losses: "<< losses<<" \n"
	<<"Words: " << totalWords<<" \n"
	<<"Words Remaining: " << wordsRemaining << endl;
}
void Hangman::revealWord()
{
	cout<<"    ----\n";
    cout<<"    |  |\n";
    cout<<"    O  |\n";
    cout<<"    |  |\n";
    cout<<"   -|- |\n";
    cout<<"    |  |\n";
    cout<<"   / \\ |\n";
    cout<<"       |\n";
    cout<<"_______|___\n";
	cout <<"The word was: "<< randomWord << endl;
}
// IN: The file containint the words for hangman.
bool Hangman::initializeFile(string filename)
{
	ifstream inFile;

	inFile.open(filename);
	if(inFile.fail()){
		return false;
	}
	// Writes the contents to a filewords array
	while(inFile >> fileWords[totalWords].word){
		fileWords[totalWords].used = false;
		totalWords++;
	}
	wordsRemaining = totalWords;
	inFile.close();
	return true;
}
// Selects a random word from the wordlist array
bool Hangman::newWord()
{
	unsigned seed = time(0);
	srand(seed);
	int randNum = rand() % totalWords + 1;
	while(fileWords[randNum].used ){
		randNum = rand() % totalWords + 1;
	}
	if(!fileWords[randNum].used){
		randomWord = fileWords[randNum].word;
		strncpy(hiddenWordArray, randomWord.c_str(),sizeof(hiddenWordArray));
		wordsRemaining--;
		return true;
	}
	else
		return false;
}
// IN: Letter entered, gameOver condition, and win condition
bool Hangman::guess(char letter,bool& done,bool& won)
{
	// Keeps track of letters that get used
	alphabet[letter-START].used = true;

	for(unsigned int i = 0; i < randomWord.length(); i++){
		if(letter == hiddenWordArray[i]){
			alphabet[hiddenWordArray[i]-START].counted = true;
		}
	}

	if(alphabet[letter-START].used && !alphabet[letter-START].counted){
		badGuess++;
	}

	wordsCorrect = 0;
	// finds the number of correct letters guessed
	for(unsigned int i = 0; i < randomWord.length();i++){
		if(alphabet[hiddenWordArray[i]-START].used &&
			alphabet[hiddenWordArray[i]-START].counted){
			wordsCorrect++;
		}
	}

	if(wordsCorrect == randomWord.length()){
		done = true;
		won = true;
		wins++;
		gameReset();
	}

	switch(badGuess){

		case HEAD:
		body[2].displaySecond = true;
		break;

		case BODY:
		body[3].displaySecond = true;
		break;

		case L_ARM:
		body[4].displaySecond = true;
		break;

		case R_ARM:
		body[4].displaySecond = false;
		body[4].displayThird = true;
		break;

		case TORSO:
		body[5].displaySecond = true;
		break;

		case L_LEG:
		body[6].displaySecond = true;
		break;

		case R_LEG:
		body[6].displaySecond = false;
		body[6].displayThird = true;
		break;
	}

	if(badGuess == NUMBER_OF_GUESSES){
		losses++;
		done = true;
		gameReset();
	}
	return false;
}
// Resets the game so the player can play the next game.
void Hangman::gameReset()
{
	for(int i = 0; i < BODY_SIZE; i++){
    	body[i].displaySecond = false;
    	body[i].displayThird = false;
    }
	char letter = 'A';
	for(int index = 0; index < ALPHABET; index++){
		alphabet[index].letter = letter;
		alphabet[index].index = index;
		alphabet[index].used = false;
		letter++;
	}
	badGuess = 0;
}
