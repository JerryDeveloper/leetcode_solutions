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
    
    void pathSum(TreeNode* root, int sum, vector<int> &cur_path, vector<vector<int>> &res) {
        if(root == NULL)
            return;
        
        cur_path.push_back(root->val);
        if(root->left == NULL && root->right == NULL && root->val == sum)            
            res.push_back(cur_path);

        pathSum(root->left, sum - root->val, cur_path, res);
        pathSum(root->right, sum - root->val, cur_path, res);
        
        cur_path.pop_back();
        
        return;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> cur_path;
        pathSum(root, sum, cur_path, res);
        
        return res;
    }
};