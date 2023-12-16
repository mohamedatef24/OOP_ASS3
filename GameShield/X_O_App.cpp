#include <iostream>
#include"../include/BoardGame_Classes.hpp"
using namespace std;

int main() {
    int in;cout<<"Enter Your Choice :\n     1- 3x3 X_O\n     2- C_4 X_O\n     3- 5x5 X_O\n     4- Pyramid_X_O\n     Enter Your Choice: ";
    cin>>in;
    if(in==1)
    {
        int choice;
        Player* players[2];
        players[0] = new Player (1, 'x');

        cout << "Welcome to FCAI X-O Game. :)\n";
        cout << "Press 1 if you want to play with computer: ";
        cin >> choice;
        if (choice != 1)
            players[1] = new Player (2, 'o');
        else
            //Player pointer points to child
            players[1] = new RandomPlayer ('o', 3);

        GameManager x_o_game (new X_O_Board(), players);
        x_o_game.run();
        system ("pause");
    }
    else if(in==2)
    {
        int choice;
        Player* players[2];
        players[0] = new Player (1, 'x');

        cout << "Welcome to FCAI C_4 X-O Game. :)\n";
        cout << "Press 1 if you want to play with computer: ";
        cin >> choice;
        if (choice != 1)
            players[1] = new Player (2, 'o');
        else
            //Player pointer points to child
            players[1] = new RandomPlayer_C_4 ('o', 6);

        GameManager x_o_game (new C_4_Board(), players);
        x_o_game.run();
        system ("pause");
    }else if(in==4)
    {
        int choice;
        Player* players[2];
        players[0] = new Player (1, 'x');

        cout << "Welcome to FCAI Pyramid X-O Game. :)\n";
        cout << "Press 1 if you want to play with computer: ";
        cin >> choice;
        if (choice != 1)
            players[1] = new Player (2, 'o');
        else
            //Player pointer points to child
            players[1] = new RandomPlayer_Pyramid ('o', 3);

        GameManager x_o_game (new Pyramidc_X_O(), players);
        x_o_game.run();
        system ("pause");
    }
    else if(in==3)
    {
        int choice;
        Player* players[2];
        players[0] = new Player (1, 'x');

        cout << "Welcome to FCAI 5x5 X-O Game. :)\n";
        cout << "Press 1 if you want to play with computer: ";
        cin >> choice;
        if (choice != 1)
            players[1] = new Player (2, 'o');
        else
            //Player pointer points to child
            players[1] = new RandomPlayer_5x5 ('o', 5);

        GameManager_5 x_o_game (new X_O5_Board(), players);
        x_o_game.run();
        system ("pause");
    }

}
