
// 494. Target Sum

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int len = nums.size();
        
        if (nums.empty()) {
            return 0;
        }
        
        // assert(nums[i] >= 0);
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (target > sum || target < -sum) {
            return 0;
        }


        int offset = sum;
        vector<vector<int> > dp(len, vector<int> (2 * sum + 1, 0));
        
        dp[0][nums[0] + offset] += 1;
        dp[0][- nums[0] + offset] += 1;

        for (int i = 1; i < len; i++) {
            for (int j = -sum; j <= sum; j++) {
                if (nums[i] == 0) {
                    dp[i][j + offset] = dp[i - 1][j + offset] * 2;
                } else {
                    if (j - nums[i] >= -sum) {
                        dp[i][j + offset] += dp[i - 1][j - nums[i] + offset];
                    }

                    if (j + nums[i] <= sum) {
                        dp[i][j + offset] += dp[i - 1][j + nums[i] + offset];
                    }
                } 
            }
        } 
        
        return dp[len - 1][target + offset];
    }
};
