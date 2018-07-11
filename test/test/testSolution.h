#include "gtest/gtest.h"
#include "solution.h"

// The fixture for testing class Solution
class SolTest : public ::testing::Test {

protected:

    // You can do set-up work for each test here.
    SolTest();

    // You can do clean-up work that doesn't throw exceptions here.
    virtual ~SolTest();

    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:

    // Code here will be called immediately after the constructor (right
    // before each test).
    virtual void SetUp();

    // Code here will be called immediately after each test (right
    // before the destructor).
    virtual void TearDown();

    string convert(string s, int numRows){return sol.convert(s, numRows);}
    vector<int> twoSum(vector<int>& nums, int target){return sol.twoSum(nums, target);}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){return sol.addTwoNumbers(l1, l2);}

private:
    Solution sol;
};
