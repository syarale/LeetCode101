
// 279. Perfect Squares

class Solution {
public:
    const int MAX = 100001;
    int numSquares(int n) {
        // assert(n > 0);
        
        vector<int> dp(n + 1, MAX); 
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int k = 1; k * k <= i; k++) {
                dp[i] = min(dp[i], dp[i - k * k] + 1);
            }
        }
        
        return dp[n];
    }
}; 
