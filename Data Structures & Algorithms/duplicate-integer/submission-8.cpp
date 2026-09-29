class Solution {
public:
    bool hasDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> seen{};
        for (auto num : nums) {
            auto inserted = seen.insert(num).second;
            if (!inserted) {
                return true;
            }
        }

        return false;
    }
};