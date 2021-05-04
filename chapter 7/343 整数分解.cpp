
// 343. Integer Break

class Solution {
public:
    int integerBreak(int n) {
        if (n <= 1) {
            return -1;
        }
        
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            for (int k = 1; k < i; k++) {
                dp[i] = max(dp[i], (i - k) * k);
                dp[i] = max(dp[i], dp[i - k] * k);
            }
        }
        
        return dp[n];
    }
};
