/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

static const int x = []() 
{     
    ios::sync_with_stdio(false);     
    cin.tie(nullptr);     
    return 0;
}();

class Solution {
public:
    // two pointers, one run fast, one run slow. if there's cycle, altimately they will meet
    
    bool hasCycle(ListNode *head) {
        
        if(head == NULL)
            return false;
        
        ListNode* fast = head->next;
        ListNode* slow = head;
        
        while(fast != NULL && fast != slow) {
            fast = fast->next;
            slow = slow->next;
            
            if(fast != NULL)
                fast = fast->next;
        }
        
        return fast == slow;
    }
};