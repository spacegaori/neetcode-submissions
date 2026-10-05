#include <ranges>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        auto n = static_cast<int>(s.size());
        if (n < 2) {
            return n;
        }
        auto max_length = 0;
        auto seen_at = std::unordered_map<char, int>(); 
        auto l = 0;
        auto r = l;
        while (r < n) {
            // std::cout << '\'';
            for (int i = l; i <= r; i++) {
                // std::cout << s[i];
            }
            // std::cout << "\'\n";
            // std::cout << '(' << l << ',' << r << ')' << '\n';
            // std::cout << "length = r - l + 1 = " << r - l + 1 << "\n";
            auto c = s[r];
            // std::cout << c << '\n';
            if (auto it = seen_at.find(c); it != seen_at.end()) {
                // std::cout << "seen this before, need update on map and l\n";
                // std::cout << "l moved from " << l;
                l = std::max(l, seen_at[c] + 1);
                // std::cout << " to " << l << '\n';
            }
            max_length = std::max(max_length, r - l + 1);
            seen_at[c] = r;
            ++r;
            // std::cout << '\n';
        }

        return max_length;
    }
};
