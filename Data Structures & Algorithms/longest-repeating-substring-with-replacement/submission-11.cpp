class Solution {
public:
    int characterReplacement(std::string s, int k) {
        const int n = static_cast<int>(s.size());

        std::unordered_map <char, int> count{};
        int max_length = 0;

        int l = 0;
        int r = 0;
        int most_freq = 0;
        while (r < n) {
            count[s[r]]++;
            most_freq = std::max(most_freq, count[s[r]]);


            while (most_freq + k < (r - l + 1)) {
                count[s[l]]--;
                l++;
            }

            max_length = std::max(max_length, r - l + 1);

            r++;
        }

        return max_length;
    }
};
