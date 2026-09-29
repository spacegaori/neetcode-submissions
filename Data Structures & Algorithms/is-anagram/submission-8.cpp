#include <ranges>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.size() != t.size()) return false;

        std::array<int, 27> char_map{};
        for (auto [i, c] : std::views::enumerate(s)) {
            char_map[s[i] - 'a']++;
            char_map[t[i] - 'a']--;
        }

        return std::ranges::all_of(char_map, [](int x) { return x == 0; });
    }
};
