#include<iostream>
#include<stdlib.h>
#include<unistd.h>
#include"7HRL.h"

using namespace std;

int main(){
    
    Dungeon d;
    system("clear");

    while(d.toiletLevel() < 7){
        string input;
        d.printScreen();
        getline(cin, input);
        if (!d.parse(input)){
            system("clear");
        } 
        
        d.turn();
        
    }
    cout<<"Congrats!!!! You Did It!!! You have an even golder toilet than Melania Trump!\n";

    return 0;
}