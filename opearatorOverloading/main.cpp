#define ON 1
#define OFF 0

#if OFF
#include <iostream>
using namespace std;

class Minho{
private:
    int age;

public:
    Minho(int age) : age(age) {
        cout << "Minho::Minho(age) 생성자 완료" << endl;
    }

    void introduce(){
        cout << "Minho age: " << age << endl;
    }

    Minho operator+(const Minho& minhoOb);
    Minho operator-(const Minho& minhoOb);
    Minho operator*(const Minho& minhoOb);
    Minho operator/(const Minho& minhoOb);

};

int main()
{
    Minho minho1 (30);
    Minho minho2 (15);
    minho1.introduce();
    minho2.introduce();

    Minho minhoAdd = minho1 + minho2;
    minhoAdd.introduce();

    // Minho minhoSub = minho1 - minho2;
    // minhoSub.introduce();

    // Minho minhoMul = minho1 * minho2;
    // minhoMul.introduce();

    // Minho minhoDiv = minho1 / minho2;
    // minhoDiv.introduce();


    return 0;
}

Minho Minho::operator+(const Minho & minhoObj){
    cout << "Minho::operator+()" << endl;
    Minho minho(this->age + minhoObj.age);
    return minho;
}
#endif

#if OFF /* 연산자 오버로딩 / 일반 전역함수 */
#include <iostream>
using namespace std;

class Min{
private:
    int age;
public:
    Min(int age) : age(age){
        cout << "Min::Min(age) 생성자 완료" << endl;
    }

    void introduce(){
        cout << "민호 나이: " << age << endl;
    }

    friend Min operator+(const Min& minObj1, const Min& minObj2);
};

int main(void){
    Min min1(30);
    Min min2(15);
    min1.introduce();
    min2.introduce();

    Min minAdd = 3 + min1;
    minAdd.introduce();
    return 0;
}

Min operator+ (const Min& minObj1, const Min& minObj2){
    cout << "operator+()" << endl;
    Min min(minObj1.age + minObj2.age);
    return min;
}
#endif

#if OFF
#include <iostream>
using namespace std;

class Point{
private:
    int xpos, ypos;
public:
    Point (int x =0, int y = 0) : xpos(x), ypos(y){}
    void showPosition() const
    {
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }
    Point& operator++(){
        xpos +=1;
        ypos +=1;
        return *this;
    }

    friend Point& operator--(Point &ref);

};

Point& operator--(Point &ref){
    ref.xpos -= 1;
    ref.ypos -= 1;
    return ref;
}

int main(void){
    Point pos (1,2);
    ++pos;
    pos.showPosition();
    --pos;
    pos.showPosition();
    ++(++pos);
    pos.showPosition();
    --(--pos);
    pos.showPosition();
    return 0;
}
#endif
