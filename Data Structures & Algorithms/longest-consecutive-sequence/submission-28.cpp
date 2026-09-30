class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        std::unordered_set<int> num_set(nums.begin(), nums.end());
        auto max_length = 0;
        for (auto num : nums) {
            if (num_set.find(num - 1) != num_set.end()) {
                continue;
            }

            auto length = 1;
            while (num_set.find(++num) != num_set.end()) {
                ++length;
            }
            max_length = std::max(max_length, length);
        }

        return max_length;
    }
};
