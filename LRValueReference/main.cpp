#include <iostream>
using namespace std;

#define ON 1
#define OFF 0

#if OFF
void print(int &x){
    cout << "print (int &x)" << endl;
}

void print(const int &x){
    cout << "print(const int &x)" << endl;
}

void print(int &&x){
    cout << "print(int &&x)" << endl;
}

int main()
{
    const int &x = 3;
    print(x); //const int &의 print함수 출력
    print(3); //

    return 0;
}
#endif

#if ON

template <class T>{
swap1(T& a, T &b){
    T tmp(a);
    a = b;
    b = tmp;
}


//move를 쓰면 복사(copy)하지 않고 swap이 가능
template <class T>
swap2(T& a, T &b){
    T tmp(move(a));
    a = move(b); //a를 L-Value에서 R-Value 참조 타입으로 캐스팅
    b = move(tmp);  //std::move(b)는 b를 R-Value처럼 취급하게 함
}

#endif
