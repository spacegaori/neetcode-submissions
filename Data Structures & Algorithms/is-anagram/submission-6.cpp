class Solution {
public:
    bool isAnagram(const std::string& s, const std::string& t) {
        return std::ranges::is_permutation(s, t);
    }
};
