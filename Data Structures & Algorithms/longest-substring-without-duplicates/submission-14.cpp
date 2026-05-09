class Solution {
public:
    int lengthOfLongestSubstring(const std::string& s) {
        const int n = static_cast<int>(s.size());

        std::unordered_map<char, int> char_map{};

        int l = 0;
        int r = 0;
        int max_length = 0;
        while (r < n) {
            for (int i = l; i <= r; ++i) {
                std::cout << s[i];
            }
            std::cout << '\n';
            if (auto search = char_map.find(s[r]); search != char_map.end()) {
                l = std::max(l, search->second + 1);
            }
            char_map[s[r]] = r;
            max_length = std::max(max_length, r - l + 1);
            r++;
        }

        std::cout << "max length = " << max_length << '\n';

        return max_length;
    }
};
