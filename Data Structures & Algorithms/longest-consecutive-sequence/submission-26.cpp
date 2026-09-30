class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        std::unordered_set<int> num_set(nums.begin(), nums.end());
        auto longest = 0;
        for (auto num : nums) {
            if (num_set.find(num - 1) != num_set.end()) {
                continue;
            }

            auto count = 0;
            do {
                count++;
            } while (num_set.find(++num) != num_set.end());
            longest = std::max(longest, count);
        }

        return longest;
    }
};
