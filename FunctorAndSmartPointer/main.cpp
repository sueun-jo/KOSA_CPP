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

#if OFF
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

#if OFF
#include <iostream>
#include <memory>
using namespace std;


int main(){
    unique_ptr<int> ptr01 (new int(5)); //int형 unique_ptr 선언
    auto ptr02 = std::move(ptr01); //ptr02로 ptr01의 소유권 이전

    cout << *ptr02 << endl;
    //대입연산자로 복사하면 오류남 (unique_ptr)은 객체와 1:1 소유권을 갖고 있기 때문임
    // unique_ptr<int> ptr03 = ptr01; //오류

    ptr02.reset(); //ptr02가 가르키고 있는 메모리 영역 삭제
    ptr01.reset(); //ptr01이 가르키고 있는 메모리 영역 삭제
}
#endif

#if OFF /* shared_ptr 예제 */
#include <memory>
#include <iostream>
using namespace std;

int main(){
    shared_ptr<int> ptr01 (new int(5)); //int형 shared_ptr을 선언하고 초기화
    cout << ptr01.use_count() << endl; // 1
    auto ptro2(ptr01); //복사생성자를 이용해 초기화
    cout << ptr01.use_count() <<endl; //2
    auto ptr03 = ptr01;
    cout << ptr01.use_count() << endl;
}
#endif

#if ON
/*shared_ptr 예제2 */
#include <memory>
#include <iostream>
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

void Sueun::introduce(){
    cout << "sueun age: " << age << endl;
}

int main(){
    shared_ptr<Sueun> sueunSmptr1 (new Sueun(26)); //int형 shared_ptr을 선언하고 초기화
    cout << sueunSmptr1.use_count() << endl;
    sueunSmptr1->introduce();

    cout << "shared_ptr<Sueun> 타입간 복사생성자 호출 후" << endl;
    shared_ptr<Sueun> sueunSmptr2 = sueunSmptr1;
    cout << sueunSmptr1.use_count() << endl;
    sueunSmptr1->introduce();
    sueunSmptr2->introduce();

    return 0;
}
#endif
