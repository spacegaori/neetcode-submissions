class Solution {
public:
    int characterReplacement(std::string s, int k) {
        const int n = static_cast<int>(s.size());

        int max_length = 0;
        for (int l = 0; l < n; l++) {
            std::unordered_map<char, int> count{};
            int most_freq = 0;
            for (int r = l; r < n; r++) {
                count[s[r]]++;
                most_freq = std::max(most_freq, count[s[r]]);

                if (most_freq + k >= r - l + 1) {
                    max_length = std::max(max_length, r - l + 1);
                }
            }
        }

        return max_length;
    }
};
