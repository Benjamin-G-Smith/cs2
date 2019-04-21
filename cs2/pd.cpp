// Palindrome test


#include <iostream>
#include <string>
#include "stack.h"
#include "queue.h"

using namespace std;

bool palindrome(string keyWord);

int main()
{
  string userWord;
  string startProgram;

  cout << "Would you like to check a palindrome? [y/n]?";
  cin >> startProgram;
  while(startProgram == "y"){
    cout << "Enter a word you want to check:";
    cin >> userWord;
    bool isPalindrome = palindrome(userWord);
    if(isPalindrome){
      cout << "Word is a palindrome" << endl;
    }
    else{
      cout << "Word is not a palindrome" << endl;
    }
    cout << "Would you like to check a palindrome? [y/n]?";
    cin >> startProgram;
  }
  return 0;
}
bool palindrome(string keyWord)
{
  string word = keyWord;
  Stack s;
  Queue q;
  int c;
  int length = word.length();
  for(int i = 0; i < length; i++){
    s.push(word[i]);
  }
  for(int i = 0; i < length; i++){
    s.pop(c);
    if(c != word[i]){
      return false;
    }
  }
  return true;

}
