#define ON 1
#define OFF 0

#if OFF
#include <iostream>
using namespace std;

class Person{
private:
    int age;
    char name[50];
public:
    Person(int myage, const char* myname) : age(myage){
        strcpy(name, myname);
    }

    void WhatYourName() const
    {
        cout << "My name is " << name << endl;
    }

    void HowOldAreYou()const
    {
        cout << "I'm " << age << "years old" << endl;
    }
};

class UnivStudent : public Person //Person class를 public으로 상속받는다
{
private:
    char major[50]; //전공

public:
    UnivStudent (const char* myname, int myage, const char* mymajor) : Person(myage, myname)
    {
        strcpy(major, mymajor);
    }
    void WhoAreYou () const
    {
        WhatYourName(); //Person클래스의 멤버함수
        HowOldAreYou(); //Person클래스의 멤버함수
        cout << "my major is " << major << endl << endl;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

#endif

#if OFF
#include <iostream>

int main(void){
    std :: cout << "sueun" << std :: endl;
    return 0;
}

#endif

#if OFF
#include "ConTest.h"

int main(){
    CON2 *p_TEST = new CON2();
    delete p_TEST;
}
#endif

#if ON
#include <iostream>
using namespace std;

class Base{
private:
    int baseNum;
public:
    Base() : baseNum(20){
        cout << "Base() 생성자" << endl;
    }
    Base(int n) : baseNum(n){
        cout << "Base(int n)" << endl;
    }


    ~Base() {
        cout << "~Base()" << endl;
    }
    void showBaseNum(){
        cout << baseNum << endl;
    }
};

class Derived : public Base{
private:
    int deriveNum;

public:
    Derived() : deriveNum(30){
        cout << "Derived()" <<  endl;
    }

    ~Derived() {
        cout << "~Derived()" <<  endl;
    }

    Derived(int n) : deriveNum(n){
        cout << "Derived(int n)" << endl;
    }

    Derived(int n1, int n2) : Base(n1), deriveNum(n2){
        cout << "Derived(int n1, int n2) " << endl;
    }

    void showDeriveNum()
    {
        showBaseNum();
        cout << deriveNum << endl;
    }
};

int main (void){
    Derived dr1;
    dr1.showDeriveNum();

    cout << "************************" << endl;
    Derived dr2(12);
    dr2.showDeriveNum();

    cout << "************************" << endl;
    Derived dr3(23, 24);
    dr3.showDeriveNum();


    return 0;
}
#endif
