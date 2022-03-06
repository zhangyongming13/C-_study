#include <memory>
#include <iostream>
#include <string>
#include <utility>
#include "DateClass.h"

using namespace std;

// Person抽象基类作为Interface class
class Person {
public:
    virtual ~Person() = default;
    virtual string GetBirthday() const = 0;
};

// 具象类
class RealPerson : public Person {
public:
    RealPerson(string name, const string &birthday)
            : theName(std::move(name)), theBirthdayDate(birthday) {}

    // 析构函数时必要的
    ~RealPerson() override = default;

    // 实现抽象基类中的函数
    string GetBirthday() const override
    {
        return theBirthdayDate.GetDate();
    }

private:
    string theName;
    DateClass theBirthdayDate;
};

// 工厂函数，负责产生实际的对象
shared_ptr<Person> CreateFactory(const string &name, const string &birthday)
{
    shared_ptr<Person> sharedPtr = make_shared<RealPerson>(name, birthday);
    return sharedPtr;
}

int main()
{
    auto pPerson = CreateFactory("zhangyongming", "1994");
    cout << pPerson->GetBirthday() << endl;

    return 0;
}
