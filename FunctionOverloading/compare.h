#ifndef COMPARE_H
#define COMPARE_H

#include <iostream>
using namespace std;
//함수 오버로딩 지원 : 함수 이름은 같고 매개변수가 다른 형태로 정의 가능
int Compare (const int a, const int b);
int Compare (const float a, const float b);
int Compare (const char a, const char b);
int Compare (const char str1[], const char str2[]);

#endif // COMPARE_H
