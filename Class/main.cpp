#include <iostream>
using namespace std;

class Stack{
protected:
    int m_size;
    int m_top;
    int *m_buffer;
public:
    void Initialize (int size = 10);
    void RemoveAll();
    bool Push(int value);
    bool Pop(int& value);

    //접근자 함수
    int GetSize();
    int GetTop();
    bool SetSize(int size);
    bool GetData(int index, int& data);
};

void Stack::Initialize(int size){
    m_size = size;
    m_top = -1;
    m_buffer = new int[m_size]; //m_size만큼 buffer에 동적할당 해줌
    memset(m_buffer, 0, sizeof(int) * m_size); //m_buffer를 0으로 초기화해줌
}

void Stack::RemoveAll(){
    m_size = 0;
    m_top = -1;
    delete[] m_buffer;
    m_buffer = NULL;
}

bool Stack::Push(int value){
    if (m_top >= m_size -1) return false;
    m_buffer[++m_top] = value;
    return true;
}

bool Stack::Pop(int &value){
    if (m_top < 0) return false;
    value = m_buffer[m_top--];
    return true;
}

int Stack::GetSize(){
    return m_size;
}

int Stack::GetTop(){
    return m_top;
}

bool Stack::SetSize(int size){
    if(size < m_size) return false;
    int* tmp = m_buffer;
    m_size = size;
    m_buffer = new int[m_size];
    memcpy(m_buffer, tmp, sizeof(int)*(m_top)+1);
    delete [] tmp;
    return true;
}

bool Stack::GetData(int index, int& data){
    if (index<0 || index>m_top) return false;
    data = m_buffer[index];
    return true;
}


int main()
{
    Stack s1;
    s1.Initialize(5);
    int data;
    s1.Pop(data);
    s1.Push(123);

    return 0;
}
