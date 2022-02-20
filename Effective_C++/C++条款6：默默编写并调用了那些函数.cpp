#include <string>
#include <iostream>

using namespace std;

template<typename T1>
class NameObject1 {
public:
    // 已定义了构造函数，编译器不会再自动生成默认构造函数
    NameObject1(const char *name, const T1 &value)
    {
        this->nameValue = name;
        this->objectValue = value;
    }

    // 已定义了copy assignment拷贝赋值操作符，编译器不会再自动生成
    NameObject1 &operator=(const NameObject1<T1> &rhs)
    {
        this->nameValue = rhs.nameValue;
        this->objectValue = rhs.objectValue;

        return *this;
    }

public:
    string nameValue;
    T1 objectValue;
};

void DefaultFuncTest()
{
    // 调用已经定义的构造函数
    NameObject1<int> no1("Test no 1", 1);
    // 调用已经定义的copy assignment拷贝赋值操作符
    NameObject1<int> no2 = no1;
    // 调用编译器默认生成的拷贝构造函数
    NameObject1<int> no3(no2);

    cout << no1.nameValue << endl;
    cout << no2.nameValue << endl;
    cout << no3.nameValue << endl;
}

template<typename T2>
class NameObject2 {
public:
    // 这里构造函数name不能是一个const类型，因为成员变量nameValue是一个引用
    // reference to non const string
    NameObject2(string &name, const T2 &value);

public:
    // 需要注意这里是一个引用类型
    string &nameValue;
    T2 objectValue;
};

class UnCopyAble {
public:
    UnCopyAble() = default;

private:
    // 将拷贝构造函数以及copy assignment拷贝操作符声明但不实现以阻止编译器自动生成对应的内容
    UnCopyAble(const UnCopyAble&);
    UnCopyAble &operator=(const UnCopyAble&);
};

void RefuseGenCopyAssignment()
{
    string newDog("Persephone");
    string oldDog("Satch");
    NameObject2<int> p(newDog, 3);
    NameObject2<int> s(oldDog, 36);

    // 这里这一句会报错
    // p = s;
}

int main()
{
    DefaultFuncTest();

    RefuseGenCopyAssignment();

    return 0;
}
