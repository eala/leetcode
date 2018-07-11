#ifndef __SOLUTION__
#define __SOLUTION__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
    friend class SolTest;
    private:
    string convert(string s, int numRows);
    vector<int> twoSum(vector<int>& nums, int target); 
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
};

#endif
