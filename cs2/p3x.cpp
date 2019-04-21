// Ben Smith
// p3x.cpp
// 5/9/2017

// PURPOSE: This program allows a user to unscramble a message from an input 
//  file. Then combining two resulting messages into one complete message.

// INPUTS: The two files containing the data that needs to be sorted into one 
//  list. If the user wants to run the program or not. 

// PROCESSING: The program sorts the numbers assigned to characters into
//  assending order. Then the program prints the characters to complete the
//  unscrambled message. Then the program combines the two lsits into one.
//  Then deletes the allocated memory.

// OUTPUTS: The complete decoded message with the merged information along 
//  with a prompt asking the user if they want to run the program again. 

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
Node* mergeLists(Node*& h1, Node*& h2);
// Combines the head h1 and h1 to complete the final merged list
// post: h1 and h2 are merged inot a new final head which is returned.


int main()
{
  ifstream inputFile;
  string file1;
  string file2;
  char startProgram;
  char ch;
  int d;
  const int SPACER = 10;
  const string SPACE = " ";
  Node* head1 = nullptr;
  Node* head2 = nullptr;
  Node* temp = nullptr;

  for(int i = 0; i < SPACER; i++){
    cout << SPACE << endl;
  }
  // Welcome message 
  cout<<"Welcome to professor Potter's puzzling merging decoder"<<endl;  
  cout << "\nWould you like to run the program(Y/N)?: ";
  cin>>startProgram;
  // validates user input
  while(toupper(startProgram) != 'N' && toupper(startProgram) != 'Y'){
    cout << "Invalid..." << endl;
    cout << "Would you like to run the program(Y/N)?: ";
    cin >> startProgram; 
  }    
  while(toupper(startProgram) != 'N'){
    cout << "\nEnter the first data file: ";
	  cin >> file1;
    
	inputFile.open(file1);
    
	while(inputFile.fail()){
      cout << "Error opening file..."<<endl;
      cout << "Enter the first data file: ";
      cin>>file1;
      inputFile.open(file1);
	}

	while(inputFile.get(ch)){
      inputFile >> d;
      sortFile(head1,ch,d);
      inputFile.ignore();
	}
    inputFile.close();
    cout << "\nEnter the second data file to merge: ";
    cin >> file2;

    inputFile.open(file2);
    
  while(inputFile.fail()){
    cout << "Error opening file..."<<endl;
    cout << "Enter the second data file: ";
    cin>>file2;
    inputFile.open(file2);
  }
    
  while(inputFile.get(ch)){
    inputFile >> d;
    sortFile(head2,ch,d);
    inputFile.ignore();
  }
  inputFile.close();
  
  cout << endl;
  printList(head2);
  cout << endl << endl;
  printList(head1);
  cout << endl << endl;

  temp = mergeLists(head1,head2);
  printList(temp);
  cout << endl << endl;
  
  delList(temp);
 
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
Node* mergeLists(Node*& h1, Node*& h2)
{
  Node* finalList = nullptr;
  Node* finalEnd = nullptr;

  finalList = h1;
  finalEnd = finalList;

  while(h1->next != nullptr && finalEnd->letter != ' ' ){
    finalEnd = finalEnd->next;
  }
  h1 = finalEnd->next; 
  
  while(h1 != nullptr && h2 != nullptr){ 
    finalEnd->next = h2;  
    finalEnd = h2->next;
    h2 = finalEnd->next;
    while(h2 != nullptr && finalEnd->letter != ' '){
      finalEnd = finalEnd->next;    
    }
    h2 = finalEnd->next;
    
    if(h2 == nullptr){
      finalEnd->next = h1;
      return finalList;
      cout << "Null" << endl;
    }
    finalEnd->next = h1;
    finalEnd = h1->next;
    h1 = finalEnd->next;
    while(h1 != nullptr && finalEnd->letter != ' ' ){
      finalEnd = finalEnd->next;
    }
    h1 = finalEnd->next;
    if(h1 == nullptr){
      finalEnd->next = h2;
      return finalList;
      cout << "Null" << endl;
    }
  }
  return finalList;  
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
