class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> freq{};
        for (auto num : nums) {
            freq[num]++;
        }
        
        std::vector<std::vector<int>> bucket(nums.size() + 1);
        for (auto [k, v] : freq) {
            bucket[v].emplace_back(k);
        }

        std::vector<int> top_k{};
        for (int i = nums.size(); i >= 0; i--) {
            for (auto e : bucket[i]) {
                top_k.push_back(e);

                k--;
                if (k == 0) {
                    return top_k;
                }
            }
        }

        return top_k;

    }
};
