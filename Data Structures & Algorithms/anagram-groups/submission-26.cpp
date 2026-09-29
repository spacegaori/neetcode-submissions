class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<string>> anagram_map{};
        for (auto str : strs) {
            auto sorted_str = str;
            std::ranges::sort(sorted_str);
            anagram_map[sorted_str].emplace_back(str);
        }
        
        std::vector<std::vector<std::string>> anagrams{};
        for (auto [_, value] : anagram_map) {
            anagrams.emplace_back(value);
        }

        return anagrams;
    }
};
