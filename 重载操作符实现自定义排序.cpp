#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct StudentScore {
    StudentScore(int studentIndex, int chinese, int math, int english)
    {
        this->studentIndex = studentIndex;
        this->chinese = chinese;
        this->math = math;
        this->english = english;
    }

    int studentIndex;
    int chinese;
    int math;
    int english;

    // 重载小于号操作符，方便sort以及优先级队列（堆排序）
    bool operator< (const StudentScore &otherStudent) const
    {
        if (chinese != otherStudent.chinese) {
            return chinese > otherStudent.chinese;
        }

        if (math != otherStudent.math) {
            return math > otherStudent.math;
        }

        if (english != otherStudent.english) {
            return english > otherStudent.english;
        }

        if (studentIndex != otherStudent.studentIndex) {
            return studentIndex > otherStudent.studentIndex;
        }

        return true;
    }
};

// 使用sort实现自定义排序，缺点是不能边加边排序，如果元素多次加入，需要多次手工调用sort排序
// 优点是vector类型的结果遍历方便
vector<int> SortScore(vector<int> &chinese, vector<int> &math, vector<int> &english)
{
    vector<StudentScore> studentVec;
    for (int i = 0; i < chinese.size(); ++i) {
        StudentScore studentScore(i, chinese[i], math[i], english[i]);
        studentVec.emplace_back(studentScore);
    }

    sort(studentVec.begin(), studentVec.end());
    vector<int> result;
    result.reserve(studentVec.size());
    for (const auto &i : studentVec) {
        result.emplace_back(i.studentIndex);
    }

    return result;
}

// 使用优先级队列进行排序，优点是可以边加边排序，使用的是堆排序速度快
// 缺点是优先级队列类似于栈，访问不便，需要自顶向下访问
vector<int> PriorityQueue(vector<int> &chinese, vector<int> &math, vector<int> &english)
{
    priority_queue<StudentScore> priQue;
    for (int i = 0; i < chinese.size(); ++i) {
        StudentScore studentScore(i, chinese[i], math[i], english[i]);
        priQue.push(studentScore);
    }

    vector<int> result;
    while (!priQue.empty()) {
        StudentScore tmp = priQue.top();
        result.emplace_back(tmp.studentIndex);
        priQue.pop();
    }

    return result;
}

int main()
{
    // 语文数学英语三科成绩，下标为学生学号，需要按照语文 数学 英文排序
    vector<int> chinese = {91, 99, 99, 60, 71};
    vector<int> math    = {80, 97, 97, 78, 61};
    vector<int> english = {90, 97, 60, 88, 77};
    auto result1 = SortScore(chinese, math, english);
    for (const auto i : result1) {
        cout << i << ' ';
    }

    cout << endl;

    auto result2 = PriorityQueue(chinese, math, english);
    int resultSize = static_cast<int>(result2.size());
    for (int i = (resultSize - 1); i >= 0; --i) {
        cout << result2[i] << ' ';
    }

    return 0;
}
