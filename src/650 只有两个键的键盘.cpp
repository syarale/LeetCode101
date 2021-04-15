
// 650. 2 Keys Keyboard

class Solution {
public:
    const int MAX = 1001;
    int minSteps(int n) {
        // assert(n >= 1);
        
        if (n == 1) {
            return 0;
        } 
        
        vector<vector<int> > dp(n + 1, vector<int> (n + 1, MAX));
        dp[0][1] = 0;
        
        int minNum = MAX; 
        for (int i = 1; i <= n; i ++) {
            for (int j = i + 1; j <= n; j++) {
                if (j % i != 0) {
                    dp[i][j] = min(dp[i][j], dp[i][j - i] + 1);
                    continue;
                }
                
                for (int k = 0; k < i; k++) {
                    dp[i][j] = min(d[i][j], dp[k][i] + 2);
                }
            }
            
            minNum = min(minNum, dp[i][n]);
        }
        
        return minNum;

    }
};
