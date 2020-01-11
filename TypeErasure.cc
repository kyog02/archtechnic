#include<iostream>
#include<vector>

using namespace std;

/***************************************************
 * TypeErasure(型消去技法)
 * テンプレートクラスだと、vectorなどリスト化することができない。
 * TypeErasureを使えば、何でも格納できる型を作成できる。
 ***************************************************/



/**
 * インターフェイス
 * 
 */
class holder
{
public:
    virtual void f() = 0;
};

class A {
public:
  void f() { cout << "A!" << endl; }
};
class B {
public:
  void f() { cout << "B!" << endl; }
};


/**
 *  テンプレートクラス
 *  
 */
template<typename T>
class holder_sub : public holder {
public:
  holder_sub(const T& obj) : m_obj(obj) {}

  virtual void f() { m_obj.f(); }

  T m_obj;
};

/**
 *  Type Erasureクラス
 *  
 */
class anyf
{
public:
  template<typename T> anyf(const T& a) { m_p.reset(new holder_sub<T>(a)); }

  void f() { m_p->f(); }

  shared_ptr<holder> m_p;
};


int main()
{
    vector<anyf> objs;
    objs.push_back(A());
    objs.push_back(B());

    for (size_t i = 0; i < objs.size(); ++i) {
    objs[i].f();
    }

}