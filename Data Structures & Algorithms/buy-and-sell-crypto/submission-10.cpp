class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = static_cast<int>(prices.size());

        int l = 0;
        int r = l + 1;
        int max_profit = 0;
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
