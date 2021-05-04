
// 1110. Delete Nodes And Return Forest

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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode* > que;
        vector<double> average;
        
        if (root == NULL) {
            return average;
        }
        
        que.push(root);
        
        while (!que.empty()) {
            int tos = que.size();
            double num = tos;
            double sum = 0;
            
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
                sum += tmp->val;
            }
            
            double averageVal = sum / num;
            average.push_back(averageVal);
        }
        
        return average;
    }
};
