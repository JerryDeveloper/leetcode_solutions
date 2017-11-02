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
    bool twoSubTreesSymmetric(TreeNode* left, TreeNode* right)
    {
        if(left == NULL && right == NULL)
            return true;
        if((left != NULL && right == NULL) || (left == NULL && right != NULL))
            return false;
        
        return (left->val == right->val) && twoSubTreesSymmetric(left->left, right->right) && twoSubTreesSymmetric(left->right, right->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        
        return twoSubTreesSymmetric(root->left, root->right);
    }
};