#include <array>
#include <algorithm>
#include <ranges>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        std::array<int, 26> chars{};

        if (s.size() != t.size()) {
            return false;
        }

        for (std::size_t i = 0; i < s.size(); ++i) {
            chars[s[i] - 'a']++;
            chars[t[i] - 'a']--;
        }

        return std::ranges::all_of(chars, [](int i){ return i == 0; });
    }
};
