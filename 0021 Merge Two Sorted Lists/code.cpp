/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        
        if(l1 == NULL)
            return l2;
        else if(l2 == NULL)
            return l1;
        
        ListNode* res = new ListNode(0);
        ListNode* cur = res;
        
        while(p1 != NULL && p2 != NULL) {
            if(p1->val < p2->val) {
                cur->next = p1;
                p1 = p1->next;
            }
            else {
                cur->next = p2;
                p2 = p2->next;
            }
            cur = cur->next;
        }
        
        if(p1 != NULL)
            cur->next = p1;
        
        if(p2 != NULL)
            cur->next = p2;
        
        return res->next;
            
    }
};