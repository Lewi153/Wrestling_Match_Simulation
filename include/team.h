#ifndef TEAM_H
#define TEAM_H
#include <iostream>
#include <random>
#include <ctime>
#include <string>
#include "wrestler.h"
using namespace std;

class team
{
    public:
        team(default_random_engine * ptr, int id);
        virtual ~team();

        void Display();
        void SetID(int id){ID = id;}
        void AddScore(int s){score=score+s;}
        int GetID(){return ID;}
        int GetScore(){return score;}
        wrestler * GetHead(int i);


    private:
        int ID;
        int score;
        int tsize;
        wrestler * head[14];


};

#endif // TEAM_H
