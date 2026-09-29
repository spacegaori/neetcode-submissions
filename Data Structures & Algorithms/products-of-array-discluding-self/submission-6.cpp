class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        const auto n = std::ssize(nums);
        auto product = std::vector<int>(n, 1);
        auto prefix = 1;
        for (auto i = 0; i < n; ++i) {
            product[i] *= prefix;
            prefix *= nums[i];
            // std::cout << prefix << ' ';
        }
        auto postfix = 1;
        for (int j = n - 1; j >= 0; --j) {
            product[j] *= postfix;
            postfix *= nums[j];
            // std::cout << postfix << ' ';
        }
        // std::cout << '\n';
        // for (const auto e : product) {
        //     std::cout << e << ' ';
        // }
        // std::cout << '\n';

        return product;
    }
};
