
// 513. Find Bottom Left Tree Value

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
    int findBottomLeftValue(TreeNode* root) {
        // assert(root != NULL);
        
        queue<TreeNode* > que;
        que.push(root);
        
        int leftVal = 0;
        
        while (!que.empty()) {
            int tos = que.size();
            leftVal = que.front()->val;
            
            while (tos > 0) {
                tos--;
                TreeNode* tmp = que.front();
                que.pop();
                
                if (tmp->left != NULL) {
                    que.push(tmp->left);
                }
                
                if (tmp->right != NULL) {
                    que.push(tmp->right);
                }
            }
        } 
        
        return leftVal;
    }
}; 
