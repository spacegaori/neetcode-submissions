class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> anagram_map{};

        for (std::string s : strs) {
            std::string s_sorted = s;
            std::sort(s_sorted.begin(), s_sorted.end());

            anagram_map[s_sorted].push_back(s);
        }

        std::vector<std::vector<std::string>> anagrams{};
        for (auto [_, strs] : anagram_map) {
            anagrams.push_back(strs);
        }

        return anagrams;
    }
};
