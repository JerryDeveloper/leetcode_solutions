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
    
    // preorder takes root first, then left children's root
    // but preorder along cannot tell whether next element is left child, or right child, or right subling
    // inorder gives such info.
    // algo:
    // in preorder take next element, in inorder find the left part and right part of the element, pass sub vector down to next
    // details: https://docs.google.com/presentation/d/1DTuFQBA3-2UzdU4IJojKcyBhf2Mu5k3QWYH_kigCos8/edit#slide=id.g2f4255db6e_0_5
    
    // preorder and inorder should have same length
    TreeNode* buildTreeUtil(const vector<int>& preorder, const int pre_start, const int pre_end, const vector<int>& inorder, const int in_start, const int in_end, const map<int, int> &inorder_map) {
        if(pre_end < 0 || pre_start >= preorder.size() || pre_start > pre_end)
            return NULL;
        
        if(pre_start == pre_end)
            return new TreeNode(preorder[pre_start]);
        
        int cur_root = preorder[pre_start];
        
        int root_in_order = (inorder_map.find(cur_root))->second;
        
        TreeNode* node = new TreeNode(cur_root);
        node->left = buildTreeUtil(preorder, pre_start + 1, pre_start + root_in_order - in_start, inorder, in_start, root_in_order - 1, inorder_map);
        node->right = buildTreeUtil(preorder, pre_start + root_in_order - in_start + 1, pre_end, inorder, root_in_order + 1, in_end, inorder_map);
        return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        map<int, int> inorder_map;
        for(int i = 0; i < inorder.size(); ++i)
            inorder_map[inorder[i]] = i;
        
        return buildTreeUtil(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inorder_map);
    }
};