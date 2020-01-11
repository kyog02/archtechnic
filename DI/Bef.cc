#include<iostream>
using namespace std;

/**
 * 上位モジュールが下位モジュールに依存している場合
 * 
 * 
 * 
 */

// 下位モジュール
class A
{
public:
    void write()
    {
        cout << "a" << endl;
    }
};

class B
{
    A a;
public:
    void writesample()
    {
        a.write();
    }
};

/*********************************/
int main()
{
    B b;
    b.writesample();
}