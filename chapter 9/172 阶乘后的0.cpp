
// 172. Factorial Trailing Zeroes

class Solution {
public:
    int trailingZeroes(int n) {
        if(n <= 4) {
            return 0;
        }

        vector<int>dp (n + 1, 0);
        dp[5] = 1;
        for (int i = 6; i <= n; i++) {
            if (i % 5 == 0) {
                dp[i] = dp[i/5] + 1;
            }
        } 
        
        int count = 0;
        for (int i = 0; i <= n; i++) {
            count += dp[i];
        }

        return count;
    }
};
