#include <vector>
#include "solution.h"
#include "testSolution.h"
#include "LeetcodeConfig.h"

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

TEST_F(SolTest, solReturnTwoSum)
{
    int numsArr[4] = { 2, 7, 11, 15 };
    vector<int> nums(&numsArr[0], &numsArr[0] + 4);

    int goldenArr[2] = { 0, 1};
    vector<int> golden(&goldenArr[0], &goldenArr[0] + 2);

    int target = 9;
    EXPECT_EQ(twoSum(nums,target), golden);
}

// Add_two_sum
TEST_F(SolTest, TwoSumTestIsSampleCorrect) {
    int numsArr[4] = { 2, 7, 11, 15 };
    vector<int> nums(&numsArr[0], &numsArr[0] + 4);

    int goldenArr[2] = { 0, 1};
    vector<int> golden(&goldenArr[0], &goldenArr[0] + 2);

    int target = 9;
    EXPECT_EQ(twoSum(nums,target), golden);
}

// ZigZag_Coversion
TEST_F(SolTest, ZigZag_Conversion_Test_SampleStringCorrect) {
    EXPECT_STREQ(convert("sample", 3).c_str(), "slapem");
}

TEST_F(SolTest, ZigZag_Conversion_Test_IsLongPatternCorrect) {
    EXPECT_STREQ(convert("bwbyvuwpzbbubozknyxuflsgagtjikxjjyjeufutixpjlqvaotuwemehuxsdkpotpyzjdtcostxdkvfaozwuocdkavn", 78).c_str(), "bwbyvuwpzbbubozknyxuflsgagtjikxjjyjeufutixpjlqvaotuwemehuxsdkpotpnyvzajkddtccoouswtzxodakfv");
}

TEST_F(SolTest, ZigZag_Conversion_Test_TestPAYPALISHIRING) {
    EXPECT_STREQ(convert("PAYPALISHIRING", 3).c_str(), "PAHNAPLSIIGYIR");
}

TEST_F(SolTest, ZigZag_Conversion_Test_TestSingleRowAB) {
    EXPECT_STREQ(convert("AB", 3).c_str(), "AB");
}

TEST_F(SolTest, ZigZag_Conversion_Test_TestTwoRowABC) {
    EXPECT_STREQ(convert("ABC", 2).c_str(), "ACB");
}

TEST_F(SolTest, ZigZag_Conversion_Test_TestABCDEF) {
    EXPECT_STREQ(convert("ABCDEF", 5).c_str(), "ABCDFE");
    cout << "library version: " << LEETCODE_VERSION_MAJOR << "." << LEETCODE_VERSION_MINOR << endl;
}
