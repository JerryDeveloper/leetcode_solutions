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
    int numTrees(int n) {
        int count[n + 1] = {0};
        count[0] = 1;
        count[1] = 1;
        
        for(int i = 2; i <= n; ++i)
        {
            // calculate num of BST for each [1, i]
            
            for(int j = 1; j <= i; ++j)
            {
                // set root = j
                count[i] += (count[j - 1] * count[i - j]);
            }
        }
        
        return count[n];
    }
};