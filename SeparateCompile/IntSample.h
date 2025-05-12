#ifndef INTSAMPLE_H
#define INTSAMPLE_H

#include <iostream>
using namespace std;

class IntSample{
public :
    void ShowScore();
    void setScore(const int s);
    int getScore();

private :
    int Score;
}; //클래스 선언
#endif // INTSAMPLE_H
