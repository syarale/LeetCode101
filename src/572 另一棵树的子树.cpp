
// 572. Subtree of Another Tree

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
    bool isRootSubtree(TreeNode* s, TreeNode* t) {
        if (s== NULL && t == NULL) {
            return true;
        }
        
        if (s == NULL || t == NULL) {
            return false;
        }
        
        // assert(s != NULL && t != NULL);
        if (s->val != t->val) {
            return false;
        }
        
        return isRootSubtree(s->left, t->left) && isRootSubtree(s->right, t->right);
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (t == NULL) {
            return true;
        }
        
        // assert(t != NULL);
        if (s == NULL) {
            return false;
        }
        
        // assert(s != NULL && t != NULL);
        if (s->val == t->val) {
            return isRootSubtree(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
        } else {
            return isSubtree(s->left, t) || isSubtree(s->right, t);
        }
        
    }
}; 
