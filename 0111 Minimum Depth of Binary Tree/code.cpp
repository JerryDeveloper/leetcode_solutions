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
    int minDepth(TreeNode* root) {
        queue<TreeNode*> q;
        if(root)
            q.push(root);
        else
            return 0;
        
        int depth = 1;
        bool found_first_leaf = false;
        while(q.size() > 0) {
            int counter = q.size();
            
            while(counter > 0) {
                TreeNode* cur = q.front();
                q.pop();
                
                bool has_child = false;
                if(cur->left) {
                    q.push(cur->left);
                    has_child = true;
                }
                if(cur->right) {
                    q.push(cur->right);
                    has_child = true;
                }
                
                if(!has_child) {
                    found_first_leaf = true;
                    break;
                }
                
                --counter;
            }
            
            if(found_first_leaf)
                break;
            
            ++depth;
        }
        
        return depth;
    }
};