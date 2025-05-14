#define ON 1
#define OFF 0

#if OFF /* friend Class 예제1 */

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

#endif

#if OFF /* friend 함수와 friend class예제*/

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
    friend void howOld(const Minho & minhoObj, const Sueun & sueunObj); //friend함수
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
    friend void Sueun::WhoIsOlder(const Minho &minhoObj); //우린 서로 칭긔칭긔
    friend void howOld (const Minho &minhoObj, const Sueun &sueunObj);
};

void howOld (const Minho &minhoObj, const Sueun &sueunObj){
    cout << "Minho is " << minhoObj.age << " yesrs old" << endl;
    cout << "Sueun is " << sueunObj.age << " years old" << endl;
}
void Sueun::WhoIsOlder(const Minho & minhoObj){
    cout << "sueun is " << ((age > minhoObj.age)? "older" : "younger") << " than minho" << endl;
}

int main()
{
    Minho minho1(33);
    minho1.introduce();
    Sueun sueun1(26);
    sueun1.introduce();
    howOld(minho1, sueun1);

    return 0;
}

#endif

#if OFF /* static 멤버 변수 예제*/
#include <iostream>
using namespace std;

class SoSimple{
public:
    static int simObjCnt; //static 멤버 변수, 클래스 변수

public:
    SoSimple() //생성자
    {
        simObjCnt++;
        cout << simObjCnt << "번째 SoSimpel 객체" << endl;
    }
};

int SoSimple::simObjCnt = 0;

int main(void){
    cout << SoSimple::simObjCnt << "번째 SoSimple 객체" << endl;
    SoSimple sim1;
    SoSimple sim2;
    cout << SoSimple::simObjCnt << "번째 SoSimple 객체" << endl;
    cout << sim1.simObjCnt << "번째 SoSimple 객체" << endl;
    cout << sim2.simObjCnt << "번째 SoSimple 객체" << endl;

    return 0;
}
#endif

#if ON
#include <iostream>
using namespace std;

class Minho {
private:
    int age;
    static int minhoPrivateCounter;
protected:
    static int minhoProtectedCounter;
public:
    static int minhoPublicCounter;

    Minho(int age) : age(age) {
        minhoPrivateCounter++;
        minhoProtectedCounter++;
        minhoPublicCounter++;

        cout << "Minho::Minho(age) 생성자로 만들어지는 " << minhoPrivateCounter << "(Private)번째 객체 생성 완료" << endl;
        cout << "Minho::Minho(age) 생성자로 만들어지는 " << minhoProtectedCounter << "(Protected)번째 객체 생성 완료" << endl;
        cout << "Minho::Minho(age) 생성자로 만들어지는 " << minhoPrivateCounter << "(Private)번째 객체 생성 완료" << endl;
        cout << "Minho::Minho(age) 생성자로 만들어지는 " << minhoProtectedCounter << "(Protected)번째 객체 생성 완료" << endl;
        cout << "Minho::Minho(age) 생성자로 만들어지는 " << minhoPublicCounter << "(Public)번째 객체 생성 완료" << endl;
    }
};

int Minho::minhoPrivateCounter = 0;
int Minho::minhoProtectedCounter = 0;
int Minho::minhoPublicCounter = 0;

class Sueun{
private:
    int age;

public:
    Sueun(int age) : age(age){
        //Minho::minhoPrivateIntroduceCounter++;
        //Minho::minhoProtectedIntroduceCounter++;
        Minho::minhoPublicCounter++;
        cout << "Sueun::Sueun(age) 생성자로 만들어지는 " << Minho::minhoPublicCounter << "번째 객체 생성 완료" << endl;
    }

};
int main(){
    Minho minho1 (33);
    Minho minho2(33);
    Sueun sueun1(26);
    Sueun sueun2(26);
    return 0;
}

#endif

