
// 236. Lowest Common Ancestor of a Binary Tree

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
    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q) {
        // assert(p != NULL && q != NULL);
        
        if (root == NULL) {
            return NULL;
        }
        
        if (root == p || root == q) {
            return root;
        }
        
        TreeNode* lptr = helper(root->left, p, q);
        TreeNode* rptr = helper(root->right, p, q);
        
        if (lptr == NULL && rptr == NULL) {
            return NULL;  // throw error
        }
        
        if (lptr != NULL && rptr != NULL) {
            return root;   
        }
        
        if (lptr == NULL) {
            return rptr;
        } else {
            return lptr;
        }
        
    } 
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || p == NULL || q == NULL) {
           return NULL;
        }
        
        return helper(root, p, q);
    }
}; 
