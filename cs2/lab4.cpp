// Ben Smith 
// lab4.cpp
// 4/19/2017

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

void setBoardContents(int** board, int row, int col);
void displayBoard(int** board, int row, int col);

int main()
{
  int row = 0;
  int col = 0;
  bool done = false;
  char runProgram;
  int** board;
  
  srand(time(0));
  
  cout << "Would you like to run the program(y/n)?";
  cin >> runProgram;
  
  while(!done){		
    if(runProgram == 'n'){
      done = true;
    }
    else{
      cout << "Enter size of number grid (1-5): ";
      cin >> row;
      while(row > 5||row <= 0){
        cout << "Number is out of bounds"<<endl;
        cout << "Enter size of number grid (1-5): ";
        cin >> row;
      }
      col = row;
      // Creates a new 2d array with the users input
      board = new int*[row];
      assert(board != nullptr);
      for(int i = 0; i < row; i++){
        board[i] = new int[col];
        assert(board[i] != nullptr);
      }
      
      setBoardContents(board,row,col);
      displayBoard(board,row,col);
      
      for(int j = 0; j < row; j++){
        delete [] board[j];
      }
      delete [] board;
      cout << endl;
      cout << "Would you like to run the program again(y/n)?";
      cin >> runProgram;
    }			
  }
  return 0;
}
void setBoardContents(int** board, int row, int col)
{
  // Fills the number grid with random numbers
  for(int numRow = 0; numRow < row; numRow++){
    for(int numCol = 0; numCol < col; numCol++){
      board[numRow][numCol] = rand() % 80 + 1;
    }
  }
}
void displayBoard(int** board, int row, int col)
{
  int counter = row-1;
  int sum1 = 0;
  int sum2 = 0;
  const string SPACE = "  ";
  const string SPACE2 ="   ";
  const string END1 = "  |";
  const string END2 = " |";
  
  cout << endl;
  for(int i = 0; i < (row*2); i ++){
  	cout << SPACE2;
  }
  cout << "TOTAL" << endl;
  // Calculates totals for each ROW
  for(int numRow = 0; numRow < row; numRow++){
  	cout << SPACE << SPACE;
    int rowSum = 0;
    for(int numCol = 0; numCol < col; numCol++){
      if(board[numRow][numCol] < 10){
        rowSum += board[numRow][numCol];
        cout << SPACE <<board[numRow][numCol] << END1;
      }
      else{
        rowSum += board[numRow][numCol];
        cout << SPACE <<board[numRow][numCol] << END2;
      }
    }
    cout << rowSum;	
    cout << endl;
  }
  cout << "TOTAL ";
  // Calculates totals for each COLUMN 
  for(int numCol = 0; numCol < col; numCol++){
    int colSum = 0;
    for(int numRow = 0; numRow < row; numRow++){
      colSum += board[numRow][numCol];
    }
    cout << colSum << SPACE;
  }
  cout << endl << endl;
  // Calculates diagonal 1 
  for(int i = 0; i < row; i++){
    sum1 += board[i][i];		
  }
  cout << "Diagonal sum 1: " << sum1 << endl;
  // Calculates disgonal 2
  for(int r = 0; r < row; r++){
    sum2 += board[r][counter];
    counter--;
  }	
  cout << "Diagonal sum 2: " << sum2 << endl;
}
