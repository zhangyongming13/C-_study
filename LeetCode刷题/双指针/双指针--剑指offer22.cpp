struct ListNode {
    int val;
    ListNode *next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    static ListNode* getKthFromEnd(ListNode* head, int k)
    {
        ListNode *first = head;
        ListNode *slow = head;
        int flag = 1;
        while (first != nullptr) {
            // 快指针出发了K个了，慢指针可以出发了
            if (flag > k) {
                slow = slow->next;
            }

            first = first->next;
            flag++;
        }

        return slow;
    }
};