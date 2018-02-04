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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        if(root)
            q.push(root);
        vector<vector<int>> res;
        
        while(true) {
            
            if(q.size() == 0)
                break;
            
            int counter = q.size();
            vector<int> cur_level;
            while(counter > 0) {
                TreeNode* next = q.front();
            
                if(next->left)
                    q.push(next->left);
                if(next->right)
                    q.push(next->right);

                cur_level.push_back(next->val);
                
                --counter;
                q.pop();
            }
            
            res.push_back(cur_level);
        }
        
        return res;
    }
};