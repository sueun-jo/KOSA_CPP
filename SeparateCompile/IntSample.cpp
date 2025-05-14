//IntSample.cpp

#include "IntSample.h"
//클래스의 멤버함수
void IntSample::ShowScore()
{cout << "score : " << Score << endl;}

void IntSample::setScore(const int s){
    Score = s;
}

int IntSample::getScore(){
    return Score;
}


