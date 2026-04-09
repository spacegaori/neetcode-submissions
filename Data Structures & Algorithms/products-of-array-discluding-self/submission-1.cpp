class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        // naive
        // std::size_t n = nums.size();
        // std::vector<int> output(n, 1);
        // for (std::size_t i = 0; i < nums.size(); ++i) {
        //     int product = 1;
        //     for (std::size_t j = 0; j < nums.size(); ++j) {
        //         if (i != j) {
        //             product *= nums[j];
        //         }
        //     }
        //     output[i] = product;
        // }

        // optimal
        int n = static_cast<int>(nums.size());
        std::vector<int> output(n, 1);

        int prefix = 1;
        for (int i = 0; i < n; ++i) {
            output[i] *= prefix;
            prefix *= nums[i];
        }

        int suffix = 1;
        for (int i = n - 1; i >= 0; --i) {
            output[i] *= suffix;
            suffix *= nums[i];
        }

        return output;
    }
};
