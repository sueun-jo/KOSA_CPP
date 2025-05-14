#include <iostream>
#include <string>

using namespace std;

Class Sueun{
private:
    char * name;
    int age;

public:
    Sueun (const char * myname, int myage){
        this->name = new char[strlen(myname)+1];
        strcpy(this->name, name);

        age = myage;
    }
    Sueun(){
        cout << "Sueun :: Sueun() 생성자 완료" << endl;
    }

    void ShowPersonInfo () const
    {
        cout << "name: " << name << endl;
        cout << "age: " << age << endl;
    }
    ~Sueun(){ //소멸자
        delete []name;
        cout << "called destructor!" << endl;
    }
};

int main()
{
#if 1
    const char sueun[] = "Sueun";
    Sueun sueun(sueun);
#else

#endif
    sueun.ShowPersonInfo();
    return 0;
}
