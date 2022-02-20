#include <iostream>
#include <memory>

using namespace std;

class Person {
public:
    Person(const string &name, const string &address)
    {
        this->name = name;
        this->address = address;
        cout << "Create a person!" << endl;
    }

    virtual ~Person() = default;

public:
    string name;
    string address;
};

class Student : public Person {
public:
    Student(const string &name, const string &address, const string &schoolName, unsigned int studentNumber) : Person(name, address) {
        this->schoolName = schoolName;
        this->studentNumber = studentNumber;
        cout << "Create a student!" << endl;
    }

    ~Student() override = default;

public:
    string schoolName;
    unsigned int studentNumber;
};

bool IsValidStudent(const Student &student)
{
    return student.studentNumber > 0;
}

void HighConsumption()
{
    Student student("ZYM", "SHENZHEN", "GDUT", 100);
    if (IsValidStudent(student)) {
        cout << "Valid student!" << endl;
    }
}

class Window {
public:
    Window(const string &name)
    {
        this->name = name;
    }

    virtual ~Window() = default;

    virtual void Display()
    {
        cout << "I am base!" << endl;
    }

public:
    string name;
};

class WindowWithScrollBars : public Window {
public:
    WindowWithScrollBars(const string &name) : Window(name){};

    ~WindowWithScrollBars() override = default;

    virtual void Display()
    {
        cout << "I am derive!" << endl;
    }
};

void PrintNameAndDisplay(Window &w)
{
    cout << w.name << endl;
    w.Display();
}

int main()
{
    WindowWithScrollBars windowWithScrollBars("MING");
    PrintNameAndDisplay(windowWithScrollBars);

    return 0;
}
