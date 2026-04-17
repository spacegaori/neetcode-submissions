class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> count{};
        for (const int num : nums) {
            ++count[num];
        }

        std::vector<std::vector<int>> bucket(nums.size() + 1);
        for (const auto& [num, freq] : count) {
            bucket[freq].emplace_back(num);
        }

        std::vector<int> top{}; top.reserve(k);
        for (int freq{ static_cast<int>(nums.size()) }; freq > 0; --freq) {
            for (int num : bucket[freq]) {
                top.emplace_back(num);

                if (static_cast<int>(top.size()) == k) {
                    return top;
                }
            }

        }

        return top;
    }
};
