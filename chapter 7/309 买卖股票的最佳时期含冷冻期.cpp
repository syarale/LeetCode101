
// 309. Best Time to Buy and Sell Stock with Cooldown

class Solution {
public:
    
    const int MIN_VAL = -10001;
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        
        if (prices.empty() || len == 1) {
            return 0;
        }
        
        vector<int> adp0(len, 0);
        vector<int> bdp0(len, 0);
        vector<int> dp1(len, MIN_VAL);
        vector<int> wait0(len, 0);
        
        dp1[0] = -prices[0];
        
        for (int i = 1; i < len; i++) {
            adp0[i] = max(adp0[i - 1], wait0[i - 1]);
            dp1[i] = max(dp1[i - 1], adp0[i] - prices[i]);
            bdp0[i] = dp1[i] + prices[i];
            wait0[i] = bdp0[i - 1];
        }
        
        return max(wait0[len - 1], max(adp0[len - 1], bdp0[len - 1]));

    }
}; 
