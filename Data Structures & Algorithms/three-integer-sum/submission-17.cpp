    class Solution {
    public:
        std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
            std::ranges::sort(nums);
            std::vector<std::vector<int>> triplets{};
            int n = static_cast<int>(nums.size());
            for (int left = 0; left < n - 2; ++left) {
                if (nums[left] > 0) {
                    return triplets;
                }
                
                if (left > 0 && nums[left - 1] == nums[left]) {
                    continue;
                }

                int mid = left + 1;
                int right = n - 1;
                while (mid < right) {
                    int sum = nums[left] + nums[mid] + nums[right];
                    if (sum > 0) {
                        --right;
                    } else if (sum < 0) {
                        ++mid;
                    } else {
                        triplets.push_back({nums[left], nums[mid], nums[right]});
                        while (mid < right && nums[mid] == nums[mid + 1]) {
                            ++mid;
                        }
                        // while (mid < right && nums[right] == nums[right - 1]) {
                            // --right;
                        // }
                        ++mid;
                        // --right;
                    }
                }
            }
            return triplets;
        }
    };
