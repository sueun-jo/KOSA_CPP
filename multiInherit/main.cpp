#define ON 1
#define OFF 0

#if OFF /*다중 상속 예제1*/
#include <iostream>
using namespace std;

class BaseOne{
public:
    void SimpleFuncOne(){ cout << "BaseOne" << endl;}
};

class BaseTwo{
public:
    void SimpleFuncTwo() {cout << "BaseTwo" << endl;}
};

class MultiDerived : public BaseOne, protected BaseTwo{
public:
    void ComplexFunc(){
        SimpleFuncOne();
        SimpleFuncTwo();
    }
};


int main()
{
    MultiDerived mdr;
    mdr.ComplexFunc();

    return 0;
}
#endif

#if ON /* 다중 상속 예제2  */
#include <iostream>
using namespace std;

class Person{
public:
    Person(){
        cout << "Person::Person() 생성자" << endl;
    }
    ~Person(){
        cout << "Person::Person() 소멸자" << endl;
    }
    virtual void write()=0; //순수 가상함수, Person을 상속받으면 파생클래스는 write함수 무조건 구현해야함
};

class Soo : public Person {
public:
    Soo() : Person() {
        cout << "Soo::Soo() 생성자" << endl;
    }
    ~Soo(){
        cout << "Soo::~Soo() 소멸자" << endl;
    }

    void write(){
        cout << "책을 잘 쓴다" << endl;
    }
};

class Hee : public Person {
public:
    Hee() : Person() {
        cout << "Hee::Hee() 생성자" << endl;
    }
    ~Hee() {
        cout << "Hee::~Hee() 소멸자" << endl;
    }
    void write(){
        cout << "책을 못 쓴다" << endl;
    }
};

class Child : public Soo, public Hee{
public:
    Child() : Soo(), Hee(){
        cout << "Child::Child() 생성자" << endl;

    }
    ~Child() {
        cout << "Child::~Child() 소멸자" << endl;
    }
    void write (){
        //write();
        Soo::write();
    }
};

int main(void){
    Child child;
    child.write();
    return 0;
}
#endif
