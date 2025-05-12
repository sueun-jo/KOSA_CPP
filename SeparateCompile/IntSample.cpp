//IntSample.cpp

#include "IntSample.h"

void IntSample::ShowScore()
{cout << "score : " << Score << endl;}

void IntSample::setScore(const int s){
    Score = s;
}

int IntSample::getScore(){
    return Score;
}


