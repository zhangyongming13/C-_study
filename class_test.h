#include <string>

using namespace std;

class Human
{
    public:
        string name;
        int age;
        Human(string humanName, int humanAge);
    protected:
        double height;
    private:
        double weight;
};

class Student
{
    public:
        // 公有属性和方法
        int age;
        string name;
        
        bool setHeight(double height);
        bool setParentName(string parentName);
        bool setPhoneNumber(string phoneNumber);
        double getHeight();
        string getParentName();
        string getPhoneNumber();

        // 构造函数
        Student(int age, string name);

    private:
        // 私有属性和方法
        double height;
        string parentName;
        string phoneNumber;
};