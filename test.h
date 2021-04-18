#ifndef TEST_MAIN_H
#define TEST_MAIN_H

#include <string>

using namespace std;

class Test {
public:
    virtual void testA() const = 0;

    virtual void testB() const = 0;
};

#endif //TEST_MAIN_H