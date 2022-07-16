#include <functional>
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

// 普通函数
int add(int i, int j) {
    return i + j;
}

unsigned int add(unsigned int i, unsigned j) {
    return i + j;
}

void overLoadAndFunc()
{
    unordered_map<string, function<int(int, int)>> binops;
    // 这个指针指向的是接收两个int的add版本
    int (*funcP)(int, int) = add;
    binops.insert({"+", funcP});
    cout << binops["+"](1, 1) << endl;
}

// 函数对象类
struct divide {
    int operator()(int denominator, int divisor) {
        return denominator / divisor;
    }
};

void functionTest()
{
    // 函数指针
    function<int(int, int)> addFunc = add;
    // 函数对象类的对象
    function<int(int, int)> divideFunc = divide();
    // lambda
    function<int(int, int)> modFunc = [](int i, int j){return i % j;};

    unordered_map<string, function<int(int, int)>> binops = {
            {"+", add},                                 // 函数指针
            {"-", minus<int>()},                     // 标准库函数对象
            {"/", divide()},                         // 用户定义的函数对象
            {"*", [](int i, int j){return i * j;}},    // 未命名的lambda
            {"%", modFunc}                             // 命名的lambda
    };

    cout << binops["+"](10, 5) << endl;
    cout << binops["-"](10, 5) << endl;
    cout << binops["/"](10, 5) << endl;
    cout << binops["*"](10, 5) << endl;
    cout << binops["%"](10, 5) << endl;
}


int main()
{
    overLoadAndFunc();

    return 0;
}
