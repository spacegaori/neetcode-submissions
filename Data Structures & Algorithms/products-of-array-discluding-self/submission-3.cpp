class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums)
    {
        const int n = std::size(nums);
        std::vector<int> output(n, 1);
    
        int prefix = 1;
        for (int i = 1; i < n; ++i) {
            prefix *= nums[i - 1];
            output[i] = prefix;
        }
        // nums     = { 1, 2, 4, 6 }
        // loop 1:
        //                 v
        // output   = { 1, 1, 1, 1 }
        // prefix   = 1 * nums[0] = 1 * 1 = 1
        // output[1]= 1 = 1
        // loop 2:
        //                    v
        // output   = { 1, 1, 2, 1 }
        // prefix   = 1 * nums[1] = 1 * 2 = 2
        // output[2]= 2
        // loop 3:
        //                       v
        // output   = { 1, 1, 2, 8 }
        // prefix   = 2 * nums[2] = 2 * 4 = 8
        // output[3]= 8
    
        int suffix = 1;
        for (int i = n - 2; i >= 0; --i) {
            suffix *= nums[i + 1];
            output[i] *= suffix;
        }
        // nums     = { 1, 2, 4, 6 }
        // loop 2:
        //                    v
        // output   = { 1, 1, 2, 8 }
        // suffix   = 1 * nums[3] = 1 * 6 = 6
        // output[2]= 2 * 6 = 12
        // output   = { 1, 1, 12, 8 }
        //
        // loop 1:
        //                 v
        // output   = { 1, 1, 12, 8 }
        // suffix   = 12 * nums[2] = 12 * 2 = 24
        // output[1]= 1 * 24 = 24
        // output   = { 1, 24, 12, 8 }
        //
        // loop 0:
        //              v
        // output   = { 1, 24, 12, 8 }
        // suffix   = 24 * nums[1] = 24 * 2 = 48
        // output[0]= 1 * 48 = 48
        // output   = { 48, 24, 12, 8 }
        return output;
    }
};
