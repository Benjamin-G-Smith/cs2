// Ben Smith
// 10/25/2017
// version 1.0

#include "primeDubBST.h"

primeDubBST::primeDubBST()
{
  root = nullptr;
  size = 800;
  numberOfPrimes = new int[size];
}
primeDubBST::primeDubBST(const primeDubBST& rhs)
{
  // calls some post order thing
}
void primeDubBST::operator=(const primeDubBST &rhs)
{
//  TNode Tnode = new TNode();
//  return Tnode;
/*  if(this != &rhs){
    return rhs;
    // delete the old data
      // calls the copy constructor
  }*/
}
primeDubBST::~primeDubBST()
{
  deleteTree(root);
  delete [] numberOfPrimes;
  // Delets the binary search tree
  // deallocates the counter array
  // deletes any other nodes
}
void primeDubBST::deleteTree(TNode*& root)
{
  if(root){
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
  }
}
bool primeDubBST::search(int data)
{
  return search(root, data);
  //privateSearch(data);
  // return true or false based on the result
}
bool primeDubBST::search(TNode*& root, int data)
{
  TNode* current = root;
  stack<TNode*> s;
  bool done = false;
    while(!done){
      if(current){
        s.push(current);
        if(current->data == data){
          return true;
        }
        current = current->left;
      }
      else{
        if(!s.empty()){
          current = s.top();
          s.pop();
          if(current->data == data){
            return true;
          }
          current = current->right;
        }
        else{
          done = true;
        }
      }
    }
    return false;
}
primeDubBST::TNode* primeDubBST::privateDeleteSearch(int data)
{
  TNode* current = root;
  stack<TNode*> s;
  bool done = false;
    while(!done){
      if(current){
        s.push(current);
        if(current->data == data){
          return current;
        }
        current = current->left;
      }
      else{
        if(!s.empty()){
          current = s.top();
          s.pop();
          if(current->data == data){
            return current;
          }
          current = current->right;
        }
        else{
          done = true;
        }
      }
    }
    return nullptr;
  // root
    // calls the search
    // Checks to see if the element data is zero in the count array
    // removes the node if the count in the array for that prime is zero
}

void primeDubBST::printToFile(string file)
{
  //fstream file;
  /*for(int i = 0; i < 541; i++){
      cout << i << " [" << numberOfPrimes[i] << " ]"<< endl;
  }*/
  ofstream outPutFile;
  outPutFile.open(file);
  printToFile(root, outPutFile);
  outPutFile.close();
}
void primeDubBST::printToFile(TNode* root, ofstream& outPutFile)
{
  if(root){
    printToFile(root->left,outPutFile);
    outPutFile << root->data << endl;
    printToFile(root->right, outPutFile);
  }
  //outPutFile.close();
}
bool primeDubBST::insert(int data)
{
  return insert(root,data);
}
bool primeDubBST::insert(TNode*& root, int data)
{
  if(filterNumber(data)){
      TNode* current = nullptr;
      TNode* parent = nullptr;
      if(root == nullptr){
        TNode* newNode = new TNode(data);
        root = newNode;
        current = root;
      }
      else{
        current = root;
        while(current != nullptr){
          if(data < current->data){
            parent = current;
            current = current->left;
          }
          else{
            parent = current;
            current = current->right;
          }
        }
        TNode* newNode = new TNode(data);
        if(data < parent->data){
          parent->left = newNode;
        }
        else{
          parent->right = newNode;
        }
      }
      return true;
  }
  else
  return false;

    /*if(parent->data > data && parent->left == nullptr){
      insertNode = new TNode(data);
      parent->left = insertNode;
      return true;
    }
    else if(parent->data < data && parent->right == nullptr){
      insertNode = new TNode(data);
      parent->right =  insertNode;
      return true;
    }*/
    //return false;
  /*TNode* current = root;
  if(filterNumber(data)){
    if(current == nullptr){
      // create node, put in data
      current = new TNode(data);
      //root->data = data;
      //root->data = data;
      return true;
    }
    else if(current->data > data){
      return insert(current->left, data);
    }
    else if(current->data < data){
      return insert(current->right, data);
    }
  }
  return false;*/
  // Call the filter
  // only adds if filter returns true
  // add to the BST
}
bool primeDubBST::removeElement()
{
  int count = 20;
  while(count){
    int randNumber = rand() % 800 + 1;
    if(checkPrime(randNumber)){
      if(checkCountDelete(numberOfPrimes,randNumber)){
        count--;
        privateRemoveElement(randNumber);
        cout<<count<< " deleted a node" << endl;
      }
    }
  }
  return true;
}
void primeDubBST::privateRemoveElement(int data)
{
  TNode* delPtr = root;
  TNode* parent = nullptr;

  while(delPtr && delPtr->data != data){
    parent = delPtr;
    if(data < delPtr->data){
      delPtr = delPtr->left;
    }
    else{
      delPtr = delPtr->right;
    }
  }
  bool left = (delPtr == parent->left);
  if(!delPtr->left && !delPtr->right){
    cin.get();
    cout << "no children" << endl;
    if(delPtr == root){
      root = nullptr;
    }
    else if(left){
      parent->left = nullptr;
    }
    else{
      parent->right = nullptr;
    }
  }
  else if(!delPtr->left || !delPtr->right){
    cin.get();
    cout << "one child" << endl;
    TNode* child = (delPtr->left)?delPtr->left:delPtr->right;
    if(delPtr == root){
      root = child;
    }
    else if(left){
      parent->left = child;
    }
    else{
      parent->right = child;
    }
  }
  else{
    cin.get();
    cout << "two children" << endl;
    TNode* swap = findMaxLeft(delPtr);
    delPtr->data = swap->data;
    if(swap != delPtr){
      swap->left = nullptr;
    }
    else{
      swap->right = nullptr;
    }
    delete delPtr;
  }

  //root

    // calls the search
    // Checks to see if the element data is zero in the count array
    // removes the node if the count in the array for that prime is zero

}
primeDubBST::TNode* primeDubBST::findMaxLeft(TNode* delPtr)
{
  TNode* min = delPtr->right;

  while(min->left != nullptr){
    min = min->left;
  }
  return min;
}
bool primeDubBST::checkPrime(int data)
{
  if(data > 3 && data % 2 != 0){
    for(int i = 3; i < data; i++){
        if(data % i == 0){
            return false;
        }
      }
      return true;
  }
  return false;
}
bool primeDubBST::checkCount(int numberOfPrimes[], int prime)
{
  int value = prime;
  if(numberOfPrimes[value] == 0){
    numberOfPrimes[value]++;
    return true;
  }
  else{
    numberOfPrimes[value]++;
    return false;
  }
}
bool primeDubBST::checkCountDelete(int numberOfPrimes[], int prime)
{
  int value = prime;
  if(numberOfPrimes[value] >= 1){
    numberOfPrimes[value]--;
    return true;
  }
  else{
    return false;
  }
}
bool primeDubBST::filterNumber(int data)
{
   if(checkPrime(data)){
     if(numberOfPrimes[data] == 0){
       numberOfPrimes[data] += 1;
       return true;
     }
       numberOfPrimes[data] += 1;
       return false;
   }
   return false;
  /*if(checkPrime(data)){
    if(checkCount(numberOfPrimes,data)){
      return true;
    }
    // only returns true if the number is prime and not a dupe
    // check against the numberOfPrimes array
    // if the numberOfPrimes is not zero for that prime, iterate the count at that prime
    // return false
    // return true if it is prime and the numberOfPrimes for that prime is zero
  }
  return false;*/
}
