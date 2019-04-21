// Ben Smith
// p4.cpp
// 5/16/2017

// PURPOSE: To test the stack and queue packages through a series
//  of functions. Allows the user to determine if their stack and
//  queue packages work.

#include "stack.h"
#include "queue.h"
#include <iostream>

using namespace std;

void testQueue();
void testStack();

int main()
{
  cout << "Press Enter to test stack:";
  cin.get();
  cout << "Testing Stack package..." << endl;
  testStack();
  cout << "Press Enter to test queue:";
  cin.get();
  cout << "Testing Queue package..." << endl;
  testQueue();

  return 0;
}
void testStack()
{
  int num;
  // constructor
  Stack s1;
  // constructor with size
  Stack s2(10);

  // push test
  cout << "[pushing 10 values onto stack of size 50]" << endl;
  for (int i = 1; i < 11; i++){
	if (!s1.push(i))
	  cout << "Could not push " << i << " onto stack" << endl;
	else
	  cout << "Successful push of " << i << endl;
  }

  // copy constructor
  cout << "[Copying stack into new instance]" << endl;
  Stack s3(s1);
  // pop & isEmpty
  cout << "[Popping all values from original stack]" << endl;
  while (!s1.isEmpty()){
	if (!s1.pop(num))
	  cout << "Could not pop from s1" << endl;
	else
	  cout << "Popped " << num << " from s1" << endl;
  }
  cout << "[Popping all values from copied stack]" << endl;
  while (!s3.isEmpty()){
	if (!s3.pop(num))
	  cout << "Could not pop from s3" << endl;
	else
	  cout << "Popped " << num << " from s3" << endl;
  }

  // resize test
  cout << "[pushing 10 values onto stack of size 10]" << endl;
  for (int i = 1; i < 11; i++){
	if (!s2.push(i))
	  cout << "Could not push " << i << " onto stack" << endl;
	else
	  cout << "Pushed " << i << " onto stack" << endl;
  }

 // assignment operator
  cout << "[Copying s2 into s1]" << endl;
  s1 = s2;
  cout << "[Popping all of s2]" << endl;
  while (!s2.isEmpty()){
	s2.pop(num);
	cout << "Popped " << num << " from s2" << endl;
  }
  cout << "[Popping all of s1]" << endl;
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
  cout << "[Adding 5 items to queue....]" << endl;
  for (int i = 3; i < 8; i++){
	if (!q1.enqueue(i))
	  cout << "Could not add to q1" << endl;
	else
	  cout << "Added " << i << " to q1" << endl;
  }

  // copy constructor
  cout << "[Copying of q1 into q2(using copy constructor)]" << endl;
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
  cout << "[Copying q2 into q3 (using assignment operator)]" << endl;
  q3 = q2;
  cout << "[now removing all values from q2]" << endl;
  while (!q2.isEmpty()){
	if (!q2.dequeue(num))
	  cout << "could not dequeue from q2" << endl;
	else
	  cout << "Removed " << num << " from q2" << endl;
  }

  cout << "[now removing all values from q3]" << endl;
  while (!q3.isEmpty()){
	if (!q3.dequeue(num))
	  cout << "could not dequeue from q3" << endl;
	else
	  cout << "removed " << num << " from q3" << endl;
  }
}
