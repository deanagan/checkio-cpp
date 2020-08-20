#include "valid_parentheses.h"

#include <gtest/gtest.h>
#include <string>

namespace validparentheses
{
class ValidParenthesesShould : public ::testing::Test
{
protected:
    void SetUp() override {
    }

    void TearDown() override {

    }
};

class ParameteredValidParenthesesShould : public ValidParenthesesShould,
                           public ::testing::WithParamInterface<std::tuple<const char*, bool>> {

};

INSTANTIATE_TEST_SUITE_P(StringsWithParenthesesToEvaluateAndExpectations,
                         ParameteredValidParenthesesShould,
                         testing::Values(// std::make_tuple("()", true)
                                        // , std::make_tuple("()[]{}", true)
                                        // , std::make_tuple("(]", false)
                                        // , std::make_tuple("([)]", false)
                                        // , std::make_tuple("{[]}", true)
                                        //, std::make_tuple("]", false)
                                        std::make_tuple("(])", false)
                                        //, std::make_tuple("){", false)
                         ));

TEST_P(ParameteredValidParenthesesShould, ReturnExpectedBracketValidity_WhenGivenParameters)
{
    // Arrange
    std::string s;
    bool expectedResult;
    std::tie(s, expectedResult) = GetParam();
    // Act
    const auto result = ValidParentheses::IsValid(s);
    // Assert
    EXPECT_EQ(result, expectedResult);
}


}
