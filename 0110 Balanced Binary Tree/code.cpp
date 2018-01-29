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
    
    int isBalancedUtil(TreeNode* cur_node) {
        if(cur_node == NULL)
            return 0;
        
        int left_height = isBalancedUtil(cur_node->left);
        if(left_height == -1)
            return -1;
        
        int right_height = isBalancedUtil(cur_node->right);
        
        if(right_height == -1 || abs(left_height - right_height) > 1)
            return -1;
        else
            return max(left_height, right_height) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        return isBalancedUtil(root) != -1;
    }
};