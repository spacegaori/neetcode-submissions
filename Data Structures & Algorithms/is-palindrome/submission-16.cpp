#include <ranges>

class Solution {
public:
    bool isPalindrome(std::string s) {
        const auto isalnum = [](const auto c){ return std::isalnum(c); };

        auto alnum = s | std::views::filter(isalnum)
                       | std::views::transform([](auto c) { return std::tolower(c); });

        return std::ranges::equal(alnum, alnum | std::views::reverse);
    }
};
