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
    map<pair<int, int>, int> counts;
    
    int numTrees(int start, int end)
    {
        if(start > end)
            return 1;   // NULL is considered as a tree
        if(start == end)
            return 1;
        
        pair<int, int> key(start, end);
        if(counts.find(key) != counts.end())
            return counts[key];
        
        int result = 0;
            
        for(int i = start; i <= end; ++i)
        {
            int left_start = start;
            int left_end = i - 1;
            int right_start = i + 1;
            int right_end = end;
            
            int leftSubTrees = numTrees(left_start, left_end);
            int rightSubTrees = numTrees(right_start, right_end);
            
            result += leftSubTrees * rightSubTrees;
        }
        
        counts[key] = result;
        return result;
    }
public:
    int numTrees(int n) {
        return numTrees(1, n);
    }
};