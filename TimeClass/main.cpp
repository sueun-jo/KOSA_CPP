#include <iostream>
using namespace std;

class Sueun{
private:
    int age;
public:
    Sueun(const Sueun & source) : age(source.age){
        cout << "Sueun::Sueun() 복사 생성자 완료" << endl;
    }

    Sueun(int age) : age(age){
        cout << "Sueun::Sueun(age) 생성자 완료" << endl;
    }
    Sueun(){
        cout << "Sueun::Sueun() 생성자 완료" << endl;
    }

    void introduce();
    ~Sueun(){
        cout << "Sueun::~Sueun() 소멸자 완료" << endl;
    }
    Sueun & operator=(const Sueun& sueunOBJ){
        this->age = sueunOBJ.age;
        cout << "Sueun::operator=() 복사 대입 연산자 완료" << endl;
        return *this;
    }
};

int main(void){
    Sueun sueun1(26);
    Sueun sueun2(16);
    Sueun sueun3(8);
    sueun1.introduce();
    sueun2.introduce();
    sueun3.introduce();

    cout << "====대입 연산 전====" << endl;

    sueun1 = sueun2 = sueun3;

    cout << "====대입 연산 후====" << endl;
    sueun1.introduce();
    sueun2.introduce();
    sueun3.introduce();
    return 0;
}

void Sueun::introduce(){
    cout << "age: " << age << endl;
}
