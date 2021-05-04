
// 53. Maximum Subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // assert(!nums.empty());
        int len = nums.size();
        vector<int> dp(len, 0);
        
        if (len == 1) { 
            return nums[0];
        }
        
        dp[0] = nums[0];
        int maxVal = dp[0]; 
        for (int i = 1; i < len; i++){
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            maxVal = max(maxVal, dp[i]);
        }
        
        return maxVal;
    }
};
