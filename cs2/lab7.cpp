// Ben Smith
// 5/10/2017
// lab7.cpp

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void insertSort(string data[], int size);
void printList(string data[], int size);
void swap(string& a, string& b);

const int MAX_SIZE = 50;
const string DAT = "/home/fac/sreeder/class/cs1430/lab7.dat";

int main()
{
  ifstream inputFile;
  int count = 0;
  string data;
  string dataArray[MAX_SIZE] ={" "};

  inputFile.open(DAT);

  if(inputFile.fail()){
    cout << "Error opening file..."<<endl;
    return 0;
  }

  while(count < MAX_SIZE && inputFile >> data){
    dataArray[count] = data;
    count++;
  }

  cout << "Before sort " << endl;
  cout << endl;
  printList(dataArray,count);
  
  cout << endl << endl;

  cout << "Sorting file..."<<endl;
  cout << "After sort " << endl;
  cout << endl;
  insertSort(dataArray,count);
  printList(dataArray,count);

  cout << endl << endl;

  inputFile.close();
  return 0;
}
void insertSort(string data[], int size)
{
  int index;
  for(int i = 1; i < size; i++){
    index = i;
    while(index > 0 && data[index] < data[index-1]){
      swap(data[index],data[index-1]);
      index--;
    }
  }
}
void swap(string& a, string& b)
{
  string temp = a;
  a = b;
  b = temp;
}
void printList(string data[], int size)
{
  for(int i = 0; i < size; i++){
    cout << data[i] << endl;
  }
}

