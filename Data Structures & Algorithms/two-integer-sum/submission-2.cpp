#include <ranges>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, std::size_t> mp{};
        mp.reserve(nums.size());
        for (std::size_t i = 0; i < nums.size(); ++i) {
            auto num = nums[i];
            if (auto it = mp.find(target - num); it != mp.end()) {
                return { static_cast<int>(it->second), static_cast<int>(i) };
            }
            mp[nums[i]] = i;
        }
        
        return { -1, -1 };
    }
};
