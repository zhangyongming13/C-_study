// 使用using
class Derived : public Base {
public:
    // 让Base class内名为mf1和mf3的所有函数在Derived作用域中都可见并且public
    using Base::mf1;
    using Base::mf3;
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

//使用转交函数forwarding function
class Derived : public Base {
public:
    // 将Base父类中的所有名称为mf1的函数都遮掩掉了（包含mf1(int)）
    virtual void mf1()
    {
        cout << "I derived mf1" << endl;
        // 通过转交函数调用父类的mf1()
        Base::mf1();
    }

    // 将Base分类中的所有名称为mf3的函数都遮掩掉了
    void mf3()
    {
        cout << "I derived mf3" << endl;
        // 通过转交函数调用父类的mf3()
        Base::mf3();
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
    derived.mf1(x); // 现在没有问题了，调用的是Base::mf1(int)
    derived.mf2(); // 正确，调用的是Base::mf2()
    derived.mf3(); // 正确，调用的是Derived::mf3()
    derived.mf3(x); // 现在没有问题了，调用的是Base::mf3(double)

    return 0;
}