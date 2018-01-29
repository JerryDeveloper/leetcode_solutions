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
    
    TreeNode* buildTreeUtil(const vector<int>& inorder, const int in_start, const int in_end, const vector<int>& postorder, const int post_start, const int post_end, const map<int, int> &inorder_map) {
        if(in_end < 0 || in_start >= inorder.size() || in_start > in_end)
            return NULL;
        
        if(in_start == in_end)
            return new TreeNode(inorder[in_start]);
        
        int cur_root = postorder[post_end];
        
        int root_in_order = (inorder_map.find(cur_root))->second;
        
        TreeNode* node = new TreeNode(cur_root);
        node->left = buildTreeUtil(inorder, in_start, root_in_order - 1, postorder, post_start, post_start + root_in_order - in_start - 1, inorder_map);
        node->right = buildTreeUtil(inorder, root_in_order + 1, in_end, postorder, post_start + root_in_order - in_start, post_end - 1, inorder_map);
        return node;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        map<int, int> inorder_map;
        for(int i = 0; i < inorder.size(); ++i) 
            inorder_map[inorder[i]] = i;
        
        return buildTreeUtil(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, inorder_map);
    }
};