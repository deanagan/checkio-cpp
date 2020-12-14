#include "divisibility.h"

#include <gtest/gtest.h>

#include <vector>

namespace divisibility
{
class DivisibilityTest : public ::testing::Test
{
protected:
    void SetUp() override {
    }

    void TearDown() override {

    }

    Divisibility sut_;
};

class ParameteredDivisibilityTest : public DivisibilityTest,
                           public ::testing::WithParamInterface<std::tuple<std::string, bool>> {

};

INSTANTIATE_TEST_SUITE_P(InputStringAndExpectedResult,
                         ParameteredDivisibilityTest,
                         testing::Values(
                            std::make_tuple("75", false),
                            std::make_tuple("61", true),
                            std::make_tuple("12123123123123123123123008", true)
                         ));

TEST_P(ParameteredDivisibilityTest, ShouldReturnIfDivisibleBy8)
{
    // Arrange
    std::string inputString;
    bool expectedResult;
    std::tie(inputString, expectedResult) = GetParam();
    // Act
    const auto result = sut_.IsDivisibleBy8(inputString);
    // Assert
    EXPECT_EQ(result, expectedResult);
}


}
