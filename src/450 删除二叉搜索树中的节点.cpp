
// 450. Delete Node in a BST

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
    TreeNode* search(TreeNode* root, int key, TreeNode*& parent) {
        TreeNode* ptr = root;
        
        while (ptr != NULL) {
            if (ptr->val == key) {
                break;
            } else if (ptr->val < key) {
                parent = ptr;
                ptr = ptr->right;
            } else {
                parent = ptr;
                ptr = ptr->left;
            }
        }
        
        return ptr;
    }
    
    TreeNode* deleteNode(TreeNode* root, TreeNode* delNode, TreeNode* parent) {
        if (root == NULL || delNode == NULL) {
            return root;
        }
        
        if (delNode->left == NULL && delNode->right == NULL) {
            delete delNode;
            if (parent != NULL) {
                // assert(delNode != root);
                if (parent->left == delNode) {
                    parent->left = NULL;
                } else {
                    parent->right = NULL;
                }
                
                return root;
            } 
            return NULL;
        }
        
        TreeNode* ptr = NULL;
        TreeNode* pred = delNode;
        if (delNode->left != NULL) {
            ptr = delNode->left;
            while (ptr->right != NULL) {
                pred = ptr;
                ptr = ptr->right;
            }
        } else {
            // assert(delNode->right != NULL);
            ptr = delNode->right;
            while (ptr->left != NULL) {
                pred = ptr;
                ptr = ptr->left;
            }
        }
        
        delNode->val = ptr->val;
        root = deleteNode(root, ptr, pred);
        
        return root;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) {
            return NULL;
        }
        
        if (root->left == NULL && root->right == NULL) {
            if (root->val == key) {
                delete root;
                return NULL;
            } else {
                return root;
            }
        } 
        
        TreeNode* parent = NULL;
        TreeNode* delNode = search(root, key, parent);
        
        while (delNode != NULL) {
            root = deleteNode(root, delNode, parent);
            
            parent = NULL;
            delNode = search(root, key, parent);
        }
        
        return root;    
    }
}; 
