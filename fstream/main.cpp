
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

#if ON

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
