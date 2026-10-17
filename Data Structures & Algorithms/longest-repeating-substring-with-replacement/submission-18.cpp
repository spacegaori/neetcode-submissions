class Solution {
public:
    int characterReplacement(std::string_view sv, int k) {
        const int n = static_cast<int>(sv.size());
        if (n < 2) {
            return n;
        }
        
        auto char_count = std::vector<int>(26, 0);

        auto max_count = 0;
        auto max_len = 0;
        auto i = std::size_t{0};
        for (auto j = i; j < n; ++j) {
            auto ch = sv[j] - 'A';
            char_count[ch]++;
            max_count = std::max(max_count, char_count[ch]);

            if ((static_cast<int>(j - i) + 1) > max_count + k) {
                --char_count[sv[i] - 'A'];
                ++i;
            }

            max_len = std::max(max_len, static_cast<int>(j - i) + 1);
        }

        return max_len;
    }
};
