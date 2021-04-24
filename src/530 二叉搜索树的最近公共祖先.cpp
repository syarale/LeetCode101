
// 530. Minimum Absolute Difference in BST

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
    int getMinimumDifference(TreeNode* root) {
        int minDiff = INT_MAX;
        TreeNode* pred = NULL;
        TreeNode* ptr = root;
        stack<TreeNode* > stk;
        
        while (ptr != NULL || !stk.empty()) {
            while (ptr != NULL) {
                stk.push(ptr);
                ptr = ptr->left;
            }
            
            ptr = stk.top();
            stk.pop();
            
            if (pred != NULL) {
                minDiff = min(minDiff, abs(ptr->val - pred->val));
            }
            
            pred = ptr;
            ptr = ptr->right;
        }
        
        return minDiff;
    }
}; 
