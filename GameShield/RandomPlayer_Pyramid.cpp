#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
#include"../include/BoardGame_Classes.hpp"
using namespace std;

// Set player symbol and name as Random Computer Player
RandomPlayer_Pyramid::RandomPlayer_Pyramid (char symbol, int dimension):Player(symbol)
{
    this->dimension = dimension;
    this->name = "Random Pyramid_X_O Player";
    cout << "My name is " << name << endl;
}

// Generate a random move
void RandomPlayer_Pyramid::get_move (int& x, int& y) {
    x = (int) (rand()/(RAND_MAX + 1.0) * dimension);
    y = (int) (rand()/(RAND_MAX + 1.0) * (dimension+2));
}
