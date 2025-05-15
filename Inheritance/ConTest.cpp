// //str.cpp
// #include "str.h"

// void StringCharArray::toCharArray(char *str){
//     int i, len=this->length();

//     for (i=0; i<len; i++)
//         *(str+i) = this->at(i);

//     *(str+i) = '\0';
// }


//ConTest.cpp
#include "ConTest.h"

CON1::CON1(){
    cout << "CON1의 기본 생성자" << endl;
}

CON1::~CON1(){
    cout << "CON1의 소멸자" << endl;
}

CON2::CON2(){
    cout << "CON2의 기본 생성자" << endl;
}

CON2::~CON2(){
    cout << "CON2의 소멸자" << endl;
}

