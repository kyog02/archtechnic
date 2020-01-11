#include <iostream>


/**
 * 共変性の書き方
 * 戻り値の型がクラス型の参照かポインタで、かつis-a関係にあるものは、戻り値が異なっていてもオーバーライド可能
 * 共変型に対してオーバーライドのルールが緩和される為、純粋仮想関数による子クラスへの関数定義の強制のメリットと実際に取得する型が親クラスに引っ張られないメリットを享受できる
 * 自分自身の型を返す関数を定義する時など、親クラス固定だと、受け取った側でのキャストが面倒だったりする
 * 
 */


// Shapeを定義
struct Shape {
    void print() {
        printf("shape");
    }
};
// Shapeから継承したBoxを定義
struct Box : public Shape {
    void print() {
        printf("box");
    }
};
 
 
struct Base {
    virtual ~Base(){}
    virtual Shape* get() = 0;
};
 
struct Derived : public Base {
    // 純粋仮想関数getをオーバーライドしてBox*を返す
    // 基底クラスと戻り値の型が違うけど共変型なのでOK
    Box* get() override {
        return new Box();
    }
};
 
int main() {
    Base* b = new Derived; // Derived生成
    auto a = b->get();     // ポリモーフィックにget()を呼び出す
    a->print();            // Boxって表示されるかな？
    delete b;
    return 0;   
}