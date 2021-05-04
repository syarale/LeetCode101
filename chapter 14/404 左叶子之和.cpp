
// 404. Sum of Left Leaves

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
    int helper(TreeNode* root, TreeNode* parent) {
        // assert(root != NULL);
        
        if (root->left == NULL && root->right == NULL) {
            if (parent->left == root) {
                return root->val;
            } else {
                return 0;
            }
        }
        
        int sum = 0;
        if (root->left != NULL) {
            sum += helper(root->left, root);
        }
        
        if (root->right != NULL) {
            sum += helper(root->right, root);
        }
        
        return sum;
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        
        if (root == NULL) {
            return 0;
        }
        
        if (root->left == NULL && root->right == NULL) {
            return 0;
        }
        
        if (root->left != NULL) {
            sum += helper(root->left, root);
        }
        
        if (root->right != NULL) {
            sum += helper(root->right, root);
        }
        
        return sum;
    }
}; 
