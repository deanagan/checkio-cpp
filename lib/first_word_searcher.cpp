#include "first_word_searcher.h"
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iterator>

namespace firstwordsearcher
{
    namespace
    {
        const auto APOSTROPHE = '\'';
    }
    std::string FirstWordSearcher::First(const std::string& input) const
    {
        using namespace std;
        std::string output;

        const auto is_valid_char = [](auto ch) { return (isalpha(ch) || (ch == APOSTROPHE)); };

        copy_if(begin(input), end(input), back_inserter(output),
            [&is_valid_char, active = false, done = false](auto ch) mutable {
                if (is_valid_char(ch) && !done) {
                    active = true;
                } else {
                    if (active) {
                        done = true;
                    }
                    active = false;
                }

                return active;
        });

        return output;
    }

}

#define CODERUNNER 0
#if CODERUNNER
int main()
{
    using namespace firstwordsearcher;
    using namespace std;

    FirstWordSearcher searcher;
    std::cout << "*" << searcher.First(" a word") << "* \n";

}
#endif
