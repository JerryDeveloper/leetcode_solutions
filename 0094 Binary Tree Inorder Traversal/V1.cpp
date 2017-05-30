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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode *> s;
        unordered_map<TreeNode *, bool> checklist;
        
        vector<int> result;
        
        if(root == NULL)
            return result;
        
        s.push(root);
        
        while(!s.empty())
        {
            TreeNode *cur = s.top();
            TreeNode *left = cur->left;
            
            if(left != NULL && !checklist[left])
            {
                // traverse the left tree
                s.push(left);
                continue;

            }
            
            result.push_back(cur->val);
            s.pop();  // remove from stack
            checklist[cur] = true;
            
            TreeNode *right = cur->right;
            if(right != NULL)
            {
                s.push(right);
            }
        }
        
        return result;
    }
};