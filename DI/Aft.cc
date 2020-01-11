#include<iostream>

#include "interface.h"

using namespace std;

/**
 * 上位モジュールが下位モジュールに依存していない場合
 * 依存性反転の原則
 * 
 * 
 */

// 下位モジュール
class A : public IclassA
{
public:
    virtual void write()
    {
        cout << "a" << endl;
    }
};

// 上位モジュール1
class B
{
    IclassA& a;
public:
    B(IclassA& aImpl)
    :a(aImpl){}

    void writesample()
    {
        a.write();
    }
};

// 上位モジュール2
// 動的
// 仮想関数のオーバーヘッドが存在するが、柔軟性あり
// 1つのメソッドでしか使用しない場合、コンストラクタで注入する必要はない。
class C
{
public:
    void writesample(IclassA& a)
    {
        a.write();
    }
};

// 上位モジュール3
// 静的
// 速度はこちらのほうが早い
// 柔軟性はない
class D
{
public:
    template<class A>
    void writesample(A& a)
    {
        a.write();
    }
};

/*********************************/
int main()
{
    A a;
    B b(a);
    b.writesample();

    C c;
    c.writesample(a);

    D d;
    d.writesample<A>(a);   
}