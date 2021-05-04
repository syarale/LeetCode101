
// 300. Longest Increasing Subsequence

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int len = nums.size();
        vector<int> dp(len, 1);
        if (len <= 1) {
            return len;
        }
        
        int maxLen = 1;
        for (int i = 1; i < len; i++) {
            for (int k = 0; k < i; k++) {
                if (nums[i] > nums[k]) {
                    dp[i] = max(dp[i], dp[k] + 1);
                }
            }
            
            maxLen = max(maxLen, dp[i]);
        }
        
        return maxLen;
    }
}; 
