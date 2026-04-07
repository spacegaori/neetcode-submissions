#include <vector>
#include <string>
#include <ranges>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> anagram_group{};
        for (const auto& str : strs) {
            auto str_sorted = str;
            std::ranges::sort(str_sorted);
            anagram_group[str_sorted].push_back(str);
        }

        std::vector<std::vector<std::string>> output{};
        for (const auto& [_, group] : anagram_group) {
            output.push_back(group);
        }

        return output;
    }
};
