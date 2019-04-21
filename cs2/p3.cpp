// Ben Smith
// p3.cpp
// 5/9/2017

// PURPOSE: This program allows a user to unscramble a message from an input 
//  file. 

// INPUTS: The file containing the data that needs to be sorted. If the user
//  wants to run the program or not. 

// PROCESSING: The program sorts the numbers assigned to characters into
//  assending order. Then the program prints the characters to complete the
//  unscrambled message. Then deletes the allocated memory.

// OUTPUTS: The decoded message along with a prompt asking the user if they 
//  want to run the program again. 

#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

struct Node{
  int position;
  char letter;
  Node *next;
};
bool sortFile(Node*& h,char ch, int d);
// Inserts d into h into numerical order along with the character ch
// returns false if no memort avalible
// POST: h is changed
void printList(Node* h);
// prints all data on h to the screen in a column
void delList(Node*& h);
// post: each node of h deleted

int main()
{
  ifstream inputFile;
  string file;
  char startProgram;
  char ch;
  int d;
  const int SPACER = 10;
  const string SPACE = " ";
  Node* head = nullptr;

  for(int i = 0; i < SPACER; i++){ // prints 10 lines on the console
    cout << SPACE << endl;
  }
  // Welcome message
  cout << "Welcome to professor Potter's puzzling message decoder" << endl;
  cout << "\nWould you like to run the program(Y/N)?: ";
  cin>>startProgram;
  // Validates user input
  while(toupper(startProgram) != 'N' && toupper(startProgram) != 'Y'){
  	cout << "Invalid..." << endl;
  	cout << "Would you like to run the program(Y/N)?: ";
  	cin >> startProgram; 
  }  
  // Runs main loop
  while(toupper(startProgram) != 'N'){
    cout << "\nEnter the first data file: ";
	  cin >> file;
    
	inputFile.open(file);
    
	while(inputFile.fail()){
      cout << "Error opening file..."<<endl;
      cout << "Enter the first data file: ";
      cin>>file;
      inputFile.open(file);
	}
	
	while(inputFile.get(ch) != nullptr){
      inputFile >> d;
      sortFile(head,ch,d);
      inputFile.ignore();
	}
	
	cout << endl;
    printList(head);
    
    cout << endl << endl;
    
    delList(head);
    
    inputFile.close();
    cout << "Would you like to decode another file?(Y/N): ";
    cin>>startProgram;
    while(toupper(startProgram) != 'N' && toupper(startProgram) != 'Y'){
  	  cout << "Invalid..." << endl;
  	  cout << "Would you like to run the program(Y/N)?: ";
  	  cin >> startProgram; 
  	 } 
  }
  cout << "\nGoodbye..."<<endl;
  return 0;
}
bool sortFile(Node*& h,char ch, int d)
{
  Node* temp;  
  Node* ptr = h;
  temp = new Node;

  if(temp == nullptr){
    return false;
  }
  
  temp->position = d;
  temp->letter = ch; 
  temp->next = nullptr;
  
  if(h == nullptr){
  	h = temp;
  }
  else if(h->position > temp->position){
    temp->next = h;
    h = temp;
  }
  else{
  	ptr = h;
    while(ptr->next != nullptr && ptr->next->position < d){
      ptr = ptr->next;
    }
    temp->next = ptr->next;
    ptr->next = temp;
  } 
  return true;
}
void printList(Node* h)
{
  Node* temp = h;
  while(temp != nullptr){
    cout << temp->letter;
    temp = temp->next;
  }
}
void delList(Node*& h)
{
  Node* deltemp;
  while(h != nullptr){
    deltemp = h;
    h = h->next;
    delete deltemp;
  }
}
