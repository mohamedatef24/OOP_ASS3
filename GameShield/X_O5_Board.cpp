#include"../include/BoardGame_Classes.hpp"
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
using namespace std;


// Set the board
X_O5_Board::X_O5_Board () {
   n_rows =  5,n_cols=5,X_wins=0,O_wins=0;
   board = new char*[n_rows];
   for (int i = 0; i < n_rows; i++) {
      board [i] = new char[n_cols];
      for (int j = 0; j < n_cols; j++)
         board[i][j] = 0;
   }

}

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool X_O5_Board::update_board (int x, int y, char mark){
   // Only update if move is valid
   if (!(x < 0 || x > 4 || y < 0 || y > 4) && (board[x][y] == 0)) {
      board[x][y] = toupper(mark);
      n_moves++;
      return true;
   }
   else{

        return false;}
}

// Display the board and the pieces on it
void X_O5_Board::display_board() {
   for (int i: {0,1,2,3,4}) {
      cout << "\n ";
      for (int j: {0,1,2,3,4}) {
            if(true){
                cout << "|  (" << i << "," << j << ")";
                cout << setw(2) << board [i][j] << " |";
            }
      }
      cout << "\n--------------------------------------------------------";
   }
   cout << endl;
}

// Returns true if there is any winner
// either X or O
// Written in a complex way. DO NOT DO LIKE THIS.
bool X_O5_Board::is_winner() {
    if(n_moves==24)
    {
        for(int i=0;i<5;i++)// Horizontally
        {
            for(int j=0;j<3;j++)
            {
                if(board[i][j]==board[i][j+1]&&board[i][j]==board[i][j+2])
                {
                    if(board[i][j]=='X') ++X_wins;
                    else if(board[i][j]=='O') ++O_wins;
                }
            }
        }for(int i=0;i<5;i++)// vertically
        {
            for(int j=0;j<3;j++)
            {
                if(board[j][i]==board[j+1][i]&&board[j][i]==board[j+2][i])
                {
                    if(board[j][i]=='X') ++X_wins;
                    else if(board[j][i]=='O') ++O_wins;
                }
            }
        }for(int i=0;i<3;i++)// Ldiag
        {
            for(int j=0;j<3;j++)
            {
                if(board[i][j]==board[i+1][j+1]&&board[i][j]==board[i+2][j+2])
                {
                    if(board[i][j]=='X') ++X_wins;
                    else if(board[i][j]=='O') ++O_wins;
                }
            }
        }for(int i=0;i<3;i++)// Rdiag
        {
            for(int j=4;j>1;j--)
            {
                if(board[i][j]==board[i+1][j-1]&&board[i][j]==board[i+2][j-2])
                {
                    if(board[i][j]=='X') ++X_wins;
                    else if(board[i][j]=='O') ++O_wins;
                }
            }
        }
    }
    if(n_moves==24)
    {
        if(X_wins>O_wins){
            cout<<"Player X Wins!\n";
            return true;
        }
        else if(O_wins>X_wins){
            cout<<"Player O Wins!\n";
            return true;
        }
        else {
            cout<<"Draw!\n";
        }
    }
    return false;
}

// Return true if 9 moves are done and no winner
bool X_O5_Board::is_draw() {
    return false;
}

bool X_O5_Board::game_is_over () {
    return n_moves >= 24;
}
