#include "compare.h"
using namespace std;

int main(){
    int a = 34, b = 4;
    float c = 1.234f, d=98.34f;
    char e = 'H', f ='K';
    char str1[] = "computer";
    char str2[] = "computers";

    cout << Compare (a, b) << endl;
    cout << Compare (c, d) << endl;
    cout << Compare (e, f) << endl;
    cout << Compare (str1, str2) << endl;
    return 0;
}
