#include <iostream>

using namespace std;

int main()
{
    int i1 = 10, i2 = 20;
    const int *p1 = &i1;
    int const *p2 = &i1;
    const int *const p3 = &i1;

    //*p1 = 10;
    p1 = &i2;
    //*p2 = 20;
    p2 = &i2;
    //*p3 = &i2;
    //p3 = &i2;

    return 0;
}
