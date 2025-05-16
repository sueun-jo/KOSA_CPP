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

#if OFF
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

#if ON
//람다를 이용한 정렬
#include <iostream>
#include <algorithm> //sort함수 쓸거임
#include <vector>
using namespace std;

class Multiplier {
    int first;
    int second;
public:
    Multiplier (int f, int s){
        first = f;
        second = s;
    }

    int getResult()
    { return first * second; }
};

int main(){
    vector <Multiplier> multipleData; //vector multipleData 선언

    for (int i=0; i<10; i++){
        Multiplier multiple = Multiplier(rand ()%10, rand()%10);
        multipleData.push_back(multiple);
    }

    cout << "정렬되지 않은 결과" << endl;
    for (auto i= multipleData.begin(); i!=multipleData.end(); i++){
        cout << i->getResult() << endl;
    }

    sort(multipleData.begin(), multipleData.end(), [](Multiplier& m1, Multiplier& m2)
         { return m1.getResult() < m2.getResult(); });

    cout << "정렬 결과" << endl;

    for (auto k = multipleData.begin(); k!= multipleData.end(); k++)
        cout << k->getResult() << endl;

    return 0;
}



#endif
