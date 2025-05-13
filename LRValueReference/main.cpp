#include <iostream>
#include <string>
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

#if OFF

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

#if OFF

class MyClass
{
public:
    MyClass(){} //생성자
    MyClass(string str) : m_str(str){}

    void print(){
        cout << m_str << endl;
    }

private:
    string m_str;
};


int main(){
    MyClass A("aaa");
    MyClass B;
    MyClass C;

    B=A;
    C = move(A); //std::move;

    A.print();
    B.print();
    C.print();

    return 0;

}
#endif

#if ON

int main(){
    string name1 = "allen";
    cout << "name1: " << name1 << endl;

    string name2 = move(name1);
    cout << "After, name2 = move(name)" <<endl;
    cout << "-> name1: " << name1 << endl;
    cout << "-> name2: " << name2 << endl << endl;

    //int형 데이터는 객체가 아니기 때문에 move해봤자 의미없음
    //move()는 l-value를 r-value화 하는 거기 때문에 이미 r-value를 r-value해봤자 동작 안함
    int zipcode1 = 90031;
    cout << "zipcode1: " << zipcode1 << endl;
    int zipcode2 = move(zipcode1);
    cout << "After, zipcode2 = move(zipcode1)" << endl;
    cout << "-> zipcode1: " << zipcode1 << endl;
    cout << "-> zipcode2: " << zipcode2 << endl;

}


#endif
