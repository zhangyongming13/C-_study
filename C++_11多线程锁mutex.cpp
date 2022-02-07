#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

mutex multiMutex;

void fn1()
{
    for (int i = 0; i < 5; ++i) {
        // 使用unique_lock进行上锁，不需要手动解锁，解锁操作由析构函数负责
        unique_lock<mutex> lock(multiMutex);
        cout << "Thread: " << this_thread::get_id() << " The thread1 is running!" << endl;
    }
}

void fn2()
{
    for (int i = 0; i < 5; ++i) {
        unique_lock<mutex> lock(multiMutex);
        cout << "Thread: " << this_thread::get_id() << " The thread2 is running!" << endl;
    }
}

void MutexTest()
{
    thread t1(fn1);
    thread t2(fn2);

    t1.detach();
    t2.detach();

    this_thread::sleep_for(chrono::milliseconds(100));
}

int main()
{
    MutexTest();

    return 0;
}
