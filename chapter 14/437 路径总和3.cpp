
// 437. Path Sum III

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
    int dfs(TreeNode* root, int targetSum) {
        int total = 0;
        if (root == NULL) {
            // assert(targetSum != 0);
            return 0;
        }
        

        if (root->val == targetSum) {
            total = 1 + dfs(root->left, 0) + dfs(root->right, 0);
            return total;  
        } 
        
        // root->val != targetSum
        int add = targetSum - root->val;
        return dfs(root->left, add) + dfs(root->right, add);

    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if (root == NULL) {
            return 0;
        } 
        
        int inleft = pathSum(root->left, targetSum);
        int inright = pathSum(root->right, targetSum);
        int incurr = dfs(root, targetSum);
        
        int total = inleft + inright + incurr;
        return total;
    }
}; 
