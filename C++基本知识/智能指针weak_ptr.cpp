#include <memory>
#include <iostream>
#include <utility>

using namespace std;
class TestB;
class TestA {
public:
    TestA()
    {
        cout << "TestA()" << endl;
    }

    void ReferTestB(shared_ptr<TestB> testPtr)
    {
        mTestBPtr = std::move(testPtr);
    }

    ~TestA()
    {
        cout << "~TestA()" << endl;
    }

private:
    shared_ptr<TestB> mTestBPtr;
};

class TestB {
public:
    TestB()
    {
        cout << "TestB()" << endl;
    }

    void ReferTestB(shared_ptr<TestA> testPtr)
    {
        mTestAPtr = std::move(testPtr);
    }

    ~TestB()
    {
        cout << "~TestB()" << endl;
    }

private:
    shared_ptr<TestA> mTestAPtr;
};

int main()
{
    shared_ptr<TestA> ptrA = make_shared<TestA>();
    shared_ptr<TestB> ptrB = make_shared<TestB>();
    ptrA->ReferTestB(ptrB);
    ptrB->ReferTestB(ptrA);
    cout << "ptrB use count is " << ptrB.use_count() << endl;
    cout << "ptrA use count is " << ptrA.use_count() << endl;

    return 0;
}
