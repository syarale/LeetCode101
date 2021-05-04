
// 543. Diameter of Binary Tree

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
    void getDiameterAndDepth(TreeNode* root, int& diameter, int& depth) {
        if (root == NULL) {
            diameter = 0;
            depth = 0;
            return;
        }
        
        int leftDiameter = 0, rightDiameter = 0;
        int leftDepth = 0, rightDepth = 0;
        
        getDiameterAndDepth(root->left, leftDiameter, leftDepth);
        getDiameterAndDepth(root->right, rightDiameter, rightDepth);
        
        // Note: diameter is the num of edges from one node to another node,
        // not the num of nodes.
        diameter = max(leftDepth + rightDepth, max(leftDiameter, rightDiameter));
        depth = max(leftDepth, rightDepth) + 1;
        return;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        int depth = 0;
        
        getDiameterAndDepth(root, diameter, depth);
        return diameter; 
    }
};
