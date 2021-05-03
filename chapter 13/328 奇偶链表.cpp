
// 328. Odd Even Linked List 

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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) { 
            return head;
        }

        ListNode* oddhead = head, *oddtail = head;
        ListNode* evenhead = head->next, *eventail = head->next;
        ListNode* ptr = eventail->next;

        int k = 3;
        while (ptr != nullptr) {
            ListNode* tmp = ptr;
            ptr = ptr->next;
            if (k % 2 != 0) {
                oddtail->next = tmp;
                oddtail = oddtail->next;
            } else {
                eventail->next = tmp;
                eventail = eventail->next;
            }
            k++;
        }

        oddtail->next = evenhead;
        eventail->next = nullptr;
        return oddhead;
    }
};
