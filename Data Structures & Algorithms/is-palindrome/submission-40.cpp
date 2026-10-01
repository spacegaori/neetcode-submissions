#include <ranges>

class Solution {
public:
    bool isPalindrome(std::string s) {
        auto is_alnum = [](auto ch){ return std::isalnum(static_cast<unsigned char>(ch)); };
        auto to_lower = [](auto ch){ return std::tolower(static_cast<unsigned char>(ch)); };
        auto forward_view = s | std::views::filter(is_alnum) | std::views::transform(to_lower);
        auto reverse_view = forward_view | std::views::reverse;

        return std::ranges::equal(forward_view, reverse_view);
    }
};
