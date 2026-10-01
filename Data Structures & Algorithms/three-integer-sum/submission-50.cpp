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
                triplets.push_back({num, nums[j], nums[k]});
                while (j < k && nums[j] == nums[j + 1]) {
                    ++j;
                }
                while (j < k && nums[k - 1] == nums[k]) {
                    --k;
                }
                ++j;
                --k;
            }

        }
        
        return triplets;
    }
};
