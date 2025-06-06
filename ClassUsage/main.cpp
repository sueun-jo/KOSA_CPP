#include <iostream>
#include <string>
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

    void constructor (const char* name, const char* sex, const char* job, const char* character, int age, bool marriage){
        strcpy_s(this->name, name);
        strcpy_s(this->sex, sex);
        strcpy_s(this->job, job);
        strcpy_s(this->character, character);
        this->age = age;
        this->marriage = marriage;
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

    void constructor (const char* name,const char* sex,const char* job,const char* character, int age, bool marriage){
        strcpy_s(this->name, name);
        strcpy_s(this->sex, sex);
        strcpy_s(this->job, job);
        strcpy_s(this->character, character);
        this->age = age;
        this->marriage = marriage;
    }
};


int main()
{
    Minho minho;
    Sueun sueun;
    minho.constructor ("minho", "male", "engineer", "diligent", 33, true);
    sueun.constructor("sueun", "female", "developer", "responsible", 26, true);

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

    return 0;
}
