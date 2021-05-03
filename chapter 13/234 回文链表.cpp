
// 234. Palindrome Linked List 

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
    ListNode* reverse(ListNode* head) {
        ListNode* rhead = nullptr, *ptr = head;
        while (ptr != nullptr) {
            ListNode* tmp = ptr;
            ptr = ptr->next;
            tmp->next = rhead;
            rhead = tmp;
        }
        return rhead;
    }

    bool isPalindrome(ListNode* head) {
        if (head == nullptr) {
            return false;
        }

        if (head->next == nullptr) {
            return true;
        }

        ListNode* fast = head, *slow = head;
        while (fast->next != nullptr && (fast->next)->next != nullptr) {
            slow = slow->next;
            fast = (fast->next)->next;
        }

        ListNode* rhead = reverse(slow->next);
        ListNode* l1 = head, *l2 = rhead;
        while (l2 != nullptr) {
            if (l1->val != l2->val) {
                return false;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        slow->next = reverse(rhead);
        return true;
    }
};
