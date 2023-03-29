#ifndef MATCH_H_INCLUDED
#define MATCH_H_INCLUDED
#include <iostream>
#include <random>
#include <ctime>
#include <string>
#include "wrestler.h"
#include "match.h"
#include "team.h"

using namespace std;

int Bout(wrestler * wr1, wrestler * wr2, default_random_engine * ptr);
void Match(team * t1, team * t2, default_random_engine * ptr);



#endif // MATCH_H_INCLUDED
