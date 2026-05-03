#include <ranges>

class Solution {
public:
    bool isPalindrome(std::string s) {
        auto is_alnum = [](const auto c){ return std::isalnum(c); };
        auto to_lower = [](auto c){ return std::tolower(c); };

        auto filtered = s | std::views::filter(is_alnum)
                       | std::views::transform(to_lower);

        return std::ranges::equal(filtered, filtered | std::views::reverse);
    }
};
