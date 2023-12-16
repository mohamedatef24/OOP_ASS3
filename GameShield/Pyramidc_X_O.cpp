#include"../include/BoardGame_Classes.hpp"
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
using namespace std;

// Set the board
Pyramidc_X_O::Pyramidc_X_O (){
   n_rows =  3,n_cols=5;
   board = new char*[n_rows];
   for (int i = 0; i < n_rows; i++) {
      board [i] = new char[n_cols];
      for (int j = 0; j < n_cols; j++){
         board[i][j] = 0;
         possible[i][j]=1;
   }}
    possible[0][0]=possible[0][1]=possible[0][3]=possible[0][4]=possible[1][0]=possible[1][4]=0;
}

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool Pyramidc_X_O::update_board (int x, int y, char mark){
   // Only update if move is valid
   if (!(x < 0 || x > 2 || y < 0 || y > 4) && (board[x][y] == 0)&&(possible[x][y])) {
      board[x][y] = toupper(mark);
      n_moves++;
      return true;
   }
   else{

        return false;}
}

// Display the board and the pieces on it
void Pyramidc_X_O::display_board() {
   for (int i: {0,1,2}) {
      cout << "\n ";
      for (int j: {0,1,2,3,4}) {
            if(possible[i][j]){
                cout << "|  (" << i << "," << j << ")";
                cout << setw(2) << board [i][j] << " |";
            }else {
                cout<<"         ";
            }
      }
      cout << "\n-------------------------------------------------------";
   }
   cout << endl;
}

// Returns true if there is any winner
// either X or O
bool Pyramidc_X_O::is_winner() {
    if(board[0][2]==board[1][2]&&board[0][2]==board[2][2]&&(board[0][2]=='X'||board[0][2]=='O')) return true;
    if(board[1][1]==board[1][2]&&board[1][1]==board[1][3]&&(board[1][1]=='X'||board[1][1]=='O')) return true;
    if(board[1][1]==board[0][2]&&board[1][1]==board[2][0]&&(board[0][2]=='X'||board[0][2]=='O')) return true;
    if(board[1][3]==board[0][2]&&board[1][3]==board[2][4]&&(board[0][2]=='X'||board[0][2]=='O')) return true;
    for(int i=2,j=0;j<3;j++)
    {
        if(board[i][j]==board[i][j+1]&&board[i][j]==board[i][j+2]&&(board[i][j]=='X'||board[i][j]=='O')) return true;
    }

    return false;
}

// Return true if 9 moves are done and no winner
bool Pyramidc_X_O::is_draw() {
    return (n_moves == 9 && !is_winner());
}

bool Pyramidc_X_O::game_is_over () {
    return n_moves >= 9;
}
