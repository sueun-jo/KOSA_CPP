#define ON 1
#define OFF 0

#if OFF
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
#endif

#if OFF
#include <iostream>
#include <queue>
using namespace std;

int main(){
    priority_queue<int> pq;
    priority_queue<int, vector<int>, greater<int>> pq2;
    priority_queue<int, deque<int>, greater<int>> pq3;

    pq.push(10);
    pq.push(20);
    pq.push(30);
    pq.push(40);
    pq.push(40);
    pq.push(10);
    pq.push(20);

    while (!pq.empty()){
        cout << pq.top() << " ";
        pq2.push(pq.top());
        pq.pop();
    }
    cout << endl;

    while (!pq2.empty()){
        cout << pq2. top() << " ";
        pq3.push(pq2.top());
        pq2.pop();
    }

    cout << endl;

    while (!pq3.empty()){
        cout << pq3.top() << " ";
        pq3.pop();
    }

    cout << endl;
    return 0;
}
#endif

#if OFF /* stack ex */

#include <iostream>
#include <stack>

using namespace std;

int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}
#endif

#if OFF /* map 실습 */
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(void){

    map<string, int> m; //string - key, int - value
    m.insert(make_pair("A", 10));
    m.insert(make_pair("B", 20));
    m.insert(make_pair("C", 30));
    m.insert(make_pair("D", 40));
    m.insert(make_pair("E", 50));
    m["F"] = 100;

    for (auto i = m.begin(); i!=m.end(); i++){
        cout << "[" << i->first << " " << i->second << "]";
    }
    cout << endl;
    auto i = m.find("A");
    cout << i->first << " : " << i->second << endl;
    m.insert(make_pair("E", 150));

    for (auto i = m.begin(); i!=m.end(); i++){
        cout << "[" << i->first << " " << i->second << "]";
    }
    return 0;
}
#endif

#if OFF /* set Ex */
#include <iostream>
#include <set>
using namespace std;

int main(void){

    set<int> s;
    pair<set<int>::iterator, bool> pr;

    s.insert(10);
    s.insert(30);
    s.insert(60);
    s.insert(20);
    s.insert(50);
    pr = s.insert(40);

    for (auto i = s.begin(); i != s.end(); i++)
        cout << *i << " ";
    cout << endl;

    s.insert(pr.first, 55);

    for (auto i = s.begin(); i != s.end(); i++)
        cout << *i << " ";
    cout << endl;

    auto f = s.find(55);
    if (f != s.end()){
        cout << *f << endl;
    }
    return 0;
}
#endif

#if OFF
#include <iostream>
#include <set>
using namespace std;


int main(void){

    multiset<int> ms;
    multiset<int>::iterator ms_iter;
    ms.insert(10);
    ms.insert(30);
    ms.insert(60);
    ms.insert(20);
    ms.insert(50);
    ms.insert(40);
    ms_iter = ms.insert(40);

    for (auto i = ms.begin(); i != ms.end(); i++)
        cout << *i << " ";
    cout << endl;

    cout << "40 개수: " << ms.count(40) << endl;
    auto f = ms.find(40);

    if (f != ms.end()){
        cout << *f << endl;
    }

    return 0;
}
#endif

#if OFF /* 비순차 연관 컨테이너 예제 - unordered map */
#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    unordered_map<string, int> um;
    um.insert({"A", 100});
    um.insert(make_pair("B", 200));

    um.insert({
        {"C", 1000},
        {"D", 2000}
    });

    for (auto i = um.begin(); i != um.end(); i++)
        cout << "[" << i->first << " " << i->second << "]";
    cout << endl;

    cout <<"find B" << endl;
    auto bc = um.bucket("B");

    for (auto i = um.begin(bc); i != um.end(bc); i++)
        cout << i->first << ": " << i->second;
    cout << endl;

    return 0;
}

#endif

#if ON
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int arr[10] = {97, 44, 23, 55, 61, 12, 3, 75, 27, 84};
    cout << "정렬된 배열: ";

    sort(arr, arr+10);
    for (int i=0; i<10; i++)
        cout << arr[i] << " ";
    cout << endl;

    vector <string> strings;
    string s;
    cout << "문자열을 입력하세요 : ";
    while(cin >> s)
        strings.push_back(s);

    sort(strings.begin(), strings.end());
    cout << "정렬된 문자열: ";
    for (vector<string>::iterator it= strings.begin(); it != strings.end(); it++)
        cout << *it << " ";
    cout << endl;

    return 0;
}



#endif
