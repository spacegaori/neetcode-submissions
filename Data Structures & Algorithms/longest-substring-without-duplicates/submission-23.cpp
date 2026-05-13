class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        const int n = static_cast<int>(s.size());

        std::unordered_map<char, int> char_map;

        int max_length = 0;
        int l = 0;
        for (int r = 0; r < n; r++) {
            if (auto it = char_map.find(s[r]); it != char_map.end()) {
                l = std::max(l, it->second + 1);
            }

            char_map[s[r]] = r;
            max_length = std::max(max_length, r - l + 1);
        }

        return max_length;
    }
};
