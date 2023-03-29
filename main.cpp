#include <iostream>
#include <random>
#include <ctime>
#include <string>
#include "wrestler.h"
#include "team.h"
#include "match.h"

using namespace std;

int main()
{
    //Random Generator Pointer to Use in All Functions:
    default_random_engine * gptr;
    gptr = new default_random_engine(time(NULL));



    //Execute a Match:
    //  2 Teams
    //  Output First: Each Team's Weight Classes Are Displayed & All Wrestler's Data Within Each Weight Class Are Displayed
    //  Then: Team Final Score's Are Displayed & Winner Is Declared

    team * team1;
    team * team2;
    team1 = new team(gptr, 100);
    team2 = new team(gptr, 200);
    Match(team1, team2, gptr);

    cout<<"TEAMS DATA: "<<endl<<endl;
    team1->Display();
    cout<<endl<<endl;
    team2->Display();
    cout<<endl<<"| Individual Team Wrestler Data Above | Match Results Below |"<<endl<<endl<<endl;


    cout<<"MATCH RESULTS: "<<endl<<endl;
    cout<<"Team: "<<team1->GetID()<<"  Score: "<<team1->GetScore()<<endl;
    cout<<"Team: "<<team2->GetID()<<"  Score: "<<team2->GetScore()<<endl<<endl;

    int score1 = team1->GetScore();
    int score2 = team2->GetScore();
    int diff = score1 - score2;

    if (diff==0){cout<<"Tie!"<<endl;}
    else if (diff>0){cout<<"Team 100 Wins!";}
    else {cout<<"Team 200 Wins!";}
    cout<<endl<<endl;


    return 0;
}
