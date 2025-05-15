#define ON 1
#define OFF 0

#if OFF
#include <iostream>
using namespace std;

class First{
public:
    virtual void MyFunc() { cout << "First Func" << endl; }
};

class Second  : public First{
public:
    virtual void MyFunc() { cout << "Second Func" << endl; }
};

class Third : public Second{
public:
    virtual void MyFunc() {cout << "Third Func" << endl; }
};

int main()
{
    Third * tptr = new Third();
    Second * sptr = tptr;
    First * fptr = sptr;

    fptr->MyFunc();
    sptr->MyFunc();
    tptr->MyFunc();
    delete tptr;
    return 0;
    return 0;
}
#endif

#if ON
#include <iostream>
#include <string>
using namespace std;

class AbstractClass{
public:
    virtual string SampleFunction() = 0; //순수 가상 함수 선언
};

class TestClass: public AbstractClass{
public:
    string SampleFunction(){
        return "Sample Function";
    }
};

int main (void){
    // AbstractClass obj1; //추상 클래스 AbstractClass는 객체를 생성하지 못함 => Error
    TestClass obj1; //파생 클래스 TestClass로 객체 생성
    cout << obj1.SampleFunction() << endl;
    return 0;
}

#endif
