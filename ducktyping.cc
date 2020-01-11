#include<iostream>
#include<vector>
using namespace std;


/***************************************
 * ダックタイピング
 * ダックタイピングという手法は、
 * 継承とかしなくても、同じインターフェースを持ってるものならなんでも処理するということ 
 ***************************************/ 

/***
 * テンプレート関数
 * この場合、sound()を持つクラスなら、継承とかなくても、どんなクラスでも受け取ることができる。
 */
template <class Animal>
void AnimalSound(const Animal& animal)
{
    animal.sound();
}

/***
 * sound()を持つクラス1
 */
class Duck
{
public:
    void sound () const { cout << "kwah kwah!" << endl;}
};

/***
 * sound()を持つクラス2
 */
class Dog
{
public:
    void sound() const { cout << "wan wan!" << endl;}
};

/******************************************************
 * テンプレートクラス
 */


class BaseObj
{
    void func(){}
};

class DerivObj: public Baseobj
{
    void func2(){}
};

template <class Obj> class Array {
  Obj* Get(int index) { return objList[index]; }
  void Set(Obj* obj){ objList.push_back(obj); }
  vector<Obj*> objList;
};

// テンプレートのインスタンス化
template class Array<BaseObj>;
template class Array<DerivObj>;

// Get()とSet()の処理を流用できる。
// BaseArrayはBaseObjの配列になっている。
class BaseArray : public Array<BaseObj> {};

// DerivArrayはDerivObjの配列になっている。
class DerivArray: public Array<DerivObj>{};

/*******************************************************/
int main()
{
    // テンプレート関数の使い方
    AnimalSound( Duck() );
    AnimalSound( Dog() );

    // テンプレートクラスの使い方

    return 0;
}