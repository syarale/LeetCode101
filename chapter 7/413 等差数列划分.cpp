
// 413. Arithmetic Slices

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len, 0);
        
        if (len < 3) {
            return 0;
        }
        
        for (int i = 2; i < len; i++) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                dp[i] = dp[i - 1] + 1;   // dp[i - 1] + {nums[i - 2], nums[i - 1], nums[i] }
            } else {
                dp[i] = 0;
            }
        }
        
        int sum = accumulate(dp.begin(), dp.end(), 0);
        return sum;
    }
}; 
