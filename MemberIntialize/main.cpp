#include <iostream>
using namespace std;

#define NAME_LEN 20
#define SEX_LEN 10
#define JOB_LEN 20
#define CHARACTER_LEN 20

class Minho{
private:
    char name[NAME_LEN];
    char sex[SEX_LEN];
    char job[JOB_LEN];
    char character[CHARACTER_LEN];
    int age;
    bool marriage;

public:
    void introduce(){
        cout << "name " << name << endl;
        cout << "gender " << sex <<endl;
        cout << "job " << job << endl;
        cout << "character " << character << endl;
        cout << "age " << age << endl;
        cout << "marriage? " << (marriage? "YES" : "NO") << endl;
    }

    void eat(const char* food){cout << "Minho eats " << food << endl;}
    void sleep(){ cout << "Minho sleeps" << endl; }
    void drive (const char* destination){cout << "Minho drives to" << destination << endl; }
    void write (){ cout << "Minho writes a book" << endl;}
    void read(){ cout << "Minho reads a book" << endl; }


    Minho(const char* name, const char* sex, const char* job, const char* character, int age, bool marriage){
        cout << "Minho::Minho() 생성자 시작" << endl;
        strcpy_s(this->name, name);
        strcpy_s(this->sex, sex);
        strcpy_s(this->job, job);
        strcpy_s(this->character, character);
        this->age = age;
        this->marriage = marriage;
        cout << "Minho::Minho() 생성자 완료" <<endl;
    }
    Minho(){
        cout << "Minho::Minho() 생성자 완료" <<endl;
    }
};

class Sueun{
private:
    char name[NAME_LEN];
    char sex[SEX_LEN];
    char job[JOB_LEN];
    char character[CHARACTER_LEN];
    int age;
    bool marriage;

public:
    void introduce(){
        cout << "name " << name << endl;
        cout << "gender " << sex <<endl;
        cout << "job " << job << endl;
        cout << "character " << character << endl;
        cout << "age " << age << endl;
        cout << "marriage? " << (marriage? "YES" : "NO") << endl;
    }

    void eat(const char* food){cout << "Sueun eats " << food << endl;}
    void sleep(){ cout << "Sueun sleeps" << endl; }
    void shopping (){ cout << "sueun does shopping" << endl;}

    Sueun (const char* name,const char* sex,const char* job,const char* character, int age, bool marriage){
        cout << "Sueun::Sueun() 생성자 시작" << endl;
        strcpy_s(this->name, name);
        strcpy_s(this->sex, sex);
        strcpy_s(this->job, job);
        strcpy_s(this->character, character);
        this->age = age;
        this->marriage = marriage;
        cout << "Sueun::Sueun() 생성자 완료" << endl;
    }
    Sueun(){
        cout << "Sueun :: Sueun() 생성자 완료" << endl;
    }
};

class DailyLife{

private:
    Minho minho; //객체를 private member로 가진다
    Sueun sueun; //객체를 private member로 가진다

public:
    DailyLife(const char* minhoName, const char* minhoSex, const char* minhoJob, const char* minhoCharacter, int minhoAge, bool minhoMarriage
              ,const char* sueunName, const char* sueunSex, const char* sueunJob, const char* sueunCharacter, int sueunAge, bool sueunMarriage)
        :minho(minhoName, minhoSex, minhoJob, minhoCharacter, minhoAge, minhoMarriage),
        sueun (sueunName, sueunSex, sueunJob, sueunCharacter, sueunAge, sueunMarriage)
    {
        cout << "DSialyLife::DailyLife(minhoObject, sueunObject) 생성자 완료" << endl;
    }

    void run(){
        minho.drive("restaurant");
        minho.eat("steak");
        sueun.eat("steak");
        minho.drive("home");
        sueun.sleep();
        minho.write();
        minho.read();
        minho.sleep();

        cout << endl;
        minho.introduce();

        cout << endl;
        sueun.introduce();
    }
};

int main()
{
    Minho minho ("minho", "male", "engineer", "diligent", 33, true);
    Sueun sueun ("sueun", "female", "developer", "responsible", 26, true);
    DailyLife dailylife("minho", "male", "engineer", "diligent", 33, true,
                        "sueun", "female", "developer", "responsible", 26, true);
    dailylife.run();

    return 0;
}
