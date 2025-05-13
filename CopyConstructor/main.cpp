#include <iostream>
using namespace std;

#define ON 1
#define OFF 0

#if OFF
class SoSimple{
private:
    int num1;
    int num2;

public:
    SoSimple(int n1, int n2) : num1(n1), num2(n2)
    {
        //empty
    }

    //레퍼런스 변수로 객체 자체를 인자로 받기
    SoSimple(SoSimple &copy) : num1(copy.num1), num2(copy.num2)
    {
        cout << "Called SoSimple(SoSimple &copy)" << endl;
    }
    void ShowSimpleData()
    {
        cout << num1 << endl;
        cout << num2 << endl;
    }

};
int main()
{
    SoSimple sim1(15, 30);
    cout << "생성 및 초기화 직전" << endl;

    SoSimple sim2 = sim1;
    cout << "생성 및 초기화 직후" << endl;
    sim2.ShowSimpleData();
    return 0;
}
#endif

#if OFF /*복사 생성자 호출 case 예제 1*/

class SoSimple{
private:
    int num1;


public:
    SoSimple(int n1) : num1(n1)
    {
        //empty
    }

    //레퍼런스 변수로 객체 자체를 인자로 받기
    SoSimple(const SoSimple &copy) : num1(copy.num1)
    {
        cout << "Called SoSimple(const SoSimple &copy)" << endl;
    }
    void ShowData()
    {
        cout << num1 << endl;
    }

};

void SimpleFuncObj(SoSimple ob){
    ob.ShowData();
}

int main()
{
    SoSimple obj(7);
    cout << "SimpleFuncObj 함수 호출 전" << endl;
    SimpleFuncObj(obj);
    cout << "SimpleFuncObj 함수 호출 후" << endl;

    return 0;
}

#endif

#if OFF /*복사 생성자 호출 확인 2*/
class SoSimple{
private:
    int num;

public:
    SoSimple(int n) : num(n)
    {
        //empty
    }

    SoSimple(const SoSimple &copy) : num(copy.num)
    {
        cout << "Called SoSimple(const SoSimple &copy)" << endl;
    }

    SoSimple& AddNum(int n){
        num += n;
        return *this;
    }

    void ShowData()
    {
        cout << "num: "<< num << endl;
    }

};

SoSimple SimpleFuncObj(SoSimple ob){
    cout << "return 이전" << endl;
    return ob;
}

int main()
{
    SoSimple obj(7);
    SimpleFuncObj(obj).AddNum(30).ShowData();
    obj.ShowData();

    return 0;
}
#endif

#if ON /*깊은 복사 예제*/

class MyProfile{
private:
    int* ptrNum;
    int zipcode;

public:
    MyProfile(int n , int zc){
        ptrNum = new int;
        *ptrNum = n;
        zipcode = zc;
    }

    MyProfile(const MyProfile& obj) : zipcode (obj.zipcode){
        ptrNum = new int;
        *ptrNum = *obj.ptrNum;
        cout << "Copy Constructor" << endl;
    }

    ~MyProfile(){
        delete ptrNum;
        cout << "Destructor" << endl;
    }

    void setProfile(int n , int zc){
        *ptrNum = n;
        zipcode = zc;
    }

    void getProfile(){
        cout << "ptrNum: " << ptrNum << endl;
        cout << "*ptrNum: " << *ptrNum << endl;
        cout << "zipcode: " << zipcode << endl;
        cout << endl;
    }

};

int main(void){

    MyProfile profile1 (10, 90031);
    profile1.getProfile();

    MyProfile profile2(profile1); //MyProfile profile2 = profile1;
    profile1.getProfile();
    profile2.getProfile();
    profile2.setProfile(500, 90000);
    profile1.getProfile();
    profile2.getProfile();
    return 0;
}
#endif
