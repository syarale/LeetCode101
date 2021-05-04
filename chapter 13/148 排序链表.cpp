
// 148. Sort List 

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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode* fast = head, *slow = head;
        while (fast->next != nullptr && (fast->next)->next != nullptr) {
            fast = (fast->next)->next;
            slow = slow->next;
        }

        ListNode* rhead = slow->next;
        slow->next = nullptr;
        head = sortList(head);
        rhead = sortList(rhead);

        ListNode* l1 = head, *l2 = rhead;
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        if (l1 != nullptr) {
            tail->next = l1;
        } else {
            tail->next = l2;
        }

        head = dummy->next;
        delete dummy;
        return head;
    }
};
