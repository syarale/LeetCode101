
// 109. Convert Sorted List to Binary Search Tree

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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getLen(ListNode* head) {
        ListNode* ptr = head;
        int len = 0;
        
        while (ptr != NULL) {
            len ++;
            ptr = ptr->next;
        }
        
        return len;
    }
    
    void inorderAndAssignment(TreeNode* root, ListNode*& curr) {
        if (root == NULL || curr == NULL) {
            return;
        }
        
        inorderAndAssignment(root->left, curr);
        root->val = curr->val;
        curr = curr->next;
        inorderAndAssignment(root->right, curr);
        return;
    }
    
    
    TreeNode* buildTree(int len) {
        if (len <= 0) {
            return NULL;
        }
        
        TreeNode* ptr = new TreeNode();
        if (len == 1) {
            return ptr;
        }
        
        int mid = len / 2;
        ptr->left = buildTree(mid);
        ptr->right = buildTree(len - mid - 1);
        
        return ptr;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        
        int len = getLen(head);
        TreeNode* root = buildTree(len);
        inorderAndAssignment(root, head);
        
        return root; 
    }
}; 
