#include <iostream>
using namespace std;

#define ON 1
#define OFF 0

#if OFF
// 증감연산자는 이렇게 쓰지 않는 것이 좋다
int main()
{
    int a=0, b=0, sum1, sum2;

    sum1 = a+++a+++a++;
    sum2 = ++b+ ++b+ ++b;

    cout << a << " " << b << " " << sum1 << " " << sum2 << endl;
    return 0;
}

#endif

#if OFF
#define M_PI 3.14159265358979323846

#include <cmath>
int main(void){
    int i = 3.65;
    long l = M_PI;
    float f = M_PI;
    double d = M_PI;
    cout << i << " " << l << endl;
    cout << f << " " << d << endl;

    return 0;
}
#endif

#if ON

#include <fstream>
#include <string>

int main(void){
    string str = "파일에 씁시다.";
    ofstream ofs("file.txt");
    ofs << str;

    ofs.close();
    ifstream ifs("file.txt");
    ifs >> str;
    cout << str << endl;
    ifs.close();

    return 0;
}
#endif
