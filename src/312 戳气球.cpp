
// 312. Burst Balloons

// DP
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        } 
        
        int len = nums.size();
        if (len == 1) {
            return nums[0];
        } 
        
        vector<vector<int> > dp(len, vector<int>(len, 0));
        dp[0][0] = nums[0] * nums[1];
        dp[len - 1][len - 1] = nums[len - 1] * nums[len - 2];
        for (int i = 1; i < len - 1; i++) {
            dp[i][i] = nums[i - 1] * nums[i] * nums[i + 1];
        }
        
        for (int l = 1; l < len; l++) {
            for (int i = 0; i < len - l; i++) {
                for (int k = i; k <= i + l; k++) {
                    int curr = nums[k];
                    int currdp = 0;
                    
                    if (i - 1 >= 0) {
                        curr *= nums[i - 1];
                    }
                    
                    if (i + l + 1 <= len - 1) {
                        curr *= nums[i + l + 1];
                    }
                    
                    if (k - 1 >= i) {
                        currdp += dp[i][k - 1];
                    }
                    
                    if (k + 1 <= i + l) {
                        currdp += dp[k + 1][i + l];
                    }
                    
                    dp[i][i + l] = max(dp[i][i + l], curr + currdp);
                }
            }
        } 
        
        return dp[0][len - 1];
    }
}; 
