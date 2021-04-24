// 1110. и╬╣ЦЁиаж

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
    TreeNode* helper(TreeNode* root, unordered_set<int>& dict, vector<TreeNode* >& forest) {
        if (root == NULL) {
            return NULL;
        }
        
        // TreeNode* ret = NULL;
        root->left = helper(root->left, dict, forest);
        root->right = helper(root->right, dict, forest);
        
        if (dict.find(root->val) != dict.end()) {
            if (root->left != NULL) {
                forest.push_back(root->left);
            }
            
            if (root->right != NULL) {
                forest.push_back(root->right);
            }
            root = NULL;
        }
        
        return root;
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode* > forest;
        unordered_set<int> dict;
        
        for (int i = 0; i < to_delete.size(); i++) {
            dict.insert(to_delete[i]);
        } 
        
        root = helper(root, dict, forest);
        if (root != NULL) {
            forest.push_back(root);
        }
        
        return forest;
    }
};
