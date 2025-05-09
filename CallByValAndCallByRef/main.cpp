#define ON 1
#define OFF 0
#include <iostream>
using namespace std;

#if OFF
/*변수에 값을 할당하는 함수*/
int assignValue(int n){
    n = 10;
    return n;
}
/*메인함수*/
int main()
{
    int num=0, value;
    value = assignValue(num);
    cout << "input " << num << " output " << value;
    return 0;
}
#endif

#if OFF //call by value with class

class Restaurant {
public:
    int Steak; //스테이크 가격
};

class Minho{
public:
    int Eat(int);
};

int Minho::Eat(int SteakPrice){
    SteakPrice = 100000; // 민호가 10만원짜리 스테이크를 먹었다고 거짓말
    cout << "민호는 먹는다" << endl;
    return SteakPrice;
}

int main(void){
    Minho minho;
    Restaurant restaurant;

    //레스토랑에서 민호에게 준 스테이크는 8만원
    restaurant.Steak = 80000;
    cout << "민호는" << minho.Eat(restaurant.Steak) <<"원짜리 스테이크를 먹었다고 거짓말을 했다" << endl;
    cout << "레스토랑은 민호가 " << restaurant.Steak << "원짜리 스테이크를 먹었다고 알고 있다." << endl;

    return 0;
}
#endif

#if OFF
//Call by ref, 포인터에 의한 전달 예제
void Swap (int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main (void)
{
    int a, b;
    cout << "두 수 입력: ";
    cin >> a >> b;
    cout << "Swap함수 호출 전의 a와 b " << a  << " " << b << endl;
    Swap (&a, &b);
    cout << "Swap함수 호출 후의 a와 b " << a  << " " << b << endl;
    return 0;
}

#endif

#if ON
//레퍼런스 변수를 이용한 call by ref
void Swap (int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}
int main (){
    int a, b;
    cout << "두 수 입력: ";
    cin >> a >> b;
    cout << "Swap함수 호출 전의 a와 b " << a  << " " << b << endl;
    Swap (a, b);
    cout << "Swap함수 호출 후의 a와 b " << a  << " " << b << endl;
    return 0;
}
#endif
