#include <vector>
#include <string>
#include <ranges>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> anagram_groups{};
        for (const auto& str : strs) {
            auto str_sorted = str;
            std::ranges::sort(str_sorted);
            anagram_groups[str_sorted].push_back(str);
        }

        std::vector<std::vector<std::string>> output{};
        output.reserve(strs.size());
        for (auto& [_, group] : anagram_groups) {
            output.push_back(std::move(group));
        }

        return output;
    }
};
