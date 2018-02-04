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
    
    int sumNumbersUtil(TreeNode* root, int sum) {
        if(root == NULL)
            return 0;
        sum = sum * 10 + root->val;
        if(root->left == NULL && root->right == NULL)
            return sum;
        return sumNumbersUtil(root->left, sum) + sumNumbersUtil(root->right, sum);
    }
    
    int sumNumbers(TreeNode* root) {
        return sumNumbersUtil(root, 0);
    }
};