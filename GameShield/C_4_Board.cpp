#include"../include/BoardGame_Classes.hpp"
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
using namespace std;

// Set the board

C_4_Board::C_4_Board (){
   n_rows =  6,n_cols=7;
   board = new char*[n_rows];
   for (int i = 0; i < n_rows; i++) {
      board [i] = new char[n_cols];
      for (int j = 0; j < n_cols; j++){
         board[i][j] = 0;
         possible[i][j]=0;
   }}
    for(int i=0;i<n_cols;i++) possible[6][i]=1;
}

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool C_4_Board::update_board (int x, int y, char mark){
   // Only update if move is valid
   if (!(x < 0 || x > 5 || y < 0 || y > 6) && (board[x][y] == 0)&&(possible[x+1][y])) {
      board[x][y] = toupper(mark);
      possible[x][y]=1;
      n_moves++;
      return true;
   }
   else{

        return false;}
}

// Display the board and the pieces on it
void C_4_Board::display_board() {
   for (int i: {0,1,2,3,4,5}) {
      cout << "\n ";
      for (int j: {0,1,2,3,4,5,6}) {
            if(true){
                cout << "|  (" << i << "," << j << ")";
                cout << setw(2) << board [i][j] << " |";
            }
      }
      cout << "\n------------------------------------------------------------------------------";
   }
   cout << endl;
}

// Returns true if there is any winner
// either X or O
// Written in a complex way. DO NOT DO LIKE THIS.
bool C_4_Board::is_winner() {
    for(int i=n_rows-1;i>=0;i--) ///horizontally
    {
        for(int j=0;j<n_cols-3;j++)
        {
            if(board[i][j]==board[i][j+1]&&board[i][j]==board[i][j+2]&&board[i][j]==board[i][j+3]&&(board[i][j]=='X'||board[i][j]=='O')) return true;
        }
    }for(int i=0;i<n_cols;i++) ///vertically
    {
        for(int j=n_rows-1;j>=n_rows-3;j--)
        {
            if(board[j][i]==board[j-1][i]&&board[j][i]==board[j-2][i]&&board[j][i]==board[j-3][i]&&(board[j][i]=='X'||board[j][i]=='O')) return true;
        }
    }
    for(int i=0,y=5;i<3;i++)
    {
        for(int j=0;j<=y-2;j++)
        {
            if(board[i][j]==board[i+1][j+1]&&board[i][j]==board[i+2][j+2]&&board[i][j]==board[i+3][j+3]&&(board[i][j]=='X'||board[i][j]=='O')) return true;
        }
    }
    for(int i=0,y=5;i<3;i++)
    {
        for(int j=6;j>=y-2;j--)
        {
            if(board[i][j]==board[i+1][j-1]&&board[i][j]==board[i+2][j-2]&&board[i][j]==board[i+3][j-3]&&(board[i][j]=='X'||board[i][j]=='O')) return true;
        }
    }
    return false;
}

// Return true if 9 moves are done and no winner
bool C_4_Board::is_draw() {
    return (n_moves == 42 && !is_winner());
}

bool C_4_Board::game_is_over () {
    return n_moves >= 42;
}
