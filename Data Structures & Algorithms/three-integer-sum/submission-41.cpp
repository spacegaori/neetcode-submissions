#include <ranges>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::ranges::sort(nums);
        if (nums[0] > 0) {
            return {};
        }

        auto triplets = std::vector<std::vector<int>>{};
        for (auto [i, num] : std::views::enumerate(nums)) {
            if (i > 0 && nums[i - 1] == num) {
                continue;
            }
            if (num > 0) {
                break;
            }

            auto left = i + 1;
            auto right = static_cast<int>(std::ssize(nums)) - 1;
            while (left < right) {
                const auto sum = num + nums[left] + nums[right];
                if(sum < 0) {
                    ++left;
                } else if (sum > 0) {
                    --right;
                } else {
                    triplets.emplace_back(std::vector{num, nums[left], nums[right]});
                    ++left;
                    --right;

                    while (left < right && nums[left - 1] == nums[left]) {
                        ++left;
                    }
                    while (left < right && nums[right] == nums[right + 1]) {
                        --right;
                    }
                }
            }
        }

        return triplets;
    }
};
