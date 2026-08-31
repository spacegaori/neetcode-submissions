class Solution {
public:
    bool isPalindrome(const std::string& s) {
        int l{ 0 };
        int r{ static_cast<int>(s.length()) - 1 };

        auto is_alnum = [](char c) {
            return std::isalnum(static_cast<unsigned char>(c));
        };
        auto to_lower = [](char c) {
            return std::tolower(static_cast<unsigned char>(c));
        };

        while (l < r) {
            while (l < r && !is_alnum(s[l])) {
                l++;
            }
            while (l < r && !is_alnum(s[r])) {
                r--;
            }

            if (to_lower(s[l]) != to_lower(s[r])) {
                return false;
            }

            l++; r--;
        }

        return true;
    }
};
