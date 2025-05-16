#define ON 1
#define OFF 0

#if OFF
#include <iostream>
using namespace std;

template <typename T>
T const add (T const& a, T const& b){
    return a+b;
}
int main()
{
    double i= 5.1;
    double j= 10.2;

    int a=5;
    int b=10;
    cout << i << " + " << j << " = " << add(i,j) << endl;
    cout << a << " + " << b << " = " << add(a,b) << endl;
    return 0;
}
#endif

#if OFF //둘 이상 인자에 대한 함수 템플릿 구현 예제1
#include <iostream>
using namespace std;

template <class T1, class T2>
void ShowData(double num){
    cout << (T1)num << ", " << (T2)num << endl; //콤마를 이용해 둘 이상의 형에 대해 템플릿 선언
}

int main (void){
    ShowData<char, int>(65);
    ShowData<char, int>(67);
    ShowData<char, double>(68.9);
    ShowData<short, double>(69.2);
    ShowData<short, double> (70.4);
    return 0;
}

#endif

#if OFF /*둘 이상의 형에 대해 함수 템플릿 구현*/
#include <iostream>
using namespace std;

template <typename T, typename R>
R maxValue (const T num1, const R num2){
    if (num1>num2)
        return num1;
    else
        return num2;
}

int main(void){
    cout << "정수 비교 결과: " << maxValue(3, 5) << endl;
    cout << "배정도 비교 결과: " << maxValue(9.1, 3.6) << endl;
    return 0;
}
#endif

#if OFF /* 인자 추론 실패 -> 각 인자 타입이 다른 경우*/
#include <iostream>
using namespace std;

template <typename R, typename T, typename U>
R const add(T const &a, U const &b){
    return a+b;
}

int main(void){
    double i = 5.1; //T에 double
    int j = 5; //U에 int
    cout << i << " + " << j << " = " << add(i,j) << endl; //R 타입 추론이 안됨 -> 오류 발생
    return 0;
}
#endif

#if OFF
#include <iostream>
using namespace std;

template <typename T>
T Max (T a, T b){
    return a>b? a : b;
}

int main(void){
    cout << Max(11, 15) << endl;
    cout << Max ('T', 'Q') << endl;
    cout << Max ("Simpple", "Best")  << endl;
    return 0;

#endif

#if ON
#include <iostream>
#include <string>
using namespace std;

template <typename T>
T const add(T const& a, T const& b){
    cout << "typename T" << endl;
    return a+b;
}

template <>
char* const add<char*>(char* const&a, char* const&b){
    cout << "specilaized" << endl;
    strcat_s(a, 20, b);
    return a; // return strcat(a,b);
}

char* const add(char* a, char* const& b){
    cout << "overloading" << endl;
    strcat_s(a, 20, b);
    return a; //return strcat(a, b);
}
int main(void){
    int i =5;
    int j = 10;

    double a = 5.1;
    double b = 10.2;

    char m[20] = "Hello";
    char n[20] = "world";

    cout << i << " + " << j << " = " << add(i,j) << endl;
    cout << a << " + " << b << " = " << add(a,b) << endl;

    cout << add<char*> (m,n) << endl;
    cout << add(m,n) << endl;

    return 0;
}

#endif
