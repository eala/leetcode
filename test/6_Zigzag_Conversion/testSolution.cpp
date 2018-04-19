#include "solution.h"
#include "testSolution.h"

//using ::testing::Return;

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

TEST_F(SolTest, IsSampleStringCorrect) {
    Solution sol;
    EXPECT_STREQ(sol.convert("sample", 3).c_str(), "slapem");
}

TEST_F(SolTest, IsLongPatternCorrect) {
    Solution sol;
    EXPECT_STREQ(sol.convert("bwbyvuwpzbbubozknyxuflsgagtjikxjjyjeufutixpjlqvaotuwemehuxsdkpotpyzjdtcostxdkvfaozwuocdkavn", 78).c_str(), "bwbyvuwpzbbubozknyxuflsgagtjikxjjyjeufutixpjlqvaotuwemehuxsdkpotpnyvzajkddtccoouswtzxodakfv");
}

TEST_F(SolTest, TestPAYPALISHIRING) {
    Solution sol;
    EXPECT_STREQ(sol.convert("PAYPALISHIRING", 3).c_str(), "PAHNAPLSIIGYIR");
}

TEST_F(SolTest, TestSingleRowAB) {
    Solution sol;
    EXPECT_STREQ(sol.convert("AB", 3).c_str(), "AB");
}

TEST_F(SolTest, TestTwoRowABC) {
    Solution sol;
    EXPECT_STREQ(sol.convert("ABC", 2).c_str(), "ACB");
}

TEST_F(SolTest, TestABCDEF) {
    Solution sol;
    EXPECT_STREQ(sol.convert("ABCDEF", 5).c_str(), "ABCDFE");
}
