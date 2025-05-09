
#include <iostream>
using namespace std;

#define ON 1
#define OFF 0

#if OFF
#include <fstream>
#include <string>

int main()
{
    fstream fs;

    fs.open("text.txt", ios::out);
    if (fs.fail()) return 0;

    fs << "keyboard" << endl;
    fs << "monitor" << endl;

    fs.close();

    fs.open("test.txt", ios::out | ios::trunc);
    fs << "desk" << endl;
    fs.close();

    fs.open("test.txt", ios::in);
    string temp;

    while (fs >> temp, !fs.eof()){
        cout << temp << endl;
    }
    fs.close();
    return 0;
}

#endif

#if OFF

#include <iomanip>
#include <fstream>

int main(){
    fstream fp;
    int data, score[5] = {78, 96, 100, 25, 96};
    fp.open("sample.txt", ios::out | ios::binary);
    fp.write((char*)score,20); //score 위치에서 20바이트 출력
    fp.close();

    fp.open("sample.txt", ios::in | ios::binary);
    if (fp.fail()) return 1;

    fp.read((char*)&data, 4);
    cout << setw(3) << right << data << endl;

    fp.close();
    return 0;
}
#endif

#if OFF
//출력형식 지정자 예제
int main(void){
    int a = 123, b = 0x12345678;

    cout << hex << "16진수 a = " << a;
    cout << dec << "\t10진수 a = " << a << endl; //t는 들여쓰기
    cout << hex << "16진수 b = " << b;
    cout << dec << "\t10진수 b = " << b << endl;

    return 0;
}
#endif
#include <fstream>
int main (void){
    ofstream ofs;

    //file.txt를 연다 (없으면 생성)
    ofs.open("file.txt");

    //"this is an apple을 파일에 쓴다.
    ofs.write("This is an apple", 16);

    //tellp() 멤버 함수를 이용해 파일의 현재 위치를 얻는다
    //현재 위치는 This is an apple의 맨 끝일 것이다.

    long pos = ofs.tellp();

    //현재 위치에서 7만큼 위치를 뒤로 이동시킴
    //현재 위치를 앞뒤로 조정하는 것을  offset을 조정한다고 함
    //offset을 -7로 조정한 위치는 문자 'n'이다.

    ofs.seekp(pos-7);

    //조정한 위치부터 문자열 "sam"을 쓴다.
    ofs.write("sam", 4);

    //파일 닫는다
    ofs.close();

    return 0;
}
