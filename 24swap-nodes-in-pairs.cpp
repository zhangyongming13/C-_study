#include <iostream>

// https://leetcode-cn.com/problems/swap-nodes-in-pairs/s

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    static ListNode* swapPairs(ListNode* head) {
        if ((nullptr == head) || (nullptr == head->next)) {
            return head;
        }

        ListNode *nextNode = head->next;
        head->next = swapPairs(nextNode->next);
        nextNode->next = head;
        return nextNode;
    }
};

int main()
{
    auto *listNode1 = new ListNode(1);
    auto *listNode2 = new ListNode(2);
    auto *listNode3 = new ListNode(3);
    auto *listNode4 = new ListNode(4);
    listNode1->next = listNode2;
    listNode2->next = listNode3;
    listNode3->next = listNode4;
    auto tmpNode = Solution::swapPairs(listNode1);
    while (nullptr != tmpNode) {
        cout << tmpNode->val << ' ';
        tmpNode = tmpNode->next;
    }
    cout << endl;
    delete listNode1;
    delete listNode2;
    delete listNode3;
    delete listNode4;
    return 0;
}
