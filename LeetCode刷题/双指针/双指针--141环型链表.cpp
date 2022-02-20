#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    static bool hasCycle(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;

        while ((fast != nullptr) && (slow != nullptr)) {
            if (fast->next != nullptr) {
                fast = fast->next->next;
            } else {
                return false;
            }

            slow = slow->next;

            if (fast == slow) {
                return true;
            }
        }

        return false;
    }
};