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
        ListNode *result = NULL;
        ListNode *last = NULL;
        
        int carry = 0;
        int value = 0;
        
        while ((l1 || l2) || ((!l1 && !l2) && carry)){
            ListNode *node = new ListNode(0);
            
            if(l1 || l2){
                if (l1)
                    value = l1->val;
                if (l2)
                    value += l2->val;
                value = value % 10;
                node->val = value + carry;
                
                if (l1)
                    carry = l1->val;
                if (l2)
                    carry += l2->val;
                carry = carry / 10;

                l1 = l1->next;
                l2 = l2->next;
            }else{
                node->val = carry;
                carry = 0;
            }

            if (NULL == result){
                result = node;
                continue;
            }else{
                last = result;
                while (NULL != last->next)
                    last = last->next;
                last->next = node;
            }
        }
        return result;
    }
};
