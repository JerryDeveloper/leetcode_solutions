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
    void traverseDown(vector<vector<int>> &res, int curLevel, TreeNode* curNode)
    {
        if(curNode == NULL)
            return;
        
        if(curLevel > res.size())
        {
            // reached a level that is never traversed before
            res.insert(res.begin(), vector<int>());
        }
        
        res[res.size() - curLevel].push_back(curNode->val);
        traverseDown(res, curLevel + 1, curNode->left);
        traverseDown(res, curLevel + 1, curNode->right);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        // DFS
        
        vector<vector<int>> res;
        
        traverseDown(res, 1, root);
        
        return res;
    }
};