#include <memory>
#include <iostream>

using namespace std;

class Base {
public:
    virtual void mf1() = 0;
    virtual void mf1(int)
    {
        cout << "I base mf1 with int" << endl;
    }

    virtual void mf2()
    {
        cout << "I base mf2" << endl;
    }

    void mf3()
    {
        cout << "I base mf3" << endl;
    }

    void mf3(double)
    {
        cout << "I base mf3 with double" << endl;
    }

private:
    int x;
};

class Derived : public Base {
public:
    // 将Base父类中的所有名称为mf1的函数都遮掩掉了（包含mf1(int)）
    virtual void mf1()
    {
        cout << "I derived mf1" << endl;
    }

    // 将Base分类中的所有名称为mf3的函数都遮掩掉了
    void mf3()
    {
        cout << "I derived mf3" << endl;
    }

    void mf4()
    {
        cout << "I derived mf4" << endl;
    }
};

int main()
{
    Derived derived;
    int x;
    derived.mf1(); // 正确，调用的是Derived::mf1()
//    derived.mf1(x); // 错误，因为Base::mf1(int)已经被Derived::mf1()遮掩了
    derived.mf2(); // 正确，调用的是Base::mf2()
    derived.mf3(); // 正确，调用的是Derived::mf3()
//    derived.mf3(x); // 错误，因为Base::mf3(double)已经被Derived::mf3()遮掩了

    return 0;
}