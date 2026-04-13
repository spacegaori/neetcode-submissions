#include <ranges>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        if (nums.empty()) return 0;

        std::ranges::sort(nums);
        auto [first, last] = std::ranges::unique(nums);
        nums.erase(first, last);

        const std::size_t n = nums.size();
        int longest = 1;
        int current = 1;
        for (std::size_t i = 1; i < n; ++i) {
            if (nums[i - 1] + 1 == nums[i]) {
                ++current;
            } else {
                current = 1;
            }

            longest = std::max(longest, current);
        }

        return longest;
    }
};
