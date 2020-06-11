#include "nearest_value_searcher.h"

#include "gtest/gtest.h"

#include <vector>

namespace nearestvaluesearcher
{
class NearestValueSearcherShould : public ::testing::Test
{
protected:
    void SetUp() override {
    }

    void TearDown() override {

    }

    NearestValueSearcher search_;
};

class ParameteredNearestValueSearcherShould : public NearestValueSearcherShould,
                           public ::testing::WithParamInterface<std::tuple<std::vector<int>, int, int>> {

};

INSTANTIATE_TEST_SUITE_P(NumbersAndSearchPointThenExpectedClosest,
                         ParameteredNearestValueSearcherShould,
                         testing::Values(
                            std::make_tuple(std::vector<int>{4, 7, 10, 11, 12, 17}, 9, 10),
                            std::make_tuple(std::vector<int>{4, 7, 10, 11, 12, 17}, 8, 7),
                            std::make_tuple(std::vector<int>{4, 8, 10, 11, 12, 17}, 9, 8),
                            std::make_tuple(std::vector<int>{4, 9, 10, 11, 12, 17}, 9, 9),
                            std::make_tuple(std::vector<int>{4, 7, 10, 11, 12, 17}, 0, 4),
                            std::make_tuple(std::vector<int>{4, 7, 10, 11, 12, 17}, 100, 17),
                            std::make_tuple(std::vector<int>{5, 10, 8, 12, 89, 100}, 7, 8),
                            std::make_tuple(std::vector<int>{-1, 2, 3}, 0, -1),
                            std::make_tuple(std::vector<int>{0, -2}, -1, -2)
                         ));

TEST_P(ParameteredNearestValueSearcherShould, ReturnNearestNumber_WhenGivenParameters)
{
    // Arrange
    std::vector<int> numbers;
    int searchNumber, expectedResult;
    std::tie(numbers, searchNumber, expectedResult) = GetParam();
    // Act
    const auto result = search_.Nearest(numbers, searchNumber);
    // Assert
    EXPECT_EQ(result, expectedResult);
}


}
