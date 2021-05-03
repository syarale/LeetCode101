
// 24. Swap Nodes in Pairs 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode();
        ListNode* rtail = dummy;

        ListNode* ptr = head;
        while (ptr != nullptr && ptr->next != nullptr) {
            ListNode* prev = ptr;
            ListNode* after = ptr->next;
            ptr = after->next;

            after->next = prev;
            rtail->next = after;
            rtail = prev;
        }

        rtail->next = ptr;
        return dummy->next;
    }
};
