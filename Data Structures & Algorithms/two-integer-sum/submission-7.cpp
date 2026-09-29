#include <ranges>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> seen{};
        for (auto [i, num] : std::views::enumerate(nums)) {
            if (seen.find(target - num) != seen.end()) {
                return {seen[target-num], static_cast<int>(i)};
            }
            seen[num] = i;
        }

        return {};
    }
};
