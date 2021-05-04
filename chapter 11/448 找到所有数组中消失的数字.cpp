
// 448. Find All Numbers Disappeared in an Array

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
        vector<int> res;
        
        if (nums.empty()) {
            return res;
        }
        
        for (int i = 0; i < len; i++) {
            int pos = abs(nums[i]) - 1;
            if (nums[pos] > 0) {
                nums[pos] = - nums[pos];
            } 
        }
        
        for (int i = 0; i < len; i++) {
            if (nums[i] > 0) {
                res.push_back(i + 1);
            }
        }
        
        return res;
    }
};
