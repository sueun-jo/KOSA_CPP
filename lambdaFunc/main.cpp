#include <iostream>
using namespace std;

class Chulsoo{
public:
    int count; //철수가 스테이크를 먹는 횟수
};


int main()
{
    Chulsoo chulsoo;
    chulsoo.count = 1;

    for (int i=0; i<10; i++){
        [=](int SteakWeight) mutable {cout << "eatLambda():: 철수는 " << chulsoo.count++ << "번째 "
                                            << SteakWeight << "g짜리 스테이크를 먹는다." << endl ;}(1000);
    }
    cout << chulsoo.count << endl;

    for (int i=0; i<10; i++){
        [&](int SteakWeight) {cout << "eatLambda():: 철수는 " << chulsoo.count++ << "번째 "
                                            << SteakWeight << "g짜리 스테이크를 먹는다." << endl ;}(1000);
    }
    cout << chulsoo.count;

    return 0;
}
