// Ben Smith
// lab6.cpp
// 5/3/2017

#include <iostream>
#include <fstream>

using namespace std;

struct Node
{
  int data;
  Node* next;
};

const string FILENAME = "/home/fac/sreeder/class/cs1430/lab6.dat";

bool insertInOrder(Node*& h, int d);
// inserts d into h in numerical order
// returns false if no memory available
// post: h may be changed

void printList(Node* h);
// prints all data on h to the screen in a column

void delList(Node*& h);
// post: each node of h deleted
void removeDuplicates(Node*& h);
// Checks to see if there are any duplicates in the list
// post: removes the extra elements
bool reverseList(Node*& h);

int main()
{
  Node* head = nullptr;
  ifstream inFile;
  int num;

  inFile.open(FILENAME);
  if (inFile.fail()){
	cout << "file problem...exiting program...press enter...";
	cin.get();
  }

  while (inFile >> num && insertInOrder(head, num));

  cout << endl;
  cout << "File contents..."<< endl;
  printList(head);

  cout << endl;
  cout << "Removing duplicates..." << endl;
  removeDuplicates(head);
  cout << endl;
  printList(head);
  cout << endl << endl;
  reverseList(head);
  printList(head);
  cout << endl << endl;



  delList(head);

  return 0;
}
bool reverseList(Node*& h)
{
  if(h == nullptr){
    return false;
  }
  Node* current = h;
  Node* next = current->next;
  Node* previous = nullptr;

  while(next != nullptr){
    current->next = previous;
    previous = current;
    current = next;
    next = current->next;
  }
  current->next = previous;
  h = current;
  return true;
}
void removeDuplicates(Node*& h)
{
  Node* ptr = h;
  Node* del;
  if(h == nullptr){
    return;
  }
  while(ptr->next != nullptr){
    if(ptr->data == ptr->next->data){
      del = ptr->next;
      ptr->next = del->next;
      delete del;
    }
    else{
      ptr = ptr->next;
    }
  }
}
bool insertInOrder(Node*& h, int d)
{
  Node* temp;
  Node* ptr = h;
  temp = new Node;

  if(temp == nullptr){
    return false;
  }

  temp->data = d;
  temp->next = nullptr;

  if(h == nullptr){
  	h = temp;
  }
  else if(h->data > temp->data){
    temp->next = h;
    h = temp;
  }
  else{
  	ptr = h;
    while(ptr->next != nullptr && ptr->next->data < d){
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
    cout << temp->data<<" ";
    temp = temp->next;
  }
  cout << endl;
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
