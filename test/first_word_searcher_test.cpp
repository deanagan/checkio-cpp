#include "first_word_searcher.h"

#include <gtest/gtest.h>

#include <vector>

namespace firstwordsearcher
{
class FirstWordSearcherShould : public ::testing::Test
{
protected:
    void SetUp() override {
    }

    void TearDown() override {

    }

    FirstWordSearcher search_;
};

class ParameteredFirstWordSearcherShouldShould : public FirstWordSearcherShould,
                           public ::testing::WithParamInterface<std::tuple<std::string, std::string>> {

};

INSTANTIATE_TEST_SUITE_P(InputStringAndExpectedResult,
                         ParameteredFirstWordSearcherShouldShould,
                         testing::Values(
                            std::make_tuple("Hello world", "Hello"),
                            std::make_tuple(" a word ",  "a"),
                            std::make_tuple("don't touch it",  "don't"),
                            std::make_tuple("greetings, friends",  "greetings"),
                            std::make_tuple("... and so on ...",  "and"),
                            std::make_tuple("hi",  "hi"),
                            std::make_tuple("Hello.World",  "Hello")
                         ));

TEST_P(ParameteredFirstWordSearcherShouldShould, ReturnFirstWord_WhenMultiWordString)
{
    // Arrange
    std::string inputString;
    std::string expectedResult;
    std::tie(inputString, expectedResult) = GetParam();
    // Act
    const auto result = search_.First(inputString);
    // Assert
    EXPECT_EQ(result, expectedResult);
}


}
