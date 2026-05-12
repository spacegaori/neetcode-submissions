class Solution {
public:
    int characterReplacement(std::string s, int k) {
        const int n = static_cast<int>(s.size());
        int max_length = 0;

        for (int i = 0; i < n; i++) {
            std::unordered_map<char, int> char_count{};
            int max_freq = 0;
            for (int j = i; j < n; j++) {
                char_count[s[j]]++;
                max_freq = std::max(max_freq, char_count[s[j]]);

                if ((j - i + 1) <= max_freq + k) {
                    max_length = std::max(max_length, j - i + 1);
                }
            }
        }

        return max_length;
    }
};
