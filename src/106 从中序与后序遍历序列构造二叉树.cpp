
// 106. Construct Binary Tree from Inorder and Postorder Traversal

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        if (inorder.empty() || postorder.empty()) {
            return NULL;
        }
        
        // assert valid input...
        int inLen = inorder.size();
        int postLen = postorder.size();
        TreeNode* ptr = new TreeNode(postorder[postLen - 1]);
        
        if (inLen == 1) {
            return ptr;
        }
        
        int curr = 0;
        for (curr = 0; curr < inLen; curr++) {
            if (inorder[curr] == ptr->val) {
                break;
            }
        }
        
        vector<int> leftIn(inorder.begin(), inorder.begin() + curr);
        vector<int> rightIn(inorder.begin() + curr + 1, inorder.end());
        vector<int> leftPost(postorder.begin(), postorder.begin() + leftIn.size());
        vector<int> rightPost(postorder.begin() + leftIn.size(), postorder.end() - 1);
        
        ptr->left = buildTree(leftIn, leftPost);
        ptr->right = buildTree(rightIn, rightPost);
        
        return ptr;
    }
}; 

