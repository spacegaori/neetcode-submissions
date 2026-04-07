class Solution {
public:
    bool hasDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> seen{};
        for (const auto num : nums) {
            auto result = seen.insert(num);
            if (!result.second) {
                return true;
            }
        }

        return false;
    }
};