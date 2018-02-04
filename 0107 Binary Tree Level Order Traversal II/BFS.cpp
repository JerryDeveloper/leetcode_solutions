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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        // BFS
        
        vector<vector<int>> res;
        queue<TreeNode*> q;
        
        if(root != NULL)
            q.push(root);
        else
            return res;
        
        while(!q.empty())
        {
            int len_cur_level = q.size();
            vector<int> temp;
            for(int i = 0; i < len_cur_level; ++i)
            {
                TreeNode* curNode = q.front();
                temp.push_back(curNode->val);
                if(curNode->left != NULL) q.push(curNode->left);
                if(curNode->right != NULL) q.push(curNode->right);
                q.pop();
            }
            res.insert(res.begin(), temp);
        }
        
        return res;
    }
};