#ifndef TEST_DATACLASS_H
#define TEST_DATACLASS_H

#include <string>

class DateClass {
public:
    DateClass() = default;

    explicit DateClass(const std::string &dateStr)
    {
        this->dateStr = dateStr;
    }

    std::string GetDate() const
    {
        return dateStr;
    }

private:
    std::string dateStr;
};


#endif
