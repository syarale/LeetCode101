
// 21. Merge Two Sorted Lists 

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        } else if (l2 == nullptr) {
            return l1;
        }

        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;
        while (l1 != nullptr && l2 != nullptr) {
            ListNode* tmp = nullptr;
            if (l1->val < l2->val) {
                tmp = l1;
                l1 = l1->next; 
            } else {
                tmp = l2;
                l2 = l2->next;
            }
            tail->next = tmp;
            tail = tail->next;
        }

        if (l1 == nullptr) {
            tail->next = l2;
        } else {
            tail->next = l1;
        }

        return dummy->next;
    }
};
