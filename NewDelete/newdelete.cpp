#include <iostream>
using namespace std;

#define ON 1
#define OFF 0

using namespace std;

// int main()
// {

#if OFF
    int *p = NULL;
    p = new int(0); //동적 메모리 할당 및 초기화
    if (p == NULL){
        cout << "동적 메모리 할당 실패\n";
        return 1;
    }

    cout << "정수 입력";
    cin >> *p; //동적 메모리 사용
    cout << "입력된 정수는 " << p[0] << endl;
    delete p;
    p = NULL;

#endif

#if OFF
    int *p = nullptr;
    p = new int{12};
    //p = new int(12.0);
    if(p == nullptr) {
        cout << "Memory allocation error!" << endl;
        return -1;
    }

    cout << "Input the number : ";
    cin >> *p;
    cout << "The inputted number is " << p[0] << endl;

    delete p;
    p = nullptr;

#endif

#if OFF
    int num;
    cin >> num;
    int *data = new int[num];
    for (int i=0; i<num; i++)
        cin >> data[i];

    delete [] data; // []를 쓰지 않아도 컴파일은 된다. 다만 동적할당된 메모리를 해제하는데 컴파일러마다 다르다.

#endif

//     return 0;
// }

#if OFF

    char* NumberToString(int n){
        char* p = new char[20];
        snprintf(p,20,"%d",n);
        return p;
    }

    int main(){
        int num;
        cout << "정수 입력: ";
        cin >> num;

        char* str = NumberToString(num);
        cout << "문자열로 변환된 값: " << str << endl;

        delete [] str;
        return 0;
    }
#endif

#if ON
    int main(void){

        return 0;
    }
#endif

