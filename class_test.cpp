#include <iostream>
#include <string>
#include "class_test.h"

using namespace std;

Human::Human(string humanName, int humanAge)
{
    this->name = humanName;
    this->age = humanAge;
}

Student::Student(int age, string name )
{
    // 类中函数的形参参数名和类的成员变量一样时，需要使用this指针
    // 不一样的时候可以不使用this
    this->age = age;
    this->name = name;
}

bool Student::setHeight(double height)
{
    this->height = height;
    return true;
}

bool Student::setParentName(string parentName)
{
    this->parentName = parentName;
    return true;
}

bool Student::setPhoneNumber(string phoneNumber)
{
    this->phoneNumber = phoneNumber;
    return true;
}


double Student::getHeight()
{
    return height;
}

string Student::getParentName()
{
    return parentName;
}

string Student::getPhoneNumber()
{
    return phoneNumber;
}

int main()
{
    Student student1(24, "zhangyongming");
    cout << student1.age << endl;
    cout << student1.name << endl;
    student1.setHeight(173.6);
    cout << student1.getHeight() << endl;

    Human human("zhangweizhi", 24);
    cout << human.name << endl;
    system("pause");
}