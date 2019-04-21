//


#include "toy.h"
#include <iostream>

using namespace std;

struct Node{
  Toy t;
  Node *next;
};

bool insertByID(Node* h, string ID);
void printList(Node* h);

int main()
{
  Node *h = nullptr;
  insertByID(h,"123");
  cout << "done" << endl;
  insertByID(h,"345");
  cout << "done" << endl;
  insertByID(h,"678");
  cout << "done" << endl;
  printList(h);
  return 0;
}
void printList(Node* h)
{
  cout << "printing" << endl;
  Node* ptr = h;
  if(ptr == nullptr){
    cout << "NULLLLLLLL" << endl;
  }
  while(ptr != nullptr){
    cout << " Id " << ptr->t.getID() << endl;
    ptr = ptr->next;
  }
}
bool insertByID(Node* h, string ID)
{
  Node* ptr;
  Node* temp = new Node;

  if(temp == nullptr){
    return false;
  }
  temp->t.setID(ID);
  if(h == nullptr){
    h = temp;
    h->next = nullptr;
  }
  else if(h->t.getID() > temp->t.getID()){
    temp->next = h;
    h = temp;
  }
  else {
    ptr = h;
    while(ptr->next != nullptr && ptr->next->t.getID() > temp->t.getID()){
      ptr = ptr->next;
    }
    temp->next = ptr->next;
    ptr->next = temp;
  }
  return true;
}
