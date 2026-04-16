#include <ranges>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(const std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> anagrams{};
        for (const std::string& str : strs) {
            std::string str_sorted{ str };
            std::ranges::sort(str_sorted);
            anagrams[str_sorted].emplace_back(str);
        }
        std::vector<std::vector<std::string>> output{};
        output.reserve(anagrams.size());
        for (auto& [_, vec] : anagrams) {
            output.emplace_back(std::move(vec));
        }

        return output;
    }
};
