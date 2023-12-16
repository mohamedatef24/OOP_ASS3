#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
#include"../include/BoardGame_Classes.hpp"
using namespace std;

// Set player symbol and name as Random Computer Player
RandomPlayer_C_4::RandomPlayer_C_4 (char symbol, int dimension):Player(symbol)
{
    this->dimension = dimension;
    this->name = "Random C_4 Player";
    cout << "My name is " << name << endl;
}

// Generate a random move
void RandomPlayer_C_4::get_move (int& x, int& y) {
    x = (int) (rand()/(RAND_MAX + 1.0) * dimension);
    y = (int) (rand()/(RAND_MAX + 1.0) * (dimension+1));
}
