
// 235. Lowest Common Ancestor of a Binary Search Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || p == NULL || q == NULL) {
            return NULL;
        }
        
        TreeNode* ptr = root;
        int minVal = min(p->val, q->val);
        int maxVal = max(p->val, q->val);
        
        while (ptr != NULL) {
            if (ptr->val < minVal) {
                ptr = ptr->right;
            } else if (ptr->val > maxVal) {
                ptr = ptr->left;
            } else {
                break;
            }
        }
        
        return ptr;
    }
}; 
