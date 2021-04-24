
// 889. Construct Binary Tree from Preorder and Postorder Traversal

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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        if (pre.empty() || post.empty()) {
            return NULL;
        }
        
        // assert valid input...
        int preLen = pre.size();
        int postLen = post.size();
        TreeNode* ptr = new TreeNode(pre[0]);
        
        if (preLen == 1) {
            return ptr;
        }
        
        int postVal = post[postLen - 2];
        int curr = 1;
        for (curr = 1; curr < preLen; curr++) {
            if (pre[curr] == postVal) {
                break;
            }
        }
        
        vector<int> leftPre(pre.begin() + 1, pre.begin() + curr);
        vector<int> rightPre(pre.begin() + curr, pre.end());
        vector<int> leftPost(post.begin(), post.begin() + leftPre.size());
        vector<int> rightPost(post.begin() + leftPre.size(), post.end() - 1);
        
        ptr->left = constructFromPrePost(leftPre, leftPost);
        ptr->right = constructFromPrePost(rightPre, rightPost);
        
        return ptr;
    }
}; 
