class Solution {
public:
    int characterReplacement(std::string s, int k) {
        const int n = static_cast<int>(s.size());

        std::unordered_map<char, int> char_count{};

        int l = 0;
        int max_freq = 0;
        int max_length = 0;
        for (int r = 0; r < n; r++) {
            char_count[s[r]]++;
            max_freq = std::max(max_freq, char_count[s[r]]);

            while (max_freq + k < (r - l + 1)) {
                char_count[s[l]]--;
                l++;
            }

            max_length = std::max(max_length, r - l + 1);
        }
        
        return max_length;
    }
};
