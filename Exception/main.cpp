#define ON 1
#define OFF 0

#if OFF

#include <iostream>
using namespace std;

int main()
{
    int a, b;
    int result;
    cout << "a/b를 수행합니다. a,b를 입력하세요" << endl;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;

    if (b==0) cout << "0으로는 나눌 수 없습니다" << endl;
    else{ result = a/b;
    cout << "a/b결과는 " << result << " 입니다" << endl;
    }
    return 0;
}

#endif

#if OFF /* try-catch 구문 */
#include <iostream>
using namespace std;

int main(){
    int num1, num2;
    cout << "2개 숫자 입력: ";
    cin >> num1 >> num2;

    try
    {
        if (num2==0)
            throw num2;
        cout << "나눗셈의 몫: " << num1/num2 << endl;
        cout << "나눗셈의 나머지: " << num1%num2 << endl;
    }

    catch (int expn){
        cout << "제수는 " << expn << " 이 될 수 없습니다." << endl;
        cout << "프로그램을 재실행 하세요" << endl;
    }

    cout << "end of main" << endl;
    return 0;
}
#endif

#if OFF /*다수의 catch 블록*/
#include <iostream>
#include <string>
using namespace std;

void inputName(char *name){
    cout << "이름을 입력하세요: ";
    cin >> name;
    if (strlen(name)<=2)
        throw name;
}

int inputAge(){
    int age;
    cout << "나이를 입력하세요: ";
    cin >> age;
    if (age<1)
        throw age;
    return age;
}

int main(void){
    char name [512];
    int age;

    try {
        inputName(name);
        age = inputAge();

        cout <<"제 이름은 " << name << "입니다." << endl;
        cout <<"제 나이는 " << age << "입니다." << endl;
    }

    catch (char *e){
        cout << "예외 발생, 잘못된 이름 입력입니다 " << e << endl;
    }
    catch (int e){
        cout << "예외 발생, 잘못된 나이 입력입니다 " << e << endl;
    }

    return 0;
}
#endif

#if OFF
#include <iostream>

using namespace std;

void handler()
{
    cout << "in handler" << endl;
}

void f1(void) noexcept(false) // throw(int)
{
    cout << "About to throw 1" << endl;
    if (1)
        throw 1;
}

void f2(void) noexcept //throw()
{
    try {
        f1();
    }
    catch(...) {
        handler();
        throw;
    }
}

int main() {
    //   f1();

    try {
        f2();
    }
    catch(int n) {
        cout << n << endl;
        cout << "Caught exception from f2" << endl;
    }
}
#endif

#if OFf /* 처리 되지 않은 예외 */
#include <iostream>
#include <exception>

using namespace std;

void MyErrorHandler(){
    cout << "처리되지 않은 예외 발생" << endl;
    exit(-1);
}

int main(void){
    set_terminate(MyErrorHandler);
    try{
        throw 1;
    }
    catch (char* const ex){
        //이 catch는 정수형 예외 처리 불가
    }

    return 0;
}

#endif

#if ON
#include <iostream>
#include <exception>
using namespace std;

class MyException : public exception {
    int myValue;
public:
    MyException(int value){
        myValue = value;
    }
    virtual const char * what() const throw()
    {
        if (myValue<10)
            return "10 이상의 값을 입력하세요";
        else if (myValue>20)
            return "20 이하의 값을 입력하세요";
        else if (myValue % 7 != 0)
            return "7의 배수 값을 입력하세요";
        return "잘못된 예외전달";
    }
};

int getMultiple(){
    int value;
    cout << "10과 20 사이 7의 배수를 입력하세요: ";
    cin >> value;
    if (value < 10 || value > 20 || value%7 !=0)
        throw MyException(value);
    return value;
}
int getValue(){
    int value;
    value = getMultiple();
    return value;
}
int main(void){
    int value;
    try{
        value = getValue();
        cout << "정답! 10과 20사이 7의 배수는 " << value << " 입니다" << endl;
    } catch (exception &e){
        cout << e.what() << endl;

    }

    return 0;
}

#endif
