#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <cstdlib>
using namespace std;

void monsterRoom(string, int&, int&);

void genieRoom(int&, int&);

void pictureRoom();

void drawPicture();

int main()
{
    srand(500);

    string player, monster;
    char door;

    int bananas = 5, oranges = 3;
    
    cout << "Please enter your name: ";
    cin >> player;
    cout << "Name your scariest monster: ";
    cin >> monster;

    bool cont = true;
    do
    {
        int alignment = rand() % 2;

        cout << player << ", you are in a room with 4 doors.\n" << endl;
        cout << "You are carrying " << bananas;
        cout << " bananas and " << oranges << " oranges.\n";

        do
        {
            cout << "Pick a door to enter by typing the direction it is in (N/E/S/W): ";
            cin >> door;
        }
        while(door != 'N' && door != 'E' && door != 'S' && door != 'W');
        cout << endl;

        if(alignment == 0)
        {
            if(door == 'N')
            {
                monsterRoom(monster, bananas, oranges);
            }
            else if(door == 'S')
            {
                genieRoom(bananas, oranges);
            }
            else if(door == 'E')
            {
                pictureRoom();
            }
            else if(door == 'W')
            {
                cont = false;
            }
        }
        else if(alignment == 1)
        {
            if(door == 'N')
              {
                  cont = false;
              }
              else if(door == 'S')
              {
                  monsterRoom(monster, bananas, oranges);
              }
              else if(door == 'E')
              {
                  genieRoom(bananas, oranges);
              }
              else if(door == 'W')
              {
                  pictureRoom();
              }
        }
    }
    while(cont);
    cout << "You found the exit!\n";
    cout << "Your score is " << bananas + oranges;
    cout << "(" << bananas << " bananas and ";
    cout << oranges << " oranges).\n";
    cout << "Bye bye!!!\n";
  
    return 0;
}

void monsterRoom(string monster, int& bananas, int& oranges)
{
    cout << "WATCH OUT!!!\n";
    cout << monster << " attacks you and ";
    cout << "steals all of your bananas and oranges.\n";
    bananas = 0;
    oranges = 0;
}

void genieRoom(int& bananas, int& oranges)
{
    cout << "A genie pops out and grants you 2 bananas and 1 orange.\n";
    bananas += 2;
    oranges++;
}

void pictureRoom()
{
    cout << "You found a picture!\n";
    drawPicture();
}

void drawPicture()
{
    cout << "        _--~~--_" << endl;
    cout << "      /~/_|  |_\\~\\" << endl;
    cout << "     |____________|" << endl;
    cout << "     |[][][][][][]|" << endl;
    cout << "   __| __         |__" << endl;
    cout << "  |  ||. |   ==   |  |" << endl;
    cout << " (|  ||__|   ==   |  |)" << endl;
    cout << "  |  |[] []  ==   |  |" << endl;
    cout << "  |  |____________|  |" << endl;
    cout << "  /__\\            /__\\" << endl;
    cout << "   ~~              ~~ " << endl;
    cout << endl;
}