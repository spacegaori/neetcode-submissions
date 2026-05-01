#include <ranges>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        std::unordered_set<int> head{};
        int max_streak = 0;
        for (int num : nums) {
            if (head.find(num - 1) == head.end()) {
                head.insert(num);
                int streak = 1;
                while (std::ranges::find(nums, ++num) != nums.end()) {
                    ++streak;
                }
                max_streak = std::max(max_streak, streak);
            }
        }

        return max_streak;
    }
};
