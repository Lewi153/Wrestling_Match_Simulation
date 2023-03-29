#include <iostream>
#include <random>
#include <ctime>
#include <string>
#include "wrestler.h"

using namespace std;

wrestler::wrestler(default_random_engine * ptr)
{
//////////////////Initialize a Wrestler//////////////

    normal_distribution <double> AbilityDist(100,15);       //Ability generator
    uniform_int_distribution<int> AgeDist(13, 17);          //Age generator

    normal_distribution<double> Wt13(100, 25);              //Weight generator @ Age=13    Min/Max = 96 / 285
    normal_distribution<double> Wt14(114, 25);              //Weight generator @ Age=14    Min/Max = 96 / 285
    normal_distribution<double> Wt15(123, 25);              //Weight generator @ Age=15    Min/Max = 96 / 285
    normal_distribution<double> Wt16(135, 25);              //Weight generator @ Age=16    Min/Max = 96 / 285
    normal_distribution<double> Wt17(148, 25);              //Weight generator @ Age=17    Min/Max = 96 / 285

    Ability = (int)AbilityDist(*ptr);                       //Generate New Wrestler's Ability
    Age = AgeDist(*ptr);                                    //Generate New Wrestler's Age



/////////////Wrestler Wt Assignment////////////

    int w;
    int wx;
    switch(Age){                       //Generate a Weight based on Age
    case 13:{
        do{w = (int)Wt13(*ptr);
        } while( w<96 || w>285 );      //No Weight can be less than 96 or exceed 285, for each age
        Wt = w;
       }break;

    case 14:{
        do{w = (int)Wt14(*ptr);
        } while( w<96 || w>285 );
        Wt = w;
       }break;

    case 15:{
        do{w = (int)Wt15(*ptr);
        } while( w<96 || w>285 );
        Wt = w;
       }break;

    case 16:{
          do{w = (int)Wt16(*ptr);
        } while( w<96 || w>285 );
        Wt = w;
       }break;

    case 17:{
        do{w = (int)Wt17(*ptr);
        } while( w<96 || w>285 );
        Wt = w;
       }break;

     default:{cout<<"*Wt Assignment* issue within wrestler construct, Wt(w): " << w << endl;}

    }//End Switch



/////////////// WtClass # Assignment /////////

    if (95<w && w<107){WtClass=1;}
    else if (106<w && w<114){WtClass=2;}
    else if (113<w && w<121){WtClass=3;}
    else if (120<w && w<127){WtClass=4;}
    else if (126<w && w<133){WtClass=5;}
    else if (132<w && w<139){WtClass=6;}
    else if (138<w && w<146){WtClass=7;}
    else if (145<w && w<153){WtClass=8;}
    else if (152<w && w<161){WtClass=9;}
    else if (160<w && w<171){WtClass=10;}
    else if (170<w && w<183){WtClass=11;}
    else if (182<w && w<196){WtClass=12;}
    else if (195<w && w<221){WtClass=13;}
    else if (220<w && w<286){WtClass=14;}
    else {cout<<"*WtClass Assignment* issue within wrestler construct, Wt(w):" << w << endl;}



///////////Initialize Rest of Wrestler Data////////

    ID=0;
    Wins=0;
    Losses=0;
    defeated="None";
    next = NULL;

}//End Constructor


wrestler::~wrestler()
{cout << "Wrestler " << ID << " Removed" << endl;}

//////////Display Wrestler Data//////

void wrestler::Display(){
    cout<<"ID: "<<ID<<endl;
    cout<<"Age: "<<Age<<endl;
    cout<<"Weight: "<<Wt<<endl;
    cout<<"WtClass: "<<WtClass<<endl;
    cout<<"Ability: "<<Ability<<endl;
    cout<<"Wins: "<<Wins<<endl;
    cout<<"Losses: "<<Losses<<endl;
    cout<<"Defeated: "<<defeated<<endl;
}
