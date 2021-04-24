
// 144. Binary Tree Preorder Traversal

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> tranvers;
        stack<TreeNode* > helper;
        
        if (root == NULL) {
            return tranvers;
        }
        
        helper.push(root);
        
        while (!helper.empty()) {
            TreeNode* curr = helper.top();
            helper.pop();
            
            tranvers.push_back(curr->val);
            
            if (curr->right != NULL) {
                helper.push(curr->right);
            }
            
            if (curr->left != NULL) {
                helper.push(curr->left);
            }
        }
        
        return tranvers;
    }
};
