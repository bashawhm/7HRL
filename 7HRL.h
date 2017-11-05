#ifndef _7HRL_H_
#define _7HRL_H_

#include<stdlib.h>
#include<time.h>
#include<iostream>
using namespace std;

// class Actor{
// public:
//     Actor () : alive(true) {}
//     bool isAlive(){
//         return alive;
//     }

// private:
//     bool alive;
// };

// class Dungeon{
// public:
//     Dungeon(){
//         srand(time(NULL));
       
//         generateFloor();
//     }
//     void generateFloor(){
//         sizeX = 5 + rand() % 20;
//         sizeY = 5 + rand() % 10;
//         map = (char **)malloc(sizeX * sizeof(char *));
//         for (int i = 0; i < sizeX; ++i){
//             map[i] = (char *)malloc(sizeY * sizeof(char));
//         }
//         for (int i = 0;i<sizeY;i++){
// 			for(int j = 0;j<sizeX;j++){
// 				map[i][j] = '.';
// 			}
// 			for(int j = 0;j<sizeX;j++){
// 				map[i][0] = '#';
			
// 				if (i == 0){
// 					  map[i][j] = '#';
			  
// 				}
// 				if (i == sizeX-1){
// 					map[i][j] = '#';
//                 }
                
//                 map[i][sizeX-1] = '#';
//                 map[sizeY-1][j] = '#';
                
//             }
            
//         }
//     }
        

    
//     void print(){
//         for(int i = 0;i<sizeY;i++){
// 			for(int j = 0;j<sizeX;j++){
// 				cout<<map[i][j];
// 			}
// 			cout<<"\n";
// 		}
//     }



// private:
//     unsigned int sizeX;
//     unsigned int sizeY;
//     char ** map;

// };



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
    bool withdraw(unsigned int price){
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
            phone();
        }
    }

    void phone(){
        cout<<"  ___ \n /   | \n |--- \n | \n |___ \n \\   | \n  --- \n ";
        cout<<"\nAnswer the phone?[y/n]";
        string tmp;
        getline(cin, tmp);
        if (tmp == "n"){
            return;
        } 
        int dis = rand() % 20;
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
        } else {
            cout<< "They hung up\n";
        }
        cout <<"\n";
    }


private:
    unsigned int monsters;
    int money;
    unsigned int humansKilled;
    unsigned int toiletGold;

};


#endif