// Ben Smith
// stack.cpp
// 5/16/2017

//Purpose: Implementation file of the stack.h

#include "stack.h"

// constructor
Stack::Stack(int s )
{
  if(s < 10){
    s = DEFAULT;
  }
  size = s;
  arr = new int[size];
  assert(arr != nullptr);
  top = 0;
}
// copy constructor
Stack::Stack(const Stack &rhs)
{
  arr = new int[rhs.size];
  for(int i = 0; i < rhs.size; i++){
    arr[i] = rhs.arr[i];
  }
  size = rhs.size;
  top = rhs.top;
}
// Overloaded assignment operator
Stack& Stack::operator=(const Stack &rhs)
{
  if(this != &rhs){
    delete [] arr;
    arr = new int[rhs.size];
    assert(this->arr != nullptr);
    for(int i = 0; i < rhs.size; i++){
      arr[i] = rhs.arr[i];
    }
    size = rhs.size;
    top = rhs.top;
  }
  return *this;
}
bool Stack::resize()
{
  int tsize = static_cast<double>(size) * 1.5;
  int* tArr = new int[tsize];
  if(tArr == nullptr){
    return false;
  }
  for(int i = 0; i < top; i++){
    tArr[i] = arr[i];
  }
  delete [] arr;
  arr = tArr;
  size = tsize;
  return true;
}
const bool Stack::isEmpty()
{
  return top == 0;
}
const bool Stack::isFull()
{
  return top == size;
}
// push
bool Stack::push(int v)
{
  if(isFull()){
    bool okay = resize();
    if(!okay){
      return false;
    }
  }
  arr[top] = v;
  top++;
  return true;
}
// pop
bool Stack::pop(int& v)
{
  if(isEmpty()){
    return false;
  }
  top--;
  v = arr[top];
  return true;
}
Stack::~Stack()
{
  delete [] arr;
}
