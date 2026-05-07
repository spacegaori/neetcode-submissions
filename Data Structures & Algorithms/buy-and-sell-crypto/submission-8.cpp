class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int n{ static_cast<int>(prices.size()) };

        int max_profit{ 0 };
        int l = 0;
        int r = l + 1;
        while (r < n) {
            if (prices[l] > prices[r]) {
                l = r;
            } else {
                max_profit = std::max(max_profit, prices[r] - prices[l]);
            }
            ++r;
        }
        return max_profit;
    }
};
