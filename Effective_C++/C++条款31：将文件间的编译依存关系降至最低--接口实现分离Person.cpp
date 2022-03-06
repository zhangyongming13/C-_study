#include <memory>
#include <iostream>
#include <string>
#include "PersonImpl.h"

using namespace std;

class DateClass;  // Person接口用到的classes的前置声明
class PersonImpl;  // Person实现类的前置声明

class Person {
public:
    Person(const string &name, const string &birthday)
    {
        pImpl = make_shared<PersonImpl>(name, birthday);
    }

    string GetBirthday()
    {
        return pImpl->GetBirthday();
    }

private:
    shared_ptr<PersonImpl> pImpl;
};

int main()
{
    Person person("zhang", "1994");
    cout << person.GetBirthday() << endl;

    return 0;
}
