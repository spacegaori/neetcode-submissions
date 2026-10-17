class Solution {
public:
    int lengthOfLongestSubstring(std::string_view sv) {
        auto i = std::size_t{0};
        auto max_length = 0;
        auto seen_at = std::unordered_map<char, std::size_t>{};
        // go through each character in string
        for (auto j = i; j < sv.size(); ++j) {
            // if the character is already seen
            // check the dictionary and update the 
            // window achordingly
            if (auto it = seen_at.find(sv[j]); it != seen_at.end()) {
                auto dest = std::max(i, it->second + 1);
                i = dest;
            }
            seen_at[sv[j]] = j;

            max_length = std::max(max_length, static_cast<int>(j - i) + 1);
        }

        return max_length;
    }
};
