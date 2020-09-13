#include <iostream>

using namespace std;

void ConstPointer()
{
    int a = 5;
    const int *p1 = &a;
    // 或者类型写在前面的 int const *p1 = &a;
    cout << *p1 << endl;
    // *p1 = 6; 错误不能直接使用常量指针修改指向对象的值
    a = 6;
    cout << *p1 << endl;  // a通过其他值修改
    // 常量指针指向的常量也可以变化
    int b = 10;
    p1 = &b;
    cout << *p1 << endl;
}

void PointerConst()
{
    char a = 'a';
    char *const p1 = &a;
    cout << *p1 << endl;
    // 可以通过指针常量修改指向对象的值
    *p1 = 'b';
    cout << *p1 << endl;
    char c = 'c';
    // p1 = &c; 非法，指针常量不能改变指向的对象（存储的地址值不变）
}

int main()
{
    ConstPointer();
    PointerConst();
    return 0;
}