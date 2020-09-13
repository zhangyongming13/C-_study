#include <iostream>
#include <string>

using namespace std;

void StringInit()
{
    string s1;  // 没有初值，默认初始化为一个空串
    s1 = "zhang";  // 拷贝初始化
    cout << s1 << endl;

    string s2(10, 'c');  // 直接初始化，内容是10个c
    string s3("Direct initialization");
    cout << s2 << endl;
    cout << s3 << endl;
}

void BuiltInAttributeOrFunc()
{
    string TestString1 = "Hello";
    // 判断字符串是否为空
    if (TestString1.empty()) {
        cout << "TestString1 is empty!!!" << endl;
    } else {
        cout << "TestString1 is not empty!!!" << endl;
    }

    // 计算字符串的长度（包含字符数量）
    cout << "TestString size is " << TestString1.size() <<endl;
    string TestString2 = "Hello";

    // 比较两个字符串是否相等
    if (TestString1 == TestString2) {
        cout << "TestString1 equal to TestString2!!!" << endl;
    }

    string TestString3 = "Hello World";
    string TestString4 = "Ha";
    // 前面内容一样，长短不一样
    if (TestString3 > TestString1) {
        cout << TestString3 << endl;
    }
    // 比较字典值
    if (TestString1 > TestString4) {
        cout << TestString1 << endl;
    }
}

void ReadValueFromString()
{
    string TestString1 = "zhangyongming";
    // 直接输出
    cout << TestString1 << endl;

    // s[n]返回字符串s中第n个字符，0开始算。一般是for循环加size的形式。
    for (int i = 0; i != TestString1.size(); ++i) {
        cout << TestString1[i] << ' ';
    }
    cout << endl;

    // c++11新特性for。
    for (auto i : TestString1) {
        cout << i << ' ';
    }
    cout << endl;
    // 如果需要修改string的内容只需要变为for (auto &i : TestString1)即可
    for (auto &i : TestString1) {
        i = 'c';
    }
    cout << TestString1 << endl;
}

int main()
{
    StringInit();
    BuiltInAttributeOrFunc();
    ReadValueFromString();

    return 0;
}