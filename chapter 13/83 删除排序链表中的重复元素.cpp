

// 83. Remove Duplicates from Sorted List 

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return head;
        }

        ListNode* rhead = head, *rtail = head;
        ListNode* ptr = head->next;
        while (ptr != nullptr) {
            if (ptr->val != rtail->val) {
                rtail->next = ptr;
                rtail = rtail->next;
                ptr = ptr->next;
            } else {
                ListNode* tmp = ptr;
                ptr = ptr->next;
                delete tmp;
            }
        }
        
        rtail->next = nullptr;
        return rhead;
    }
};
