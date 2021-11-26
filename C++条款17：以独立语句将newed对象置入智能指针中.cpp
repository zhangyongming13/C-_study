#include <iostream>
#include <memory>

using namespace std;

class Widget {
public:
    Widget()
    {
        priority = 0;
    }

public:
    int priority;
};

int Priority()
{
    cout << "Priority has called!" << endl;
    return 0;
}

void ProcessWidget(shared_ptr<Widget> pW, int Priority)
{
    pW->priority = 10;
    cout << pW->priority << endl;
}

int main()
{
    // 以独立语句将newed对象置入智能指针中
    shared_ptr<Widget> pW(new Widget);
    ProcessWidget(pW, Priority());

    return 0;
}
