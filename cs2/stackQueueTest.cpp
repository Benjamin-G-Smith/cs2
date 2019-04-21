// Susan Reeder
// stackQueueTest.cpp
// testing of integer stack & queue packages

#include <iostream>
#include "stack.h"
#include "queue.h"

using namespace std;

void testStack();
// tests all stack package methods

void testQueue();
// tests all queue package methods

int main()
{
  cout << "testing Stack operations...." << endl;
  testStack();
  cout << "testing Queue operations...." << endl;
  testQueue();
  return 0;
}

void testStack()
{
  int num;
  // constructor
  Stack s1;
  // constructor with size
  Stack s2(52);

  // push
  cout << "pushing 4 values onto stack of size 50" << endl;
  for (int i = 0; i < 4; i++){
	if (!s1.push(i))
	  cout << "Sorry, could not push " << i << " onto stack" << endl;
	else
	  cout << "Successful push of " << i << endl;
  }

  // copy constructor
  cout << "making a copy of stack into new instance" << endl;
  Stack s3(s1);
  // pop & isEmpty
  cout << "now popping all values from original stack" << endl;
  while (!s1.isEmpty()){
	if (!s1.pop(num))
	  cout << "Could not pop from s1" << endl;
	else
	  cout << "Popped " << num << " from s1" << endl;
  }
  cout << "now popping all values from copied stack" << endl;
  while (!s3.isEmpty()){
	if (!s3.pop(num))
	  cout << "Could not pop from s3" << endl;
	else
	  cout << "Popped " << num << " from s3" << endl;
  }

  // resize
  cout << "pushing 5 values onto stack of size 3" << endl;
  for (int i = 0; i < 52; i++){
	if (!s2.push(i))
	  cout << "Sorry, could not push " << i << " onto stack" << endl;
	else
	  cout << "Pushed " << i << " onto stack" << endl;
  }

 // assignment operator
  cout << "copying s2 into s1" << endl;
  s1 = s2;
  cout << "now popping all of s2" << endl;
  while (!s2.isEmpty()){
	s2.pop(num);
	cout << "Popped " << num << " from s2" << endl;
  }
  cout << "now popping all of s1" << endl;
  while (!s1.isEmpty()){
	s1.pop(num);
	cout << "Popped " << num << " from s1" << endl;
  }

}

void testQueue()
{
  int num;
  // constructor
  Queue q1, q3;
  // enqueue
  cout << "Adding 5 items to queue...." << endl;
  for (int i = 3; i < 8; i++){
	if (!q1.enqueue(i))
	  cout << "Could not add to q1" << endl;
	else
	  cout << "Added " << i << " to q1" << endl;
  }

  // copy constructor
  cout << "Making a copy of q1 into q2(using copy constructor)" << endl;
  Queue q2(q1);
  cout << "now emptying q1" << endl;
  // dequeue & isEmpty
  while (!q1.isEmpty()){
	if (!q1.dequeue(num))
	  cout << "could not dequeue from q1" << endl;
	else
	  cout << "Removed " << num << " from q1" << endl;
  }

  // assignment operator
  cout << "copying q2 into q3 (using assignment operator)" << endl;
  q3 = q2;
  cout << "now removing all values from q2" << endl;
  while (!q2.isEmpty()){
	if (!q2.dequeue(num))
	  cout << "could not dequeue from q2" << endl;
	else
	  cout << "Removed " << num << " from q2" << endl;
  }

  cout << "now removing all values from q3" << endl;
  while (!q3.isEmpty()){
	if (!q3.dequeue(num))
	  cout << "could not dequeue from q3" << endl;
	else
	  cout << "removed " << num << " from q3" << endl;
  }
}
