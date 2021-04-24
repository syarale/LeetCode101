
// 538. Convert BST to Greater Tree

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
    void helper(TreeNode* root, int& pred) {
        // assert(root != NULL);
        
        if (root->right != NULL) {
            helper(root->right, pred);
        }
        
        root->val += pred;
        pred = root->val;
        
        if (root->left != NULL) {
            helper(root->left, pred);
        } 
        
        return;
    }
    
    TreeNode* convertBST(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        
        int pred = 0;
        helper(root, pred);
        
        return root;
    }
}; 
