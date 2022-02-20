#include <iostream>

using namespace std;

class Base
{
public:
    Base() = default;
    virtual ~Base() = default;

    virtual void PrintInfo()
    {
        cout << "I am base!" << endl;
    }
};

class Derived : public Base
{
public:
    Derived() = default;
    ~Derived() override = default;

    void PrintInfo() override
    {
        cout << "I am derived!" << endl;
    }
};

// static_cast强制类型转换示例
void StaticCast()
{
    // 基本类型的强制转换
    char a = 'a';
    int b = static_cast<int>(a);
    cout << b << endl;

    // 将double指针转换成void指针
    auto *c = new double;
    void *d = static_cast<void*>(c);

    // 将int类型转换成const int类型
    int e = 100;
    const int f = static_cast<const int>(e);
    cout << f << endl;

    // 编译错误，static_cast不能转换掉const属性
    // const int g = 200;
    // int *h = static_cast<int *>(g);

    // 派生类指针static_cast强制转换成基类指针，这个是安全的
    auto *pDerived1 = new Derived();
    Base *pBase1 = static_cast<Base*>(pDerived1);
    pBase1->PrintInfo();

    // 基类指针转换成派生类指针，虽然是可以转换的，但是是不安全的
    auto *pBase2 = new Base();
    Derived *pDerived2 = static_cast<Derived*>(pBase2);
    pDerived2->PrintInfo();
}

// dynamic_cast强制类型转换
void DynamicCast()
{
    // 进行上行转换（派生类转基类）
    auto *pDerived1 = new Derived();
    Base *pBase1 = dynamic_cast<Base*>(pDerived1);
    pBase1->PrintInfo();

    // 进行下行转换（基类转派生类，不建议这样转换，可能存在问题），比如下面的转换就失败了
    auto *pBase2 = new Base();
    auto *pDerived2 = dynamic_cast<Derived*>(pBase2);
    if (pDerived2 == nullptr) {
        cout << "Dynamic cast failed!" << endl;
    } else {
        pDerived2->PrintInfo();
    }
}

void ConstCast()
{
    const int a = 56;
    const int *b = &a;
    // 这里通告const_cast转换去掉了原来常量指针中的指针, 需要注意的是常量a的值并没有被修改
    int *c = const_cast<int*>(b);
    *c = 80;
    cout << "The new value is " << *c << endl;

    const char *d = "hello";
    char *e = const_cast<char*>(d);
}

unsigned short Hash(void *p)
{
    unsigned long val = reinterpret_cast<unsigned long>(p);
    return (unsigned short )(val ^ (val >> 16));
}

void ReinterpretCast()
{
    // 将指针类型转换为算术类型
    char a = 'm';
    unsigned long b = reinterpret_cast<unsigned long>(&a);
    cout << b << endl;
    // 再将算术类型转换回指针类型，该指针依然可以得到原来的值
    char *d = reinterpret_cast<char*>(b);
    cout << *d << endl;

    int c[2];
    for (int i = 0; i < 2; ++i) {
        cout << Hash(c + i) << endl;
    }
}

class A {
public:
    int mA;
};

class B {
public:
    int mB;
};

class C : public A, public B {};

void DiffBetweenReinterpretStatic()
{
    C c;
    auto pB1 = reinterpret_cast<B*>(&c);
    auto pB2 = static_cast<B*>(&c);
    cout << &c << endl;
    cout << "Reinterpret cast : " << pB1 << endl;
    cout << "static cast : " << pB2 << endl;

    // 这里看起来是修改了mB的值，但是实际上修改的却是mA的值，因为reinterpret_cast并没有偏移mA的地址导致的
    pB1->mB = 100;
    cout << c.mB << endl;
    // 这里修改的就是mB的值，因为static_cast计算了mA的地址然后进行了偏移
    pB2->mB = 101;
    cout << c.mB << endl;
}

int main()
{
    cout << "Enter static cast..." << endl;
    StaticCast();
    cout << "Enter Dynamic cast..." << endl;
    DynamicCast();
    cout << "Enter const cast..." << endl;
    ConstCast();
    cout << "Enter reinterpret cast..." << endl;
    ReinterpretCast();
    cout << "Enter DiffBetweenReinterpretStatic..." << endl;
    DiffBetweenReinterpretStatic();
}
