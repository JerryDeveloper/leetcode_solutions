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
    TreeNode* treeBuilder(const vector<int>& nums, int start, int end)
    {
        if(end <= start)
            return NULL;
        
        int mid = start + (end - start) / 2;
        TreeNode *curRoot = new TreeNode(nums[mid]);
        
        curRoot->left = treeBuilder(nums, start, mid);
        curRoot->right = treeBuilder(nums, mid + 1, end);
        
        return curRoot;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return treeBuilder(nums, 0, nums.size());
    }
};