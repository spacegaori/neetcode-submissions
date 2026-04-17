class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> count{};
        for (const int num : nums) {
            ++count[num];
        }


        std::unordered_map<int, std::vector<int>> bucket{};
        for (auto [key, value] : count) {
            bucket[value].emplace_back(key);
            std::cout << "Added " << value << " to key (" << key << ")\n";
            
        }

        auto it = std::ranges::max_element(bucket,
        [](const auto& a, const auto& b) {
            return a.first < b.first; // Compare keys
        }); 
        std::vector<int> top{};
        for (auto i{ std::ssize(nums) + 1 }; i >= 0; --i) {
            std::cout << "bucket[" << i << "]\n";
            if (bucket[i].empty()) {
                continue;
            }
            for (int e : bucket[i]) {
                top.emplace_back(e);

                if (top.size() == k) {
                    return top;
                }
            }
        }

        return top;
    }
};
