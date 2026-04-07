#include <ranges>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, std::size_t> mp{};
        for (const auto [index, num] : std::views::enumerate(nums)) {
            if (mp.contains(target - num)) {
                return { mp[target-num], index };
            }
            mp[num] = index;
        }
        
        return { -1, -1 };
    }
};
