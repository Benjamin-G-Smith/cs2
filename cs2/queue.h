// Ben Smith
// queue.h
// 5/17/2017

// Purpose: The class file for the queue. Allows a user to preform queue
//  functions enqueue and dequeue.

using namespace std;

#ifndef QUEUE_H
#define QUEUE_H

class Queue
{
 public:
  Queue();
  Queue(const Queue &rhs);
  Queue& operator=(const Queue &rhs);
  ~Queue();
  bool enqueue(int v);
  // Pre: There must be a valid input value for v along with the memory for
  //  allocation.
  // Post: The value passed into v is stored into a new node in a liked list
  //  for the queue.
  bool dequeue(int& v);
  // Pre: There must be a value to dequeue from a linked list
  // Post: A value is removed from the front of a queue
  const bool isEmpty();
  // Checks to see if the queue   is empty or not

 private:
  void deleteList(); // Private helper function to delete
  struct Qnode{
    int data;
    Qnode* next;
  };
  Qnode* front;
  Qnode* tail;
};
#endif
