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
    
    // each node should return 2 pieces of information to upper level:
    // - max chain from a leaf up to current node, this is used for upper level to calculate path beyond current node
    // - max path, may include or exclude current node, this is a result of max path that is fully under the subtree of current node
    // use a pair to return (max chain length, max path length)
    
    pair<int, int> maxPathSumUtil(TreeNode* root) {
        if(root == NULL)
            return make_pair(INT_MIN, INT_MIN);
        
        pair<int, int> left_res = maxPathSumUtil(root->left);
        pair<int, int> right_res = maxPathSumUtil(root->right);
        
        // if below current node both chains are negative, discard them
        int max_chain = max(max(left_res.first, right_res.first), 0) + root->val;  
        
        // the max path that does not include current node
        int max_subtrees = max(left_res.second, right_res.second);
        // the max path that include current node
        int max_cur = max(left_res.first, 0) + root->val + max(right_res.first, 0);
        
        int max_path = max(max_subtrees, max_cur);
        
        return make_pair(max_chain, max_path);
    }
    
    int maxPathSum(TreeNode* root) {
        pair<int, int> res = maxPathSumUtil(root);
        
        return res.second;
    }
};