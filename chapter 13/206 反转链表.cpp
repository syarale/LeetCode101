
// 206. Reverse Linked List 

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
    ListNode* reverseList(ListNode* head) {
        ListNode* rhead = head;
        ListNode* rtail = head;

        if (head == nullptr) {
            return nullptr;
        }

        ListNode* ptr = head->next;
        rtail->next = nullptr;
        while (ptr != nullptr) {
            ListNode* tmp = ptr->next;
            ptr->next = rhead;
            rhead = ptr;
            ptr = tmp;
        }

        return rhead;
    }
};
