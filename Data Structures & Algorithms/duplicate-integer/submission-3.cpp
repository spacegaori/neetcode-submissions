class Solution {
public:
    bool hasDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> seen{};

        for (const auto& n : nums) {
            const auto inserted{ seen.insert(n).second };
            if (!inserted) {
                return true;
            }
        }

        return false;
    }
};