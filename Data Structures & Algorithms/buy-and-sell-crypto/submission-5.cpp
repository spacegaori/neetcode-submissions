class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int n{ static_cast<int>(prices.size()) };

        int max_profit{ 0 };
        for (int bought_at = 0; bought_at < n - 1; ++bought_at) {
            for (int sold_at = bought_at + 1; sold_at < n; ++sold_at) {
                std::cout << "Bought at '" << bought_at << "', sold at '" << sold_at << "'\n";
                std::cout << "Current maximum profit = " << max_profit << '\n';
                max_profit = std::max(max_profit, prices[sold_at] - prices[bought_at]);
                std::cout << "Updated maximum profit = " << max_profit << '\n';
            }
        }
        return max_profit;
    }
};
