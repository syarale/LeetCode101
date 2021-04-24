
// 99. Recover Binary Search Tree

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
 

// space: O(log n)

class Solution {
public:
    
    void recoverTree(TreeNode* root) {
        stack<TreeNode* > stk;
        TreeNode* ptr = root;
        TreeNode* pred = NULL;
        TreeNode* first = NULL;
        TreeNode* second = NULL;
        
        if (root == NULL) {
            return;
        }
        
        while (ptr != NULL || !stk.empty()) {
            while (ptr != NULL) {
                stk.push(ptr);
                ptr = ptr->left;
            }
            
            if (!stk.empty()) {
                ptr = stk.top();
                stk.pop();
                
                if (pred != NULL) {
                    if (pred->val > ptr->val) {
                        if (first == NULL) {
                            first = pred;
                            second = ptr;
                        } else {
                            second = ptr;
                        }
                    }
                }

                pred = ptr;
                ptr = ptr->right;
            }
        }
        
        if (first != NULL && second != NULL) {
            int tmp = first->val;
            first->val = second->val;
            second->val = tmp;
        }
        
        return;

    }
};




// 99. Recover Binary Search Tree

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
 

 
// space : O(n); 
//class Solution {
//public:
//    void inorder(TreeNode* root, vector<TreeNode* >& ret) {
//        
//        if (root == NULL) {
//            return;
//        } 
//        
//        inorder(root->left, ret);
//        ret.push_back(root);
//        inorder(root->right, ret);
//           
//        return;
//    }
//    
//    void recoverTree(TreeNode* root) {
//        
//        if (root == NULL) {
//            return;
//        }
//        
//        vector<TreeNode* > seq;
//        inorder(root, seq);
//        
//        int len = seq.size();
//        TreeNode* ptr1 = NULL;
//        TreeNode* ptr2 = NULL;
//        
//        for (int i = 0; i < len; i++) {
//            if (i + 1 < len && seq[i]->val > seq[i + 1]->val && ptr1 == NULL) {
//                ptr1 = seq[i];
//            }
//            
//            if (i - 1 >= 0 && seq[i - 1] ->val > seq[i]->val) {
//                ptr2 = seq[i];
//            }
//        }
//        
//        if (ptr1 != NULL && ptr2 != NULL) {
//            int tmp = ptr1->val;
//            ptr1->val = ptr2->val;
//            ptr2->val = tmp;
//        }
//
//        return;
//    }
//}; 
