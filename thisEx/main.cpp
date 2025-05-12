#include <iostream>
using namespace std;

#define ON 1
#define OFF 0

#if OFF //SelfRef의 반환 예시
class SelfRef{
private :
    int num;
public :
    SelfRef(int n) : num(n){
        cout << "객체 생성" <<endl;
    }

    SelfRef& Adder (int n){
        num += n;
        return *this;
    }

    SelfRef& ShowTwoNumber(){
        cout << num << endl;
        return *this;
    }

};

int main (void){
    SelfRef obj(3);
    SelfRef &ref = obj.Adder(2);
    obj.ShowTwoNumber();
    ref.ShowTwoNumber();
    ref.Adder(1).ShowTwoNumber().Adder(2).ShowTwoNumber();

    return 0;
}

#endif

/* this 활용(1) 60p~ */
#if OFF
class Chulsoo{
private:
    int age;
public:
    Chulsoo(int age){
        this->age = age;
        cout << "Chulsoo::Chulsoo(age) 생성자 완료" <<endl;
    }
    void setAge(int age){
        this->age = age;
    }
    void introduce(){
        cout <<"철수 나이는 " << age << "세 입니다." << endl;
    }

    Chulsoo* returnThisPointer(){
        return this;
    }
    Chulsoo& returnThis(){
        return *this;
    }
    Chulsoo returnThisRef(){
        return *this;
    }
};

int main(void){
    Chulsoo chulsoo1(32);
    cout <<"chulsoo1 객체 introduce" << endl;
    chulsoo1.introduce();
    chulsoo1.setAge(50);
    chulsoo1.introduce();

    Chulsoo chulsoo2(32);
    cout << "ChulsooPointer introduce" << endl;
    chulsoo2.returnThisPointer()->introduce();
    chulsoo2.returnThisPointer()->setAge(50);
    chulsoo2.returnThisPointer()->introduce();

    Chulsoo chulsoo3(32);
    cout << "chulsoo introduce" << endl;
    chulsoo3.returnThis().introduce();
    chulsoo3.returnThis().setAge(50);
    chulsoo3.returnThis().introduce();

    Chulsoo chulsoo4(32);
    cout << "chulsooRef introduce" << endl;
    chulsoo4.returnThisRef().introduce();
    chulsoo4.returnThisRef().setAge(50);
    chulsoo4.returnThisRef().introduce();
}
#endif
