#include <iostream>
#include <string>
#include <fstream>
using namespace std;
//Global Variables
const int ROWS = 12;
const int COLS = 30; 
const char LIVE = 'x'; //life cells
const char DEAD = '.'; //dead cells
//functions
void MakeArray(string filename, char board[][COLS]);
void GameBoard(char board[][COLS]);
 
int main()
{
 char board [ROWS][COLS];
 string filename; //Name of the file
 cout<<"Enter the filename: \n";
 cin>>filename;
 MakeArray(filename, board);
 GameBoard(board);
 //stop terminal window from quitting after programs ends
 char q;
 cin >> q; 
 return 0;
}
void MakeArray(string filename, char board[][COLS])
{
 ifstream myfile; 
 myfile.open (filename.c_str());
 for (int r=0; r<ROWS; r++)
 {
  for (int c=0; c<COLS; c++)
  {
   myfile>>board[r][c];
  }
 }
 myfile.close();
}
void GameBoard (char board[][COLS])
{
 for (int r=0; r<ROWS; r++)
 {
  for (int c=0; c<COLS; c++)
  {
   cout<<board[r][c];
  }
  cout<<endl; 
 }
}
