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
