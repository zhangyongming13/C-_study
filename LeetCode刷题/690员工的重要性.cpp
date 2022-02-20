#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        for (auto i : employees) {
            employeeMap[i->id] = *i;
        }

        // 深度遍历
        trace(id);

        return result;
    }

private:
    void trace(int id) {
        result += employeeMap[id].importance;

        if (employeeMap.empty()) {
            return;
        }

        for (auto i : employeeMap[id].subordinates) {
            trace(i);
        }
    }
private:
    map<int, Employee> employeeMap;
    int result = 0;
};

int main()
{
    Employee employee1;
    employee1.id = 1;
    employee1.importance = 2;
    employee1.subordinates = {2};

    Employee employee2;
    employee2.id = 2;
    employee2.importance = 3;
    employee2.subordinates = {};

    vector<Employee*> employees;
    employees.emplace_back(&employee1);
    employees.emplace_back(&employee2);

    Solution solution;
    cout << solution.getImportance(employees, 2) << endl;

    return 0;
}
