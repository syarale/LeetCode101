
// 382. Linked List Random Node

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
private:
    ListNode* headptr;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        headptr = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int count = 2;
        int ret = headptr->val;
        ListNode* ptr = headptr->next;
        
        while (ptr != NULL) {
            if (rand() % count == 0) {
                ret = ptr->val;
            }
            count ++;
            ptr = ptr->next;
        }
        
        return ret;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */ 
