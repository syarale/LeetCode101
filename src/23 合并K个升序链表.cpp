
// 23. Merge k Sorted Lists

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
    struct cmp {
        bool operator() (ListNode* node1, ListNode* node2) {
            return node1->val > node2->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        priority_queue<ListNode*, vector<ListNode*>, cmp> que; 
        
        if (lists.empty()) {
            return NULL;
        }
        
        for (int i = 0; i < len; i++) {
            if (lists[i] != NULL) {
                que.push(lists[i]);
            }
        }
        
        ListNode* root = new ListNode(0);
        ListNode* tail = root;
        
        while (!que.empty()) {
            tail->next = que.top();
            tail = tail->next;
            que.pop();
            
            if (tail->next != NULL) {
                que.push(tail->next);
            }
        }
        
        return root->next;
    }
};
