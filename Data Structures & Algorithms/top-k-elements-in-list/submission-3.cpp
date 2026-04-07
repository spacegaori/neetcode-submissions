class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> frequency{};
        for (const auto num : nums) {
            ++frequency[num];
        }

        std::vector<std::vector<int>> bucket(nums.size() + 1);
        for (const auto [num, count] : frequency) {
            bucket[count].push_back(num);
        }

        std::vector<int> result{};
        for (auto it = bucket.rbegin(); it != bucket.rend(); ++it) {
            for (auto num : *it) {
                result.push_back(num);

                if (result.size() == k) {
                    return result;
                }
            }
        }
        
    }
};
