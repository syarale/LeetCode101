// 714. Best Time to Buy and Sell Stock with Transaction Fee

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int len = prices.size();
        vector<int> dp0(len, 0);
        vector<int> dp1(len, INT_MIN);
        
        if (prices.empty() || fee < 0) {
            return 0;
        }
        
        dp0[0] = 0;
        dp1[0] = -prices[0] - fee;
        
        for (int i = 1; i < len; i++) {
            dp0[i] = max(dp0[i - 1], dp1[i - 1] + prices[i]);
            dp1[i] = max(dp1[i - 1], dp0[i - 1] - prices[i] - fee);
        }
        
        return max(dp0[len - 1], dp1[len - 1]);

    }
};
