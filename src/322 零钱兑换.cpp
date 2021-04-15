
// 322. Coin Change

class Solution {
public:
    const int MAX = 10001;
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        
        if (coins.empty()) {
            return -1;
        }
        
        int len = coins.size();
        vector<int> dp(amount + 1, MAX);
        dp[0] = 0;
        
        for (int i = 1; i <= len; i++) {
            for (int j = coins[i - 1]; j <= amount; j++) {
                dp[j] = min(dp[j], dp[j - coins[i - 1]] + 1);
            }
        }
        
        if (dp[amount] < MAX) {
            return dp[amount];
        } else {
            return -1;
        }
    }
}; 
