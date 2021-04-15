
// 188. Best Time to Buy and Sell Stock IV

class Solution {
public:
    int maxProfitUnlimited(vector<int>& prices) {
        int maxProfit = 0;
        int len = prices.size();
        
        for (int i = 1; i < len; i++) {
            if (prices[i] > prices[i - 1]) {
                maxProfit += (prices[i] - prices[i - 1]);
            }
        }
        
        return maxProfit;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        
        if (prices.empty()) {
            return 0;
        }
        
        if (k >= len) {
            return maxProfitUnlimited(prices);
        }
        
        vector<int> buy(k + 1, 0);
        vector<int> sell(k + 1, 0);
        
        buy[0][1] = -prices[0];
        
        for (int i = 1; i < len; i++) {
            for (int j = 1; j <= k; j++) {
                buy[j] = max(buy[j], sell[j - 1] - prices[i]);
                sell[j] = max(sell[j], buy[j] + prices[i]);
            }
        }
        
        return sell[k];

    }
}; 
