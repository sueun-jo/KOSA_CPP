#include <iostream>

using namespace std;

int main()
{
    float i = 100.12345;
    double j = 200.12345;
    float count = static_cast <float>(j/i);
    //예제1

    double d = 1212;
    void *p = &d;
    double *dp = static_cast <double*>(p);
    //예제2

    int num = 0x040204;
    char* ptr = reinterpret_cast<char*>(&num);
    cout << static_cast<int>(*(ptr+1)) << endl;
    //예제3

    const char* str = "Hello";
    char* str2 = const_cast<char*>(str); //const 성향 제거
    cout << str << endl;
    //예제4



    return 0;
}
