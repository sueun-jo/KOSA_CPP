#define ON 1
#define OFF 0
#if OFF
#include <iostream>
#include <vector>
using namespace std;

int main()
{

    vector<int> v(6,1);
    cout<< "v.capacity(): " << v.capacity() << " / v.size(): " << v.size() << endl;
    for (auto i=0; i<v.size(); i++)
        cout << v[i] << " ";

    cout << endl << endl;

    v.assign(4,3);
    cout<< "v.capacity(): " << v.capacity() << " / v.size(): " << v.size() << endl;

    for (auto i=0; i< v.size(); i++)
        cout << v[i] << endl;

    v[2] = 7;
    for (vector<int>::iterator it = v.begin()+3; it != v.end(); it++)
        *it = 9;
    v.push_back(10);
    v.push_back(20);
    cout<< "v.capacity(): " << v.capacity() << " / v.size(): "  << v.size() << endl;
    for (auto i=0; i< v.size(); i++)
        cout << v[i] << " ";
    cout << endl << endl;

    v.push_back(30);
    cout<< "v.capacity(): " << v.capacity() << " / v.size(): " << v.size() << endl;
    for (auto i=0; i< v.size(); i++)
        cout << v[i] << " ";
    cout << endl << endl;

    v.resize(17);
    cout<< "v.capacity(): " << v.capacity() << " / v.size(): " << v.size() << endl;
    for (auto i=0; i< v.size(); i++)
        cout << v[i] << " ";
    cout << endl << endl;

    return 0;
}
#endif

#if ON
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Person{
private:
    int age;
    string name;

public:
    Person(const int a, const string& n): age(a), name(n){}

    int getAge(){return age;}
    string getName() {return name;}
};

int main(int argc, char **argv){
    //c++03
    Person p1 {20, "tom"};
    Person p2 {19, "jane"};

    //c++11유니폼 초기화
    vector<Person> vec {
        {21, "smith"}, {39, "john"}, {23, "mary"}, {45, "ted"}
    };

    for_each(vec.begin(), vec.end(), [](Person p){cout << p.getAge() << ", " << p.getName() << endl;} );

    return 0;
}

#endif
