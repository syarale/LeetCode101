
//  19. Remove Nth Node From End of List

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptr = head;
        int i = 0;
        for (i = 0; i < n; i++) {
            if (ptr == nullptr) {
                break;
            }
            ptr = ptr->next;
        }

        if (ptr == nullptr) {
            if (i < n - 1) {
                return head;
            } else {
                ListNode* tmp = head;
                head = head->next;
                delete tmp;
                return head;
            }
        }

        ListNode* prevDel = head;
        while (ptr->next != nullptr) {
            prevDel = prevDel->next;
            ptr = ptr->next;
        }

        ListNode* tmp = prevDel->next;
        prevDel->next = tmp->next;
        delete tmp;
        return head;
    }
};
