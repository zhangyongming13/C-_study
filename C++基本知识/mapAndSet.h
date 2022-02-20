//
// Created by Zhang on 2020/10/13.
//

#ifndef TEST_MAPANDSET_H
#define TEST_MAPANDSET_H

#include <string>

using namespace std;

class Person{
public:
    string name;
    unsigned int age = 0;

    Person(const string& personName, unsigned int personAge);
};

// 定义一个普通的函数
bool MyCompare(const Person &p1, const Person &p2);

#endif //TEST_MAPANDSET_H
