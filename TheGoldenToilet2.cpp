#include<iostream>
#include<stdlib.h>
#include<unistd.h>
#include"7HRL.h"

using namespace std;

int main(){
    string melania[5];
    melania[0] = "Look at your shitty dungeon!\n";
    melania[1] = "I'm so great.\nHahahahahaha\n";
    melania[2] = "I didn't get to this country in the wheel well of a cargo jet for this!\n";
    melania[3] = "These monsters breed like imagrants.\n";
    melania[4] = "Where's my pool boy!\n";

    int i = 0;

    Dungeon d;
    system("clear");

    cout << "Welcome to The Golden Toilet 2: The Quest for the Goldest Toilet!\n\n";

    cout << "You must have a toilet plated with 7 gold layers to beat Melania Trump\nBuy more monsters to earn money faster!\n\n";

    while(d.toiletLevel() < 7){
        int mel = rand() % 20;
        if (mel == 5){
            cout << "<Melania> " << melania[i] << "\n";
            if (i < 4){
                ++i;
            } else {
                i = 0;
            }
        }
        string input;
        d.printScreen();
        getline(cin, input);
        if (!d.parse(input)){
            system("clear");
        } 

        d.turn();
        
    }
    d.act1();
    cout << "<Melania> Gold toilets are going out of fashion.\nMelania moves on to diamond encrusted toilets.\n\n\n\n";
    cout << "Melania laughs at your puny toilet.\n\n";

    while (!d.isDone()){
        string input;
        d.printScreen();
        getline(cin, input);
        if (!d.parse(input)){
            // system("clear");
        } 

        d.turn();


    }
    cout<<"Congrats!!!! You Did It!!! You have an even more fashionable toilet than Melania Trump!\n";

    return 0;
}