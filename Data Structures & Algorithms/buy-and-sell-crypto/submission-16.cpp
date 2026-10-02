#include <limits>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        auto max_profit = 0;
        auto min_price = std::numeric_limits<int>::max();
        for (auto price : prices) {
            max_profit = std::max(max_profit, price - min_price);
            min_price = std::min(min_price, price);
        }
            
        return max_profit;
    }
};
