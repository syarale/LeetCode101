// 653. Two Sum IV - Input is a BST

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
    bool preorder(TreeNode* root, unordered_set<int>& hash, int target) {
        if (root == NULL) {
            return false;
        }
        
        if (hash.find(target - root->val) != hash.end()) {
            return true;
        } 
        
        hash.insert(root->val);
        return preorder(root->left, hash, target) || preorder(root->right, hash, target);
        
    }
    
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> hash;
         
        if (root == NULL) {
            return false;
        }
        
        bool isExist = preorder(root, hash, k);
        return isExist;
    }
}; 
