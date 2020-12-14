#include "divisibility.h"
#include <algorithm>

namespace divisibility
{
bool Divisibility::IsDivisibleBy8(const std::string& input) const
{
    std::string n = input;
    std::sort(begin(n), end(n));

     do {
        std::string last3digits { n.length() >= 3 ? prev(end(n), 3) : begin(n), end(n) };

        const auto last3 = stoi(last3digits);
        if (last3%8 == 0) {
            return true;
        }

    } while(next_permutation(begin(n), end(n)));

    return false;
}

}
