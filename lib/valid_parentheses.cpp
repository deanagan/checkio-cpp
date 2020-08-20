#include "valid_parentheses.h"
#include <map>
#include <algorithm>
#include <vector>

namespace validparentheses
{

namespace
{
    const std::map<char,char> brackets { {'{', '}'}, {'(', ')'}, {'[',']'} };

}
bool ValidParentheses::IsValid(const std::string& s) {

    if (s.length() % 2U) {
        return false;
    }

    std::vector<char> entries;

    for(const auto ch : s)
    {
        if (brackets.find(ch) != end(brackets)) {
            entries.emplace_back(ch);
        } else if (!entries.empty() && brackets.at(entries.back()) == ch) {
            entries.pop_back();
        }
    }

    return entries.empty();
}

}  // namespace validparentheses