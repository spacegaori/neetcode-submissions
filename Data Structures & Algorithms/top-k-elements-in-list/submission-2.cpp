#include <vector>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> frequency{};
        for (int num : nums) {
            ++frequency[num];
        }

        std::vector<std::vector<int>> bucket(nums.size() + 1);
        for (const auto& [num, count] : frequency) {
            bucket[count].push_back(num);
        }

        std::vector<int> result{};
        result.reserve(k);
        for (auto it = std::rbegin(bucket); it != std::rend(bucket); ++it) {
            for (int num : *it) {
                result.push_back(num);
                if (static_cast<int>(result.size()) == k) {
                    return result;
                }
            }
        }

        return result;
    }
};
