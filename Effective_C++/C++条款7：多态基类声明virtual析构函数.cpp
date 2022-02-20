#include <iostream>

using namespace std;

class Base {
public:
    Base() = default;
    virtual ~Base()
    {
        cout << "I am base!" << endl;
    }
};

class Derive : public Base {
public:
    Derive() = default;
    ~Derive() override
    {
        cout << "I am derive!" << endl;
    }
};

int main()
{
    Base *pBase = new Derive();
    delete pBase;

    return 0;
}
