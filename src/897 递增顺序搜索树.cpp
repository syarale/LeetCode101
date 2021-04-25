
// 897. Increasing Order Search Tree

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
    void inorder(TreeNode* root, TreeNode*& tail) {
        if (root == NULL) {
            return;
        }
        
        inorder(root->left, tail);
        root->left = NULL;
        tail->right = root;
        tail = root;
        inorder(root->right, tail);
        
        tail->right = NULL;
        return;
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        
        TreeNode* prefix = new TreeNode(-1);
        TreeNode* tail = prefix;
        
        inorder(root, tail);
        return prefix->right;

    }
}; 
