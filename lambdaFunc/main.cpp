#include <iostream>
using namespace std;

#define ON 1
#define OFF 0

#if OFF
class Chulsoo{
public:
    int count; //철수가 스테이크를 먹는 횟수
};


int main()
{
    Chulsoo chulsoo;
    chulsoo.count = 1;

    //캡쳐에 = 가 들어간 경우
    for (int i=0; i<10; i++){
        [=](int SteakWeight) mutable {cout << "eatLambda():: 철수는 " << chulsoo.count++ << "번째 "
                                            << SteakWeight << "g짜리 스테이크를 먹는다." << endl ;}(1000);
    }
    cout << chulsoo.count << endl;

    //캡쳐에 & 가 들어간 경우
    for (int i=0; i<10; i++){
        [&](int SteakWeight) {cout << "eatLambda():: 철수는 " << chulsoo.count++ << "번째 "
                                            << SteakWeight << "g짜리 스테이크를 먹는다." << endl ;}(1000);
    }
    cout << chulsoo.count;

    return 0;
}

#endif

#if ON

class Chulsoo{
public:
    int count; //철수가 스테이크를 먹는 횟수
};


int main()
{
    Chulsoo chulsoo;
    chulsoo.count = 1;

    //반환형을 char로 지정한 람다함수
    cout << [=](int SteakWeight) mutable -> char{cout << "eatLambda() :: 철수는 "
                                                        << chulsoo.count++ <<"번째 " << SteakWeight << "g짜리 스테이크를 먹는다" <<endl;
                                                        return SteakWeight;} (67) << endl;

    //반환형을 int로 지정한 람다함수
    cout << [=](int SteakWeight) mutable -> int{cout << "eatLambda() :: 철수는 "
                                                       << chulsoo.count++ << "번째 " <<SteakWeight << "g짜리 스테이크를 먹는다." <<endl;
    return SteakWeight;}(67) << endl;

    //반환형 지정하지 않았지만 SteakWeight를 반환하므로  int
    cout << [=](int SteakWeight) mutable {cout << "eatLambda() :: 철수는 "
                                                       << chulsoo.count++ << "번째 " <<SteakWeight << "g짜리 스테이크를 먹는다." <<endl;
    return SteakWeight;}(67) << endl;

    auto love = [](string a, string b){
        cout << a <<"보다 " << b <<"가 좋아" <<endl;
    };

    love("돈", "너");
    love ("냉면", "만두");
    return 0;
}
#endif
