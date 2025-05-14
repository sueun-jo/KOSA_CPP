#include <iostream>
#include <string>
using namespace std;

#define ON 1
#define OFF 0

#if OFF
void print(int &x){
    cout << "print (int &x)" << endl;
}

void print(const int &x){
    cout << "print(const int &x)" << endl;
}

void print(int &&x){
    cout << "print(int &&x)" << endl;
}

int main()
{
    const int &x = 3;
    print(x); //const int &의 print함수 출력
    print(3); //

    return 0;
}
#endif

#if OFF

template <class T>{
swap1(T& a, T &b){
    T tmp(a);
    a = b;
    b = tmp;
}


//move를 쓰면 복사(copy)하지 않고 swap이 가능
template <class T>
swap2(T& a, T &b){
    T tmp(move(a));
    a = move(b); //a를 L-Value에서 R-Value 참조 타입으로 캐스팅
    b = move(tmp);  //std::move(b)는 b를 R-Value처럼 취급하게 함
}

#endif

#if OFF

class MyClass
{
public:
    MyClass(){} //생성자
    MyClass(string str) : m_str(str){}

    void print(){
        cout << m_str << endl;
    }

private:
    string m_str;
};


int main(){
    MyClass A("aaa");
    MyClass B;
    MyClass C;

    B=A;
    C = move(A); //std::move;

    A.print();
    B.print();
    C.print();

    return 0;

}
#endif

#if OFF

int main(){
    string name1 = "allen";
    cout << "name1: " << name1 << endl;

    string name2 = move(name1);
    cout << "After, name2 = move(name)" <<endl;
    cout << "-> name1: " << name1 << endl;
    cout << "-> name2: " << name2 << endl << endl;

    //int형 데이터는 객체가 아니기 때문에 move해봤자 의미없음
    //move()는 l-value를 r-value화 하는 거기 때문에 이미 r-value를 r-value해봤자 동작 안함
    int zipcode1 = 90031;
    cout << "zipcode1: " << zipcode1 << endl;
    int zipcode2 = move(zipcode1);
    cout << "After, zipcode2 = move(zipcode1)" << endl;
    cout << "-> zipcode1: " << zipcode1 << endl;
    cout << "-> zipcode2: " << zipcode2 << endl;

}

#endif

#if OFF

class MyArray{
private:
    int num;

public:
    MyArray(int n){
        cout << "생성자 호출" << endl;
        num = n;
    }

    MyArray(const MyArray& copy){
        cout << "복사 생성자 호출" << endl;
        num = copy.num;
    }
    MyArray(MyArray&& move){
        cout << "이동생성자 호출" <<endl;
        num= move.num;
        move.num = 0;
    }

    MyArray operator = (MyArray&& move){ //이동대입 연산자
        cout << "이동 대입 연산자 호출" << endl;
        swap(num, move.num);
        return *this;
    }

    int getNum(){
        return num;
    }
};

MyArray CreateMyArray(){
    return MyArray(100);
}

int main(){
    MyArray ar1(10);
    MyArray ar2(ar1);

    cout << "ar1.getNum: " << ar1.getNum() << endl;
    cout << "ar2.getNum: " << ar1.getNum() << endl;

    ar2 = CreateMyArray();
    cout << "ar1.getNum: " << ar1.getNum() << endl;
    cout << "ar1.getNum: " << ar2.getNum() << endl;

    MyArray ar3(std::move(ar1));
    cout << "ar1.getNum: " << ar1.getNum() << endl;
    cout << "ar1.getNum: " << ar3.getNum() << endl;

}
#endif

#if ON
class MyClass{
public:
    MyClass(){}
    MyClass(string str, int a) : m_str(str), m_ptr(new int(a)){}
    ~MyClass(){
        cout << "~MyClass()" << endl;
        if (m_ptr != nullptr)
            delete m_ptr;
    }
    void print(){
        cout << "String: " << m_str << endl;
        if(m_ptr != nullptr)
            cout << "Ptr: " << *m_ptr << endl << endl;
        else
            cout << "Ptr: " << endl << endl;
    }

    MyClass& operator = (MyClass& other){
        cout << "operator=(MyClass& other)" << endl;
        m_str = other.m_str;
        m_ptr = new int(*other.m_ptr);
        return *this;
    }
#if 0
    MyClass& operator = (MyClass&& other) == default;
#else
    MyClass& operator = (MyClass&& other){
        cout << "operator=(MyClass&& other)" << endl;
        m_str = move(other.m_str);
        m_ptr = move(other.m_ptr);
        other.m_ptr = nullptr;
        return *this;
    }
#endif
private:
    string m_str = "ABC";
    int* m_ptr = nullptr;
};

int main(){
    MyClass A("aaa", 10);
    MyClass B;
    MyClass C;

    B = A;
    C = move(A);

    A.print();
    B.print();
    C.print();

    return 0;
}
#endif
