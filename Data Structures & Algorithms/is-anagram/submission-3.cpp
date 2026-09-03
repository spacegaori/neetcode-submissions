class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        const auto n{ std::ssize(s) };
        if (n != std::ssize(t)) {
            return false;
        }
        std::array<char, 26> seen{};
        for (auto i{ 0 }; i < n; ++i) {
            const auto sKey = s[i] - 'a';
            seen[sKey]++;

            const auto tKey = t[i] - 'a';
            seen[tKey]--;
        }

        return std::all_of(seen.begin(), seen.end(), [](bool b){ return b == 0; });
    }
};
