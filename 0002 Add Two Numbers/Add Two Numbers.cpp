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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry_over = 0;
        ListNode* l1_cur = l1;
        ListNode* l2_cur = l2;
        
        // res_cur always point to the last node, whose val has not been filled
        ListNode *fst = new ListNode(0);
        ListNode *res_cur = fst;
        ListNode *prev_ptr = fst;
        
        int counter = 0;
        while(l1_cur != NULL || l2_cur != NULL)
        {
            int l1_val = l1_cur != NULL?l1_cur->val:0;
            int l2_val = l2_cur != NULL?l2_cur->val:0;
            
            int sum = l1_val + l2_val + carry_over;
            res_cur->val = sum % 10;
            carry_over = sum / 10;
            
            ListNode *l = new ListNode(0);
            res_cur->next = l;
            prev_ptr = res_cur;
            res_cur = res_cur->next;
            
            l1_cur = l1_cur != NULL?l1_cur->next:NULL;
            l2_cur = l2_cur != NULL?l2_cur->next:NULL;
        }
        
        // check last carry_over
        if(carry_over > 0)
        {
            res_cur->val = carry_over;
        }
        else
        {
            delete res_cur;
            prev_ptr->next = NULL;
        }
        
        return fst;
    }
};