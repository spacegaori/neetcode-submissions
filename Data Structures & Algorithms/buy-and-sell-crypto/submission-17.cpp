#include <limits>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        auto l = 0;
        auto r = 1;
        auto max_profit = 0;
        auto min_price = prices[0];
        while (r < prices.size()) {
            if (prices[r] < min_price) {
                min_price = prices[r];
                l = r;
                r = l + 1;
            } else {
                max_profit= std::max(max_profit, prices[r] - prices[l]);
                r++;
            }
        }


        return max_profit;
    }
};
