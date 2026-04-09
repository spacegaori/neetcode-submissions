class Solution {
public:
    // 1, 2, 4, 6
    // forward:
    // 1, 1, 2, 8
    // backward:
    // 48, 24, 6, 1
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        std::vector<int> output(nums.size(), 0);
        for (std::size_t i = 0; i < nums.size(); ++i) {
            int product = 1;
            for (std::size_t j = 0; j < nums.size(); ++j) {
                if (i != j) {
                    product *= nums[j];
                }
            }
            output[i] = product;
        }

        return output;
    }
};
