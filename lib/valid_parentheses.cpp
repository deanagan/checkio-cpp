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

bool ValidParentheses::ContainsValue(char ch) {
    return std::find_if(begin(brackets), end(brackets), [ch](auto bp) {
        return bp.second == ch;
    }) != end(brackets);
}

bool ValidParentheses::ContainsKey(char ch) {
    return brackets.find(ch) != end(brackets);
}

char ValidParentheses::Pop(std::vector<char>& coll) {
    const auto ch = coll.back();
    coll.pop_back();
    return ch;
}

bool ValidParentheses::IsValid(const std::string& s) {

    std::vector<char> entries { '\0' };

    for(const auto ch : s)
    {
        if (ContainsKey(ch)) {
            entries.emplace_back(brackets.at(ch));
        } else if (ContainsValue(ch) && (ch != Pop(entries))) {
            return false;
        }
    }

    return (entries.size() == 1) && (entries.at(0) == '\0');
}

}  // namespace validparentheses