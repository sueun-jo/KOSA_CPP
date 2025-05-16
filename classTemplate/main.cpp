#define ON 1
#define OFF 0
#if OFF
/*class Template 예제*/
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class MyArray{
private:
    vector<T> list;
public:
    void add_list(T const&);
    void delete_last_list(void);
    void show_list(void);
};

template <typename T>
void MyArray<T>::add_list(T const& element){
    list.push_back(element);
}
template <typename T>
void MyArray<T>::delete_last_list(void){
    list.pop_back();
}

template <typename T>
void MyArray<T>::show_list(void){
    cout << "[MyArray list look up]" << endl;
    for (typename vector<T>::iterator i= list.begin(); i!=list.end(); ++i)
        cout << *i << endl;
}
int main()
{
    MyArray<int> array1;
    array1.add_list(1);
    array1.add_list(2);
    array1.add_list(3);
    array1.add_list(4);
    array1.add_list(5);
    array1.show_list();

    array1.delete_last_list();
    array1.delete_last_list();
    array1.show_list();

    MyArray<double> array2;
    array2.add_list(1.1);
    array2.add_list(2.2);
    array2.add_list(3.3);
    array2.add_list(4.4);
    array2.add_list(5.5);
    array2.show_list();
    array2.delete_last_list();
    array2.delete_last_list();

    array2.show_list();
    return 0;
}
#endif

#if OFF
/* 템플릿 파라미터 */

#include <iostream>
#include <vector>
using namespace std;

template <typename T, int init /* = 3*/> // template <typename T = int>
class MyArray{
private:
    vector<T> list;
public:
    MyArray(){
        for (int i=0; i<init; ++i)
            list.push_back(i);
    }
    void add_list(T const&);
    void delete_last_list(void);
    void show_list(void);
};

template <typename T, int init>
void MyArray<T, init>::add_list(T const& element){
    list.push_back(element);
}
template <typename T, int init>
void MyArray<T, init>::delete_last_list(void){
    list.pop_back();
}

template <typename T, int init>
void MyArray<T, init>::show_list(void){
    cout << "[MyArray list look up]" << endl;
    for (typename vector<T>::iterator i= list.begin(); i!=list.end(); ++i)
        cout << *i << endl;
}

int main(){
    MyArray<int, 3> array1;
    array1.add_list(1);
    array1.add_list(2);
    array1.add_list(3);
    array1.add_list(4);
    array1.add_list(5);
    array1.show_list();

    array1.delete_last_list();
    array1.delete_last_list();
    array1.show_list();

    MyArray<double, 4> array2;
    array2.add_list(1.1);
    array2.add_list(2.2);
    array2.add_list(3.3);
    array2.add_list(4.4);
    array2.add_list(5.5);
    array2.show_list();
    array2.delete_last_list();
    array2.delete_last_list();

    array2.show_list();
    return 0;
}
#endif

#if ON /* 클래스 템플릿의 특수화 예제*/
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class MyArray{
private:
    vector<T> list;
public:
    void add_list(T const&);
    void delete_last_list(void);
    void show_list(void);
};

template <typename T>
void MyArray<T>::add_list(T const& element){
    list.push_back(element);
}

template <typename T>
void MyArray<T>::delete_last_list(void){
    list.pop_back();
}

template <typename T>
void MyArray<T> :: show_list(void){
    cout << "[MyArray list look up]" << endl;
    for (typename vector<T>::iterator i=list.begin(); i!=list.end(); ++i)
        cout << *i << endl;
}

template <>
class MyArray<int>{
private:
    vector<int> list;
public:
    void add_list(int const&);
    void delete_last_list(void);
    void show_list(void);
};

void MyArray<int>::add_list(int const& element){
    list.push_back(element);
}
void MyArray<int>::delete_last_list(void){
    list.pop_back();
}
void MyArray<int>::show_list(void){
    cout << "[MyArray list look up (specialization for int)]" << endl;
    for (vector<int>::iterator i=list.begin(); i!=list.end(); ++i)
        cout << *i << endl;
}

int main(){
    MyArray<int> array1;
    array1.add_list(1);
    array1.add_list(2);
    array1.add_list(3);
    array1.add_list(4);
    array1.add_list(5);
    array1.show_list();

    array1.delete_last_list();
    array1.delete_last_list();
    array1.show_list();

    MyArray<double> array2;
    array2.add_list(1.1);
    array2.add_list(2.2);
    array2.add_list(3.3);
    array2.add_list(4.4);
    array2.add_list(5.5);
    array2.show_list();

    array2.delete_last_list();
    array2.delete_last_list();
    array2.show_list();

    return 0;
}
#endif
