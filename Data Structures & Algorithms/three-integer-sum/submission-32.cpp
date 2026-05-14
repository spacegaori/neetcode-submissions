class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int> nums) {
        std::sort(nums.begin(), nums.end());

        const int n = static_cast<int>(nums.size());
        std::vector<std::vector<int>> triplets;
        for (int i = 0; i < n; i++) {
            int j = i + 1;
            int k = n - 1;

            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0) {
                    while (nums[j] == nums[j + 1]) {
                        j++;
                    }
                    j++;

                    continue;
                } else if (sum > 0) {
                    while (nums[k] == nums[k - 1]) {
                        k--;
                    }
                    k--;
                    continue;
                }
                triplets.push_back({nums[i], nums[j], nums[k]});
                while (nums[j] == nums[j + 1]) {
                    j++;
                }
                j++;
                while (nums[k] == nums[k - 1]) {
                    k--;
                }
                k--;
            }
        }

        return triplets;
    }
};
