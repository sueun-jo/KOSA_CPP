#define ON 1
#define OFF 0

#if OFF
#include <iostream>
using namespace std;

class Sueun{
private:
    int age;
public:
    Sueun (int age) : age(age)
    {
        cout << "Sueun::Sueun() 생성자" << endl;
    }

    Sueun (){
        cout << "Sueun::Sueun() 생성자2" << endl;
    }

    ~Sueun(){
        cout << "Sueun::~Sueun() 소멸자" << endl;
    }

    void setAge(int age){
        this->age = age;
    }
    void introduce();
};

int main()
{
    // Sueun * sueunptr1 = (Sueun *)malloc(sizeof(Sueun));

    Sueun * sueunptr1 = new Sueun(26);

    // sueunptr1->setAge(26);
    sueunptr1->introduce();
    delete sueunptr1;

   // free(sueunptr1);

    return 0;
}

void Sueun::introduce(){
    cout << "수은짱 나이 " << age << endl;
}
#endif

#if ON

#include <iostream>

using namespace std;

class Point {
private:
    int xpos, ypos;
public:
    Point(int x=0, int y=0) : xpos(x), ypos(y) {  }
    friend ostream& operator<<(ostream& os, const Point& pos);
};

ostream& operator<<(ostream& os, const Point& pos)
{
    os<<'['<<pos.xpos<<", "<<pos.ypos<<']'<<endl;
    return os;
}

class BoundCheckPointArray {
private:
    Point *arr;
    int arrlen;

    BoundCheckPointArray(const BoundCheckPointArray& arr) { }
    BoundCheckPointArray& operator=(const BoundCheckPointArray& arr) { return *this; }

public:
    BoundCheckPointArray(int len) :arrlen(len) {
        arr = new Point[len];
    }

    Point& operator[] (int idx) {
        if(idx<0 || idx>=arrlen) {
            cout<<"Array index out of bound exception"<<endl;
            exit(1);
        }

        return arr[idx];
    }

    Point operator[] (int idx) const {
        if(idx<0 || idx>=arrlen) {
            cout<<"Array index out of bound exception"<<endl;
            exit(1);
        }

        return arr[idx];
    }

    int GetArrLen() const {
        return arrlen;
    }

    ~BoundCheckPointArray() {
        delete []arr;
    }
};

int main(void)
{
    BoundCheckPointArray arr(3);
    arr[0]=Point(3, 4);
    arr[1]=Point(5, 6);
    arr[2]=Point(7, 8);

    for(int i=0; i<arr.GetArrLen(); i++)
        cout<<arr[i];

    return 0;
}
#endif

