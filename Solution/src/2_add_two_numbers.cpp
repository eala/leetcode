/*
Ref: https://leetcode.com/problems/add-two-numbers/description/

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

#include "solution.h"

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {
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
