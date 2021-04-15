// 416. Partition Equal Subset Sum

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) {
            return false;
        }
        
        int len = nums.size();
        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        
        if (target >= nums[0]) {
            dp[nums[0]] = true;
        }
        
        for (int i = 1; i < len; i++) {
            for (int j = target; j >= nums[i]; j--) {
                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }
        
        return dp[target];
    }
};
