
// 213. House Robber II 

class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        
        if (nums.empty()) {
            return 0;
        }
        
        if (len == 1) {
            return nums[0];
        } else if (len == 2) {
            return max(nums[0], nums[1]);
        } else if (len == 3) {
            return max(nums[0], max(nums[1], nums[2]));
        }
        
        int maxVal = 0;
        vector<int> dp(len, 0);
        
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for (int i = 2; i < len - 1; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        
        maxVal = dp[len - 2];
        
        for (int i = len - 1; i >= 1; i--) {
            dp[i] = max(dp[i + 1], dp[i + 2] + nums[i]);
        }
        
        maxVal = max(maxVal, dp[1]);
        return maxVal;
    }
};
