// Ben Smith 
// lab5.cpp

#include <iostream>
#include <fstream>

using namespace std;

struct Node
{
  int data;
  Node* next;
};

const string FILENAME = "/home/fac/sreeder/class/cs1430/lab5.dat";

bool insertInOrder(Node*& h, int d);
// inserts d into h in numerical order
// returns false if no memory available
// post: h may be changed

void printList(Node* h);
// prints all data on h to the screen in a column

void delList(Node*& h);
// post: each node of h deleted

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
  printList(head);

  cout << endl << endl;
  
  delList(head);
	
  return 0;
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
    cout << temp->data << endl;
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
