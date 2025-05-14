#include <iostream>

using namespace std;


class Minho; // Sueun 클래스가 Minho클래스를 참조하려면 먼저 선언이 필요함

class Sueun{
private:
    int age;
public:
    Sueun(int age) : age(age){
        cout << "Sueun::Sueun(age) 생성자 완료" << endl;
    }
    void introduce(){
        cout << "sueun's age: " << age << endl;
    }
    void WhoIsOlder(const Minho & minhoObj);
};

class Minho{
private:
    int age;
public :
    Minho(int age) : age(age){
        cout << "Minho::Minho(age) 생성자 완료" << endl;
    }
    void introduce (){
        cout << "minho's age: " << age << endl;
    }

    friend class Sueun;
};

void Sueun::WhoIsOlder(const Minho & minhoObj){
    cout << "sueun is " << ((age > minhoObj.age)? "older" : "younger") << " than minho" << endl;
}

int main()
{
    Minho minho1(33);
    minho1.introduce();
    Sueun sueun1(26);
    sueun1.introduce();

    return 0;
}
