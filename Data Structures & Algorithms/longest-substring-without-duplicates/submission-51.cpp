#include <ranges>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        auto seen_at = std::unordered_map<char, int>(); 

        auto max_length = 0;
        auto l = 0;
        for (auto r = 0; r < s.size(); r++) {
            if (seen_at.find(s[r]) != seen_at.end()) {
                l = std::max(seen_at[s[r]] + 1, l);
            }
            seen_at[s[r]] = r;
            max_length = std::max(max_length, r - l + 1);
        }

        return max_length;
    }
};
