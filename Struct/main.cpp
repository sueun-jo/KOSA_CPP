#include <iostream>
using namespace std;

#define NAME_LEN 20
#define SEX_LEN 10
#define JOB_LEN 20
#define CHARACTER_LEN 20

#define ON 1
#define OFF 0

#if OFF
struct Chulsoo{
    char name [NAME_LEN];
    char sex [SEX_LEN];
    char job [JOB_LEN];
    char character [CHARACTER_LEN];
    int age;
    void introduce(){}
    void eat(char* food){}
    void sleep(){}
    void drive (char* destination){}
};

int main(void){
    Chulsoo chulsoo = {"철수", "남성", "작가", "diligent", 32};

    chulsoo.drive("레스토랑");
    chulsoo.eat("스테이크");
    return 0;
}

#endif

#if ON
class Chulsoo
{
public:
    char name[NAME_LEN];
    char sex[SEX_LEN];
    char job[JOB_LEN];
    char character[CHARACTER_LEN];
    int age;
    void introduce(){};
    void eat(char food){};
    void sleep(){};
    void drive(char destination){};

};


int main(void)
{
    Chulsoo chulsoo ={"철수", "남성", "작가", "diligent", 32};
    chulsoo.drive((char)"레스토랑");
    chulsoo.eat((char)"스테이크");
    return 0;
}
#endif
