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
    
    // this is preorder traversal list. so just apply preorder traversal method, the node operation at each node is connect prev node's right child to cur and pre's left child to NULL
    
public:
    void flatten(TreeNode* root) {
        
        if(root == NULL)
            return;
        
        stack<TreeNode*> s;
        TreeNode* prev = root;
        
        if(root->right)
            s.push(root->right);
        if(root->left)
            s.push(root->left);
        
        while(!s.empty()) {
            
            TreeNode* cur = s.top();
            s.pop();
            prev->left = NULL;
            prev->right = cur;
            
            if(cur->right)
                s.push(cur->right);
            if(cur->left)
                s.push(cur->left);
            
            prev = cur;
        }
        
        prev->left = NULL;
        prev->right = NULL;
        
        return;
    }
};