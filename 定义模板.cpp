#include <iostream>
#include <cstring>
#include <vector>
#include <memory>
#include <string>

using namespace std;

template <typename T1>
T1 Compare1(const T1 &value1, const T1 &value2)
{
    if (value1 < value2) {
        return value2;
    }

    if (value2 < value1) {
        return value1;
    }

    return value1;
}

// 模板函数中多个参数不一致的情况
template <typename T2, typename T3>
bool Compare2(const T2 &value1, const T3 &value2)
{
    if (value1 < (value2 - 'a')) {
        return false;
    }

    if ((value2 - 'a') < value1) {
        return true;
    }

    return true;
}

// 非类型模板参数，这里的模板分别是数组的长度
template <unsigned int N, unsigned int M>
int Compare3(const char (&p1)[N], const char (&p2)[M])
{
    return strcmp(p1, p2);
}

void FuncTemplate()
{
    int value1 = 10;
    int value2 = 9;
    // 根据传进来的实参，编译时实例化成Compare(const int &value1, const int &value2)
    cout << Compare1(value1, value2) << endl;

    char value3 = 'a';
    char value4 = 'd';
    // 实例化成Compare(const char &value1, const char &value2)
    cout << Compare1(value3, value4) << endl;

    if (Compare2(value1, value3)) {
        cout << "Large" << endl;
    } else {
        cout << "Small" << endl;
    }

    // 非类型模板参数参数，这里在编译的时候会被实例化成这样：int Compare3(const char (&p1)[3], const char (&p2)[4])
    cout << Compare3("hi", "mom") << endl;
}

// 类模板
template <typename T5>
class Blob {
public:
    typedef T5 valueType;
    typedef typename vector<T5>::size_type sizeType;
    Blob()
    {
        data = make_shared<vector<T5>>();
    }

    Blob(initializer_list<T5> il)
    {
        data = make_shared<vector<T5>>(il);
    }

    template <typename T8>
    void PrintMem(T8 b, T8 e)
    {
        while (b < e) {
            cout << *b << ' ';
            ++b;
        }

        cout << endl;
    }

    sizeType Size() const
    {
        return data->size();
    }

    bool Empty() const
    {
        return data->empty();
    }

    void push_back(const T5 &t)
    {
        data->push_back(t);
    }

    void pop_back()
    {
        check(0, "pop on empty Blob");
        data->pop_back();
    }

    T5 &front()
    {
        check(0, "front on empty Blob");
        return data->front();
    }

    T5 &back()
    {
        check(0, "back on empty Blob");
        return data->back();
    }

    T5 &operator[] (sizeType i)
    {
        return (*data)[i];
    }

private:
    shared_ptr<vector<T5>> data;

    // 如果data[i]不合法，抛出异常，异常信息记录在msg中
    void check(sizeType i, const string &msg)
    {
        if (i >= data->size()) {
            throw out_of_range(msg);
        }
    }
};

void ClassTemplate()
{
    // 根据提供的模板实参类型，实例化出对应版本的类，这里是int
    Blob<int> iA1 = {0, 1, 2, 3, 4, 5};
    cout << iA1.Size() << endl;

    // 这里是string类型
    Blob<string> strB1 = {"hello", "c++"};
    cout << strB1.front() << endl;
    cout << strB1[1] << endl;
}

// 这个的目的是能让delete删除对象的时候打印出一个提示，所以需要使用模板来自动推算出传入的类型
class DebugDelete {
public:
    explicit DebugDelete(ostream &s = cerr) : os(s) {};

    // 成员模板
    template <typename T7>
    void operator() (T7 *p) const
    {
        os << "deleting unique_ptr" << endl;
        delete p;
    }

private:
    ostream  &os;
};

void MemberTemplate()
{
    // 非模板类的成员模板演示
    auto *p = new double;
    // 可以像delete表达式一样使用的对象
    DebugDelete d;
    d(p);

    auto *ip = new int;
    // 在一个临时的DebugDelete对象上调用operator() (int*)
    DebugDelete() (ip);

    // 模板类中定义并使用成员模板，成员模板和模板类各自的模板互相独立，成员模板只有在被调用的时候
    // 才会根据传入值的类型来实例化
    Blob<int> iA1 = {0, 1, 2, 3, 4, 5};
    vector<int> tmpVec = {10, 11};
    iA1.PrintMem(tmpVec.cbegin(), tmpVec.cend());
}

int main()
{
    FuncTemplate();
    ClassTemplate();
    MemberTemplate();

    return 0;
}
