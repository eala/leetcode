/**
* Definition for singly-linked list.
* struct ListNode {
*    int val;
*    ListNode *next;
*    ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result = NULL;
        ListNode *tail = NULL;
        int carry = 0;
        int digitSum = 0;
        
        while (NULL != l1 || NULL != l2 || 1  == carry){
            digitSum = carry;
            if (NULL != l1){
                digitSum += l1->val;
                l1 = l1->next;
            }
            if (NULL != l2){
                digitSum += l2->val;
                l2 = l2->next;
            }

            int val = digitSum % 10;
            ListNode *node = new ListNode(val);
            carry = digitSum / 10;

            if (NULL == result){
                result = node;
            }else{
                tail = result;
                while (NULL != tail-> next)
                    tail = tail-> next;
                tail-> next = node;
            }
        }
        return result;
    }
};
