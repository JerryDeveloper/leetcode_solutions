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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        
        if(root)
            s.push(root);
        
        vector<int> res;
        while(!s.empty()) {
            TreeNode* cur = s.top();
            s.pop();
            
            res.push_back(cur->val);
        
            if(cur->right)
                s.push(cur->right);
            if(cur->left)
                s.push(cur->left);
        }
        
        return res;
    }
};