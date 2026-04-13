#include <ranges>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        const int n = static_cast<int>(nums.size());
        if (n < 2) {
            return n;
        }

        // std::cout << "original nums: [ ";
        // for (auto n : nums) {
            // std::cout << n << ' ';
        // }
        // std::cout << "]\n";

        std::ranges::sort(nums);
        auto [first, last] = std::ranges::unique(nums);
        nums.erase(first, last);

        std::cout << "sorted nums: [ ";
        for (auto& n : nums) {
            std::cout << n << ' ';
        }
        std::cout << "]\n";

        std::size_t start = 0;
        int longest = 1;
        while (start < n) {
            std::cout << "start " << start << ":\n";
            std::cout << "longest = " << longest << '\n';
            std::size_t end = start;
            while (end < n && nums[end] + 1 == nums[end + 1]) {
                std::cout << "(nums[end] + 1 = " << nums[end] + 1 << ") == (nums[end + 1] = " << nums[end + 1] << ")\n";
                ++end;
            }
            longest = std::max(longest, static_cast<int>(end - start + 1));
            start = end + 1;
            // std::size_t end = start;
            // while (end < n && nums[end] + 1 == nums[end + 1]) {
        //         ++end;
        //     }
        //     longest = std::max(longest, static_cast<int>(end - start));
        //     auto it = std::find(nums.begin() + start, nums.end(), nums[end + 1]);
        //     start = std::distance(nums.begin(), it);
        }

        return longest;
    }
};
