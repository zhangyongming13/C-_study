#ifndef TEST_PERSONIMPL_H
#define TEST_PERSONIMPL_H

#include <string>

class DateClass {
public:
    DateClass() = default;

    explicit DateClass(const std::string &dateStr)
    {
        this->dateStr = dateStr;
    }

    std::string GetDate()
    {
        return dateStr;
    }

private:
    std::string dateStr;
};

class PersonImpl
{
public:
    PersonImpl() = default;
    PersonImpl(const std::string &name, const std::string &birthday)
    {
        theName = name;
        DateClass dateClass(birthday);
        theBirthday = dateClass;
    }

    std::string GetBirthday()
    {
        return theBirthday.GetDate();
    }

private:
    std::string theName;
    DateClass theBirthday;
};

#endif
