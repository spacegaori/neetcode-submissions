#include <ranges>

class Solution {
public:
    bool isPalindrome(std::string s) {
        auto alnum = s | std::views::filter([](const auto c) { return std::isalnum(c); })
                       | std::views::transform([](auto c) { return std::tolower(c); });

        return std::ranges::equal(alnum, alnum | std::views::reverse);
    }
};
