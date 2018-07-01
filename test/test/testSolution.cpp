#include <vector>
#include "include/solution.h"
#include "testSolution.h"

//using ::testing::Return;
using namespace std;

SolTest::SolTest() {
    /*
    // Have qux return true by default
    ON_CALL(m_bar,qux()).WillByDefault(Return(true));
    // Have norf return false by default
    ON_CALL(m_bar,norf()).WillByDefault(Return(false));
    */
}

SolTest::~SolTest() {};

void SolTest::SetUp() {};

void SolTest::TearDown() {};

// Add_two_sum
TEST(TwoSum_Test, IsSampleCorrect) {
    int numsArr[4] = { 2, 7, 11, 15 };
    vector<int> nums(&numsArr[0], &numsArr[0] + 4);

    int goldenArr[2] = { 0, 1};
    vector<int> golden(&goldenArr[0], &goldenArr[0] + 2);

    int target = 9;
    Solution sol;
    EXPECT_EQ(sol.twoSum(nums,target), golden); 
}

// ZigZag_Coversion
TEST(ZigZag_Conversion_Test, IsSampleStringCorrect) {
    Solution sol;
    EXPECT_STREQ(sol.convert("sample", 3).c_str(), "slapem");
}

TEST(ZigZag_Conversion_Test, IsLongPatternCorrect) {
    Solution sol;
    EXPECT_STREQ(sol.convert("bwbyvuwpzbbubozknyxuflsgagtjikxjjyjeufutixpjlqvaotuwemehuxsdkpotpyzjdtcostxdkvfaozwuocdkavn", 78).c_str(), "bwbyvuwpzbbubozknyxuflsgagtjikxjjyjeufutixpjlqvaotuwemehuxsdkpotpnyvzajkddtccoouswtzxodakfv");
}

TEST(ZigZag_Conversion_Test, TestPAYPALISHIRING) {
    Solution sol;
    EXPECT_STREQ(sol.convert("PAYPALISHIRING", 3).c_str(), "PAHNAPLSIIGYIR");
}

TEST(ZigZag_Conversion_Test, TestSingleRowAB) {
    Solution sol;
    EXPECT_STREQ(sol.convert("AB", 3).c_str(), "AB");
}

TEST(ZigZag_Conversion_Test, TestTwoRowABC) {
    Solution sol;
    EXPECT_STREQ(sol.convert("ABC", 2).c_str(), "ACB");
}

TEST(ZigZag_Conversion_Test, TestABCDEF) {
    Solution sol;
    EXPECT_STREQ(sol.convert("ABCDEF", 5).c_str(), "ABCDFE");
}
