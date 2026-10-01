#include <ranges>
class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::ranges::sort(nums);

        auto triplets = std::vector<std::vector<int>>();
        for (auto [i, num] : std::views::enumerate(nums)) {
            if (num > 0) {
                break;
            }
            if (i > 0 && nums[i - 1] == num) {
                continue;
            }

            auto j = i + 1;
            auto k = nums.size() - 1;
            while (j < k) {
                auto sum = num + nums[j] + nums[k];
                if (sum < 0) {
                    ++j;
                    continue;
                } else if (sum > 0) {
                    --k;
                    continue;
                }
                triplets.emplace_back(std::vector<int>{num, nums[j], nums[k]});
                ++j;
                --k;
                while (j < k && nums[j - 1] == nums[j]) {
                    ++j;
                }
                while (j < k && nums[k] == nums[k + 1]) {
                    --k;
                }
            }

        }
        
        return triplets;
    }
};
