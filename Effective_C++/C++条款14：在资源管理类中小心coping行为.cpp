#include <iostream>
#include <string>
#include <mutex>

using namespace std;

class UnCopyAble {
public:
    UnCopyAble() = default;

private:
    // 将拷贝构造函数以及copy assignment拷贝操作符声明但不实现以阻止编译器自动生成对应的内容
    UnCopyAble(const UnCopyAble&);
    UnCopyAble &operator=(const UnCopyAble&);
};

class Lock : private UnCopyAble{
public:
    explicit Lock(mutex *pm) : mutexPtr(pm) {
        mutexPtr->lock();
    }

    ~Lock()
    {
        mutexPtr->unlock();
    }

    mutex *mutexPtr;
};

int main()
{
    mutex m;
    {
        Lock m1(&m);
    }

    return 0;
}