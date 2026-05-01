#include <ranges>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        std::unordered_set<int> num_set(nums.begin(), nums.end());

        int max_streak = 0;
        for (int num : num_set) {
            if (num_set.find(num - 1) == num_set.end()) {
                int streak = 1;
                while (num_set.find(num + 1) != num_set.end()) {
                    ++num;
                    ++streak;
                }
                max_streak = std::max(max_streak, streak);
            }
        }

        return max_streak;
    }
};
