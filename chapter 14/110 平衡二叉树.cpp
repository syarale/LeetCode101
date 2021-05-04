
// 110. Balanced Binary Tree

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
    bool getBalanceAndDepth(TreeNode* root, int& depth) {
        if (root == NULL) {
            depth = 0;
            return true;
        }
        
        int leftDepth = 0;
        bool isLeftBalanced = getBalanceAndDepth(root->left, leftDepth);
        
        if (!isLeftBalanced) {
            depth = -1;
            return false;
        }
        
        int rightDepth = 0;
        bool isRightBalanced = getBalanceAndDepth(root->right, rightDepth);
        if (!isRightBalanced) {
            depth = -1;
            return false;
        }
        
        if (abs(leftDepth - rightDepth) <= 1) {
            depth = max(leftDepth, rightDepth) + 1;
            return true;
        } else {
            depth = -1;
            return false;
        }
        
    }
    
    bool isBalanced(TreeNode* root) {
        int depth = 0;
        return getBalanceAndDepth(root, depth);

    }
}; 
