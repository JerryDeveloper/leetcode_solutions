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
    vector<TreeNode*> generateTrees(int start, int end)
    {
        // make sure end >= start when calling this
        
        if(start == end)
            return vector<TreeNode*> {new TreeNode(start)};
            
        vector<TreeNode*> result;
            
        for(int i = start; i <= end; ++i)
        {
            int left_start = start;
            int left_end = i - 1;
            int right_start = i + 1;
            int right_end = end;
            
            vector<TreeNode*> leftSubTrees;
            if(left_start > left_end)
                leftSubTrees = vector<TreeNode*> {NULL};
            else
                leftSubTrees = generateTrees(left_start, left_end);
                
            vector<TreeNode*> rightSubTrees;
            if(right_start > right_end)
                rightSubTrees = vector<TreeNode*> {NULL};
            else
                rightSubTrees = generateTrees(right_start, right_end);
            
            for(auto le: leftSubTrees)
            { 
                for(auto ri: rightSubTrees)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = le;
                    root->right = ri;
                    
                    result.push_back(root);
                }
            }
        }
        
        return result;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return generateTrees(1, n);
    }
};