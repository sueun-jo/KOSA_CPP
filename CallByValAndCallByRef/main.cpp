#include <iostream>
using namespace std;

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
