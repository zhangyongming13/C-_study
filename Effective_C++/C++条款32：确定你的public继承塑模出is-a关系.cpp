#include <memory>
#include <iostream>

using namespace std;

class Bird {
};

class FlyingBird : public Bird {
public:
    virtual void Fly()
    {
        cout << "I can fly!" << endl;
    }
};

class Penguin : public Bird {
};

int main()
{
    FlyingBird flyingBird;
    flyingBird.Fly();

    return 0;
}
