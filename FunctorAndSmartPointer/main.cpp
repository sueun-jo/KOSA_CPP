#define ON 1
#define OFF 0

#if ON
/* Functor 예제*/
#include <iostream>
using namespace std;



class Adder{
public:
    int operator()(const int& n1, const int& n2)
    {
        return n1+n2;
    }
    double operator()(const double & e1, const double &e2){
        return e1+e2;
    }

};

int main()
{
    Adder adder; //class Adder의 adder이라는 이름의 객체 생성
    cout << adder(1,3) << endl;
    cout << adder(1.5, 3.7) << endl;


    return 0;
}
#endif

#if OFF
#endif
