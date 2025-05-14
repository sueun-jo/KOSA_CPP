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
