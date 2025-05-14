#include <iostream>
using namespace std;

#define ON 1
#define OFF 0
#if OFF
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

#endif

#if ON

class Person{
private:
    char * name;
    int age;

public:
    Person(const char * myname, int myage){
        int len = strlen(myname)+1;
        name = new char[len];
        strcpy(name, myname);
        age = myage;
    }

    void ShowPersonInfo() const
    {
        cout << "이름: " << name << endl;
        cout << "나이: " << age << endl;
    }

    ~Person(){
        delete []name;
        cout << "소멸자" << endl;
    }

    //해결책이 되는 대입연산자 오버라이딩
    Person & operator = (const Person& ref){
        delete []name;
        int len = strlen(ref.name)+1;
        name = new char[len];
        strcpy(name, ref.name);
        age = ref.age;
        return *this;
    }
};

int main (void){
    Person man1("Jo Sueun", 26);
    Person man2("Yoo Minho", 33);

    man2 = man1;
    man1.ShowPersonInfo();
    man2.ShowPersonInfo();
    return 0;
}
#endif
