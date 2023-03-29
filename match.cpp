#include <iostream>
#include <random>
#include <ctime>
#include <string>
#include "match.h"
#include "wrestler.h"
#include "team.h"

using namespace std;

int Bout(wrestler * wr1, wrestler * wr2, default_random_engine * ptr){


    //Get raw Ability score
    int ability1 = wr1->GetAbility();
    int ability2 = wr2->GetAbility();

    normal_distribution<double> abilityDist1(ability1, 15);
    normal_distribution<double> abilityDist2(ability2, 15);

    //Get random current Ability score based on raw
    int score1=(int)abilityDist1(*ptr);
    int score2=(int)abilityDist2(*ptr);

    //Add Win/Loss
    int w1, w2, l1, l2;
    w1=wr1->GetWins();
    l1=wr1->GetLosses();
    w2=wr2->GetWins();
    l2=wr2->GetLosses();

    if(score1>=score2){         //Wrestler 1 wins
        w1++;
        l2++;
        wr1->SetWins(w1);
        wr2->SetLosses(l2);
        int d = wr2->GetID();
        wr1->SetDefeated(to_string(d));}
    else{                       //Wrestler 2 wins
        w2++;
        l1++;
        wr2->SetWins(w2);
        wr1->SetLosses(l1);
        int d = wr1->GetID();
        wr2->SetDefeated(to_string(d));}
    return(score1-score2);      //Return difference: Positive OR 0 = Team 1 wins  /   Negative = Team 2 wins
};






void Match(team * t1, team * t2, default_random_engine * ptr){
    int diff;
    wrestler * curr1;
    wrestler * curr2;
    for(int i =0; i<14; i++){                           //Loop through all Wt Classes (14), Bout for each
        curr1 = t1->GetHead(i);
        curr2 = t2->GetHead(i);
        if (curr1==NULL && curr2==NULL){
            continue;}
        else if(curr1==NULL){                           //No Wrestler in Team 1 Wt Class - Team 2 Wins
            t2->AddScore(6);
            int w2=curr2->GetWins();
            w2++;
            curr2->SetWins(w2);
            curr2->SetDefeated("No-Contest Win");}
        else if(curr2==NULL){                           //No Wrestler in Team 2 Wt Class - Team 1 Wins
            t1->AddScore(6);
            int w1=curr1->GetWins();
            w1++;
            curr1->SetWins(w1);
            curr1->SetDefeated("No-Contest Win");}
        else{                                           //Wrestler vs Wrestler: Full Point System
            diff = Bout(curr1, curr2, ptr);
            if (diff == 0){
                t1->AddScore(3);}
            else if(diff >= 14){
                t1->AddScore(6);}
            else if(diff < -14){
                t2->AddScore(6);}
            else if (diff > 7 && diff < 14){
                t1->AddScore(4);}
            else if (diff < -7 && diff > -14){
                t2->AddScore(4);}
            else if (diff < 8 && diff > 0){
                t1->AddScore(3);}
            else if (diff > -8 && diff < 0){
                t2->AddScore(3);}
    }
}};


