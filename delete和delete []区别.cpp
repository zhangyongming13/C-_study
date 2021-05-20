#include <iostream>

using namespace std;

class ClassA {
public:
    ClassA()
    {
        cout << "ClassA constructed function!" << endl;
    }

    ~ ClassA()
    {
        cout << "ClassA destructor function!" << endl;
    }
};

class ClassB {
public:
    ClassB()
    {
        mBuffer = new char[10];
        cout << "ClassB constructed function!" << endl;
    }

    ~ ClassB()
    {
        delete mBuffer;
        cout << "ClassB destructor function!" << endl;
    }

private:
    char *mBuffer;
};

int main()
{
    // 这里的int是简单类型，所以即使使用delete也不会报错
    int *a = new int[10];
    delete a;
    // new的时候使用[]，在释放内存的时候需要使用对应的delete[]进行删除，这样new新建的两个ClassA对应的析构函数都会被调用到
    auto *pClassA1 = new ClassA[2];
    delete[] pClassA1;

    cout << endl;
    // 这里释放内存的时候没有使用对应的delete[]，在简单数据类型的时候，内存依然可以正常释放，但是只有第一个ClassA对应的
    // 析构函数被调用了，但第二个ClassA为什么会被释放呢？按照网上的论点，就是new分配内存的时候系统记录了大小，释放的时候就一起释放了
    // 这里在ClassA不是简单类型会报非法指针的错误
//    auto *pClassA2 = new ClassA[2];
//    delete pClassA2;

    // 上述new []使用delete进行删除还有可能造成的一个问题就是：由于第二个开始的析构函数不会被调用到，所以在非简单类型并且
    // 需要在析构函数释放内存的时候就会造成内存泄露，下面例子中第二个ClassB由于析构函数没有被调用到，导致原本在析构函数中释放
    // 的内存mBuff泄露了
    auto *pClassB = new ClassB[2];
    delete pClassB;

    return 0;
}
