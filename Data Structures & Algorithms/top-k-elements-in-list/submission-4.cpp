#include <ranges>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> frequency{};
        for (const auto num : nums) {
            ++frequency[num];
        }

        std::vector<std::vector<int>> buckets(nums.size() + 1);
        for (const auto& [num, count] : frequency) {
            buckets[count].push_back(num);
        }

        std::vector<int> result{};
        result.reserve(k);
        for (const auto& bucket : std::views::reverse(buckets)) {
            for (auto num : bucket) {
                result.push_back(num);
                if (static_cast<int>(result.size()) == k) {
                    return result;
                }
            }
        }

        return result;
    }
};
