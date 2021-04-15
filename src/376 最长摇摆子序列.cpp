
// 376. Wiggle Subsequence

class Solution {
public:
    
    // DP, Time: O(n^2)
    int wiggleMaxLength(vector<int>& nums) {
        int len = nums.size();
        
        if (nums.empty()) {
            return 0;
        }
        
        if (len == 1) {
            return 1;
        }
        
        vector<int> pdp(len, 1);     // positive dp table: list[i - 1] < list[i] in the wiggle list. 
        vector<int> ndp(len, 1);     // negative dp table: list[i - 1] > list[i] in the wiggle list.
        
        if (nums[1] > nums[0]) {
            pdp[1] = 2;
        } else if (nums[1] < nums[0]) {
            ndp[1] = 2;
        } else {
            pdp[1] = 1;
            ndp[1] = 1;
        }
        
        int maxLen = max(max(pdp[0], ndp[0]), max(pdp[1], ndp[1]));
        for (int i = 2; i < len; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[j] < nums[i]) {
                    pdp[i] = max(pdp[i], ndp[j] + 1);
                }

                if (nums[j] > nums[i]) {
                    ndp[i] = max(ndp[i], pdp[j] + 1);
                }
            }
            
            maxLen = max(maxLen, max(pdp[i], ndp[i]));
        }
        
        return maxLen;
    }
};
