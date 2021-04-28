
// 238. Product of Array Except Self

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        if (nums.empty()) {
            return res;
        }
        
        int len = nums.size();
        res.resize(len, 0);
        int tmp = 1;
        for (int i = 0; i < len; i++) {
            tmp *= nums[i];
            res[i] = tmp;
        }
        
        int right = 1;
        for (int i = len - 1; i >= 0; i--) {
            if (i == 0) {
                res[i] = right;
                continue;
            }
            
            res[i] = res[i - 1] * right;
            right *= nums[i];
        }
        
        return res;
    }
}; 
