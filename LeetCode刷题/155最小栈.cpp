#include <iostream>

using namespace std;

struct node {
    int val;
    node *next;
    node(int val, node *next) : val(val), next(next) {}
};

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        minAddr = nullptr;
        this->head = new node(0, nullptr);
    }

    void push(int val) {
        node *tmpNode = head->next;
        head->next = new node(val, nullptr);
        head->next->next = tmpNode;

        if ((minAddr == nullptr) || (val < minAddr->val)) {
            minAddr = head->next;
        }
    }

    void pop() {
        node *tmpNode = head->next;
        // 出栈的值刚好是最小值的时候需要重新计算最小值
        if (tmpNode == minAddr) {
            minAddr = head->next->next;
            node *tmpHead = minAddr;
            while (tmpHead != nullptr) {
                if (tmpHead->val < minAddr->val) {
                    minAddr = tmpHead;
                }

                tmpHead = tmpHead->next;
            }
        }

        head->next = head->next->next;
        delete tmpNode;
    }

    int top() {
        return head->next->val;
    }

    int getMin() {
        return minAddr->val;
    }

private:
    node *minAddr;
    node *head;
};

int main()
{
    auto* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    cout << obj->getMin() << endl;
    obj->pop();
    cout << obj->top() << endl;
    cout << obj->getMin() << endl;
}
