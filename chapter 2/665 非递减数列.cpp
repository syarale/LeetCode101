// 665£º·ÇµÝ¼õÊýÁÐ

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 0;
        int len = nums.size();
        
        if (len <= 2) {
            return true;
        } 
        
        for (int i = 0; i < len; i++) {
            if (i + 1 < len && nums[i] > nums[i + 1]) {
                if (i - 1 < 0 || nums[i - 1] <= nums[i + 1]) {
                    nums[i] = nums[i + 1];
                } else {
                    nums[i + 1] = nums[i];
                }
                
                count++;
            }
        }
        
        return count <= 1;
    }
}; 
