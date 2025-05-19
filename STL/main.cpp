#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    int qsize = q.size();
    for (int i=0; i < qsize; i++){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;


    return 0;
}
