
// 105. Construct Binary Tree from Preorder and Inorder Traversal

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) {
            return NULL;
        }
        
        int rootVal = preorder[0];
        int ptr = 0;
        for (ptr = 0; ptr < inorder.size(); ptr++) {
            if (inorder[ptr] == rootVal) {
                break;
            }
        }
        
        TreeNode* root = new TreeNode(rootVal);
        
        vector<int> leftInorder(inorder.begin(), inorder.begin() + ptr);
        vector<int> rightInorder(inorder.begin() + ptr + 1, inorder.end());
        
        vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + 1 + ptr);
        vector<int> rightPreorder(preorder.begin() + ptr + 1, preorder.end());
        
        root->left = buildTree(leftPreorder, leftInorder);
        root->right = buildTree(rightPreorder, rightInorder);
        return root;
    }
};
