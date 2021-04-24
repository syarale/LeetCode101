
// 94. Binary Tree Inorder Traversal

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode* > stk;
        
        if (root == NULL) {
            return ret;
        }
        
        TreeNode* ptr = root;
        while (ptr != NULL || !stk.empty()) {
            while (ptr != NULL) {
                stk.push(ptr);
                ptr = ptr->left;
            }
            
            if (!stk.empty()) {
                ptr = stk.top();
                stk.pop();

                ret.push_back(ptr->val);
                ptr = ptr->right;
            }
        }
        
        return ret;
    }
}; 
