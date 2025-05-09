#include <iostream>
using namespace std;

#define ON 1
#define OFF 0

/* Default Value.cpp */
#if OFF
int BoxVolume(int length, int width=1, int height=1);

int main()
{
    cout << "[3, 3, 3]: " << BoxVolume(3,3,3) << endl;
    cout << "[5, 5, D]: " << BoxVolume(5,5) << endl;
    cout << "[7, D, D]: " << BoxVolume(7) << endl;

    return 0;
}

int BoxVolume(int length, int width, int height){
    return length*width*height;
}

#endif
