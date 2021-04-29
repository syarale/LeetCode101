
// 338. Counting Bits 

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num + 1, 0);

        for (int i = 1; i <= num; i++) {
            if ((i & 1) == 1) {
                dp[i] = dp[i - 1] + 1;
            } else {
                dp[i] = dp[i >> 1];
            }
        }

        return dp;
    }
};
