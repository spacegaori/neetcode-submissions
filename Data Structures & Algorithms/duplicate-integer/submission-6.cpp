class Solution {
public:
    bool hasDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> seen{};
        for (const auto& num : nums) {
            const auto inserted = seen.insert(num).second;
            if (!inserted) {
                return true;
            }
        }

        return false;
    }
};