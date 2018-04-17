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
    
    // 1. get the length of both list
    // 2. start from beginning of shorter list, and beginning + diff of longer list
    // 3. traverse until two pointers equal
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0;
        int lenB = 0;
        
        ListNode* ptrA = headA;
        while(ptrA != NULL) {
            ++lenA;
            ptrA = ptrA->next;
        }
        ListNode* ptrB = headB;
        while(ptrB != NULL) {
            ++lenB;
            ptrB = ptrB->next;
        }
        
        int diff = abs(lenA - lenB);
        ptrB = headB;
        ptrA = headA;
        if(lenA > lenB)
            for(int i = 0; i < diff; ++i)
                ptrA = ptrA->next;
        else
            for(int i = 0; i < diff; ++i)
                ptrB = ptrB->next;
        
        while(ptrA != NULL && ptrB != NULL) {
            if(ptrA == ptrB)
                return ptrA;
            ptrA = ptrA->next;
            ptrB = ptrB->next;
        }
        
        return NULL;
    }
};