// Ben Smith
// queue.cpp
// 5/17/2017

// Purpose: Implementation of the queue.h file

#include "queue.h"

// constructor
Queue::Queue()
{
  front = nullptr;
  tail = nullptr;
}
// copy constructor
Queue::Queue(const Queue& rhs)
{
  front = new Qnode;
  Qnode* temp;
  temp = rhs.front;
  tail = front;
  front->data = temp->data;
  while(temp->next != nullptr){
    tail->next = new Qnode;
    tail = tail->next;
    temp = temp->next;
    tail->data = temp->data;
  }
  tail->next = nullptr;
}
// Overloaded assignment operator
Queue& Queue::operator=(const Queue& rhs)
{
  if(rhs.front == nullptr){
    front = nullptr;
    tail = nullptr;
  }
  deleteList();
  front = new Qnode;
  Qnode* temp;
  temp = rhs.front;
  tail = front;
  front->data = temp->data;
  while(temp->next != nullptr){
    tail->next = new Qnode;
    tail = tail->next;
    temp = temp->next;
    tail->data = temp->data;
  }
  tail->next = nullptr;
  return *this;
}
bool Queue::enqueue(int v)
{
  if(front == nullptr){
    front = new Qnode;
    if(front == nullptr){
      return false;
    }
    front->data = v;
    front->next = nullptr;
    tail = front;
    tail->next = nullptr;
  }
  else{
    tail->next = new Qnode;
	if(tail->next == nullptr){
      return false;
	}
	tail = tail->next;
    tail->data = v;
    tail->next = nullptr;
  }
  return true;
}
bool Queue::dequeue(int &v)
{
  Qnode* delptr;
  if(front == nullptr){
    return false;
  }
  else{
    v = front->data;
    delptr = front;
    front = front->next;
    delete delptr;
  }
  return true;
}
void Queue::deleteList()
{
  Qnode* delptr;
  while(front != nullptr){
    delptr = front;
    front = front->next;
    delete delptr;
  }
}
const bool Queue::isEmpty()
{
  return front == nullptr;
}
Queue::~Queue()
{
  Qnode* delptr;
  while(front != nullptr){
    delptr = front;
    front = front->next;
    delete delptr;
  }
}
