#include <iostream>

using namespace std;
int f(){
    return 20 + 30;
}
int main()
{
    double d = 1.414;
    decltype(f()) decVar1 = d; //decVar1은 int형이 된다. d=1.414여도 1로 들어감
    decltype(d) decVar2 = decVar1; //decVar2는 double형이 된다.
    decltype((d)) decVar3 = decVar2; //변수에 괄호가 들어가면 레퍼런스 변수가 된다. devVar3은 decVar2의 레퍼런스 변수가 된다.
    decVar2 = 3.141592;

    cout << &decVar1 << endl;
    cout << &decVar2 << endl;
    cout << &decVar3 << endl;


    return 0;
}
