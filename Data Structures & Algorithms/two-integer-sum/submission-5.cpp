class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, std::size_t> seen{};
        seen.reserve(nums.size());
        for (std::size_t i = 0; i < nums.size(); ++i) {
            const auto num = nums[i];
            const auto complement = target - num;
            if (auto it = seen.find(complement); it != seen.end()) {
                return { static_cast<int>(it->second), static_cast<int>(i) };
            }
            seen[num] = i;
        }
        
        return { -1, -1 };
    }
};
