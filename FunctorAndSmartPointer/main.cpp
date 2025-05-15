#define ON 1
#define OFF 0

#if OFF
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

#if ON
/* smart pointer */
#include <iostream>
#include <memory>
using namespace std;
class Sueun{
private:
    int age;
public:
    Sueun(int age) : age(age) {
        cout << "Sueun::Sueun(age) 생성자 완료" << endl;
    }
    Sueun() {
        cout << "Sueun::Sueun() 생성자 완료" << endl;
    }
    ~Sueun(){
        cout << "Sueun::~Sueun() 소멸자" << endl;
    }
    void introduce();
};

int main(void){
    Sueun * sueunPtr2 = new Sueun(26);
    sueunPtr2->introduce();
    delete sueunPtr2;

    //auto_ptr은 C++11 이후 삭제, C++98(클래식 c++)은 컴파일 되겟지용
    // auto_ptr<Sueun> sueunSmptr (new Sueun(26));
    // sueunSmptr->introduce();
    return 0;
}

void Sueun::introduce(){
    cout << "age: " << age << endl;
}
#endif
