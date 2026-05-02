class Solution {
public:
    bool isPalindrome(std::string s) {
        if (s.size() < 2) {
            return true;
        }

        int left = 0;
        int right = static_cast<int>(s.size() - 1);
        while (left < right) {
            while (!std::isalnum(s[left])) {
                ++left;
            }
            while (!std::isalnum(s[right])) {
                --right;
            }

            if (left >= right) {
                break;
            }

            if (std::tolower(s[left]) != std::tolower(s[right])) {
                return false;
            }
            ++left;
            --right;
        }

        return true;
    }
};
