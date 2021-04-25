// 145. Binary Tree Postorder Traversal

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<pair<TreeNode*, bool> > stk;
        
        if (root == NULL) {
            return ret;
        } 
        
        TreeNode* ptr = root;
        while (ptr != NULL || !stk.empty()) {
            while (ptr != NULL) {            
                stk.push({ptr, false});
                ptr = ptr->left;
            }
            
            if (!stk.empty()) {
                ptr = (stk.top()).first;
            }
            
            if (ptr->right == NULL || (stk.top()).second) {
                ret.push_back(ptr->val);
                stk.pop();
                ptr = NULL;
            } else {
                (stk.top()).second = true;
                ptr = ptr->right;
            }
            
        }
        
        return ret;
    }
};
