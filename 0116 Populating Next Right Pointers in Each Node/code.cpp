/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        queue<TreeLinkNode*> q;
        if(root)
            q.push(root);
        
        while(!q.empty()) {
            int counter = q.size() - 1;
            TreeLinkNode *prev = q.front();
            q.pop();
            if(prev->left)
                q.push(prev->left);
            if(prev->right)
                q.push(prev->right);
            
            while(counter > 0) {
                TreeLinkNode *cur = q.front();
                q.pop();
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
                
                prev->next = cur;
                prev = cur;
                --counter;
            }
            
            prev->next = NULL;
        }
    }
};