#ifndef _7HRL_H_
#define _7HRL_H_

#include<stdlib.h>
#include<time.h>
#include<iostream>
using namespace std;


class Dungeon{
public:
    Dungeon(){
        srand(time(NULL));
        money = 50;
        humansKilled = 0;
        toiletGold = 0;
        monsters = 4;
    }
    void printScreen(){
        cout << "Money $ " << money << "    Puny Humans Killed " << humansKilled << "    Toilet Gold Level " << toiletGold << "    Monsters " << monsters << "\n";
        cout << "----------------------------------------------------------------------------\n";
        cout << "Take Turn[t]  |  Buy Even Golder Toilet ($40) [g]  |  Buy more monsters ($40) [m]  |  Quit[q]\n";

    }


    //false if failed, true if success
    bool withdraw(int price){
        if (money < price){
            return false;
        } else {
            money -= price;
            return true;
        }
    }

    bool parse(string input){
        if (input == "t"){
            return false;
        } else if (input == "g"){
            if (!withdraw(40)){
                system("clear");
                cout<< "Not enough money\n";
                return true;
            } else {
                toiletGold += 1;
            }

        } else if (input == "q"){
            exit(1);
        } else if (input == "m"){
            if (!withdraw(40)){
                system("clear");
                cout<<"Not Enough Money\n";
                return true;
            } else {
                monsters += 3;
            }
        } else {
            return false;
        }
    }

    unsigned int toiletLevel(){
        return toiletGold;
    }

    void turn(){
        humansKilled = rand() % monsters;
        money += humansKilled;
        unsigned int tmp = rand() % 3;
        if (tmp == 1){
            char tmpS = 7;
            cout << tmpS;
            usleep(200);
            if (phone()){
                paperwork();
            }
        }
    }

    void paperwork(){
        cout << " _______ \n \\_______\\ \n  \\_______\\ \n   \\_______\\ \n    \\_______\\ \n\n";
        int dis = rand() % 12;
        if (dis == 0){
            cout << "You get a paper cut and accidentally give half the monsteres the epock off.\n";
            monsters = monsters - (monsters / 2);
        } else if (dis == 1){
            cout << "Your siatica acts up.\n You buy a yoga ball.\n";
            money -= 5;
        } else if (dis == 2){
            cout << "Due to budget cuts you have to lay off a monster.\n";
            if (monsters > 0){
                monsters -= 1;
            }
        } else if (dis == 3){
            cout << "You look outside and Pan Pan is selling your car.\n";
            money -= 40;
            cout << "You buy a new one\n";
        } else if (dis == 4){
            cout << "You accidentally sent a 5 diamond chef to the board meeting.\n";
            if (monsters > 0){
                monsters -= 1;
            }
        } else if (dis == 5){
            cout << "You win a renewable energy grant.\n";
            money += 15;
        } else if (dis == 6){
            cout << "The pipes start leaking more than Google Chrome\n";
            money -= 25;
        } else if (dis == 7){
            cout << "You spare a humans life so they can work in your sweatshop making low quality, designer, knockoff wallets.\n";
            money += 2;
        } else if (dis == 8){
            cout << "You organize the garbage instead of doing paper work.\n";
        } else if (dis == 9){
            cout << "Payroll fucked up your cash.\n";
            money -= 10;
        } else {
            cout << "Boring paperwork as usual\n";
        }

    }

    bool phone(){
     
        cout<<"  ___ \n /   | \n |--- \n | \n |___ \n \\   | \n  --- \n ";
        cout<<"\nAnswer the phone?[y/n]";
        string tmp;
        getline(cin, tmp);
        if (tmp == "n"){
            return true;
        } 
        int dis = rand() % 22;
        if (dis == 3){
            money -= 20;
            cout<< "Cracked Cement! Looks like you have to repair the ceiling.\n";
        } else if (dis == 4){
            money -= 10;
            cout<< "Pipes Burst! All your antique bibles are ruined!!\n";
        } else if (dis == 5){
            money -= 50;
            cout<< "The monsters are loose! Pay a puny human to capture them.\n";
        } else if (dis == 6){
            cout<< "Do you canoe?";
        }  else if (dis == 7){
            money -= 5;
            cout << "You have been chosen. They will come soon.\n";
            cout << "Out of fear you board up the windows.\n";
        } else if (dis == 8){
            cout<< "The number 3 is very important to you now.\n";
        } else if (dis == 9){
            money -= 10;
            cout<< "Your phychic advisor suggests that you work on improving relationships with those closest to you because you'll need them the next lunar review.\n";
            cout << "You buy $10 worth of candy for you aunt.\n";
        } else if (dis == 10){
            cout<< "Your phychic advisor has had very strong vibrations coming from your house. You should stay away from any building activities during the next week.\n";
        } else if (dis == 11){            
            cout<< "Your phychic advisor suggests that you keep your secrets well this month. There may be untrustworthy indeviduals in your environs.\n";
        } else if (dis == 12){
            cout<< "The drop off has been made. You've been warned.\n";
        } else if (dis == 13){
            money -= 5;
            cout << "Your phychic advisor suggests that you plan your meetings very carefully this month because you may have some unexpected news.\n";
            cout <<"You spend $5 on confetti to chear yourself up.\n"; 
        } else if (dis == 14){
            cout<< "The number 6 will be very important for you in the next 24 hours.\n";
        } else if (dis == 15){
            cout<< "Wrong Number Sorry.\n";
        } else if (dis == 16){
            money -= 50;
            cout<< "The end is near. Make preparations.\n";
            cout <<"You spend $50 out of paranoia.\n";
        } else if (dis == 17){
            money -= 10;
            cout<< "The flashing light was just a test. You'll have plenty of warning next time.\n";
            cout << "You spent $10 on black curtains.\n";
        } else if (dis == 18){
            cout<< "Your phychic advisor's head just exploded. Be forwarned.\n";
        } else if (dis == 19){
            money -= 10;
            cout<< "They're coming soon. Maybe you should think twice about opening the door.\n";
            cout << "You spend $10 on titanium doors.\n";
        } else if (dis == 3){
            cout<< "Were fixing the phone line. Don't pick up next time it rings.\n";
        } else if (dis == 2){
            cout<< "The grease is in the spoon! I repeat, the grease is in the spoon!\n";
        } else if (dis == 20){
            cout << "You win A BRAND NEW CAR!\n";
            money += 20;
        } else {
            cout<< "They hung up\n";
        }
        cout <<"\n";
        return false;
    }


private:
    unsigned int monsters;
    int money;
    unsigned int humansKilled;
    unsigned int toiletGold;

};


#endif