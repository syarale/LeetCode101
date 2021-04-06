// 257. Binary Tree Paths

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
    void dfs(TreeNode* curr, vector<int>& path, vector<vector<int> >& res) {
        if (curr == nullptr) {
            return;
        }
        
        path.push_back(curr->val);
        if (curr->left == nullptr && curr->right == nullptr) {
            res.push_back(path);
        } else {
            dfs(curr->left, path, res);
            dfs(curr->right, path, res);
        }
        path.pop_back();
        
        return;
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> pathStr;
        vector<int> path;
        vector<vector<int> > res;
        
        if (root == nullptr) {
            return pathStr;
        } 
        
        dfs(root, path, res);
        for (int i = 0; i < res.size(); i++) {
            int len = res[i].size();
            string str = "";
            
            for (int j = 0; j < len; j++) {
                if (!str.empty()) {
                    str += ("->" + to_string(res[i][j]));
                } else {
                    str = to_string(res[i][j]);
                }
            }
            
            pathStr.push_back(str);
        }
        
        return pathStr;
    }
}; 
