#include<iostream>
#include<stdlib.h>
#include<unistd.h>
#include"7HRL.h"

using namespace std;

int main(){
    
    Dungeon d;
    system("clear");

    cout << "You must have a toilet plated with 7 gold layers to beat Melania Trump\nBuy more monsters to earn money faster!\n";

    while(d.toiletLevel() < 7){
        string input;
        d.printScreen();
        getline(cin, input);
        if (!d.parse(input)){
            system("clear");
        } 

        d.turn();
        
    }
    d.act1();
    cout << "Gold toilets are going out of fashion.\nMelania moves on to diamond encrusted toilets.\n\n\n\n";

    while (!d.isDone()){
        string input;
        d.printScreen();
        getline(cin, input);
        if (!d.parse(input)){
            system("clear");
        } 

        d.turn();


    }
    cout<<"Congrats!!!! You Did It!!! You have an even more fashionable toilet than Melania Trump!\n";

    return 0;
}