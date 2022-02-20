#include <string>
#include <iostream>
#include <vector>

using namespace std;

const unsigned MINI_NUM_PASSWORD = 10;

string EncryptPassword(const string &password)
{
    if (password.size() < MINI_NUM_PASSWORD) {
        throw logic_error("Password is too short!");
    }

    // t通告copy构造函数定义并进行初始化
    string encryptResult(password);
    for (unsigned int i = 0; i < encryptResult.size(); ++i) {
        if ((i % 2) == 0) {
            encryptResult[i] = (static_cast<char>(static_cast<unsigned>(encryptResult[i]) + 1));
        }
    }

    return encryptResult;
}

class Student {
public:
    Student()
    {
        this->age = 0;
    }

    Student(const string &name, unsigned int age, const string &sex)
    {
        this->name = name;
        this->age = age;
        this->sex = sex;
    }

    ~Student() = default;

public:
    string name;
    unsigned int age;
    string sex;
};

vector<Student> GenStudent()
{
    Student student1("zhang", 12, "man");
    Student student2("yong", 13, "man");
    Student student3("ming", 12, "woman");
    vector<Student> result;
    result.emplace_back(student1);
    result.emplace_back(student2);
    result.emplace_back(student3);

    return result;
}

void FuncA()
{
    // 做法A定义在循环外面
    Student student;
    vector<Student> studentVec = GenStudent();
    for (const auto &item : studentVec) {
        student = item;
        cout << student.name << endl;
    }
}

void FuncB()
{
    // 做法B定义在循环里面
    vector<Student> studentVec = GenStudent();
    for (const auto &item : studentVec) {
        Student student(item);
        cout << student.name << endl;
    }
}

int main()
{
    FuncA();
    FuncB();

    return 0;
}
