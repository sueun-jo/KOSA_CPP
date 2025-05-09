#include <iostream>
using namespace std;

class Minho{
public:
    void Eat();
}; //세미콜론 빼먹지 마시오

void Minho::Eat(){
    cout << "민호는 먹는다" <<endl;
}

int main()
{
    Minho minho;
    minho.Eat();

    return 0;
}
