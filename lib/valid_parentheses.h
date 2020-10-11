#pragma once

#include <string>
#include <vector>

namespace validparentheses
{
    class ValidParentheses {
    public:
        static bool IsValid(const std::string& s);

    private:
        static bool ContainsValue(char ch);
        static bool ContainsKey(char ch);
        static char Pop(std::vector<char>& coll);
    };
}
