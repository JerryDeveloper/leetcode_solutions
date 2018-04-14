/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

static int x = [](){ 
    std::ios::sync_with_stdio(false); 
    cin.tie(NULL);  
    return 0; 
}();

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return NULL;
        
        ListNode* prev = head;
        ListNode* cur = head->next;
        
        while(cur != NULL) {
            if(prev->val != cur->val) {
                prev->next = cur;
                prev = cur;
            }
            cur = cur->next;
        }
        
        prev->next = cur;
        
        return head;
    }
};