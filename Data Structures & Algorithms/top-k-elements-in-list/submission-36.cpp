#include <ranges>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> freq_map{};
        for (const auto num : nums) {
            freq_map[num]++;
        }

        std::vector<std::vector<int>> bucket(nums.size() + 1);
        for (const auto& [k, v] : freq_map) {
            // std::cout << "[" << k << ", " << v << "]\n";
            bucket[v].push_back(k);
        }

        // int i = 0;
        // for (auto v : bucket) {
        //     std:cout << i << ":\n";
        //     for (auto e : v) {
        //         std::cout << e << ", ";
        //     }
        //     std::cout << "\n";
        //     i++;
        // }

        auto top_k = bucket
            | std::views::join
            | std::views::reverse
            | std::views::take(k);
        

        return std::ranges::to<std::vector>(top_k);
    }
};
