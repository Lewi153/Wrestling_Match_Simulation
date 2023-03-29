#ifndef WRESTLER_H
#define WRESTLER_H
#include <iostream>
#include <random>
#include <ctime>
#include <string>
using namespace std;

class wrestler
{
    public:
        wrestler(default_random_engine * ptr);


        virtual ~wrestler();

        void SetID(int x){ID=x;}
        void SetAge(int x){Age=x;}
        void SetWt(int x){Wt=x;}
        void SetAbility(int x){Ability=x;}
        void SetWins(int x){Wins=x;}
        void incWins(){Wins++;}
        void SetLosses(int x){Losses=x;}
        void SetWtClass(int x){WtClass = x;}
        void SetNext(wrestler * n){next = n;}
        void SetDefeated(string d){defeated = d;}

        int GetID(){return ID;}
        int GetAge(){return Age;}
        int GetWt(){return Wt;}
        int GetAbility(){return Ability;}
        int GetWins(){return Wins;}
        int GetLosses(){return Losses;}
        int GetWtClass(){return WtClass;}
        string GetDefeated(){return defeated;}
        wrestler * GetNext(){return next;}

        void Display();

    private:
        int ID;
        int Age;
        int Wt;
        int Ability;
        int Wins;
        int Losses;
        int WtClass;
        string defeated;
        wrestler * next;
};

#endif /// WRESTLER_H
