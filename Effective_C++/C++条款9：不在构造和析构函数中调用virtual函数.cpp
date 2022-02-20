#include <iostream>

using namespace std;

class Base {
public:
    Base()
    {
        PrintInfo();
    }

    virtual void PrintInfo()
    {
        cout << "I am base!" << endl;
    }
};

class Derive : public Base {
public:
    virtual void PrintInfo()
    {
        cout << "I am derive!" << endl;
    }
};

int main()
{
    Derive derive;
    return 0;
}
